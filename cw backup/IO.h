#ifndef _IO_
#define _IO_

#include "SDL.h"

class IO
{
public:
    IO();

    void DrawRectangle(int pX, int pY, int pW, int pH);
    void ClearScreen();
    int GetScreenHeight();
    int InitGraphics();
    int PollKey();
    int GetKey();
    int IsKeyDown(int pKey);
    void UpdateScreen();
};

#endif