//=============================================================================
#ifndef _CWOLF_H_
    #define _CWOLF_H_

#include "CEntity.h"

//=============================================================================
class CWolf : public CEntity {
    public:
        CWolf();

		bool OnLoad(char* File, int Width, int Height, int MaxFrames);

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnCleanup();

        void OnAnimate();

        bool OnCollision(CEntity* Entity);

        void Patrol();
};

//=============================================================================

#endif


