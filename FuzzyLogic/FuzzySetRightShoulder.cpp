#include "FuzzySetRightShoulder.h"

FuzzySetRightShoulder::FuzzySetRightShoulder(double peak, double left, double right)
	: FuzzySet(((peak + right) + peak) / 2), peakPoint(peak),leftOffset(left),rightOffset(right)
{

}

double FuzzySetRightShoulder::CalculateDom(double val)const
{
	//test for the case where the left or right offsets are zero
	//(to prevent divide by zero errors below)
	if ((IsEqual(rightOffset, 0.0) && (IsEqual(peakPoint, val))) ||
		(IsEqual(leftOffset, 0.0) && (IsEqual(peakPoint, val))))
	{
		return 1.0;
	}

	//find DOM if left of center
	else if ((val <= peakPoint) && (val > (peakPoint - leftOffset)))
	{
		double grad = 1.0 / leftOffset;
		double result = grad * (val - (peakPoint - leftOffset));
		return result;
	}
	//find DOM if right of center and less than center + right offset
	else if ((val > peakPoint) && (val <= peakPoint + rightOffset))
	{
		return 1.0;
	}
	else
	{
		return 0;
	}
}