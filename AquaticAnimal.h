#ifndef AQUATICANIMAL_H
#define AQUATICANIMAL_H
#include "FishTank.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <random>
using namespace std;

class AquaticAnimal : public FishTank
// this class will be inherited by fish tank and check which aquatic animal that user temperature and ph fits
// this class will also go to the game next day to let random animal sick or hungry
{
    private:
    int hunger;
    int health;
    string disease;
    int price;
    int age;
    string *type; // all type of animal shopping store has
    int element;
    string name;

    public:
    bool check_environment(double _temp, double _ph);
    // this function will check the environment for the tank


    int next_day(int n, AquaticAnimal *arr, string arr2[], int account);
    // this function will let different fish sick or hungry
    
    
    
    AquaticAnimal();

    AquaticAnimal(string _name, int _hunger, int _health, string _disease, int _price, int _age, double _temp, double _ph, double _vol);

    AquaticAnimal(int _element, string _type[]);

    string getname();

    void setname(string _name);

    string gettype ();
    // type is a pointer here, because we will use for buy or sell in shopping store


    virtual ~AquaticAnimal();

    int gethunger();
    int gethealth();
    string getdisease();

    int getprice();

    int getage();

    int getelement();

    void sethunger(int _hunger);

    void sethealth(int _health);

    void setdisease(string _disease);

    void setprice(int _price);

    void setage(int _age);

    void setelement(int _element);

    void print();

    void setType(int _element, string *_type);
        

};

#endif