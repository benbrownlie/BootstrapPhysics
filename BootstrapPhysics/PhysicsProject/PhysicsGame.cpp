#include "PhysicsGame.h"
#include "Sphere.h"
#include "Plane.h"
#include "Input.h"
#include "Font.h"
#include "Gizmos.h"
#include <glm/ext.hpp>

bool PhysicsGame::startup()
{
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_renderer = new aie::Renderer2D();
	setBackgroundColour(0.0f, 0.2f, 0.1f, 1.0f);

	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_scene = new PhysicsScene();
	m_scene->setTimeStep(0.01f);
	m_scene->setGravity({ 0.0f, -10.0f });

	Sphere* ball1 = new Sphere(glm::vec2(-20.0f, 0), glm::vec2(), 1, 5, glm::vec4(1.0f, 0.5f, 0.2f, 1.0f));
	m_scene->addActor(ball1);
	//ball1->applyForce(glm::vec2(5.0f, 0.0f));

	Sphere* ball2 = new Sphere(glm::vec2(20.0f, 0), glm::vec2(), 1, 5, glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));
	m_scene->addActor(ball2);

	Plane* surface = new Plane(glm::vec2(0.2f, 1.0f), -30.0f, glm::vec4(0.2f, 0.8f, 0.2f, 1.0f));
	m_scene->addActor(surface);

	return true;
}

void PhysicsGame::shutdown()
{
	delete m_renderer;
	delete m_scene;
	delete m_font;
}

void PhysicsGame::update(float deltaTime)
{
	//Get the input instance
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();

	m_scene->update(deltaTime);

	//Exit on Esc
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}
}

void PhysicsGame::draw()
{
	clearScreen();

	m_renderer->begin();

	//Draw the scene
	m_scene->draw();

	//Draw the Gizmos
	static float aspectRatio = 16.0f / 9.0f;
	aie::Gizmos::draw2D(glm::ortho<float>(
		-100,				//Left
		 100,				//Right
		-100 / aspectRatio, //Bottom
		 100 / aspectRatio, //Top
		-1.0f,				//zNear
		 1.0f				//zFar
		));

	//Draw fps
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	m_renderer->drawText(m_font, fps, 0.0f, 720.0f - 32.0f);

	m_renderer->end();
}
