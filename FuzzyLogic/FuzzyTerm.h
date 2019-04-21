#pragma once

class FuzzyTerm
{
	public:

		virtual ~FuzzyTerm() {};

		virtual FuzzyTerm* Clone() const = 0;
		virtual double GetDom() const = 0;
		virtual void ClearDom() = 0;
		virtual void ORWithDOM(double val) = 0;
};
