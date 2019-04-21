#pragma once

#include "Weapon.h"
#include <iostream>

class SniperWeapon : public Weapon
{
	public:
		SniperWeapon(const int roundLeft_ = 0);
		void InitializeFuzzyModule() override;
		double GetDesirability(double distToTarget) override;

		int roundLeft;
};