#pragma once

#include<string>
#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include <map>

class TextureManager
{
	public:
		static TextureManager* GetInstance()
		{
			return s_Instance = (s_Instance != nullptr) ? s_Instance : new TextureManager();
		}

		bool Load(std::string id, std::string filename);
		void Drop(std::string id);
		void Clean();

		void Draw(std::string id, int x, int y, int width, int height, SDL_FlipMode flip = SDL_FLIP_NONE);

	private:
		TextureManager(){}
		std::map<std::string, SDL_Texture*> m_TextureMap;
		static TextureManager* s_Instance;

};
