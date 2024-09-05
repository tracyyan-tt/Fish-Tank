#include "Clownfish.h"
#include <iostream>
#include "ShoppingStore.h"
#include "AquaticAnimal.h"
using namespace std;

// this class will be inherited by shoppingStore, and will cout the skill message if user has that animal

clownfish::clownfish()
{
}
// this is a virtual function from Aquatic Animal class
void clownfish:: skill()
{
    cout << "Clownfish is swimming !!!" << endl;
}
