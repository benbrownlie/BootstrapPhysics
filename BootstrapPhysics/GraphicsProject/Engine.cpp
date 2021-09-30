#include "Engine.h"
#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include "glm/ext.hpp"
#include <iostream>

Engine::Engine() : Engine(1280, 720, "Window")
{

}

Engine::Engine(int width, int height, const char* title)
{
	m_world = new World(width, height);
	m_width = width;
	m_height = height;
	m_title = title;
}

Engine::~Engine()
{
	delete m_world;
}

int Engine::run()
{
	int exitCode = 0;

	//Start
	exitCode = start();
	if (exitCode)
	{
		return exitCode;
	}

	//Update
	while (!getGameOver())
	{
		exitCode = update();
		if (exitCode)
		{
			return exitCode;
		}
		exitCode = draw();
		if (exitCode)
		{
			return exitCode;
		}
	}

	//End
	exitCode = end();
	if (exitCode)
	{
		return exitCode;
	}

	return 0;
}

int Engine::start()
{
	//Initialize GLFW
	if (glfwInit() == GLFW_FALSE)
	{
		return -1;
	}

	//Create a window
	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
	if (!m_window)
	{
		glfwTerminate();
		return -2;
	}
	glfwMakeContextCurrent(m_window);

	//Load OpenGL
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return -3;
	}
	int majorVersion = ogl_GetMajorVersion();
	int minorVersion = ogl_GetMinorVersion();
	printf("OpenGL version %i.%i\n", majorVersion, minorVersion);

	//Initialize the screen
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	//Initialize the shader
	m_shader.loadShader(
		aie::eShaderStage::VERTEX,
		"simplevert.shader"
	);
	m_shader.loadShader(
		aie::eShaderStage::FRAGMENT,
		"simplefrag.shader"
	);
	if (!m_shader.link())
	{
		printf("Shader Error: %s\n", m_shader.getLastError());
		return -10;
	}

	m_world->start();

	return 0;
}

int Engine::update()
{
	if (!m_window) return -4;

	glfwPollEvents();

	m_world->update();

	return 0;
}

int Engine::draw()
{
	if (!m_window) return -5;

	//Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_shader.bind();

	glm::mat4 projectionViewModel = m_world->getProjectionViewModel();
	m_shader.bindUniform("projectionViewModel", projectionViewModel);

	m_world->draw();

	glfwSwapBuffers(m_window);

	return 0;
}

int Engine::end()
{
	if (!m_window) return -6;

	m_world->end();

	//Cleanup and exit 
	glfwDestroyWindow(m_window);
	glfwTerminate();
	return 0;
}

bool Engine::getGameOver()
{
	if (!m_window) return true;

	bool gameIsOver = glfwWindowShouldClose(m_window);
	gameIsOver = gameIsOver || glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS;

	return gameIsOver;
}
