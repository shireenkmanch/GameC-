/* race.cpp
 *
 * Class Race 
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "race.h"
#include "gameelement.h"

GameElement raceElement;

Race::Race(): attackValue(0), defenseValue(0), healthValue(0), strengthValue(0), dayMode(true){
  setElementType(1);
}

void Race::setName(string newName){
  name = newName;
}

string Race::getName(){
  return name;
}

/* void setRaceType(int newRaceType)
 *
 * returns void
 * accepts integer parameter as input:
 * (0 = human, 1 = elf, 2 = dwarf, 3 = orc, 4 = hobbit)
 * stores the input in private variable raceType
 */

void Race::setRaceType(int newRaceType){
  raceType = newRaceType;
  if(raceType == 0){
    // race is human
    //raceElement.setRaceType(0);
  } else if(raceType == 1){
    // race is elf
    //raceElement.setRaceType(1);
  } else if(raceType == 2){
    // race is dwarf
    //raceElement.setRaceType(2);
  } else if(raceType == 3){
    // race is orc
    //raceElement.setRaceType(3);
  } else {
    // race is hobbit
    //raceElement.setRaceType(4);
  }
}

//called by pick() method, to assign objects to the null pointers
//mutator methods to alter thr values of races attack, health, strength and defence parameters
//using the respective values from the items carried
//dagger
void Race::setDagger(){
	Dagger dagger; //create a dagger object
	pdagger= &dagger;// store dagger object location in pointer
	//cout<<pdagger->getWeaponType();
	//this->weight+= dagger.getWeight(); 
  this->attackValue+= dagger.getAttackChange();
  this->defenseValue+= dagger.getDefenceChange();
  this->healthValue+= dagger.getHealthChange();
  this->strengthValue+= dagger.getStrengthChange();
  this->weightCarried+= dagger.getWeight();
}


//sword
void Race::setSword(){
	Sword sword;
	psword=&sword;
	this->attackValue+= sword.getAttackChange();
  this->defenseValue+= sword.getDefenceChange();
  this->healthValue+= sword.getHealthChange();
  this->strengthValue+= sword.getStrengthChange();
  this->weightCarried+= sword.getWeight();
}

//ring of life
void Race::setRingLife(){
	RingLife life;
	plife=&life;
	this->attackValue+= life.getAttackChange();
  this->defenseValue+= life.getDefenceChange();
  this->healthValue+= life.getHealthChange();
  this->strengthValue+= life.getStrengthChange();
  this->weightCarried+= life.getWeight();
}

//ring of strength
void Race::setRingStrength(){
	RingStrength strength;
	pstrength=&strength;
	this->attackValue+= strength.getAttackChange();
  this->defenseValue+= strength.getDefenceChange();
  this->healthValue+= strength.getHealthChange();
  this->strengthValue+= strength.getStrengthChange();
  this->weightCarried+= strength.getWeight();
}

//leather armour
void Race::setLeather(){
	Leather leather;
	pleather=&leather;
	this->attackValue+= leather.getAttackChange();
  this->defenseValue+= leather.getDefenceChange();
  this->healthValue+= leather.getHealthChange();
  this->strengthValue+= leather.getStrengthChange();
  this->weightCarried+= leather.getWeight();
}

//plate armour
void Race::setPlate(){
	Plate plate;
	pplate=&plate;
	this->attackValue+= plate.getAttackChange();
  this->defenseValue+= plate.getDefenceChange();
  this->healthValue+= plate.getHealthChange();
  this->strengthValue+= plate.getStrengthChange();
  this->weightCarried+= plate.getWeight();
}

//large shield
void Race::setLarge(){
	LargeShield large;
	plarge=&large;
	this->attackValue+= large.getAttackChange();
  this->defenseValue+= large.getDefenceChange();
  this->healthValue+= large.getHealthChange();
  this->strengthValue+= large.getStrengthChange();
  this->weightCarried+= large.getWeight();
}

