//==============================================================================
#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL/SDL.h>

#include "Define.h"

#include "CFPS.h"

#include "CArea.h"
#include "CCamera.h"
#include "CEntity.h"
#include "CEvent.h"
#include "CSurface.h"
#include "CWolf.h"
#include "CPlayer.h"
#include "CFireball.h"
#include "CCheckPoint.h"
#include "CHealthbar.h"
#include "PlayerControl.h"
#include "Vector.h"

//==============================================================================
class CApp : public CEvent {
    private:
        bool            Running;

        SDL_Surface*    Surf_Display;

        CPlayer			Player;
        CWolf			Wolf;
        CWolf           Wolf2;
        CWolf           Wolf3;
        CWolf           Wolf4;
        CWolf           Wolf5;
        CWolf           Wolf6;
        CWolf           Wolf7;
        CWolf           Wolf8;
        CWolf           Wolf9;
        CWolf           Wolf10;
        CCheckPoint     CheckPoint1;
        CCheckPoint     CheckPoint2;
        CCheckPoint     CheckPoint3;
        CCheckPoint     CheckPoint4;
        CCheckPoint     CheckPoint5;
        CCheckPoint     CheckPoint6;
        CCheckPoint     CheckPoint7;
        CCheckPoint     CheckPoint8;

    public:
        CApp();

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(SDL_Event* Event);

        	void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        	void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

            void OnExit();

        void OnLoop();

        void OnRender();

        void OnCleanup();
};

//==============================================================================

#endif
