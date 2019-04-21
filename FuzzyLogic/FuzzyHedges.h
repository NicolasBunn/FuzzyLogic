#pragma once

#include "FuzzySet.h"
#include "FuzzyTerm.h"
#include "FzSet.h"
#include <math.h>

class FzVery : public FuzzyTerm
{
	private:

		FuzzySet& set;

		FzVery(const FzVery& inst);
		FzVery& operator=(const FzVery&);

	public:
		FzVery(FzSet& ft);

		double GetDom() const override;

		FuzzyTerm* Clone() const override;

		void ClearDom() override;
		void ORWithDOM(double val) override;
	
};

class FzFairly : public FuzzyTerm
{
	private:

		FuzzySet& set;

		FzFairly(const FzFairly& inst);
		FzFairly& operator=(const FzFairly&);

	public:
		FzFairly(FzSet& ft);

		double GetDom() const override;
		FuzzyTerm* Clone() const override;
		void ClearDom() override;
		void ORWithDOM(double val) override;
};
