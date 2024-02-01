#include <stdio.h>
#include <iostream>

#include "IO.h"

SDL_Window* screen = SDL_CreateWindow("Tetris",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    640, 640, 0);
SDL_Renderer* renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_SOFTWARE);

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
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Could not init SDL: %s\n", SDL_GetError());
        return 1;
    }
    std::atexit(SDL_Quit);

    return 0;
}

/*
Clear the screen
*/
void IO::ClearScreen()
{
    SDL_RenderClear(renderer);
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
    //SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
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