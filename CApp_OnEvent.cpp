//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

//==============================================================================
void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_LEFT: {
			Player.MoveLeft = true;
			break;
		}

		case SDLK_RIGHT: {
			Player.MoveRight = true;
			break;
		}

		case SDLK_SPACE:{
		    Player.MoveUp = true;
            Player.Jump();
            break;
		}
		case SDLK_c:{


		}

		default: {
		}
	}
}

//------------------------------------------------------------------------------
void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_LEFT: {
			Player.MoveLeft = false;
			break;
		}

		case SDLK_RIGHT: {
			Player.MoveRight = false;
			break;
		}

		case SDLK_c: {
		    for(int i = 0; i < 1; i++)
				{
					if(Player.GetFrameCol() == 1 || Player.GetFrameCol() == 0 || Player.GetFrameCol() == 3)
					{
                        Vector accel(25, 0);
                        Vector speed(1,0);
                        Vector pos(Player.GetX() + 75,Player.GetY() + 30);
                        Vector dir(1,0);
                        CEntity::EntityList.push_back(new CFireball(pos,speed,accel,dir,0));
					} else if(Player.GetFrameCol() == 2 || Player.GetFrameCol() == 4)
                        {
                        Vector accel(-25, 0);
                        Vector speed(1,0);
                        Vector pos(Player.GetX() - 35,Player.GetY() + 30);
                        Vector dir(1,0);
                        CEntity::EntityList.push_back(new CFireball(pos,speed,accel,dir,0));
                        }
					}

			break;
		}

		default: {
		}
	}
}

//------------------------------------------------------------------------------
void CApp::OnExit() {
	Running = false;
}

//==============================================================================
