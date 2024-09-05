#ifndef KOI_H
#define KOI_H
#include <iostream>
#include "ShoppingStore.h"
#include "AquaticAnimal.h"
using namespace std;

class koi : public shoppingStore
// this class will be inherited by shoppingStore, and will cout the skill message if user has that animal
{
    private:

    public:
    koi();
    // this is a virtual function from Aquatic Animal class
    virtual void skill();


};
#endif