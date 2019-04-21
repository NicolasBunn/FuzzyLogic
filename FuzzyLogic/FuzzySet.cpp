#include "FuzzySet.h"

FuzzySet::FuzzySet(double repVal)
	: dom(0.0), representativeValue(repVal)
{

}
double FuzzySet::GetRepresentativeVal() const
{
	return representativeValue;
}

void FuzzySet::ClearDom()
{
	dom = 0.0;
}

void FuzzySet::ORWithDOM(double val)
{
	if (val > dom)
	{
		dom = val;
	}
}

double FuzzySet::GetDom() const
{
	return dom;
}

void FuzzySet::SetDom(double val)
{
	dom = val;
}

bool FuzzySet::IsEqual(const double a, const double b) const
{
	double result = abs(a - b);

	return result < 0.1 ? true : false;
}