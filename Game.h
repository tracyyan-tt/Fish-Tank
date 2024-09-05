#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>
#include "AquaticAnimal.h"
#include "ShoppingStore.h"
#include "FishTank.h"

using namespace std;
class Game : public FishTank
// this class will be inherited by FishTank class, because it will print the temperature, ph and volume that the user save in previous play
{
public:
bool start_game(string _filename); // this will open a new game
Game();
Game(int _account, int _feed, int _treatment, double _temperature, double _phlevel, double _volume);

~Game();
int getFeed();
int getTreatment();
int getNanimal();
void setNanimal(int _nAnimal);
void setFeed(int _feed);
void setTreatment(int _treatment);

void setfilename (string _filename);

void setaccoune(int _account);

int getaccount();

string getfilename();


bool load_game(string _filename, int &n, string arr[], double &temp, double &ph, double &vol, int &account);
// this will use to load previous game for user

bool save_game(string _filename, int n, string arr[], int balance);
// this will save the game for user in the input file


private:
int feed;
int treatment;
int nAnimal;
string *animal;
string filename;
int account; // user account money
};
#endif