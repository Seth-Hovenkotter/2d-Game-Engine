#ifndef _PLAYERCONTROL_H
	#define _PLAYERCONTROL_H

#include "Vector.h"

class PlayerControl
{

	int X;

	int Y;

	int Health;


public:

	static PlayerControl Control;

	PlayerControl();

public:

	void SavePlayersCurrentPosition(int xx, int yy);

	Vector PlayersCurrentPosition();

public:

	void SavePlayerHealth(int hp);

	int PlayersCurrentHealth();

};


#endif