//small shield
void Race::setSmall(){
	SmallShield small;
	psmall=&small;
	this->attackValue+= small.getAttackChange();
  this->defenseValue+= small.getDefenceChange();
  this->healthValue+= small.getHealthChange();
  this->strengthValue+= small.getStrengthChange();
  this->weightCarried+= small.getWeight();
}

/* void getRaceType()
 *
 * returns an integer as the race type
 * accepts no parameter as input:
 * (0 = human, 1 = elf, 2 = dwarf, 3 = orc, 4 = hobbit)
 */

int Race::getRaceType(){
  return raceType;
}

void Race::setAttackValue(int newAttackValue){
  attackValue += newAttackValue;
}

int Race::getAttackValue(){
  return attackValue;
}

void Race::setAttackChance(int newAttackSuccess, int newTotalAttackProbability){
  // allow the computer to set the seed value of the random number
  // the seed value is set to the system's clock
  srand(time(NULL));
  attackSuccess = newAttackSuccess;
  totalAttackProbability = newTotalAttackProbability;
  int i = 0;
  for(i = 0; i < totalAttackProbability; i++){
    if(i < attackSuccess){
      attackProbability[i] = true;
    } else{
      attackProbability[i] = false;
    }
  }
  attackChance = attackProbability[rand()%totalAttackProbability];
}

bool Race::getAttackChance(){
  // calls setAttackChance(int, int) method
  // allows a random value of success or failure to be set for each attack
  setAttackChance(attackSuccess, totalAttackProbability);
  return attackChance;
}

void Race::setDefenseValue(int newDefenseValue){
  defenseValue += newDefenseValue;
}

int Race::getDefenseValue(){
  return defenseValue;
}

void Race::setDefenseChance(int newDefenseSuccess, int newTotalDefenseProbability){
  // allow the computer to set the seed value of the random number
  // the seed value is set to the system's clock
  srand(time(NULL));
  defenseSuccess = newDefenseSuccess;
  totalDefenseProbability = newTotalDefenseProbability;
  int i = 0;
  for(i = 0; i < totalDefenseProbability; i++){
    if(i < defenseSuccess){
      defenseProbability[i] = true;
    } else{
      defenseProbability[i] = false;
    }
  }
  defenseChance = defenseProbability[rand()%totalDefenseProbability];
}

bool Race::getDefenseChance(){
  // calls setDefenseChance(int, int) method
  // allows a random value of success or failure to be set for each defense
  setDefenseChance(defenseSuccess, totalDefenseProbability);
  return defenseChance;
}

void Race::setHealthValue(int newHealthValue){
  healthValue += newHealthValue;
}

int Race::getHealthValue(){
  return healthValue;
}

void Race::setStrengthValue(int newStrengthValue){
  strengthValue += newStrengthValue;
}

int Race::getStrengthValue(){
  return strengthValue;
}

void Race::showPlayerInformation(){
  cout<<"\n\n["<<getRowCoordinate()<<"]["<<getColumnCoordinate()
      <<"] is the position on the board"
      <<"\n\nIt is "<<getModeOfDay()<<" ("<<getCommandCount()<<")\n"
      <<"Player: "<<getName()<<"; Attack = "<<getAttackValue()
      <<"; Defense = "<<getDefenseValue()<<"; Health = "<<getHealthValue()
      <<"; carrying 0 of 100";
}

void Race::setCommandCount(int count){
  countOfCommands = count;
}

/* method: int getCommandCount()
 * returns the number of commands the player has entered so far as an integer
 *
 */

int Race::getCommandCount(){
  return countOfCommands;
}


/* method: void setModeOfDay(bool newMode)
 *
 * the method for sets the time of the day
 * returns: void 
 * accepts a single boolean parameter: newmode
 * newMode sets private variable dayMode to either true or false
 * if dayMode is true, it is day time. Else, it is night time
 */

void Race::setModeOfDay(bool newMode){
  if(newMode == true){
    dayMode = true;
  } else{
    dayMode = false;
  }
}

