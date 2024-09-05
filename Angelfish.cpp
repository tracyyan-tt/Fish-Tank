#include "Angelfish.h"
#include <iostream>
#include "ShoppingStore.h"
#include "AquaticAnimal.h"
using namespace std;

// this class will be inherited by shoppingStore, and will cout the skill message if user has that animal

angelfish::angelfish()
{
}
// this is a virtual function from Aquatic Animal class
void angelfish:: skill()
{
    cout << "Angelfish is swimming !!!" << endl;
}