/***********************************************************
// OOP244 Workshop 7: Derived Classes
// File Contact.cpp
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
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Hero.h"
using namespace std;

namespace sict {
	Hero::Hero() {
		m_name[0] = '\0';
		m_health = 0;
		m_atkStr = 0;
	}
	Hero::Hero(const char* name, int health, int atk) {
		if (name[0] != '0' && health > 0 && atk > 0) {
			strcpy(m_name, name);
			m_health = health;
			m_atkStr = atk;
		}
		else {
			*this = Hero();
		}
	}
	void Hero::operator-=(int attack) {
		if (attack > 0) {
			if (attack > m_health) {
				this->m_health = 0;
			}
			else {
				m_health -= attack;
			}
		}
	}
	bool Hero::isAlive() const {
		if (this->m_health > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	int Hero::attackStrength() const {
		if (this->m_atkStr <= 0) {
			return 0;
		}
		else {
			return this->m_atkStr;
		}
	}
	std::ostream& operator<<(std::ostream& os, const Hero& hero){
		if (hero.m_name[0] != '\0')
			os << hero.m_name;
		else
			os << "No hero";
		return os;
	}
	const Hero& operator*(const Hero& first, const Hero& second){
		Hero left = first, right = second, winner;
		
		cout << "Ancient Battle! " << first << " vs " << second << " : ";
		for (int i = 1; i <= MAX_ROUNDS; i++) {
			left -= right.attackStrength();
			right -= left.attackStrength();
			
			if (!right.isAlive()) {
				cout << "Winner is " << first << " in " << i << " rounds." << endl;
				return first;
			}
			else if (!left.isAlive()) {
				cout << "Winner is " << second << " in " << i << " rounds." << endl;
				return second;
			}
			else if (i == MAX_ROUNDS) {
				cout << "Winner is " << first << " in " << i << " rounds." << endl;
				return first;
			}
		}
		return first;
	}
}
