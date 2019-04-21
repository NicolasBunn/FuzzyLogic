#pragma once

#include <iostream>
#include "FuzzySet.h"

class FuzzySetRightShoulder : public FuzzySet
{
private:

	double peakPoint;
	double rightOffset;
	double leftOffset;

public:

	FuzzySetRightShoulder(double peak, double left, double right);

	double CalculateDom(double val) const override;
};