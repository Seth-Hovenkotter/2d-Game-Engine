//=============================================================================
#include "CPlayer.h"
//=============================================================================
CPlayer::CPlayer() {
    Health = 20;
    Pass = false;
}

//=============================================================================
bool CPlayer::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    Type = ENTITY_TYPE_PLAYER;
    return true;
}

//-----------------------------------------------------------------------------
void CPlayer::OnLoop() {
    if(Health <= 0){
        Dead = true;
        OnCleanup();
    }
	CEntity::OnLoop();
}

//-----------------------------------------------------------------------------
void CPlayer::OnRender(SDL_Surface* Surf_Display) {
	CEntity::OnRender(Surf_Display);
}

//------------------------------------------------------------------------------
void CPlayer::OnCleanup() {
	CEntity::OnCleanup();
}

//------------------------------------------------------------------------------
void CPlayer::OnAnimate() {

    if(SpeedX != 0) {
		Anim_Control.MaxFrames = 8;
	}else{
		Anim_Control.MaxFrames = 0;
	}

	if(MoveUp && MoveRight) {
        CurrentFrameCol = 3;
    }else

    if(MoveUp && MoveLeft){
        CurrentFrameCol = 4;
    }else

	if(MoveLeft) {
		CurrentFrameCol = 2;
	}else

	if(MoveRight) {
		CurrentFrameCol = 1;
	}
	else{
        CurrentFrameCol = 0;
	}

	CEntity::OnAnimate();
}

//------------------------------------------------------------------------------
bool CPlayer::OnCollision(CEntity* Entity) {
    if(Entity->Type == ENTITY_TYPE_WOLF)
	{
        Health = Health - 1;
		BounceBack();
		Jump();
	}
    return true;
}
//------------------------------------------------------------------------------

int CPlayer::GetFrameCol(){
    return CurrentFrameCol;
}

void CPlayer::BounceBack(){
    switch(GetFrameCol()){
        case 0:
            SpeedX = -MaxSpeedX;
            break;
        case 1:
            SpeedX = -MaxSpeedX;
            break;
        case 2:
            SpeedX = MaxSpeedX;
            break;
        case 3:
            SpeedX = -MaxSpeedX;
            break;
        case 4:
            SpeedX = MaxSpeedX;
            break;
    }
}
//=============================================================================
