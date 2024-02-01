#include "Shapes.h"

// declaring shapes
char mShapes[7 /*type*/][4 /*rotation*/][5 /*horizontal blocks*/][5 /*vertical blocks*/] =
    {
        // Square
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0}}},

        // I
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 1, 1},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 1, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {1, 1, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 1, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}}},
        // L
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 0, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 1, 0},
             {0, 1, 0, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 1, 1, 0, 0},
             {0, 0, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 1, 0},
             {0, 1, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}}},
        // reverse L
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 0, 0},
             {0, 1, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 1, 0, 0, 0},
             {0, 1, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 1, 0},
             {0, 0, 0, 1, 0},
             {0, 0, 0, 0, 0}}},
        // N
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 1, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 1, 1, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 1, 0, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 1, 1, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}}},
        // reverse N
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 0, 1, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 1, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 1, 0, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 1, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}}},
        // T
        {
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 2, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 1, 2, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 1, 2, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0},
             {0, 1, 2, 1, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}}}};

// Moving a shape to the position in which it was first drawn on the board when it was created
int mShapeInitialPosition[7 /*type*/][4 /*rotation*/][2 /*position*/] =
    {
        // Square
        {
            {-2, -3},
            {-2, -3},
            {-2, -3},
            {-2, -3}},
        // I
        {
            {-2, -2},
            {-2, -3},
            {-2, -2},
            {-2, -3}},
        // L
        {
            {-2, -3},
            {-2, -3},
            {-2, -3},
            {-2, -2}},
        // reverse L
        {
            {-2, -3},
            {-2, -2},
            {-2, -3},
            {-2, -3}},
        // N
        {
            {-2, -3},
            {-2, -3},
            {-2, -3},
            {-2, -2}},
        // reverse N
        {
            {-2, -3},
            {-2, -3},
            {-2, -3},
            {-2, -2}},
        // T
        {
            {-2, -3},
            {-2, -3},
            {-2, -3},
            {-2, -2}},
};

/*
Retrun block type:
0 - no block
1 - normal block
2 - pivot point

Parameters:
pShape      ->  Shape to draw
pRotation   ->  one of the four rotations
pX:         ->  Horizontal blocks position
pY:         ->  Vertical blocks position
*/
int Shapes::GetBlockType(int pShape, int pRotation, int pX, int pY)
{
    return mShapes[pShape][pRotation][pX][pY];
}

/*
Returns the horizontal displacement of the piece that has to be applied
in order to create it in the correct position.

Parameters:
pShape      ->  Shape to draw
pRotation   ->  one of the four rotations
*/
int Shapes::GetXInitialPosition(int pShape, int pRotation)
{
    return mShapeInitialPosition[pShape][pRotation][0];
}

/*
Returns the vertical displacement of the piece that has to be applied
in order to create it in the correct position.

Parameters:
pShape      ->  Shape to draw
pRotation   ->  one of the four rotations
*/
int Shapes::GetYInitialPosition(int pShape, int pRotation)
{
    return mShapeInitialPosition[pShape][pRotation][1];
}