#include "Game.h"

#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>
#include "AquaticAnimal.h"
#include "ShoppingStore.h"
#include "FishTank.h"

using namespace std;

// this class will be inherited by FishTank class, because it will print the temperature, ph and volume that the user save in previous play

bool Game::start_game(string _filename) // this will open a new game
{
    ofstream OF;
    OF.open(_filename);
    if (OF.is_open())
    {
        cout << "GAME START !!!" << endl;
        
        return true;
    }
    else
    {
        return false;
    }
}
Game::Game()
{
    account = 0;
    feed = 0;
    treatment = 0;
    animal = nullptr;
}
Game::Game(int _account, int _feed, int _treatment, double _temperature, double _phlevel, double _volume) : FishTank(_temperature, _phlevel, _volume)
{
    account = _account;
    feed = _feed;
    treatment = _treatment;
}

Game::~Game()
{
    if(animal != nullptr)
    {
        delete [] animal;
    }
}
int Game::getFeed()
{
    return feed;
}
int Game::getTreatment()
{
    return treatment;
}
int Game::getNanimal()
{
    return nAnimal;
}

void Game::setNanimal(int _nAnimal)
{
    nAnimal = _nAnimal;
}
void Game::setFeed(int _feed)
{
    feed = _feed;
}
void Game::setTreatment(int _treatment)
{
    treatment = _treatment;
}


void Game::setfilename (string _filename)
{
    filename = _filename;
}

void Game::setaccoune(int _account)
{
    account = _account;
}

int Game::getaccount()
{
    return account;
}

string Game::getfilename()
{
    return filename;
}


bool Game::load_game(string _filename, int &n, string arr[], double &temp, double &ph, double &vol, int &account) // this will use to load previous game for user
{
    ifstream IF;
    double _temp;
    double _ph;
    double _vol;
    int _n;
    int _account;
    string name;
    
    int count = 0;
    IF.open(_filename);
    
    if (IF.is_open())
    {
        cout << "GOING TO YOUR GAME ......" << endl;
        //string hold;
        while(IF >> _temp >> _ph >> _vol >> _n >> _account)
        {
            
            temp = _temp;
            ph = _ph;
            vol = _vol;
            n= _n;
            account = _account;
            
            cout << "YOUR TEMPERATURE IS :" << temp << endl;
            cout << "YOUR PH LEVEL IS :" << ph << endl;
            cout << "YOUR VOLUME IS :" << vol << endl;
            cout << "YOUR AQUATIC ANIMAL IS : " << endl;
            for (int i = 0; i < n; ++i)
            {
                
                IF >> name;
                arr[i] = name;
                cout << arr[i] << endl;

            }
            cout << "YOUR ACCOUNT BALANCE IS :" << account << endl; 
 
            IF.ignore(256,'\n');
        }
        return true;

    }
    else
    {
        return false;
    }
    IF.close();
}

bool Game::save_game(string _filename, int n, string arr[], int balance) // this will save the game for user in the input file
{
    ofstream OF;
    OF.open(_filename);
    if (OF.is_open())
    {
        cout << "YOUR GAME IS SAVING......" << endl;
        OF << FishTank::getTemperature() << " ";
        OF << FishTank::getPhlevel() << " ";
        OF << FishTank::getVolume() << " ";
        OF << n << " ";
        OF << balance << endl;
        //OF << "Your aquatic animal inside of your fish tank is:" << endl;
        for (int i = 0; i < n; ++i)
        {
            OF << arr[i] << endl;
        }
        return true;
        //OF << balance << " ";
        //OF << "Your aquatic animal is here: " << AquaticAnimal::gettype() << endl; 
    }
    else
    {
        return false;
    }
    OF.close();
}