#include "AquaticAnimal.h"
#include "FishTank.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <random>
using namespace std;

bool AquaticAnimal::check_environment(double _temp, double _ph) // this function will check the environment for the tank
    {
        if(FishTank::getTemperature() == _temp)
        {
            if (FishTank::getPhlevel() == _ph)
            {
                return true;
            }
        }
        return false;
    };

    int AquaticAnimal::next_day(int n, AquaticAnimal *arr, string arr2[], int account) // this function will let different fish sick or hungry
    {
        int number;
        int number2;
        if(n > 0)
        {
            srand((unsigned int)time(nullptr));
            number = rand() % n;
            for (int j = 0; j < 6; ++j)
            {
                if(arr2[number] == arr[j].getname())
                {

                        arr[j].setdisease("I am sick");
                        cout << "YOUR "  << arr[j].getname() << " IS SICK" << endl;
                        arr[j].health = arr[j].health - 10;
                        if(arr[j].health == 0)
                        {
                            cout << "YOUR " << arr[j].getname() << " IS DYING" << endl;
                        }
                        cout << "DO YOU WANNA HELP HIM??? IT WILL COST $10 TO HELP, TYPE 1 FOR YES, OTHER NUMBER FOR NO" << endl;
                        int e;
                        cin >> e;
                        if(e == 1 && account >= 10)
                        {
                            cout << "THANK YOU" << endl;
                            account -= 10;
                            arr[j].health = 100;
                            cout << "YOUR ACCOUNT BALANCE IS " << account << endl;
                        }
                        else if(e == 1 && account < 10)
                        {
                            cout << "SORRY, YOU BALANCE IS NOT ENOUGH" << endl;
                            account = account;
                        }
                        else
                        {
                            account = account;
                            cout << "THAT'S FINE :)" << endl;
                        }
                        break;
                    
                }
                else
                {
                    continue;
                }
                arr[j].age += 1;
            }
        }
        if(n > 0)
        {
            srand((unsigned int)time(nullptr));
            number2 = rand() % n;
            for (int i =0; i < 6; ++i)
            {
                if(arr2[number2] == arr[i].getname())
                {
                    arr[i].hunger = arr[i].hunger + 10;
                    arr[i].health -= 10;
                    cout << "YOUR " << arr[i].getname() << " IS HUNGRY" << endl;
                    cout << "YOU CAN PAY $25 TO HELP, TYPE 1 FOR YES, OTHER NUMBER FOR NO" << endl;
                    int z;
                    cin >> z;
                    if (z == 1 && account >=25)
                    {
                        cout << "THANK YOU" << endl;
                        account -= 25;
                        arr[i].hunger -= 10;
                        arr[i].health += 10;
                        cout << "YOUR ACCOUNT BALANCE IS " << account << endl;
                    }
                    else if(z == 1 && account < 25)
                    {
                        cout << "SORRY, YOUR ACCOUNT BALANCE IS NOT ENOUGH" << endl;
                        account = account;
                    }
                    else
                    {
                        account = account;
                        cout << "THAT'S FINE :)" << endl;
                    }
                    break;
                }

                else
                {
                    continue;
                }
            }
        }
        else
        {
            cout << "THERE HAS NO AQUATIC ANIMAL IN YOUR FISH TANK" << endl;
        }
        return account;
    }
    
    
    AquaticAnimal::AquaticAnimal()
    {
        hunger = 0;
        health = 100;
        disease = " ";
        price = 0;
        age = 0;
        type = nullptr;
    };

    AquaticAnimal::AquaticAnimal(string _name, int _hunger, int _health, string _disease, int _price, int _age, double _temp, double _ph, double _vol):FishTank(_temp, _ph, _vol)
    {
        hunger = _hunger;
        health = _health;
        disease = _disease;
        price = _price;
        age = _age;
        name = _name;
    };

    AquaticAnimal::AquaticAnimal(int _element, string _type[])
    {
        element = _element;
        for (int i = 0; i < element; ++i)
        {
            this -> type[i] = _type[i];
        }
    }

    string AquaticAnimal::getname()
    {
        return name;
    }

    void AquaticAnimal::setname(string _name)
    {
        name = _name;
    }

    string AquaticAnimal::gettype () // type is a pointer here, because we will use for buy or sell in shopping store
    {
        return *type;
    };

    AquaticAnimal::~AquaticAnimal()
    {
        if (type != nullptr)
        {
            delete [] type;
            type = nullptr;
        }
    };

    int AquaticAnimal::gethunger()
    {
        return hunger;
    };

    int AquaticAnimal::gethealth()
    {
        return health;
    };

    string AquaticAnimal::getdisease()
    {
        return disease;
    };

    int AquaticAnimal::getprice()
    {
        return price;
    };

    int AquaticAnimal::getage()
    {
        return age;
    };

    int AquaticAnimal::getelement()
    {
        return element;
    };

    void AquaticAnimal::sethunger(int _hunger)
    {
        hunger = _hunger;
    };

    void AquaticAnimal::sethealth(int _health)
    {
        health = _health;
    };

    void AquaticAnimal::setdisease(string _disease)
    {
        disease = _disease;
    };

    void AquaticAnimal::setprice(int _price)
    {
        price = _price;
    };

    void AquaticAnimal::setage(int _age)
    {
        age = _age;
    };

    void AquaticAnimal::setelement(int _element)
    {
        element = _element;
    };

    void AquaticAnimal::print()
    {
        cout << "Still well......" << endl;

    }

    void AquaticAnimal::setType(int _element, string *_type)
    {
        element = _element;
        type = new string[element];
        if (type != nullptr)
        {
            for (int i = 0; i < element; ++i)
            {
                type[i] = _type[i];
            }
        }
    }
