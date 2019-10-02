//=============================================================================
#include "CCheckPoint.h"

//=============================================================================
CCheckPoint::CCheckPoint() {
    Crossed = false;

    Type = ENTITY_TYPE_CHECKPOINT;
}

//=============================================================================
bool CCheckPoint::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------
void CCheckPoint::OnLoop() {
	CEntity::OnLoop();
}

//-----------------------------------------------------------------------------
void CCheckPoint::OnRender(SDL_Surface* Surf_Display) {
	CEntity::OnRender(Surf_Display);
}

//------------------------------------------------------------------------------
void CCheckPoint::OnCleanup() {
	CEntity::OnCleanup();
}

//------------------------------------------------------------------------------
void CCheckPoint::OnAnimate() {
	if(SpeedX != 0) {
		Anim_Control.MaxFrames = 8;
	}else{
		Anim_Control.MaxFrames = 0;
	}

	if(Crossed){
        CurrentFrameCol = 1;
        Anim_Control.MaxFrames = 12;
        if(CurrentFrameRow == 12){
            CurrentFrameCol = 2;
            Anim_Control.MaxFrames = 0;
        }
	}




	CEntity::OnAnimate();
}

//------------------------------------------------------------------------------
bool CCheckPoint::OnCollision(CEntity* Entity) {
    if(Entity->Type == ENTITY_TYPE_PLAYER){
        Crossed = true;
        Flags = ENTITY_FLAG_MAPONLY;
    }
    return true;
}

//------------------------------------------------------------------------------
