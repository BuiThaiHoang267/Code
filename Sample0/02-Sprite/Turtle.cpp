#include "Game.h"
#include "Turtle.h"

CTurtle::CTurtle(float x, float y, float vx) :CGameObject(x, y)
{
	this->vx = vx;
};

void CTurtle::Update(DWORD dt)
{
	x += vx * dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - TURTLE_WIDTH) {

		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - TURTLE_WIDTH)
		{
			x = (float)(BackBufferWidth - TURTLE_WIDTH);
		}
	}
}

void CTurtle::Render()
{
	LPANIMATION ani;

	//[RED FLAG][TODO]: Student needs to think about how to associate this animation/asset to Mario!!
	if (vx > 0) ani = CAnimations::GetInstance()->Get(520);
	else ani = CAnimations::GetInstance()->Get(520);

	ani->Render(x, y);
}

