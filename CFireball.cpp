#include "CFireball.h"


CFireball::CFireball()
{



	AccelX = 0;
	AccelY = 0;

	SpeedX = 0;
	SpeedY = 0;

	MaxSpeedX = 0;
	MaxSpeedY = 0;

	Position = (0,0);
	Direction = (0,0);

	LifeTime = 0;
	FireDelay = 0;
}

CFireball::CFireball(Vector position, Vector speed, Vector acceleration, Vector direction, int Frame)
{

	OnLoad(("FrostOrb.png"),20,20,4);

    Flags = ENTITY_FLAG_GHOST;
    Type = ENTITY_TYPE_PROJECTILE;

	X = position.X;
	Y = position.Y;

	AccelX = acceleration.X;
	AccelY = acceleration.Y;

	SpeedX = speed.X;
	SpeedY = speed.Y;

	MaxSpeedX = SpeedX * 15;

	Direction = direction;

	LifeTime = 0;
	FireDelay = 15;

	Interval = 0;

	CurrentFrameCol = Frame;

}


bool CFireball::OnLoad(char* File, int Width, int Height, int MaxFrames)
{
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {

        return false;
    }

    return true;
}

void CFireball::OnLoop()
{
	LifeTime += CFPS::FPSControl.GetSpeedFactor();

	if(LifeTime > FireDelay)
	{
		Dead = true;
		OnCleanup();
		Flags = ENTITY_FLAG_IGNORE;
	}

	CEntity::OnLoop();
}

void CFireball::OnRender(SDL_Surface* SurfDisplay)
{
    CEntity::OnRender(SurfDisplay);
}

void CFireball::OnCleanup()
{
    CEntity::OnCleanup();
}

void CFireball::OnAnimate()
{

    if(SpeedX != 0) {

        Anim_Control.MaxFrames = 6;

    }
	else{

        Anim_Control.MaxFrames = 0;
    }

    CEntity::OnAnimate();
}

bool CFireball::OnCollision(CEntity* Entity)
{
    if(Entity->Type == ENTITY_TYPE_WOLF){
        Dead = true;
        OnCleanup();
        Flags = ENTITY_FLAG_IGNORE;
    }
    return true;
}
