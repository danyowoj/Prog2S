#ifndef _IO_
#define _IO_

#include <sstream>
#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"

class IO
{
public:
    IO();

    void DrawRectangle(int pX, int pY, int pW, int pH);
    void PrintLevelInfo(int Level_number);
    void PrintScoreInfo(int Score_number);
    void PrintNextShapeInfo();
    void PrintControls();
    void ClearScreen();
    int GetScreenHeight();
    int InitGraphics();
    int PollKey();
    int GetKey();
    int IsKeyDown(int pKey);
    void UpdateScreen();
};

#endif