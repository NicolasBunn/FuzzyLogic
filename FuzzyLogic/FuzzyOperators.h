#pragma once

#include <vector>
#include "FuzzyTerm.h"

class FzAND : public FuzzyTerm
{
	public:
		std::vector<FuzzyTerm*> terms;
		FzAND& operator =(const FzAND&) = delete;

		~FzAND();

		FzAND(const FzAND& fa);

		FzAND(FuzzyTerm& op1, FuzzyTerm& op2);
		FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3);
		FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4);

		FuzzyTerm* Clone() const override;

		double GetDom() const;
		void ClearDom();
		void ORWithDOM(double val) override;
};

class FzOR : public FuzzyTerm
{
	//an instance of this class may AND together up to 4 terms
	std::vector<FuzzyTerm*> terms;

	//no assignment op necessary
	FzOR& operator=(const FzOR&) = delete;

public:

	~FzOR();

	//copy ctor
	FzOR(const FzOR& fa);

	//ctors accepting fuzzy terms.
	FzOR(FuzzyTerm& op1, FuzzyTerm& op2);
	FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3);
	FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4);

	//virtual ctor
	FuzzyTerm* Clone();

	double GetDOM()const;

	//unused
	void ClearDOM();
	void ORwithDOM(double val);
};

