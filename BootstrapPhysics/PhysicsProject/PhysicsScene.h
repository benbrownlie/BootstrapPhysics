#pragma once
#include "glm/vec2.hpp"
#include "glm/exponential.hpp"
#include "glm/ext.hpp"
#include <set>

class PhysicsObject;
class Sphere;

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void addActor(PhysicsObject* actor);
	void removeActor(PhysicsObject* actor);

	void update(float deltaTime);
	void draw();

	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; }
	glm::vec2 getGravity() const;

	void setTimeStep(const float timeStep) { m_timeStep = timeStep; }
	float getTimeStep() const { return m_timeStep; }

	static bool sphereToSphere(Sphere* sphere1, Sphere* sphere2);

private:
	glm::vec2 m_gravity;
	float m_timeStep;
	std::set<PhysicsObject*> m_actors;
};

