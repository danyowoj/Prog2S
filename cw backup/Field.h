#ifndef _FIELD_
#define _FIELD_

#include "Shapes.h"

#define FIELD_LINE_WIDTH 6       // Width of each of the two lines that delimit the field
#define BLOCK_SIZE 16            // Width and Height of each block of a piece
#define FIELD_POSITION 320       // Center position of the field from the left of the screen
#define FIELD_WIDTH 10           // Field width in blocks
#define FIELD_HEIGHT 20          // Field height in blocks
#define MIN_VERTICAL_MARGIN 20   // Minimal vertical margin for the field limit
#define MIN_HORIZONTAL_MARGIN 20 // Minimal horizontal margin for the field limit
#define SHAPE_BLOCKS 5           // Number of horizontal and vertical blocks of a matrix piece

class Field
{
public:
    Field(Shapes *pShapes, int pScreenHeight);
    int GetXPositionInPixels(int pPosition);
    int GetYPositionInPixels(int pPosition);
    bool IsFreeBlock(int pX, int pY);
    bool IsPossibleMovement(int pX, int pY, int pShape, int pRotation);
    void StoreShape(int pX, int pY, int pShape, int pRotation);
    void DeletePossibleLines();
    bool IsGameOver();

private:
    enum
    {
        POS_FREE,
        POS_FILLED
    };
    int mField[FIELD_WIDTH][FIELD_HEIGHT];
    Shapes *mShapes;
    int mScreenHeight;
    void InitField();
    void DeleteLine(int pY);
};

#endif