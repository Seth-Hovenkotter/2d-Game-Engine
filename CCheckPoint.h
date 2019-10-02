//=============================================================================
#ifndef _CCHECKPOINT_H_
    #define _CCHECKPOINT_H_

#include "CEntity.h"

//=============================================================================
class CCheckPoint : public CEntity {
    public:
        CCheckPoint();

        bool Crossed;

		bool OnLoad(char* File, int Width, int Height, int MaxFrames);

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnCleanup();

        void OnAnimate();

        bool OnCollision(CEntity* Entity);
};

//=============================================================================

#endif


