#ifndef LINUX
#include <windows.h>
#endif
#include "Game.h"

/*
Init
*/
Game::Game(Field *pField, Shapes *pShapes, IO *pIO, int pScreenHeight)
{
    mScreenHeight = pScreenHeight;
    // get pointers to Field and Shapes classes
    mField = pField;
    mShapes = pShapes;
    mIO = pIO;
    // game initialization
    InitGame();
}

/*
Get a random int between two integers

Parameters:
pA  ->  first number
pB  ->  second number
*/
int Game::GetRandom(int pA, int pB)
{
    return rand() % (pB - pA + 1) + pA;
}

/*
Initial parameters of the game
*/
void Game::InitGame()
{
    // init random numbers
    srand((unsigned int)time(NULL));
    // first shape
    mShape = GetRandom(0, 6);
    mRotation = GetRandom(0, 3);
    mPosX = (FIELD_WIDTH / 2) + mShapes->GetXInitialPosition(mShape, mRotation);
    mPosY = mShapes->GetYInitialPosition(mShape, mRotation);
    // next shape
    mNextShape = GetRandom(0, 6);
    mNextRotation = GetRandom(0, 3);
    mNextPosX = FIELD_WIDTH + 5;
    mNextPosY = 5;
}

/*
Create a random shape
*/
void Game::CreateNewShape()
{
    // new shape
    mShape = mNextShape;
    mRotation = mNextRotation;
    mPosX = (FIELD_WIDTH / 2) + mShapes->GetXInitialPosition(mShape, mRotation);
    mPosY = mShapes->GetYInitialPosition(mShape, mRotation);
    // random next shape
    mNextShape = GetRandom(0, 6);
    mNextRotation = GetRandom(0, 3);
}

/*
Draw shape

Parameters:
pX          ->  horizontal position in blocks
pY          ->  vertical position in blocks
pShape      ->  shape to draw
pRotation   ->  one of four rotations
*/
void Game::DrawShape(int pX, int pY, int pShape, int pRotation)
{
    // get the position of the block on the screen that we want to draw, in pixels
    int mPixelsX = mField->GetXPositionInPixels(pX);
    int mPixelsY = mField->GetYPositionInPixels(pY);
    // move through the matrix of blocks of the shape and draws the filled blocks
    for (int i = 0; i < SHAPE_BLOCKS; i++)
    {
        for (int j = 0; j < SHAPE_BLOCKS; j++)
        {
            if (mShapes->GetBlockType(pShape, pRotation, j, i) != 0)
            {
                int pX1 = mPixelsX + i * BLOCK_SIZE, pY1 = mPixelsY + j * BLOCK_SIZE;
                int pX2 = (mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1, pY2 = (mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1;

                mIO->DrawRectangle(pX1, pY1, pX2 - pX1, pY2 - pY1);
            }
        }
    }
}

/*
Draw field

Draw the two lines that limit the field
*/
void Game::DrawField()
{
    // calculate field limits pixels
    int mX1 = FIELD_POSITION - (BLOCK_SIZE * (FIELD_WIDTH / 2)) - 1;
    int mX2 = FIELD_POSITION + (BLOCK_SIZE * (FIELD_WIDTH / 2));
    int mY = mScreenHeight - (BLOCK_SIZE * FIELD_HEIGHT);
    // rectangles that limit the field
    mIO->DrawRectangle(mX1 - FIELD_LINE_WIDTH, mY, mX1 - (mX1 - FIELD_LINE_WIDTH), mScreenHeight - BLOCK_SIZE);
    mIO->DrawRectangle(mX2, mY, (mX2 + FIELD_LINE_WIDTH) - mX2, mScreenHeight - BLOCK_SIZE);
    // draw the blocks that are already stored in the field
    mX1 += 1;
    for (int i = 0; i < FIELD_WIDTH; i++)
    {
        for (int j = 0; j < FIELD_HEIGHT; j++)
        {
            // if block if filled -> draw it
            if (!mField->IsFreeBlock(i, j))
            {
                int pX1 = mX1 + i * BLOCK_SIZE, pY1 = mY + j * BLOCK_SIZE;
                int pX2 = (mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1, pY2 = (mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1;
                mIO->DrawRectangle(pX1, pY1, pX2 - pX1, pY2 - pY1);
            }
        }
    }
}

/*
Draw scene

Draws all the objects of the scene
*/
void Game::DrawScene()
{
    DrawField();                                                // draw the game field
    DrawShape(mPosX, mPosY, mShape, mRotation);                 // draw the falling shape
    DrawShape(mNextPosX, mNextPosY, mNextShape, mNextRotation); // draw the next shape
}