#include "Game.h"

/*
Main
*/
int main(int argc, char* argv[])
{
    // Class for drawing staff, it uses SDL for the rendering. Change the methods of this class
    // in order to use a different renderer
    IO mIO;
    int mScreenHeight = mIO.GetScreenHeight();

    // Pieces
    Shapes mShapes;

    // Board
    Field mField(&mShapes, mScreenHeight);

    // Game
    Game mGame(&mField, &mShapes, &mIO, mScreenHeight);

    // Get the actual clock milliseconds (SDL)
    unsigned long mTime1 = SDL_GetTicks();

	// ----- Main Loop -----
	while (!mIO.IsKeyDown(SDLK_ESCAPE))
	{
		// ----- Draw -----

		mIO.ClearScreen();	// Clear screen
		mGame.DrawScene();	// Draw staff
		mIO.UpdateScreen(); // Put the graphic context in the screen

		// ----- Input -----

		int mKey = mIO.PollKey();

		switch (mKey)
		{
		case (SDLK_RIGHT):
		{
			if (mField.IsPossibleMovement(mGame.mPosX + 1, mGame.mPosY, mGame.mShape, mGame.mRotation))
				mGame.mPosX++;
			break;
		}

		case (SDLK_LEFT):
		{
			if (mField.IsPossibleMovement(mGame.mPosX - 1, mGame.mPosY, mGame.mShape, mGame.mRotation))
				mGame.mPosX--;
			break;
		}

		case (SDLK_DOWN):
		{
			if (mField.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mShape, mGame.mRotation))
				mGame.mPosY++;
			break;
		}

		case (SDLK_d):
		{
			// Check collision from up to down
			while (mField.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mShape, mGame.mRotation))
			{
				mGame.mPosY++;
			}

			mField.StoreShape(mGame.mPosX, mGame.mPosY - 1, mGame.mShape, mGame.mRotation);

			mField.DeletePossibleLines();

			if (mField.IsGameOver())
			{
				mIO.GetKey();
				exit(0);
			}

			mGame.CreateNewShape();

			break;
		}

		case (SDLK_r):
		{
			if (mField.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mShape, (mGame.mRotation + 1) % 4))
				mGame.mRotation = (mGame.mRotation + 1) % 4;

			break;
		}
		}

		// ----- Vertical movement -----

		unsigned long mTime2 = SDL_GetTicks();

		if ((mTime2 - mTime1) > DELAY)
		{
			if (mField.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mShape, mGame.mRotation))
			{
				mGame.mPosY++;
			}
			else
			{
				mField.StoreShape(mGame.mPosX, mGame.mPosY, mGame.mShape, mGame.mRotation);

				mField.DeletePossibleLines();

				if (mField.IsGameOver())
				{
					mIO.GetKey();
					exit(0);
				}

				mGame.CreateNewShape();
			}

			mTime1 = SDL_GetTicks();
		}
	}

	return 0;
}