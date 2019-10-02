#include "CHealthbar.h"

CHealthbar CHealthbar::GUIControl;

CHealthbar::CHealthbar()
{

}

bool CHealthbar::OnLoad(char* File, int Width, int Height, int MaxFrames)
{

	if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false)
	{
        return false;
	}

	Type = ENTITY_TYPE_GENERIC;
	Flags = ENTITY_FLAG_IGNORE;

	SpeedX = 0;
	SpeedY = 0;

	MaxSpeedX = 0;
	MaxSpeedY = 0;

	return true;
}

void CHealthbar::OnLoop()
{
	PlayerHealth = PlayerControl::Control.PlayersCurrentHealth();
	X = CCamera::CameraControl.GetX();
	Y = CCamera::CameraControl.GetY();
	CEntity::OnLoop();
}

void CHealthbar::OnRender(SDL_Surface* SurfDisplay)
{
	CEntity::OnRender(SurfDisplay);
}

void CHealthbar::OnCleanup()
{
	CEntity::OnCleanup();
}

void CHealthbar::OnAnimate()
{
		if(PlayerHealth == 20){
			CurrentFrameRow = 0;

		}else if(PlayerHealth == 18){
			CurrentFrameRow = 1;

		}else if(PlayerHealth == 16){
            CurrentFrameRow = 2;

		}else if(PlayerHealth == 14){
            CurrentFrameRow = 3;

		}else if(PlayerHealth == 12){
            CurrentFrameRow = 4;

		}else if(PlayerHealth == 10){
            CurrentFrameRow = 5;

		}else if(PlayerHealth == 8){
            CurrentFrameRow = 6;

		}else if(PlayerHealth == 6){
            CurrentFrameRow = 7;

		}else if(PlayerHealth == 4){
            CurrentFrameRow = 8;

		}else if(PlayerHealth == 2){
            CurrentFrameRow = 9;
		}
		else if(PlayerHealth == 0){
            CurrentFrameRow = 10;
		}
}
