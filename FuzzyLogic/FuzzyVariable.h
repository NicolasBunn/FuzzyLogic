#pragma once

#include <map>
#include "FuzzySet.h"
#include "FzSet.h"

class FuzzyModule;

class FuzzyVariable
{
	public:
		using MemberSets = std::map<std::string, FuzzySet*>;
		
		FuzzyVariable();
		
		FuzzyVariable(const FuzzyVariable&) = delete;
		FuzzyVariable& operator=(const FuzzyVariable&) = delete;

		MemberSets memberSets;
		double minRange;
		double maxRange;

		void AdjustRangeToFit(double minBound, double maxBound);
		~FuzzyVariable();

		void Fuzzify(double val);
		double DeFuzzifyMaxAv() const;

		FzSet AddLeftShoulderSet(std::string name, double minBound, double peak, double maxBound);
		FzSet AddRightShoulderSet(std::string name, double minBound, double peak, double maxBound);
		FzSet AddTriangularSet(std::string name, double minBound, double peak, double maxBound);

		bool IsEqual(const double a, const double b) const;

		friend class FuzzyModule;

};