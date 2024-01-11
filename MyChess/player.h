#pragma once
#include "gameObject.h"

class Player : public gameObject
{
public:
	void update() override;
	void draw() override;
	void init() override;
};