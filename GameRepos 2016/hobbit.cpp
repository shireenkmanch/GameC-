/* 
 * hobbit.cpp
 *
 * The class for the hobbit race
 * Defines methods for a hobbit race
 * Derives attributes and methods from base class race.h
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


#include <ctime>
#include <cstdlib>
#include "gameelement.h"
#include "race.h"
#include "hobbit.h"

using namespace std;


/* 
 * generic constructor definition
 *
 * constructor sets the default attributes of hobbit when an object is created
 * it uses the mutator methods defined in race.cpp
 */
Hobbit::Hobbit() {
  
  // calling random function of time
  srand( time( NULL ) );

  // sets name as Hobbit
  setName( "Hobbit" );
  
  // sets element type as Hobbit
  setElementType( "Hobbit" );

  // sets Hobbit's attack value as 25
  setAttackValue( 25 );

  // sets Hobbit's attack chance probability as 1/3
  setAttackChance( 1,3 );

  // sets Hobbit's defense value as 20
  setDefenseValue( 20 );
  
  // sets Hobbit's defense chance probability as 2/3
  setDefenseChance( 2,3 );

  // sets Hobbit's health as 70
  setHealthValue( 70 );
  
  // sets Hobbit's strength as 85
  setStrengthValue( 85 );

  // sets the attribute race type as 4
  setRaceType( 4 );

  // sets the initial location as 0,0
  setLocation( 0,0 );

  // sets initial weight carried by Hobbit as 0
  setWeightCarried( 0 );

  // sets Hobbit's special race ability as output of rand()
  setSpecialRaceAbility( -( rand()%6 ) );

  // sets Hobbit's intial gold count as 0
  setGold( 0 );

}


/* 
 * void Hobbit::setGameElement(Race * newHobbit)
 * 
 * polymorphic mutator method from Board class
 *
 * return type: void
 * input parameter: accepts a pointer of type race (Race * newHobbit)
 * sets it to the private variable 'orc' also of type Race *
 */
void Hobbit::setGameElement( Race * newHobbit ) {

  hobbit = newHobbit;

}


/* 
 * Race Hobbit::getGameElement()
 *
 * polymorphic mutator method from Board class
 *
 * return type: Race pointer
 * input parameter: nothing
 * retuns the GameElement hobbit as a Race pointer
 */
Race * Hobbit::getGameElement() {

  return hobbit;

}
