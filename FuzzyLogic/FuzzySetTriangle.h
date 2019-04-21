#pragma once

#include <iostream>
#include "FuzzySet.h"

class FuzzySetTriangle : public FuzzySet
{
	public:
		double peakPoint;
		double leftOffset;
		double rightOffset;

		FuzzySetTriangle(double mid, double left, double right);
		virtual double CalculateDom(double val) const override;

};