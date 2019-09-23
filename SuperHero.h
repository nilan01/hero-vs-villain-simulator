/***********************************************************
// OOP244 Workshop 7:Derived Classes
// File Contact.h
// Version 1.0
// Date July. 16, 2019
// Author Nilan Patel
// Student Number: <038 908 117>
// Section SEE
// Description
//
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include "Hero.h"

namespace sict{
	class SuperHero : public Hero{
		int sBonusAttk;
		int sDef;
	public:
		SuperHero();
		SuperHero(const char* name, int health, int str, int bonus_att, int def);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif // !SICT_SUPERHERO_H
