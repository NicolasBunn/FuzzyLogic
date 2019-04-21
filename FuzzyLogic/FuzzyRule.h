#pragma once

#include "FuzzyTerm.h"

class FuzzyRule
{
	public:
		const FuzzyTerm* antecedent;
		FuzzyTerm* consequence;
		FuzzyRule(const FuzzyRule&) = delete;
		FuzzyRule& operator=(const FuzzyRule&) = delete;
		FuzzyRule(FuzzyTerm& ant, FuzzyTerm& con);
		~FuzzyRule();
		void SetConfidenceOfConsequentToZero();
		void Calculate();
};