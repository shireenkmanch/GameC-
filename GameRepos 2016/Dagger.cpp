/* 
 * Dagger.cpp
 *
 * The class for the dagger item
 * Derives attributes and methods from base class Weapon
 * Defines method for dagger items declared in Dagger.h
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#include <iostream>
#include "Dagger.h"


//default constructor
Dagger::Dagger() {

   //call mautator method,set weapon type to Dagger
   setWeaponType( "Dagger" );

   //call mautator method,set element type to Dagger
   setElementType( "Dagger" );

   //increase carriers attack by 5
   setAttackChange( 5 ); 

   //increase carriers defence by 0
   setDefenceChange( 0 );

   //increase carriers health by 0
   setHealthChange( 0 );

   //increase carriers strength by 0
   setStrengthChange( 0 );

   //increase carriers inventory weight by 10
   setWeight( 10 );

}


/*
 * mutator method to assign value to pointer to dagger 
 * accepts pointer to object of type Weapon
 * returns nothing 
 */
void Dagger::setGameElement( Weapon * newDagger ) {

  dagger = newDagger;

}


/*
 * accessor method to retrieve pointer to Dagger object
 * returns pointer to oject of type Dagger, accepts no parameter
 */
GameElement * Dagger::getGameElement() {

  return dagger;

}


//destructor
Dagger::~Dagger() {
}
