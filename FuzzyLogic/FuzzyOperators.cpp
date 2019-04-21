#include "FuzzyOperators.h"

FzAND::FzAND(const FzAND& fa)
{
	std::vector<FuzzyTerm*>::const_iterator curTerm;
	for (curTerm = fa.terms.begin(); curTerm != fa.terms.end(); ++curTerm)
	{
		terms.push_back((*curTerm)->Clone());
	}
}

//ctor using two terms
FzAND::FzAND(FuzzyTerm& op1, FuzzyTerm& op2)
{
	terms.push_back(op1.Clone());
	terms.push_back(op2.Clone());
}

//ctor using three terms
FzAND::FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3)
{
	terms.push_back(op1.Clone());
	terms.push_back(op2.Clone());
	terms.push_back(op3.Clone());
}

//ctor using four terms
FzAND::FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4)
{
	terms.push_back(op1.Clone());
	terms.push_back(op2.Clone());
	terms.push_back(op3.Clone());
	terms.push_back(op4.Clone());
}

FzAND::~FzAND()
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = terms.begin(); curTerm != terms.end(); ++curTerm)
	{
		delete *curTerm;
	}
}

FuzzyTerm* FzAND::Clone() const
{
	return new FzAND(*this);
}

void FzAND::ORWithDOM(double val)
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = terms.begin(); curTerm != terms.end(); ++curTerm)
	{
		(*curTerm)->ORWithDOM(val);
	}
}

double FzAND::GetDom() const
{
	double smallest = 1000;

	std::vector<FuzzyTerm*>::const_iterator curTerm;
	for (curTerm = terms.begin(); curTerm != terms.end(); ++curTerm)
	{
		if ((*curTerm)->GetDom() < smallest)
		{
			smallest = (*curTerm)->GetDom();
		}
	}

	return smallest;
}

void FzAND::ClearDom()
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = terms.begin(); curTerm != terms.end(); ++curTerm)
	{
		(*curTerm)->ClearDom();
	}
}

FzOR::FzOR(const FzOR& fa)
{
	std::vector<FuzzyTerm*>::const_iterator curTerm;
	for (curTerm = fa.terms.begin(); curTerm != fa.terms.end(); ++curTerm)
	{
		terms.push_back((*curTerm)->Clone());
	}
}

//ctor using two terms
FzOR::FzOR(FuzzyTerm& op1, FuzzyTerm& op2)
{
	terms.push_back(op1.Clone());
	terms.push_back(op2.Clone());
}

//ctor using three terms
FzOR::FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3)
{
	terms.push_back(op1.Clone());
	terms.push_back(op2.Clone());
	terms.push_back(op3.Clone());
}

//ctor using four terms
FzOR::FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4)
{
	terms.push_back(op1.Clone());
	terms.push_back(op2.Clone());
	terms.push_back(op3.Clone());
	terms.push_back(op4.Clone());
}


FzOR::~FzOR()
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = terms.begin(); curTerm != terms.end(); ++curTerm)
	{
		delete *curTerm;
	}
}

double FzOR::GetDOM()const
{
	double largest = 0.0;
	std::vector<FuzzyTerm*>::const_iterator curTerm;
	for (curTerm = terms.begin(); curTerm != terms.end(); ++curTerm)
	{
		if ((*curTerm)->GetDom() > largest)
		{
			largest = (*curTerm)->GetDom();
		}
	}
	return largest;
}

