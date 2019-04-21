#include "FuzzyVariable.h"
#include "FuzzySetTriangle.h"
#include "FuzzySetLeftShoulder.h"
#include "FuzzySetRightShoulder.h"

FuzzyVariable::FuzzyVariable()
	: minRange(0.0), maxRange(0.0)
{

}

FuzzyVariable::~FuzzyVariable()
{
	MemberSets::iterator it;
	for (it = memberSets.begin(); it != memberSets.end(); ++it)
	{
		delete it->second;
	}
}

void FuzzyVariable::Fuzzify(double val)
{
	MemberSets::const_iterator curSet;
	for (curSet = memberSets.begin(); curSet != memberSets.end(); ++curSet)
	{
		curSet->second->SetDom(curSet->second->CalculateDom(val));
	}
}

bool FuzzyVariable::IsEqual(const double a, const double b) const
{
	double result = abs(a - b);

	return result < 0.1 ? true : false;
}

double FuzzyVariable::DeFuzzifyMaxAv() const
{
	double bottom = 0.0;
	double top = 0.0;

	MemberSets::const_iterator curSet;
	for (curSet = memberSets.begin(); curSet != memberSets.end(); ++curSet)
	{
		bottom += curSet->second->GetDom();
		top += curSet->second->GetRepresentativeVal() * curSet->second->GetDom();
	}

	if (IsEqual(0.0f, bottom))
	{
		return 0.0;
	}

	return top / bottom;
}

void FuzzyVariable::AdjustRangeToFit(double minBound, double maxBound)
{
	if (minBound < minRange)
	{
		minRange = minBound;
	}

	if (maxBound > maxRange)
	{
		maxRange = maxBound;
	}
}

FzSet FuzzyVariable::AddLeftShoulderSet(std::string name, double minBound, double peak, double maxBound)
{
	memberSets[name] = new FuzzySetLeftShoulder(peak, peak - minBound, maxBound - peak);

	AdjustRangeToFit(minBound, maxBound);

	return FzSet(*memberSets[name]);
}

FzSet FuzzyVariable::AddRightShoulderSet(std::string name, double minBound, double peak, double maxBound)
{
	memberSets[name] = new FuzzySetRightShoulder(peak, peak - minBound, maxBound - peak);

	//adjust range if necessary
	AdjustRangeToFit(minBound, maxBound);

	return FzSet(*memberSets[name]);
}

FzSet FuzzyVariable::AddTriangularSet(std::string name, double minBound, double peak, double maxBound)
{
	memberSets[name] = new FuzzySetTriangle(peak, peak - minBound, maxBound - peak);

	AdjustRangeToFit(minBound, maxBound);

	return FzSet(*memberSets[name]);
}