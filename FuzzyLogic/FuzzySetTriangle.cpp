#include "FuzzySetTriangle.h"

FuzzySetTriangle::FuzzySetTriangle(double mid, double left, double right)
	: FuzzySet(mid),leftOffset(left),rightOffset(right),peakPoint(mid)
{

}

double FuzzySetTriangle::CalculateDom(double val) const
{
	if ((IsEqual(rightOffset, 0.0) && (IsEqual(peakPoint, val))) ||
		(IsEqual(leftOffset, 0.0) && (IsEqual(peakPoint, val))))
	{
		return 1.0f;
	}

	//If Dom is left of center
	if ((val <= peakPoint) && (val >= (peakPoint - leftOffset)))
	{
		double grad = 1.0 / leftOffset;
		double result = grad * (val - (peakPoint - leftOffset));
		return result;
	}

	//If dom is right of center
	else if ((val > peakPoint) && (val < (peakPoint + rightOffset)))
	{
		double grad = 1.0 / -rightOffset;
		double result = grad * (val - peakPoint) + 1.0;
		return result;
	}
	else
	{
		return 0.0;
	}
}

