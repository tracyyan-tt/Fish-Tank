#include "Koi.h"
#include <iostream>
#include "ShoppingStore.h"
#include "AquaticAnimal.h"
using namespace std;

// this class will be inherited by shoppingStore, and will cout the skill message if user has that animal

koi::koi()
{
}
// this is a virtual function from Aquatic Animal class
void koi:: skill()
{
    cout << "Koi is swimming !!!" << endl;
}
