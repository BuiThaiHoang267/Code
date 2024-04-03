#pragma once
#pragma once

#pragma once

#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#define TURTLE_WIDTH 14

class CTurtle : public CGameObject
{
protected:
	float vx;
public:
	CTurtle(float x, float y, float vx);
	void Update(DWORD dt);
	void Render();
};