/* method getModeOfDay()
 *
 * the method for gets the time of the day
 * does not accept any input parameter
 * returns: string - string is either 'Day' or 'Night'
 * 
 */

string Race::getModeOfDay(){
  string timeOfDay;
  if(dayMode == true){
    timeOfDay = "Day";
  } else{
    timeOfDay = "Night";
  }
  return timeOfDay;
}


/* method switchMode()
 *
 * the method switches between the modes of the day (day and night)
 * does not accept any input parameter
 * does not return any input parameter
 * 
 */

void Race::switchMode(){
  // string variable to hold the mode of the day 
  string checkModeOfDay;
  // get the mode of the day and store in string
  checkModeOfDay = getModeOfDay();
  if(checkModeOfDay == "Day"){
    // if the mode is day time, set mode to night
    setModeOfDay(false);
  } else{
    // if the mode is night time, set mode to day
    setModeOfDay(true);
  }
}


//pick method
//returns nothing ; takes in the current location of player
void Race::pick(Board square){
/*check the type of element the square holds
 * 0 = empty
 * 1 = race
 * 2 = item
*/
	cout<<square.getElementType()<<endl;
	if(square.getElementType()==2){//there is an item that can be picked
		cout<<"picked"<<endl;
		//check if player can add on more weight
		//compare weightCarried attribute with strength of race
		//if(weightCarried+<=this->strengthValue){
		//allow addition of any number if Ring otherwise check if another type of that item in the same category exists
		// if it is ring, pick up
		// else check if player has weapon or other items
		//} else {
		//}
		//}
		//else {
		//cout<<"Not strong enough to carry this item"<<endl;
		//}
	}
	else{//no item; only race or an empty square. Player cant pick
		cout<<"\nThere is no item to pick up from this location"<<endl;
	}
  
}


void Race::drop(){
  
  // check current coordinates of player
  // pass getRowCoordinate() and getColumnCoordinate() methods derived from
  // GameElement class to getStatus()
  // status of square: if square is empty, prompt player for which item to drop
  // if square is not empty, ignore request

  //if(square.getStatus(getColumnCoordinate(), getColumnCoordinate()) == empty){
    cout<<"\nWhich item would you like to drop: ";
    //provide a list of items the player holds
    //} else {
    cout<<"\nYou cannot drop an item at this location"
	<<"\nThe location is already occupied"<<endl;
    //}
}

 //prints out what character holds and amount of gold earned
void Race::inventory(){
	 cout<<"\nInventory: "<<endl; 
	 //cout<<pdagger->getWeaponType();
	 //if (pdagger!=NULL){cout<< pdagger->getWeaponType() <<endl;}
}

void Race::attack(){
  
  // check current coordinates of player
  // pass getRowCoordinate() and getColumnCoordinate() methods derived from
  // GameElement class to getStatus()
  // status of square: is square empty, does square contain a race element
  
  //if(square.getStatus(getColumnCoordinate(), getColumnCoordinate()) == race){
    if(getAttackChance() == true){
      cout<<"\n"<<getName()<<" attacked successfully";
      successfulAttack = true;
    } else{
      cout<<"\n"<<getName()<<" failed attack";
      successfulAttack = false;
    }
    //}else {
    cout<<"\nThere is no race to attack";
    //}
}

void Race::defend(){
  if(getDefenseChance() == true){
    cout<<"\n"<<getName()<<" defended successfully";
  } else{
    cout<<"\n"<<getName()<<" failed defense and takes "<<" damage";
  }
}

//should accept square.getStatus() return value
void Race::combatRound(Race defendant){
  // if the attack is successful, the enemy defends, else no need to defend
  // the enemy attacks back nonetheless
  if (successfulAttack == true){
    defendant.defend();
  }
  if (defendant.getHealthValue() > 0){
    defendant.attack();
    defend();
  } else{
    cout<<getName()<<" has successfully defeated "<<defendant.getName()<<endl;
  }
}
