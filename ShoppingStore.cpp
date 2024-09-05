#include "ShoppingStore.h"
#include <iostream>
#include <string>
#include "AquaticAnimal.h"
using namespace std;

    shoppingStore::shoppingStore()
    {
        cost = 0;
        n = 0;
        cart = nullptr;
    }
    shoppingStore::shoppingStore(int _n, int _cost, string _cart[], int _account)
    {   
        n = _n;
        cart = new string [n];
        for (int i = 0; i < n; ++i)
        {
            cart[i] = _cart[i];
        }
        cost = _cost;
        account = _account;
    }
    
    string shoppingStore::getstuff() // cart is a pointer in that class, we need to use for sell and buy
    {
       
        return *cart;

    }

    shoppingStore::shoppingStore(const shoppingStore &ObjToCopy)
    {
        cost = ObjToCopy.cost;
        n = ObjToCopy.n;
        
        cart = new string[n];

        for (int i = 0; i < n; ++i)
        {
            cart[i] = ObjToCopy.cart[i];
        }
    }


    int shoppingStore::getcost()
    {
        return cost;
    }
    int shoppingStore::getn()
    {
        return n;
    }

    void shoppingStore::setcost(int _cost)
    {
        cost = _cost;
    }
    void shoppingStore::setn(int _n)
    {
        n = _n;
    }

    void shoppingStore::setaccount(int _account)
    {
        account = _account;
    }

    int shoppingStore::getaccount()
    {
        return account;
    }

  
    
    shoppingStore::~shoppingStore()
    {
        if (cart != nullptr)
        {
            delete [] cart;
            cart = nullptr;
        }
    }

    shoppingStore shoppingStore:: operator+(const shoppingStore &p) // this is operator + for finish the buy function
    {
        shoppingStore temp;
        temp.n = this -> n + p.n;
        temp.cost = this -> cost + p.cost;
        temp.cart = new string[this -> n + p.n];
        for (int i = 0; i < n; ++i)
        {
            temp.cart[i] = this -> cart[i];
        }
        for (int i = this -> n; i < this -> n + p.n; ++i)
        {
            temp.cart[i] = p.cart[i - this -> n];
        }
        return temp;
    }
    shoppingStore shoppingStore:: operator-(const shoppingStore &p)
    {
        shoppingStore temp;
        temp.n = this -> n - p.n;
        //temp.cost = this -> cost - p.cost;
        temp.cart = new string[this -> n - p.n];
        if (temp.n == 0)
        {
            cout << "NO AQUATIC ANIMAL IN YOUR FISH TANK" << endl;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = i; j < n; ++j)
                {
                    if(cart[i] != p.cart[j])
                    {
                        temp.cart[i] = cart[i];
                    }
                }
            }
        }
        return temp;
    }
    shoppingStore shoppingStore:: operator =(const shoppingStore &p)
    {
        if(this != &p)
        {
            if(cart != nullptr)
            {
                delete [] cart;
                cart = nullptr;
            }
            cost = p.cost;
            n = p.n;
            cart = new string[n];
            for (int i = 0; i < n; ++i)
            {
                cart[i] = p.cart[i];
            }
        }
        return *this;
    }
    ostream & operator << (ostream & o, const shoppingStore &p)
    {
        o << "THANK YOU..." << endl;
        return o;
    }


    void shoppingStore::skill() // this will be virtual function for all other animal class
    {
        cout << "NO ANIMAL" << endl;
    }
    void shoppingStore::setcart(int _n, string *_cart)
    {
        n = _n;
        cart = new string[n];
        if (cart != nullptr)
        {
            for (int i = 0; i < n; ++i)
            {
                cart[i] = _cart[i];
            }
        }
    }





    void shoppingStore::print()
    {
        cout << "Good..." << endl;
        cout << "Here is the choices" << endl;
        for(int i = 0; i < n; ++i)
        {
            cout << cart[i] << endl;
        }
        
    }
    int shoppingStore::buy(int cost, int account)
    {
        if ((account - cost) >= 0)
        {
            account = account - cost;
            //cout << "HERE IS YOUR BALANCE AFTER BUYING: " << account << endl;
        }
        else
        {
            account = account;
            //cout << "SORRY, LOOKS LIKE YOUR BALANCE IS NOT ENOUGH" << endl;
        }
        return account;
    }
    int shoppingStore::sell(int account, string arr[], int ele, AquaticAnimal arr2[], int ele2)
    {
        int n = 0;
        int n2;
        if (ele > 0)
        {
            /*cout << "HERE IS THE AQUATIC ANIMAL YOU CAN SELL" << endl;
            for (int i = 0; i < ele; ++i)
            {
                cout << arr[i] << " type " << i << endl;
            }
            cin >> n2;*/
                for (int i = 0; i < ele; ++i)
                {
                    for (int j = i; j < ele2; ++j)
                    {
                            if(arr[i] == arr2[j].getname())
                            {
                                if(arr[i] == "Turtle")
                                {
                                    if (arr2[j].getage() > 10 && arr2[j].getage() <= 30)
                                    {
                                        n = 25;
                                        account += n;
                                        break;
                                    }
                                    else if (arr2[j].getage() > 30 && arr2[j].getage() <= 60)
                                    {
                                        n = 30;
                                        account += n;
                                        break;
                                    }
                                    else if (arr2[j].getage() > 60 && arr2[j].getage() < 80)
                                    {
                                        n = 50;
                                        account += n;
                                        break;
                                    }
                                    else if (arr2[j].getage() < 10)
                                    {
                                        n = 15;
                                        account += n;
                                        break;
                                    }
                                }
                                else
                                {
                                    if (arr2[j].getage() > 3 && arr2[j].getage() <= 5)
                                    {
                                        n = 20;
                                        account += n;
                                        break;
                                    }
                                    else if (arr2[j].getage() > 5 && arr2[j].getage() < 8)
                                    {
                                        n = 30;
                                        account += n;
                                        break;
                                    }
                                    else if(arr2[j].getage() < 3)
                                    {
                                        n = 15;
                                        account += n;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                continue;
                            }
                    }
                }
        }
        else 
        {
            cout << "THERE IS NO AQUATIC ANIMAL YOU CAN SELL" << endl;
        }
        cout << "HERE IS YOUR BALANCE AFTER SELLING: " << account << endl;
 
        return account;
    }