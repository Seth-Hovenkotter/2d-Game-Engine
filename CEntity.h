//==============================================================================
#ifndef _CENTITY_H_
    #define _CENTITY_H_

#include <vector>

#include "CArea.h"
#include "CAnimation.h"
#include "CCamera.h"
#include "CFPS.h"
#include "CSurface.h"
#include "Vector.h"

//==============================================================================
enum {
	ENTITY_TYPE_GENERIC = 0,

	ENTITY_TYPE_PLAYER,
	ENTITY_TYPE_WOLF,
	ENTITY_TYPE_CHECKPOINT,
	ENTITY_TYPE_GOAL,
	ENTITY_TYPE_PROJECTILE
};

//==============================================================================
enum {
	ENTITY_FLAG_NONE 	= 0,

	ENTITY_FLAG_GRAVITY	= 0x00000001,
	ENTITY_FLAG_GHOST	= 0x00000002,
	ENTITY_FLAG_MAPONLY	= 0x00000004,
	ENTITY_FLAG_IGNORE = 0x00000005,
};

//==============================================================================
class CEntity {
	public:
		static std::vector<CEntity*>    EntityList;

	protected:
		CAnimation      Anim_Control;

		SDL_Surface*    Surf_Entity;

	public:
		float	X;
		float	Y;

		int		Width;
		int		Height;

		bool	MoveLeft;
		bool	MoveRight;
		bool    Idle;
		bool    MoveUp;

	public:
		int		Type;

		bool	Dead;
		int		Flags;

		int     Health;

	protected:
		float	SpeedX;
		float	SpeedY;

		float	AccelX;
		float	AccelY;

	public:
		float	MaxSpeedX;
		float	MaxSpeedY;

	protected:
		int		CurrentFrameCol;
		int		CurrentFrameRow;

	protected:
		int		Col_X;
		int		Col_Y;
		int		Col_Width;
		int		Col_Height;

	public:
		CEntity();

		virtual ~CEntity();

	public:
		virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames);

		virtual void OnLoop();

		virtual void OnRender(SDL_Surface* Surf_Display);

		virtual void OnCleanup();

		virtual void OnAnimate();

		virtual bool OnCollision(CEntity* Entity);

	public:
		void    OnMove(float MoveX, float MoveY);

		void 	StopMove();

	public:
		bool    Collides(int oX, int oY, int oW, int oH);

	private:
		bool 	PosValid(int NewX, int NewY);

		bool 	PosValidTile(CTile* Tile);

		bool 	PosValidEntity(CEntity* Entity, int NewX, int NewY);

    protected:
        bool CanJump;

    public:
        bool Jump();

    public:
        float GetX() { return X;}
        float GetY() { return Y;}

        float GetXY() { return X,Y;}
        void SetXY(float NewX, float NewY) { X = NewX; Y = NewY;}

    protected:

        Vector Position;

        Vector Direction;

    public:

        Vector GetPosition() {return Position;}

        Vector GetDirection() {return Direction;}

};

//==============================================================================
class CEntityCol {
	public:
		static std::vector<CEntityCol>	EntityColList;

	public:
		CEntity* EntityA;
		CEntity* EntityB;

	public:
		CEntityCol();
};

//==============================================================================

#endif
