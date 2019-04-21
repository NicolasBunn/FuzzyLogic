#pragma once
#include "Weapon.h"
#include <iostream>

class ShotgunWeapon : public Weapon
{
	public:
		ShotgunWeapon(const int roundLeft = 0);
		void InitializeFuzzyModule() override;
		double GetDesirability(double distToTarget) override;

		int roundLeft;
};