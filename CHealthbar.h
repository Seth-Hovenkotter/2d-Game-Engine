#ifndef _CHEALTHBAR_H
	#define _CHEALTHBAR_H

#include "CEntity.h"

#include "PlayerControl.h"

#include "CSurface.h"


class CHealthbar : public CEntity
{

private:

	SDL_Surface* TheGUI;

public:

	static CHealthbar GUIControl;

	CHealthbar();

	bool OnLoad(char* File, int Width, int Height, int MaxFrames);

	void OnLoop();

	void OnRender(SDL_Surface* SurfDisplay);

	void OnCleanup();

	void OnAnimate();

	int PlayerHealth;

};



#endif
