#include"turtle.h"
#include <iostream>
#include "ShoppingStore.h"
#include "AquaticAnimal.h"
using namespace std;


// this class will be inherited by shoppingStore, and will cout the skill message if user has that animal

turtle::turtle()
{
}

    
void turtle::skill()
{
    cout << "Turtle is crawling !!!" << endl;
}
