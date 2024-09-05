#include "Discus.h"
#include <iostream>
#include "ShoppingStore.h"
#include "AquaticAnimal.h"
using namespace std;


// this class will be inherited by shoppingStore, and will cout the skill message if user has that animal

discus::discus()
{
}
// this is a virtual function from Aquatic Animal class
void discus::skill()
{
    cout << "Discus is swimming !!!" << endl;
}