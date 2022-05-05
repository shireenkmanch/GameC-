/*
 * elf.cpp
 *
 * The class for the elf race
 * Defines methods for the elf race
 * Derives attributes and methods from base class Race
 *
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
#include "elf.h"

using namespace std;


/*
 * generic constructor definition
 *
 * constructor sets the default attributes of elf when an object is created
 * it uses the mutator methods defined in race.cpp
 */
Elf::Elf() {

  // sets name as Elf 
  setName( "Elf" );
  
  // sets element type as Elf
  setElementType( "Elf" );
  
  // sets Elf's attack value as 40
  setAttackValue( 40 );
  
  // sets Elf's attack chance probability as 1/1
  setAttackChance( 1,1 );
  
  // sets Elf's defense value as 10
  setDefenseValue( 10 );
  
  // sets Elf's defense chance probability as 1/4
  setDefenseChance( 1,4 );
  
  // sets Elf's health as 40
  setHealthValue( 40 );
  
  //sets Elf's strength as 70
  setStrengthValue( 70 );
  
  // sets the attribute RaceType as 1
  setRaceType( 1 );
  
  // sets initial location as 0,0
  setLocation( 0,0 );
  
  // sets the initial weight carried by Elf as 0
  setWeightCarried( 0 );
  
  // sets Elf's special ability as 1
  setSpecialRaceAbility( 1 );
  
  // sets Elf's initial gold count as 0
  setGold( 0 );

}


/* 
 * void Elf::setGameElement(Race * newElf)
 * 
 * polymorphic mutator method from Board class
 *
 * return type: void
 * input parameter: accepts a pointer of type race
 * sets it to the private variable 'elf' also of type Race *
 */
void Elf::setGameElement( Race * newElf ) {

  elf = newElf;

}


/* 
 * Race Elf::getGameElement()
 *
 * polymorphic mutator method from Board class
 *
 * return type: Race pointer
 * input parameter: nothing
 * retuns the GameElement elf as a Race pointer
 */
Race * Elf::getGameElement() {
  
  return elf;

}
