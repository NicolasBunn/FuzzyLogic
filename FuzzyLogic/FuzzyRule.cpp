#include "FuzzyRule.h"

FuzzyRule::FuzzyRule(FuzzyTerm& ant, FuzzyTerm& con)
	: antecedent(ant.Clone()), consequence(con.Clone())
{

}

FuzzyRule::~FuzzyRule()
{
	delete antecedent;
	delete consequence;
}

void FuzzyRule::SetConfidenceOfConsequentToZero()
{
	consequence->ClearDom();
}

void FuzzyRule::Calculate()
{
	consequence->ORWithDOM(antecedent->GetDom());
}

