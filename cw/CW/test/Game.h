#ifndef _GAME_
#define _GAME_

#include "Field.h"
#include "Shapes.h"
#include "IO.h"
#include <time.h>

#define DELAY 640 // the number of milliseconds that the shape remains stationary before dropping down one block

class Game
{
public:
    Game(Field *pField, Shapes *pShapes, IO *pIO, int pScreenHeight);

    void DrawScene(int Level, int Score);
    void CreateNewShape();

    int mPosX, mPosY;      // the position of the falling shape
    int mShape, mRotation; // type and rotation of the falling shape
private:
    int mScreenHeight;             // screen height in pixels
    int mNextPosX, mNextPosY;      // position of the next shape
    int mNextShape, mNextRotation; // type and rotation of the next shape

    Field *mField;
    Shapes *mShapes;
    IO *mIO;

    int GetRandom(int pA, int pB);
    void InitGame();
    void DrawShape(int pX, int pY, int pShape, int pRotation);
    void DrawField();
};

#endif