#include "FuzzyModule.h"

FuzzyModule::~FuzzyModule()
{
	VarMap::iterator curVar = variables.begin();

	for (curVar; curVar != variables.end(); ++curVar)
	{
		delete curVar->second;
	}

	std::vector<FuzzyRule*>::iterator curRule = rules.begin();
	for (curRule; curRule != rules.end(); ++curRule)
	{
		delete *curRule;
	}
}

void FuzzyModule::AddRule(FuzzyTerm& antecedent, FuzzyTerm& consequence)
{
	rules.push_back(new FuzzyRule(antecedent, consequence));
}

void FuzzyModule::Fuzzify(const std::string& nameOfFLV, double val)
{
	variables[nameOfFLV]->Fuzzify(val);
}

double FuzzyModule::DeFuzzify(const std::string& nameOfFLV, DefuzzifyType method)
{
	SetConfidencesOfConsequentsToZero();

	std::vector<FuzzyRule*>::iterator curRule = rules.begin();
	for (curRule; curRule != rules.end(); ++curRule)
	{
		(*curRule)->Calculate();
	}


	return variables[nameOfFLV]->DeFuzzifyMaxAv();
	
}

FuzzyVariable& FuzzyModule::CreateFLV(const std::string& varName)
{
	variables[varName] = new FuzzyVariable();
	return *variables[varName];
}

void FuzzyModule::SetConfidencesOfConsequentsToZero()
{
	std::vector<FuzzyRule*>::iterator curRule = rules.begin();
	for (curRule; curRule != rules.end(); ++curRule)
	{
		(*curRule)->SetConfidenceOfConsequentToZero();
	}
}