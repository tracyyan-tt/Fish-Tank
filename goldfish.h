#ifndef GOLDFISH_H
#define GOLDFISH_H
#include <iostream>
#include "ShoppingStore.h"
#include "AquaticAnimal.h"
using namespace std;

class goldfish : public shoppingStore
// this class will be inherited by shoppingStore class and will cout the skill message if user has that animal
{
    private:

    public:
    goldfish();
    // this is a virtual function from Aquatic Animal class
    virtual void skill();

};
#endif