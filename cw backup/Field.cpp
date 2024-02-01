#include "Field.h"

/*
Init
*/
Field::Field(Shapes *pShapes, int pScreenHeight)
{
    // Get the screen height
    mScreenHeight = pScreenHeight;
    // Get the pointer to the shapes class
    mShapes = pShapes;
    // Init the field blocks with fre positions
    InitField();
}

/*
Init the field blocks with free positions
*/
void Field::InitField()
{
    for (int i = 0; i < FIELD_WIDTH; i++)
        for (int j = 0; j < FIELD_HEIGHT; j++)
            mField[i][j] = POS_FREE;
}

/*
Store a shape int he field by filling the blocks

Parameters:
pX          ->  Horizontal position in blocks
pY          ->  Vertical position in blocks
pShape      ->  Shape to draw
pRotation   ->  one of the four rotations
*/
void Field::StoreShape(int pX, int pY, int pShape, int pRotation)
{
    // store each block of the shape into the field
    for (int i1 = pX, i2 = 0; i1 < pX + SHAPE_BLOCKS; i1++, i2++)
    {
        for (int j1 = pY, j2 = 0; j1 < pY + SHAPE_BLOCKS; j1++, j2++)
        {
            // store blocks of the shape if they are not empty
            if (mShapes->GetBlockType(pShape, pRotation, j2, i2) != 0)
                mField[i1][j1] = POS_FILLED;
        }
    }
}

/*
Check for game over
*/
bool Field::IsGameOver()
{
    // game over if the upper line has blocks
    for (int i = 0; i < FIELD_WIDTH; i++)
    {
        if (mField[i][0] == POS_FILLED) return true;
    }

    return false;
}

/*
Delete a line of the field by moving all above lines down

Parameters:
pY  ->  Vertical position in blocks of the line to delete
*/
void Field::DeleteLine(int pY)
{
    // Moves all the upper lines down by one row
    for (int j = pY; j > 0; j--)
    {
        for (int i = 0; i < FIELD_WIDTH; i++)
        {
            mField[i][j] = mField[i][j - 1];
        }
    }
}

/*
Delete all the lines that should be removed
*/
void Field::DeletePossibleLines()
{
    for (int j = 0; j < FIELD_HEIGHT; j++)
    {
        int i = 0;
        while (i < FIELD_WIDTH)
        {
            if (mField[i][j] != POS_FILLED) break;
            i++;
        }

        if (i == FIELD_WIDTH) DeleteLine(j);
    }
}

/*
Returns true if block is empty
Returns false if block is filled

Parameters:
pX  ->  Horizontal position in blocks
pY  ->	Vertical position in blocks
*/
bool Field::IsFreeBlock(int pX, int pY)
{
    if (mField[pX][pY] == POS_FREE) return true; else return false;
}

/*
Returns the horizontal position if pixels of the given block

Parameters:
pPosition   ->  Horizontal position of the block in the field
*/
int Field::GetXPositionInPixels(int pPosition)
{
    return  ((FIELD_POSITION - (BLOCK_SIZE * (FIELD_WIDTH / 2))) + (pPosition * BLOCK_SIZE));
}

/*
Returns the vertical position if pixels of the given block

Parameters:
pPosition   ->  Horizontal position of the block in the field
*/
int Field::GetYPositionInPixels(int pPosition)
{
    return ((mScreenHeight - (BLOCK_SIZE * FIELD_HEIGHT)) + (pPosition * BLOCK_SIZE));
}

/*
Check if the shape can be stored at this position without collisions
Returns true if the movement is possible, otherwise returns false

Parameters:
pX          ->  Horizontal position in blocks
pY          ->  Vertical position in blocks
pShape      ->  Shape to draw
pRotation   ->  One of the four rotations
*/
bool Field::IsPossibleMovement(int pX, int pY, int pShape, int pRotation)
{
    // Checks collision with pieces already stored in the field or the field limits
    for (int i1 = pX, i2 = 0; i1 < pX + SHAPE_BLOCKS; i1++, i2++)
    {
        for (int j1 = pY, j2 = 0; j1 < pY + SHAPE_BLOCKS; j1++, j2++)
        {
            // Check if the piece is outside the limits of the field
            if (i1 < 0 ||
                i1 > FIELD_WIDTH - 1 ||
                j1 > FIELD_HEIGHT - 1)
            {
                if (mShapes->GetBlockType(pShape, pRotation, j2, i2) != 0)
                    return 0;
            }
            // Check if the shape have collisioned with a block already stored in the map
            if (j1 >= 0)
            {
                if ((mShapes->GetBlockType(pShape, pRotation, j2, i2) != 0) &&
                    (!IsFreeBlock(i1, j1)))
                    return false;
            }
        }
    }

    // No collisions
    return true;
}