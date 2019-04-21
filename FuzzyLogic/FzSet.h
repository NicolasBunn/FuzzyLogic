#pragma once

#include "FuzzyTerm.h"
#include "FuzzySet.h"

class FzAND;

class FzSet : public FuzzyTerm
{
public:

	friend class FzVery;
	friend class FzFairly;

	FuzzySet& set;

	FzSet(FuzzySet& fs) : set(fs) {}

	FuzzyTerm* Clone() const override
	{
		return new FzSet(*this);
	}
	double GetDom() const override
	{
		return set.GetDom();
	}
	void ClearDom() override
	{
		set.ClearDom();
	}
	void ORWithDOM(double val) override
	{
		set.ORWithDOM(val);
	}
};