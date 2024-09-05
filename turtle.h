#ifndef TURTLE_H
#define TURTLE_H
#include <iostream>
#include "ShoppingStore.h"
#include "AquaticAnimal.h"
using namespace std;

class turtle : public shoppingStore
// this class will be inherited by shoppingStore, and will cout the skill message if user has that animal
{
    public:
    turtle();
    
    virtual void skill();

};
#endif