#ifndef SHOPPINGSTORE_H
#define SHOPPINGSTORE_H

#include <iostream>
#include <string>
#include "AquaticAnimal.h"
using namespace std;

class shoppingStore 
// this class will let user buy or sell animal, and it will use operator + to let the animal add inside of user fish tank
// also this will be base class for all aquatic animal class, such as goldfish, angelfish and so on
{
    public:
    shoppingStore();
    shoppingStore(int _n, int _cost, string _cart[], int _account);
    
    string getstuff();
     // cart is a pointer in that class, we need to use for sell and buy

    shoppingStore(const shoppingStore &ObjToCopy);


    int getcost();
    int getn();

    void setcost(int _cost);
    void setn(int _n);

    void setaccount(int _account);

    int getaccount();
  
    
    ~shoppingStore();

    shoppingStore operator+(const shoppingStore &p);
     // this is operator + for finish the buy function
    shoppingStore operator-(const shoppingStore &p);
       
    shoppingStore operator =(const shoppingStore &p);
    friend ostream & operator << (ostream & o, const shoppingStore &p);


    virtual void skill();
     // this will be virtual function for all other animal class
    void setcart(int _n, string *_cart);





    void print();
    int buy(int cost, int account);
    int sell(int account, string arr[], int ele, AquaticAnimal arr2[], int ele2);

    private:
    string *cart; // shopping cart for user in that time shopping
    int cost; // user total cost int that time shopping
    int n; // the total element that user buy in that time
    int account;

};
#endif