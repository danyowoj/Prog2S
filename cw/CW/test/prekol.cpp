#include <iostream>
#include <sstream>

#include "SDL.h"
#include "SDL_ttf.h"
// Create Window and Renderer
SDL_Window* window = SDL_CreateWindow("SDL_ttf in SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

SDL_Surface* surface;
SDL_Texture* texture;
SDL_Rect dstrect;

#undef main
int main(int argc, char *argv[])
{
	bool quit = false;
	SDL_Event event;

	// Init SDL and TTF
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	
	// Set Font and Color
	TTF_Font* font = TTF_OpenFont("8bitOperatorPlus8-Regular.ttf", 25);
	SDL_Color color = { 0, 255, 0 };
	std::cout << "font = " << font << std::endl;
	
	// Vars to print text correctly
	int textW = 0;
	int textH = 0;

	// Print level info
	int Level_number = 15;
	std::stringstream Level;
	Level << "Level: " << Level_number;
	surface = TTF_RenderText_Solid(font, Level.str().c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
	dstrect = { 500, 300, textW, textH };

	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	SDL_RenderPresent(renderer);

	// Print score info
	int Score_number = 9000;
	std::stringstream Score;
	Score << "Score: " << Score_number;
	surface = TTF_RenderText_Solid(font, Score.str().c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
	dstrect = { 500, 350, textW, textH };

	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	SDL_RenderPresent(renderer);
	
	// Print next shape info
	surface = TTF_RenderText_Solid(font, "Next Shape:", color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
	dstrect = { 500, 400, textW, textH };

	// Draw Rectangle
	SDL_Rect rect;
	rect.x = 500;
	rect.y = 350;
	rect.w = 50;
	rect.h = 50;

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, &rect);

	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}
		// Render all the Textures
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		SDL_RenderPresent(renderer);
	}

	// Delete Renderer, Window, Font, all the Textures, all the Surfaces and close TTF and SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont(font);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_Quit();
	SDL_Quit();

	return 0;
}