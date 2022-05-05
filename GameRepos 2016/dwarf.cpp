/* 
 * dwarf.cpp
 *
 * The class for the dwarf race
 * Derives attributes and methods from base class Race
 * Defines methods for dwarf race declared in dwarf.h
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#include "gameelement.h"
#include "race.h"
#include "dwarf.h"

using namespace std;


/* 
 * generic constructor definition
 *
 * constructor sets the default attributes of dwarf when an object is created
 * it uses the mutator methods defined in race.cpp
 */
Dwarf::Dwarf() {
  
  // sets name as Dwarf
  setName( "Dwarf" );

  // sets element type as Dwarf
  setElementType( "Dwarf" );

  // sets Dwarf's attack value as 30
  setAttackValue( 30 );

  // sets Dwarf's attack chance probability as 2/3
  setAttackChance( 2,3 );

  // sets Dwarf's defense value as 20
  setDefenseValue( 20 );

  // sets Dwarf's defense chance probability as 2/3
  setDefenseChance( 2,3 );

  // sets Dwarf's health value as 50
  setHealthValue( 50 );

  // sets Dwarf's strength value as 130
  setStrengthValue( 130 );

  // sets the attribute RaceType as 2
  setRaceType( 2 );

  // sets intial location as 0,0
  setLocation( 0,0 );

  // sets the initial weight carried by Dwarf as 0
  setWeightCarried( 0 );

  // sets Dwarf's special race ability as 0
  setSpecialRaceAbility( 0 );

  // sets Dwarf's initial gold count as 0
  setGold( 0 );

}


/* 
 * void Dwarf::setGameElement(Race * newDwarf)
 * 
 * polymorphic mutator method from Board class
 *
 * return type: void
 * input parameter: accepts a pointer of type race
 * sets it to the private variable 'dwarf' also of type Race *
 */
void Dwarf::setGameElement( Race * newDwarf ) {

    dwarf = newDwarf;

}


/* Race Dwarf::getGameElement()
 *
 * polymorphic mutator method from Board class
 *
 * return type: Race pointer
 * input parameter: nothing
 * retuns the GameElement dwarf as a Race pointer
 */
Race * Dwarf::getGameElement() {
 
 return dwarf;

}
