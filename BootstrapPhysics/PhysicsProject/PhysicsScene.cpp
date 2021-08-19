#include "PhysicsScene.h"
#include "PhysicsObject.h"
#include "Sphere.h"

PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(glm::vec2(0, 0))
{

}

PhysicsScene::~PhysicsScene()
{

}

void PhysicsScene::addActor(PhysicsObject* actor)
{
	m_actors.insert(actor);
}

void PhysicsScene::removeActor(PhysicsObject* actor)
{
	m_actors.erase(actor);
}

void PhysicsScene::update(float deltaTime)
{
	static float accumulatedTime = 0.0f;
	accumulatedTime += deltaTime;

	//As long as there is enough accumulated time for a fixedUpdate...
	while (accumulatedTime >= m_timeStep)
	{
		//...call each actor's fixedUpdate
		for (PhysicsObject* actor : m_actors)
		{
			actor->fixedUpdate(m_gravity, m_timeStep);
		}
		accumulatedTime -= m_timeStep;

		auto outerEnd = m_actors.end();
		outerEnd--;

		for (auto outer = m_actors.begin(); outer != outerEnd; outer++)
		{
			auto innerStart = outer;
			innerStart++;
			for (auto inner = innerStart; inner != m_actors.end(); inner++)
			{
				PhysicsObject* object1 = *outer;
				PhysicsObject* object2 = *inner;

				//Collision check
				sphereToSphere(dynamic_cast<Sphere*>(object1), dynamic_cast<Sphere*>(object2));
			}
		}
	}
}

void PhysicsScene::draw()
{
	for (PhysicsObject* actor : m_actors)
	{
		actor->draw();
	}
}

glm::vec2 PhysicsScene::getGravity() const
{
	return glm::vec2();
}

bool PhysicsScene::sphereToSphere(Sphere* sphere1, Sphere* sphere2)
{
	if (sphere1 != nullptr && sphere2 != nullptr)
	{
		glm::vec2 position1 = sphere1->getPosition();
		glm::vec2 position2 = sphere2->getPosition();
		glm::vec2 distanceVec = position1 - position2;
		float distance = glm::sqrt(distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y);
		float totalRadius = sphere1->getRadius() + sphere2->getRadius();

		if (glm::abs(distance) < totalRadius)
		{
			sphere2->applyForce(-(sphere2->getVelocity() * sphere2->getMass()));
			sphere1->applyForce(-(sphere1->getVelocity() * sphere1->getMass()));
		}
	}

	return false;
}
