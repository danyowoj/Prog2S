#include <stdio.h>
#include <iostream>

#include "IO.h"

SDL_Window* screen = SDL_CreateWindow("Tetris",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    640, 640, 0);
SDL_Renderer* renderer = SDL_CreateRenderer(screen, -1, 0);
SDL_Color color = { 0, 255, 0 };
SDL_Surface* surface_level;
SDL_Surface* surface_score;
SDL_Surface* surface_shape;
SDL_Surface* surface_controls;
SDL_Texture* texture_level;
SDL_Texture* texture_score;
SDL_Texture* texture_shape;
SDL_Texture* texture_controls;
SDL_Rect dstrect_level;
SDL_Rect dstrect_score;
SDL_Rect dstrect_shape;
SDL_Rect dstrect_controls;

int textW = 0;
int textH = 0;


/*
Init
*/
IO::IO()
{
    InitGraphics();
}

/*
SDL Graphics Initialization
*/
int IO::InitGraphics()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    return 0;
}

/*
Clear the screen
*/
void IO::ClearScreen()
{
    SDL_RenderClear(renderer);
    SDL_DestroyTexture(texture_level);
    SDL_DestroyTexture(texture_score);
    SDL_DestroyTexture(texture_shape);
    SDL_DestroyTexture(texture_controls);
    SDL_FreeSurface(surface_level);
    SDL_FreeSurface(surface_score);
    SDL_FreeSurface(surface_shape);
    SDL_FreeSurface(surface_controls);
}

/*
Draw a rectangle of a given color

Parameters:
pX     ->  the x location of the rectangle's upper left corner
pY     ->  the y location of the rectangle's upper left corner
pW      -> 	the width of the rectangle
pH      ->  the height of the rectangle
*/
void IO::DrawRectangle(int pX, int pY, int pW, int pH)
{
    SDL_Rect rect;
    rect.x = pX;
    rect.y = pY;
    rect.w = pW;
    rect.h = pH;

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void IO::PrintLevelInfo(int Level_number)
{
    TTF_Font* font = TTF_OpenFont("8bitOperatorPlus8-Regular.ttf", 20);

    std::stringstream Level;
    Level << "Level: " << Level_number;
    surface_level = TTF_RenderText_Solid(font, Level.str().c_str(), color);
    texture_level = SDL_CreateTextureFromSurface(renderer, surface_level);
    SDL_QueryTexture(texture_level, NULL, NULL, &textW, &textH);
    dstrect_level = { 475, 320, textW, textH };
}

void IO::PrintScoreInfo(int Score_number)
{
    TTF_Font* font = TTF_OpenFont("8bitOperatorPlus8-Regular.ttf", 20);

    std::stringstream Score;
    Score << "Score: " << Score_number;
    surface_score = TTF_RenderText_Solid(font, Score.str().c_str(), color);
    texture_score = SDL_CreateTextureFromSurface(renderer, surface_score);
    SDL_QueryTexture(texture_score, NULL, NULL, &textW, &textH);
    dstrect_score = { 475, 350, textW, textH };
}

void IO::PrintNextShapeInfo()
{
    TTF_Font* font = TTF_OpenFont("8bitOperatorPlus8-Regular.ttf", 20);

    surface_shape = TTF_RenderText_Solid(font, "Next Shape:", color);
    texture_shape = SDL_CreateTextureFromSurface(renderer, surface_shape);
    SDL_QueryTexture(texture_shape, NULL, NULL, &textW, &textH);
    dstrect_shape = { 475, 380, textW, textH };
}

void IO::PrintControls()
{
    TTF_Font* font = TTF_OpenFont("8bitOperatorPlus8-Regular.ttf", 20);

    surface_controls = TTF_RenderText_Solid_Wrapped(font, "Arrows -> move R -> rotate       D -> drop", color, 180);
    texture_controls = SDL_CreateTextureFromSurface(renderer, surface_controls);
    SDL_QueryTexture(texture_controls, NULL, NULL, &textW, &textH);
    dstrect_controls = { 10, 320, textW, textH };
}

/*
Return the screen height
*/
int IO::GetScreenHeight()
{   
    return SDL_GetWindowSurface(screen)->h;
}

/*
Update screen
*/
void IO::UpdateScreen()
{ 
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderCopy(renderer, texture_level, NULL, &dstrect_level);
    SDL_RenderCopy(renderer, texture_score, NULL, &dstrect_score);
    SDL_RenderCopy(renderer, texture_shape, NULL, &dstrect_shape);
    SDL_RenderCopy(renderer, texture_controls, NULL, &dstrect_controls);
    SDL_RenderPresent(renderer);
}

/*
Key input
*/
int IO::PollKey()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            return event.key.keysym.sym;
        case SDL_QUIT:
            exit(3);
        }
    }
    return -1;
}

int IO::GetKey()
{
    SDL_Event event;
    while (true)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_KEYDOWN)
        {
            break;
        }
        if (event.type == SDL_QUIT)
        {
            exit(3);
        }
    }

    return 0;
}

int IO::IsKeyDown(int pKey)
{
    const Uint8 *mKeytable;
    int mNumkeys;
    SDL_PumpEvents();
    mKeytable = SDL_GetKeyboardState(&mNumkeys);
    return mKeytable[pKey];
}