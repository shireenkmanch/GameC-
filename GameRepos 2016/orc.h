/*
 * orc.h
 *
 * Header file for orc race
 * Derives attributes and methods from base class Race
 * Declares attributes and methods for an orc race
 *
 * Authors:
 * Sooppiyaragath Shalom Nazir
 * Shireen Kudukkil Manchingal
 * Dzidzor Adogla-Bessa
 * Joseph Nortey
 *
 * Date: November 15, 2016
 */


#ifndef ORC_H
#define ORC_H

using namespace std;


/* 
 * Orc class derives attributes and methods from Race class
 */
class Orc: public Race {

 public:

  /*
   * generic constructor
   * creates orc object when called and sets attributes of default orc
   */
  Orc();
  

  /* void Orc::setElementCharacteristics()
   * sets characteristics of orc race based on time of the day
   *
   * input parameter: void
   * return type: void
   */
  void setElementCharacteristics();


  /*
   * mutator method for setting Game element orc
   * derived from Board class
   * return type: nothing ( void )
   * input parameter: Race pointer ( Race * newOrc )
   */
  void setGameElement( Race * newOrc );


  /* 
   * accessor method for getting GameElement of type Race pointer
   * derived from board class
   * return type: Race pointer
   * input parameter: nothing ( void )
   */
  Race * getGameElement();

 private:

  // race pointer variable to store address to orc object of type race
  Race * orc;

};


#endif
