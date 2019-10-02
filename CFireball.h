#ifndef _CFIREBALL_H
	#define _CFIREBALL_H

#include "CEntity.h"

#include "Vector.h"

class CFireball : public CEntity
{

public:

	CFireball();

	CFireball(Vector position, Vector speed, Vector acceleration, Vector direction, int Frame);

	bool OnLoad(char* File, int Width, int Height, int MaxFrames);

	void OnLoop();

	void OnRender(SDL_Surface* SurfDisplay);

	void OnCleanup();

	void OnAnimate();

	bool OnCollision(CEntity* Entity);

public:

	float LifeTime;

	float FireDelay;

	float Interval;


};



#endif
