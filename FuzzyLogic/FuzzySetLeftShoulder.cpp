#include "FuzzySetLeftShoulder.h"

FuzzySetLeftShoulder::FuzzySetLeftShoulder(double peak, double left, double right)
	: FuzzySet(((peak - left) + peak) / 2), peakPoint(peak),leftOffset(left),rightOffset(right)
{

}

double FuzzySetLeftShoulder::CalculateDom(double val) const
{
	if ((IsEqual(rightOffset, 0.0) && IsEqual(peakPoint, val)) ||
		(IsEqual(leftOffset, 0.0) && (IsEqual(peakPoint, val))))
	{
		return 1.0f;
	}
	else if(( val >= peakPoint) && (val < (peakPoint + rightOffset)))
	{
		double grad = 1.0 / -rightOffset;
		double result = grad * (val - peakPoint) + 1.0f;
		return result;
	}
	else if ((val < peakPoint) && (val >= peakPoint - leftOffset))
	{
		return 1.0;
	}
	else
	{
		return 0.0;
	}
}