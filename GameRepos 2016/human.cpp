/*
 * human.cpp
 *
 * The class for the human race
 * Defines methods for a human element
 * Derives attributes and methods from base class Race
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
#include "human.h"


/*
 * generic constructor definition
 *
 * constructor sets the default attributes of human when an object is created
 * it utilizes the mutator methods defined in Race.cpp
 *
 */
Human::Human() {

  // sets name as Human
  setName( "Human" );

  // sets element type as Human
  setElementType( "Human" );

  // sets Human's attack value as 30
  setAttackValue( 30 );

  // sets Human's attack chance probability as 2/3
  setAttackChance( 2,3 );

  // sets Human's defense value as 20
  setDefenseValue( 20 );

  // sets Human's defense chance probability as 1/2 
  setDefenseChance( 1,2 );

  // sets Human's health as 60
  setHealthValue( 60 );

  // sets Human's strength as 100
  setStrengthValue( 100 );

  // sets the attribute raceType as 0
  setRaceType( 0 );

  // sets initial location as 0,0
  setLocation( 0,0 );

  // sets initial weight carried by Human as 0
  setWeightCarried( 0 );

  // sets Human's special ability as 0
  setSpecialRaceAbility( 0 );

  // sets Human's initial gold count as 0 
  setGold( 0 );

}


/*
 * void Human::setGameElement(Race * newHuman)
 * 
 * polymorphic mutator method from Board class
 *
 * return type: void
 * input parameter: accepts a pointer of type race
 * sets it to the private variable 'human' also of type race
 */
void Human::setGameElement( Race * newHuman ) {

  human = newHuman;

}


/*
 * Race Human::getGameElement()
 *
 * polymorphic mutator method from Board class
 *
 * return type: Race pointer
 * input parameter: nothing
 * returns the GameElement human as a Race pointer
 */
Race * Human::getGameElement() {

  return human;

}
