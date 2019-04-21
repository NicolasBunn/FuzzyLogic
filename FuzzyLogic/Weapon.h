#pragma once

#include "FuzzyModule.h"

class Weapon
{
	public:
		FuzzyModule fm;

		virtual void InitializeFuzzyModule() = 0;
		virtual double GetDesirability(double distToTarget) = 0;

		double lastDesirabilityScore = 0.0;
};