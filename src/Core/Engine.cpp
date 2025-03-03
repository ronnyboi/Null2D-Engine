#include "Engine.h"
#include <iostream>
#include "../Graphics/TextureManager.h"
#include "../Physics/Vector2D.h"
#include "../Physics/Transform.h"

Engine* Engine::s_Instance = nullptr;

bool Engine::Init()
{
	std::cout << "Starting SDL Initialization..." << std::endl;
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Failed to intialize SDL: %s", SDL_GetError());
		return false;
	}
	m_Window = SDL_CreateWindow("NULL2D",SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (m_Window == nullptr)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}
	m_Renderer = SDL_CreateRenderer(m_Window, NULL);
	if (m_Renderer == nullptr)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}

	TextureManager::GetInstance()->Load("trees", "assets/trees.png");

	// testing the vector and transform classes
	Vector2D v1, v2;
	v1.Log(" V1: ");

	Transform tf;
	tf.Log();

	return m_IsRunning = true;
}

void Engine::Update()
{
	//SDL_Log("helloworld");
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderClear(m_Renderer);

	TextureManager::GetInstance()->Draw("trees", 100, 100, 240, 240);
	SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_EVENT_QUIT:
			Quit();
			break;

	}
}

bool Engine::Clean()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
	return true;
}

void Engine::Quit()
{
	m_IsRunning = false;
}
