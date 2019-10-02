//=============================================================================
#include "CWolf.h"

//=============================================================================
CWolf::CWolf() {
    Health = 1;
    Type = ENTITY_TYPE_WOLF;
}

//=============================================================================
bool CWolf::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------
void CWolf::OnLoop() {

    if(Health <=0){
        Dead = true;
        OnCleanup();
        Flags = ENTITY_FLAG_GHOST;
    }
	CEntity::OnLoop();
}

//-----------------------------------------------------------------------------
void CWolf::OnRender(SDL_Surface* Surf_Display) {
	CEntity::OnRender(Surf_Display);
}

//------------------------------------------------------------------------------
void CWolf::OnCleanup() {
	CEntity::OnCleanup();
}

//------------------------------------------------------------------------------
void CWolf::OnAnimate() {
	if(SpeedX != 0) {
		Anim_Control.MaxFrames = 8;
	}else{
		Anim_Control.MaxFrames = 0;
	}

	CEntity::OnAnimate();
}

//------------------------------------------------------------------------------
bool CWolf::OnCollision(CEntity* Entity) {
    if(Entity->Type == ENTITY_TYPE_PROJECTILE){
            Health = Health - 1;
    }
    return true;
}

//=============================================================================

