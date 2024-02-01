#ifndef _SHAPES_
#define _SHAPES_

class Shapes
{
public:
    int GetBlockType(int pShape, int pRotation, int pX, int pY);
    int GetXInitialPosition(int pShape, int pRotation);
    int GetYInitialPosition(int pShape, int pRotation);
};

#endif