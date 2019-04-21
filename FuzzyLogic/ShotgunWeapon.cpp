#include "ShotgunWeapon.h"
#include "FuzzyOperators.h"

ShotgunWeapon::ShotgunWeapon(const int roundLeft_)
	: roundLeft(roundLeft_)
{
	InitializeFuzzyModule();
}

void ShotgunWeapon::InitializeFuzzyModule()
{
	FuzzyVariable& distToTarget = fm.CreateFLV("DistToTarget");

	FzSet targetClose = distToTarget.AddLeftShoulderSet("Target_Close", 0, 25, 150);
	FzSet targetMedium = distToTarget.AddTriangularSet("Target_Medium", 25, 150, 300);
	FzSet targetFar = distToTarget.AddRightShoulderSet("Target_Far", 150, 300, 1000);

	FuzzyVariable& desirability = fm.CreateFLV("Desirability");
	FzSet veryDesirable = desirability.AddRightShoulderSet("VeryDesirable", 50, 75, 100);
	FzSet desirable = desirability.AddTriangularSet("Desirable", 25, 50, 75);
	FzSet undesirable = desirability.AddLeftShoulderSet("Undesirable", 0, 25, 50);

	FuzzyVariable& ammoStatus = fm.CreateFLV("AmmoStatus");
	FzSet ammoLoads = ammoStatus.AddRightShoulderSet("Ammo_Loads", 10, 30, 100);
	FzSet ammoOkay = ammoStatus.AddTriangularSet("Ammo_Okay", 0, 10, 30);
	FzSet ammoLow = ammoStatus.AddTriangularSet("Ammo_Low", 0, 0, 10);
	
	FzAND targetCloseAmmoLoads(targetClose, ammoLoads);
	FzAND targetCloseAmmoOkay(targetClose, ammoOkay);
	FzAND targetCloseAmmoLow(targetClose, ammoLow);
	FzAND targetMediumAmmoLoads(targetMedium, ammoLoads);
	FzAND targetMediumAmmoOkay(targetMedium, ammoOkay);
	FzAND targetMediumAmmoLow(targetMedium, ammoLow);
	FzAND targetFarAmmoLoads(targetFar, ammoLoads);
	FzAND targetFarAmmoOkay(targetFar, ammoOkay);
	FzAND targetFarAmmoLow(targetFar, ammoLow);

	fm.AddRule(targetCloseAmmoLoads, desirable);
	fm.AddRule(targetCloseAmmoOkay, veryDesirable);
	fm.AddRule(targetCloseAmmoLow, veryDesirable);
	fm.AddRule(targetMediumAmmoLoads, desirable);
	fm.AddRule(targetMediumAmmoOkay, undesirable);
	fm.AddRule(targetMediumAmmoLow, undesirable);
	fm.AddRule(targetFarAmmoLoads, undesirable);
	fm.AddRule(targetFarAmmoOkay, undesirable);
	fm.AddRule(targetFarAmmoLow, undesirable);
}

double ShotgunWeapon::GetDesirability(double distToTarget)
{
	fm.Fuzzify("DistToTarget", distToTarget);
	fm.Fuzzify("AmmoStatus", (double)roundLeft);

	lastDesirabilityScore = fm.DeFuzzify("Desirability", FuzzyModule::DefuzzifyType::max_av);

	return lastDesirabilityScore;
}