#include <iostream>
#include "RocketWeapon.h"
#include "ShotgunWeapon.h"
#include "SniperWeapon.h"

int InputData()
{
	bool valid = false;
	int result = 0;

	while (!valid)
	{
		char buffer[10] = {};
		valid = true;
		int tempResult = 0;
		std::cin >> buffer;
		int incrementation = 1;
		for (std::size_t i = 1; i < strlen(buffer); i++)
		{
			incrementation *= 10;
		}

		for (std::size_t i = 0; i < strlen(buffer); i++)
		{
			if (buffer[i] >= 48 && buffer[i] <= 57) //accepting 2-9
			{
				int decision = buffer[i] - '0';
				tempResult += (decision * incrementation);
				incrementation /= 10;
			}
			else
			{
				valid = false;
			}
		}

		if (valid)
		{
			result = tempResult;
		}
	}

	return result;
}

int main()
{
	std::cout << "Enter distance from target \n ";
	int distance = InputData();

	std::cout << "Enter rocket weapon ammo \n";
	int rocketWeaponAmmo = InputData();

	std::cout << "Enter shotgun weapon ammo \n";
	int shotgunWeaponAmmo = InputData();

	std::cout << "Enter sniper weapon ammo \n";
	int sniperWeaponAmmo = InputData();

	RocketWeapon rocketWeapon(rocketWeaponAmmo);
	ShotgunWeapon shotgunWeapon(shotgunWeaponAmmo);
	SniperWeapon sniperWeapon(sniperWeaponAmmo);

	std::cout << "Rocket Desirability " << rocketWeapon.GetDesirability(distance) << std::endl;
	std::cout << "Shotgun Desirability " << shotgunWeapon.GetDesirability(distance) << std::endl;
	std::cout << "Sniper Desirability " << sniperWeapon.GetDesirability(distance) << std::endl;

	return 0;
}