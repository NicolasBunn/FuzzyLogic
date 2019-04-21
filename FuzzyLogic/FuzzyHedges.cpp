#include "FuzzyHedges.h"

FzVery::FzVery(const FzVery& inst)
	:set(inst.set)
{

}


FzVery::FzVery(FzSet& ft)
	: set{ft.set}
{

}

double FzVery::GetDom() const
{
	return set.GetDom() * set.GetDom();
}

FuzzyTerm* FzVery::Clone() const
{
	return new FzVery(*this);
}

void FzVery::ClearDom()
{
	set.ClearDom();
}

void FzVery::ORWithDOM(double val)
{ 
	//set.ORwithDOM(val * val); 
}

FzFairly::FzFairly(const FzFairly& inst)
	:set(inst.set)
{

}


FzFairly::FzFairly(FzSet& ft)
	: set{ ft.set }
{

}

double FzFairly::GetDom() const
{
	return set.GetDom() * set.GetDom();
}

FuzzyTerm* FzFairly::Clone() const
{
	return new FzFairly(*this);
}

void FzFairly::ClearDom()
{
	set.ClearDom();
}

void FzFairly::ORWithDOM(double val)
{
	//set.ORwithDOM(val * val); 
}

