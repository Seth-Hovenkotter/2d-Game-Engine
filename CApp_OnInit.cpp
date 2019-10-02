//==============================================================================
#include "CApp.h"

//==============================================================================
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if(CArea::AreaControl.OnLoad("./maps/1.area") == false) {
    	return false;
    }

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    if(Player.OnLoad("bubbles.png", 64, 64, 8) == false) {
    	return false;
    }
//-----------------------------------------------------------------------------------------------------------------
//Wolves
    if(Wolf.OnLoad("WolfSheet.png", 106, 42, 5) == false) {
    	return false;
    }
    if(Wolf2.OnLoad("WolfSheet.png", 106, 42, 5) == false) {
    	return false;
    }
    if(Wolf3.OnLoad("WolfSheet.png", 106, 42, 5) == false) {
    	return false;
    }
    if(Wolf4.OnLoad("WolfSheet.png", 106, 42, 5) == false) {
    	return false;
    }
    if(Wolf5.OnLoad("WolfSheet.png", 106, 42, 5) == false) {
    	return false;
    }
    if(Wolf6.OnLoad("WolfSheet.png", 106, 42, 5) == false) {
    	return false;
    }
    if(Wolf7.OnLoad("WolfSheet.png", 106, 42, 5) == false) {
    	return false;
    }
    if(Wolf8.OnLoad("WolfSheet.png", 106, 42, 5) == false) {
    	return false;
    }
    if(Wolf9.OnLoad("WolfSheet.png", 106, 42, 5) == false) {
    	return false;
    }
    if(Wolf10.OnLoad("WolfSheet.png", 106, 42, 5) == false) {
    	return false;
    }

//--------------------------------------------------------------------------------------------------------------------
//Checkpoints
    if(CheckPoint1.OnLoad("CheckpointSheet.png", 40, 64, 12) == false){
        return false;
    }
    if(CheckPoint2.OnLoad("CheckpointSheet.png", 40, 64, 12) == false){
        return false;
    }
    if(CheckPoint3.OnLoad("CheckpointSheet.png", 40, 64, 12) == false){
        return false;
    }
    if(CheckPoint4.OnLoad("CheckpointSheet.png", 40, 64, 12) == false){
        return false;
    }
    if(CheckPoint5.OnLoad("CheckpointSheet.png", 40, 64, 12) == false){
        return false;
    }
    if(CheckPoint6.OnLoad("CheckpointSheet.png", 40, 64, 12) == false){
        return false;
    }
    if(CheckPoint7.OnLoad("CheckpointSheet.png", 40, 64, 12) == false){
        return false;
    }
    if(CheckPoint8.OnLoad("CheckpointSheet.png", 40, 64, 12) == false){
        return false;
    }
//-------------------------------------------------------------------------------------------------------------
//Health Bar
    CHealthbar::GUIControl.OnLoad("HealthBar.png",327,64,11);
//-------------------------------------------------------------------------------------------------------------
//Wolf Positions
    Player.SetXY(50, 200);
    Wolf.X = 2500;
    Wolf2.X = 2750;
    Wolf3.X = 3965;
    Wolf4.X = 3525;
    Wolf5.SetXY(5000,400);
    Wolf6.X = 4920;
    Wolf7.X = 5450;
    Wolf8.SetXY(6460, 600);
    Wolf9.SetXY(6360, 100);
    Wolf10.SetXY(8800, 100);
//-------------------------------------------------------------------------------------------------------------
//Checkpoint positions
    CheckPoint1.X = 500;
    CheckPoint2.X = 1650;
    CheckPoint3.X = 2900;
    CheckPoint4.X = 5250;
    CheckPoint5.SetXY(6600, 100);
    CheckPoint6.SetXY(6800, 688);
    CheckPoint7.SetXY(8975, 100);
    CheckPoint8.SetXY(10100, 650);


    CEntity::EntityList.push_back(&Player);
    CEntity::EntityList.push_back(&Wolf);
    CEntity::EntityList.push_back(&Wolf2);
    CEntity::EntityList.push_back(&Wolf3);
    CEntity::EntityList.push_back(&Wolf4);
    CEntity::EntityList.push_back(&Wolf5);
    CEntity::EntityList.push_back(&Wolf6);
    CEntity::EntityList.push_back(&Wolf7);
    CEntity::EntityList.push_back(&Wolf8);
    CEntity::EntityList.push_back(&Wolf9);
    CEntity::EntityList.push_back(&Wolf10);
    CEntity::EntityList.push_back(&CheckPoint1);
    CEntity::EntityList.push_back(&CheckPoint2);
    CEntity::EntityList.push_back(&CheckPoint3);
    CEntity::EntityList.push_back(&CheckPoint4);
    CEntity::EntityList.push_back(&CheckPoint5);
    CEntity::EntityList.push_back(&CheckPoint6);
    CEntity::EntityList.push_back(&CheckPoint7);
    CEntity::EntityList.push_back(&CheckPoint8);
    CEntity::EntityList.push_back(&CHealthbar::GUIControl);


	CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);

    return true;
}

//==============================================================================
