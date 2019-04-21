#pragma once

#include <iostream>
#include "FuzzySet.h"

class FuzzySetLeftShoulder : public FuzzySet
{
	private:

		double peakPoint;
		double rightOffset;
		double leftOffset;

	public:

		FuzzySetLeftShoulder(double peak, double left, double right);

		double CalculateDom(double val) const override;
};