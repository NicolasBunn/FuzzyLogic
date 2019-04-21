#pragma once

#include <map>
#include <vector>
#include "FuzzyVariable.h"
#include "FuzzyRule.h"
#include "FuzzyTerm.h"

class FuzzyModule
{
	public:

		using VarMap = std::map<std::string, FuzzyVariable*>;

		enum class DefuzzifyType {max_av,centroid}; //centroid pas dispo

		VarMap variables;
		std::vector<FuzzyRule*> rules;
		void SetConfidencesOfConsequentsToZero();

		~FuzzyModule();

		FuzzyVariable& CreateFLV(const std::string& varName);
		void AddRule(FuzzyTerm& antecedent, FuzzyTerm& consequence);
		void Fuzzify(const std::string& nameOfFLV, double val);
		double DeFuzzify(const std::string& nameOfFLV, DefuzzifyType method);
};
