#include "PlayerControl.h"


PlayerControl PlayerControl::Control;

PlayerControl::PlayerControl()
{
	X = 0;
	Y = 0;
}

void PlayerControl::SavePlayersCurrentPosition(int xx, int yy)
{
	X = xx;
	Y = yy;
}

Vector PlayerControl::PlayersCurrentPosition()
{
	Vector newPos;

	newPos.X = X;
	newPos.Y = Y;

	return newPos;
}

void PlayerControl::SavePlayerHealth(int hp)
{
	Health = hp;
}

int PlayerControl::PlayersCurrentHealth()
{
	return Health;
}
