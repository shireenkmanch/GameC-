/* 
 * orc.cpp
 *
 * The class for the orc race
 * Derives attributes and methods from base class Race
 * Defines methods for an orc race
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
#include "orc.h"

using namespace std;


/*
 * generic constructor definition
 *
 * constructor sets the default attributes of orc when an object is created
 * it uses the mutator methods defined in Race.cpp
 */
Orc::Orc() {

  // sets name to Orc
  setName( "Orc" );

  // sets element type to Orc
  setElementType( "Orc" );
 
  // sets Orc's attack value to 25
  setAttackValue(25);

  // sets Orc's attack chance probability to 1/4
  setAttackChance(1,4);

  // sets Orc's defense value to 10
  setDefenseValue(10);

  // sets Orc's defense chance probability to 1/4
  setDefenseChance(1,4);

  // sets Orc's health to 50
  setHealthValue(50);

  // sets Orc's strength to 130
  setStrengthValue(130);

  // sets attribute race type to 3
  setRaceType(3);

  // set initial location to 0,0
  setLocation(0,0);

  // set weight carried by Orc to 0
  setWeightCarried(0);

  // set Orc's initial gold count to 0
  setGold(0);

  // sets Orc's special race ability as 100 to use in comparison in Race::combatRound()
  setSpecialRaceAbility(100);

}


/* 
 * Orc::Orc( bool dayTime )
 * sets characteristics of orc race based on time of the day
 *
 * input parameter: void
 * return type: void
 */ 
void Orc::setElementCharacteristics() {
  // if the mode is changed from day to night
  if( modeOfDay() == false ) {

    // set attack value to 45
    setAttackValue( 45 );
    
    // sets Orc's attack probability of success as 1/1
    setAttackChance( 1,1 );
    
    // set defense value to 25
    setDefenseValue( 25 );
    
    // sets Orc's defense probability of success as 1/2
    setDefenseChance( 1,2 );

    // set Orc's special race ability as 1
    setSpecialRaceAbility( 1 );

   } else {
    // if the mode is changed from night to day
   
    // set attack value to 15
    setAttackValue( 25 );

    // sets Orc's attack chance probability as 1/4
    setAttackChance( 1,4 );
    
    // set defense value to 10
    setDefenseValue( 10 );

    // sets Orc's defense chance probability as 1/4
    setDefenseChance( 1,4 );

    // set Orc's special race ability as 100 to use in comparison in Race::combatRound()
    setSpecialRaceAbility(100);

  }

}


/* 
 * void Orc::setGameElement( Race * newOrc )
 * 
 * polymorphic mutator method from Board class
 *
 * return type: void
 * input parameter: accepts a pointer of type race ( Race * newOrc )
 * sets it to the private variable 'orc' also of type Race *
 */
void Orc::setGameElement( Race * newOrc ) {
 
 orc = newOrc;

}


/* 
 * Race Orc::getGameElement()
 *
 * polymorphic mutator method from Board class
 *
 * return type: Race pointer
 * input parameter: nothing
 * retuns the GameElement orc as a Race
 */
Race * Orc::getGameElement() {
 
 return orc;

}

