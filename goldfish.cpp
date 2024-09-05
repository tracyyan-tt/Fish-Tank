#include <iostream>
#include "goldfish.h"
#include "ShoppingStore.h"
#include "AquaticAnimal.h"
using namespace std;

// this class will be inherited by shoppingStore class and will cout the skill message if user has that animal
goldfish::goldfish()
{
}
// this is a virtual function from Aquatic Animal class
void goldfish:: skill()
{
    cout << "Goldfish is swimming !!!" << endl;
}

