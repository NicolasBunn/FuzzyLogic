#pragma once

#include "Weapon.h"
#include <iostream>

class RocketWeapon : public Weapon
{
	public:
		RocketWeapon(const int roundLeft_ = 0);
		void InitializeFuzzyModule() override;
		double GetDesirability(double distToTarget) override;

		int roundLeft;
};