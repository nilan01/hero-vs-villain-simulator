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
#include <iostream>
#include "SuperHero.h"
using namespace std;
namespace sict{
	SuperHero::SuperHero(){
		sBonusAttk = 0;
		sDef = 0;
	}
	SuperHero::SuperHero(const char* name, int health, int str, int bonusAttk, int def) : Hero(name, health, str){
		if (bonusAttk > 0 || def > 0){
			sBonusAttk = bonusAttk;
			sDef = def;
		}
		else{
			*this = SuperHero();
		}
	}
	int SuperHero::defend() const{
		if (sDef == 0) {
			return 0;
		}
		else {
			return sDef;
		}
	}
	int SuperHero::attackStrength() const{
		if (Hero::attackStrength() == 0) {
			return 0;
		}
		else {
			return (Hero::attackStrength() + sBonusAttk);
		}
	}
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second){
		int rounds = 1;
		SuperHero firstSh = first;
		SuperHero secondSh = second;

		cout << "Super Fight! " << firstSh << " vs " << secondSh << " : ";
		do {
			firstSh -= secondSh.attackStrength() - firstSh.defend();
			secondSh -= firstSh.attackStrength() - secondSh.defend();
			if (firstSh.isAlive() == false) {
				cout << "Winner is " << second << " in " << rounds << " rounds." << endl;
				return second;
			}
			else if (secondSh.isAlive() == false) {
				cout << "Winner is " << first << " in " << rounds << " rounds." << endl;
				return first;
			}
			else if (rounds == MAX_ROUNDS) {
				cout << "Winner is " << first << " in " << rounds << " rounds." << endl;
				return first;
			}
			rounds++;
		} while (rounds <= MAX_ROUNDS);

		return first;
	}
}