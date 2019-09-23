/***********************************************************
// OOP244 Workshop 7:Derived Classes
// File Contact.h
// Version 1.0
// Date July. 11, 2019
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
#ifndef SICT_HERO_H
#define SICT_HERO_H
namespace sict {
#define MAX_ROUNDS 100

	class Hero {
		char m_name[41];
		int m_health;
		int m_atkStr;
	public:
		Hero();
		Hero(const char* name, int health, int atk);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;

	friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

	};
	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif
