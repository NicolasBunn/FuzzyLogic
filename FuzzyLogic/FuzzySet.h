#pragma once

#include <cmath>        // std::abs
#include <iostream>

class FuzzySet
{
	public:
		double dom; //Degres of membership
		double representativeValue; //Maximum amount of the set membership

		FuzzySet(double repVal);
		virtual double CalculateDom(double val) const = 0;

		void ORWithDOM(double val);
		double GetRepresentativeVal() const;
		void ClearDom();
		double GetDom() const;
		void SetDom(double val);

		bool IsEqual(const double a, const double b) const;
	
};
