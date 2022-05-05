/*
 * dwarf. h
 *
 * Header file for dwarf race
 * Inherits from race class
 * Defines attributes and methods for dwarf race
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


#ifndef DWARF_H
#define DWARF_H

using namespace std;


/* 
 * Dwarf class derives attributes and methods from Race class
 */
class Dwarf: public Race {

 public:
 
  /* 
   * generic constructor
   * creates dwarf object when called and sets attributes of default dwarf
   */
  Dwarf();


  /* 
   * mutator method for setting game element dwarf
   * derived from Board class
   * return type: nothing ( void )
   * input parameter: Race pointer ( Race * newDwarf )
   */
  void setGameElement( Race * newDwarf );
  

  /* 
   * accessor method for getting GameElement of type Race pointer
   * derived from board class
   * return type: Race pointer
   * input parameter: nothing ( void )
   */
  Race * getGameElement();
  

 private:

  // race pointer variable to store address to dwarf object of type race
  Race * dwarf;

};


#endif
