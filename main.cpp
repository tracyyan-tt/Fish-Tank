#include "FishTank.h"
#include "AquaticAnimal.h"
#include "ShoppingStore.h"
#include "Game.h"
#include "turtle.h"
#include "goldfish.h"
#include "Koi.h"
#include "Angelfish.h"
#include "guppy.h"
#include "Discus.h"
#include "Clownfish.h"

/*#include "FishTank.cpp"
#include "Game.cpp"
#include "turtle.cpp"
#include "AquaticAnimal.cpp"
#include "ShoppingStore.cpp"
#include "goldfish.cpp"
#include "Koi.cpp"
#include "Angelfish.cpp"
#include "guppy.cpp"
#include "Discus.cpp"
#include "Clownfish.cpp"*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
int system(const char *command);
struct animal // make a animal array
{
    string animal_name;
    int animal_price;
    int animal_number;
};


int main()
{
    const int Maxsize = 100;
    // here is when the game start
    cout << endl;
    cout << right << setw(33) << "WELCOME TO FISH TANK GAME !!!" << endl;
    cout << endl;
    cout << left << setw(20) << "HERE IS YOUR CHOICE" << '|';
    cout << right << setw(23) << "TYPING OPTION" << endl;
    cout << setfill('-') << setw(44) << "" << endl;
    cout << left << setfill(' ') << setw(20) << "NEW GAME" << "|";
    cout << right << setfill(' ') << setw(23) << "new game or NEW GAME" << endl;
    cout << left << setfill(' ') << setw(20) << "LOAD GAME" << "|";
    cout << right << setfill(' ') << setw(23) << "load game or LOAD GAME" << endl;
    cout << "IF YOU WANNA EXIT, PLEASE TYPE STOP IN CAPITAL" << endl;
    
    double user_temperature;
    double user_ph;
    double user_volume;
    int user_system;
    int initial_account;
    string file1;
    string arr[Maxsize];
    int user_element;
    int shop_element;
    Game newgame(initial_account, 0,0, user_temperature, user_ph, user_volume);
    //AquaticAnimal first;
    
    string message;
    getline(cin, message);
        while (message != "STOP" && message != "stop")
        //it will start the game until user type stop
        {
            AquaticAnimal Goldfish("Goldfish", 0,100, "well", 10,0,69,6.6,10);
            //this is a gift for every new user, i choose goldfish because that fish can live in most of the environment
            if (message == "NEW GAME" || message == "new game")
            //if user type new game, it start a new one
            {
                
                cout << "WE HAVE A GIFT FOR NEW USER:" << endl;
                cout << "YOUR ACCOUNT BALANCE IS 100 AND YOU HAVE YOUR FIRST AQUATIC ANIMAL IN YOUR FISH TANK" << endl;
                cout << "BUT FIRST, PLEASE MAKE YOUR FISH TANK" << endl;

                cout << "PLEASE TYPE YOUR TEMPERATURE, PH AND VOLUME, ALSO IF YOU WANT A FILTRATION SYSTEM, PLEASE TYPE 1, WHICH WILL COST $15, TYPE OTHER NUMBER IF NOT BUY" << endl;
                cout << "YOUR TEMPERATURE SHOULD BETWEEN 68 or 69, PH LEVEL SHOULD BETWEEN 6.5 or 6.6" << endl;
                //it ask user to make their tank
                cin >> user_temperature;
                cin >> user_ph;
                cin >> user_volume;
                cin >> user_system;
                initial_account = 100;
                if(user_system ==1)
                {
                    initial_account -= 15;
                }
                if(user_temperature == 68 || user_temperature == 69)
                {
                    if(user_ph == 6.5 || user_ph == 6.6)
                    {
                        cout << "LOOKS WELL, LET'S KEEP GOING" << endl;
                    }
                    else
                    {
                        cout << "TYPING INCORRECT..." << endl;
                        continue;
                    }
                }
                else
                {
                    continue;
                }

                cout << "PLEASE TYPE A FILENAME TO SAVE FOR YOUR GAME" << endl;
                //here will be a filename to save the whole game
                cin.ignore();
                getline(cin,file1);
                if(newgame.start_game(file1) == true)
                {
                    arr[0] = "Goldfish";
                    //system("photo1.jpg");







                    int cost1 = 0;
                    int hunger1 = 0;
                    int health1 = 0;
                    string disease1 = "";
                    int price1 = 0;
                    int age1 = 0;
                    string name3;


            

                    FishTank myTank(user_temperature,user_ph,user_volume);


                    user_element = 1;

                    cout << endl;
                    cout << right << setw(65) << "LET'S SEE WHAT YOU HAVE FROM NOW" << endl;
                    cout << setfill('-') << setw(100) << "" << endl;
                    cout << left << setw(30) << "HERE IS YOUR AQUATIC ANIMAL BY GIF" << "|";
                    cout << right << setw(30) << "HERE IS YOUR BALANCE BY GIFT AFTER BUY FILTRATION SYSTEM OR NOT" << endl;
                    //here is the gift for new user
                    for (int i = 0; i < user_element; ++i)
                    {
                        cout << left << setfill(' ') << setw(34) << arr[i] << "|";
                    }
                    


                    // and the new game will also have their money by gift
                    cout << right << setfill(' ') << setw(23) << initial_account << endl;
                    cout << endl;
                }
                else
                {
                
                    cout << "FILE IS NOT FOUND" << endl;
                    break;
                }
                
            }
            else if (message == "LOAD GAME" || message == "load game")
            {
                cout << "PLEASE TYPE YOUR SAVE GAME FILE TO LOAD YOUR GAME" << endl;
                // here will be the user to load their previous game
                getline(cin,file1);
                cout << endl;
                if(newgame.load_game(file1,user_element,arr,user_temperature, user_ph, user_volume,initial_account)==true)
                {
                    cout << endl;
                    cout << "LET'S GO" << endl;
                }
                else
                {
                    cout << "NO SUCH A FILE" << endl;
                    break;
                }
            }
            else if(message != "NEW GAME" || message != "new game" || message != "load game" || message != "LOAD GAME")
            {   
                cout << "SORRY, YOUR MESSAGE IS NOT CLEAR, PLEASE TYPE AGAIN..." << endl;
                cout << "PLEASE TYPE AS NEW GAME OR LOAD GAME" << endl;
                getline(cin, message);
                continue;
            }   

              
                    // then it will take user to the store for buy animal or sell animal
                    shoppingStore myacc(user_element, 0, arr, initial_account);
                    newgame.setPhlevel(user_ph);
                    newgame.setTemperature(user_temperature);
                    newgame.setVolume(user_volume);
                    newgame.start_game(file1);
                    cout << "WELL DONE WITH YOUR FIRST STEP" << endl;
                    cout << "NOW DO YOU WANNA BUY A NEW AQUATIC ANIMAL OR SELL A AQUATIC ANIMAL ???" << endl;
                    cout << "TYPE YES OR NO" << endl;
                    cout << "IF YOU WANNA EXIT STORE, PLEASE TYPE EXIST" << endl;
                    
                    int money;
                    int stuff;
                    string my_cart[Maxsize];
                    string my_sell[Maxsize];
                    int stuff2 = 0;
                    string go = "";
                    animal arr2[6] = {{"Koi",10,1},{"Clownfish",10,2}, {"Discus",15,3}, {"Angelfish",15,4}, {"Guppy",15,5}, {"Turtle",20,6}};
                    //it is a struct array

                    

                    AquaticAnimal Koi("Koi", 0,100,"well",10,0,68,6.5,10);
                    AquaticAnimal Discus("Discus", 0,100, "well", 10,0,69,6.6,10);
                    //AquaticAnimal Royal_Pleco ("Royal Pleco", 0,100,"well", 15,0,68,6.5,10);
                    AquaticAnimal Angelfish("Angelfish", 0,100,"well", 15,0,68,6.5,10);
                    AquaticAnimal Guppy("Guppy", 0,100,"well", 15,0, 68, 6.6, 10);
                    AquaticAnimal Turtle("Turtle", 0, 100, "well", 20, 0, 69,6.5, 20);
                    AquaticAnimal arr5[Maxsize] = {Koi,Goldfish, Discus, Angelfish,Guppy, Turtle};
                    shop_element = 7;

                    AquaticAnimal all;
                    

                    
                    shoppingStore myshop(stuff, money, my_cart, initial_account);


                    getline(cin,go); // if user type yes, it will take user to the store
                        while (go != "EXIST" && go != "exist")
                        {
                            if (go == "YES" || go == "yes")
                            {

                                string mes;
                                string mes2;


                                cout << "IF YOU WANNA BUY ANIMAL, TYPE BUY ANIMAL" << endl;
                                cout << "IF YOU WANNA SELL AQUATIC ANIMAL, TYPE SELL ANIMAL" << endl;
                                //cin.ignore();
                                getline(cin,mes);
                                int m;
                                if(mes == "BUY ANIMAL" || mes == "buy animal")
                                {
                                    money = 0;
                                    stuff = 0;
                                    cout << endl;
                                    cout << right << setw(33) << "HERE IS OUR AQUATIC ANIMAL" << endl;
                                    cout << setfill('-') << setw(44) << "" << endl;
                                    for (int i = 0; i < 6; ++i) // here showing all the animal that fix user tank
                                    {
                                        if(arr5[i].check_environment(user_temperature, user_ph) == true)
                                        {
                                            cout << left << setfill(' ') << setw(20) << arr2[i].animal_name << " $" << arr2[i].animal_price << "|";
                                            cout << right << setfill(' ') << setw(23) << "type" << arr2[i].animal_number << endl;

                                        }

                                    }
                                    //user can go to the store for buying any aquatic animal that fits that fish tank
                                        

                                        AquaticAnimal Koi2("Koi", 0,100,"well",10,0,68,6.5,10);
                                        AquaticAnimal Discus2("Discus", 0,100, "well", 10,0,69,6.6,10);
                                        AquaticAnimal Angelfish2("Angelfish", 0,100,"well", 15,0,68,6.5,10);
                                        AquaticAnimal Guppy2("Guppy", 0,100,"well", 15,0, 68, 6.6, 10);
                                        AquaticAnimal Turtle2("Turtle", 0, 100, "well", 20, 0, 69,6.5, 20);
                                        AquaticAnimal Clownfish("Clownfish", 0,100, "well", 10,0,69,6.6,10);
                                        AquaticAnimal arr6[Maxsize] = {Koi2,Clownfish, Discus2, Angelfish,Guppy2, Turtle2};
                                        animal arr7[6] = {{"Koi",10,1},{"Clownfish",10,2}, {"Discus",15,3}, {"Angelfish",15,4}, {"Guppy",15,5}, {"Turtle",20,6}};

                                    
                                    cin >> m;
                                    string m2;

                                    if(m == 1 || m == 2)
                                    {

                                        if (arr6[0].check_environment(user_temperature,user_ph) == false && m == 1) // if user type a wrong number, it will not let user buy
                                        {
                                            cout << "SORRY YOU CAN'T BUY THIS" << endl;
                                            cin.ignore();
                                            continue;
                                        }
                                        else if(arr6[1].check_environment(user_temperature, user_ph) == false && m == 2)
                                        {
                                            cout << "SORRY YOU CAN'T BUY THIS" << endl;
                                            cin.ignore();
                                            continue;
                                        } 
                                        else
                                        {
                                        
                                            cout << "DO YOU WANNA BUY ??? TYPE YES OR NO" << endl;
                                            cin.ignore();
                                            getline(cin,m2);
                                        }
                                            if (m2 == "yes" || m2 == "YES")
                                            {   
                                                if(initial_account >= 10)
                                                {

                                                    if(m == 1)
                                                    {
                                                        my_cart[stuff] = arr7[0].animal_name;
                                                    }
                                                    else if(m == 2)
                                                    {
                                                        my_cart[stuff] = arr7[1].animal_name;
                                                    }
                                                    money += 10;
                                                    stuff += 1;
                                                }
                                                else
                                                {
                                                    cout << "YOUR ACCOUNT BALANCE IS NOT ENOUGH" << endl;
                                                    //continue;
                                                }
                                            }
                                            else
                                            {
                                                stuff = stuff;
                                                money = money;
                                            }
                                    }
                                    else if (m == 3 || m == 4 || m == 5)
                                    {

                                        if (arr6[2].check_environment(user_temperature,user_ph) == false && m == 3)
                                        {
                                            cout << "SORRY YOU CAN'T BUY THIS" << endl;
                                            cin.ignore();
                                            continue;
                                        }
                                        else if(arr6[3].check_environment(user_temperature, user_ph) == false && m == 4)
                                        {
                                            cout << "SORRY YOU CAN'T BUY THIS" << endl;
                                            cin.ignore();
                                            continue;
                                        } 
                                        else if(arr6[4].check_environment(user_temperature, user_ph) == false && m == 5)
                                        {
                                            cout << "SORRY YOU CAN'T BUY THIS" << endl;
                                            cin.ignore();
                                            continue;
                                        }
                                        else
                                        {
                                            cout << "DO YOU WANNA BUY ??? TYPE YES OR NO" << endl;
                                            cin.ignore();
                                            getline(cin,m2);
                                        }
                                            if (m2 == "YES" || m2 == "yes")
                                            {   
                                                if(initial_account >= 15)
                                                {
                                                    if(m == 3)
                                                    {
                                                        my_cart[stuff] = arr7[2].animal_name;
                                                    }
                                                    else if(m == 4)
                                                    {
                                                        my_cart[stuff] = arr7[3].animal_name;
                                                    }
                                                    else if(m == 5)
                                                    {
                                                        my_cart[stuff] = arr7[4].animal_name;
                                                    }
                                                    money += 15;
                                                    stuff += 1;
                                                }
                                                else
                                                {
                                                    cout << "YOUR ACCOUNT BALANCE IS NOT ENOUGH..." << endl;
                                                    //continue;
                                                }
                                            }
                                            else
                                            {
                                                stuff = stuff;
                                                money = money;
                                            }
                                    }
                                        
                                    else if (m == 6)
                                    {
                                        if (arr6[5].check_environment(user_temperature,user_ph) == false && m == 6)
                                        {
                                            cout << "SORRY YOU CAN'T BUY THIS" << endl;
                                            cin.ignore();
                                            continue;
                                        }
                                        else
                                        {
                                            cout << "DO YOU WANNA BUY ??? TYPE YES OR NO" << endl;
                                            cin.ignore();
                                            getline(cin,m2);
                                        }
                                            if (m2 == "yes" || m2 == "YES")
                                            {
                                                if(initial_account >= 20)
                                                {
                                                    my_cart[stuff] = arr7[5].animal_name;
                                                    money += 20;
                                                    stuff += 1;
                                                }
                                                else if(initial_account < 20)
                                                {
                                                    cout << "YOUR ACCOUNT BALANCE IS NOT ENOUGH" << endl;
                                                    //continue;
                                                }
                                            }
                                            else 
                                            {
                                                stuff = stuff;
                                                money = money;
                                            }
                                    }
                                    else
                                    {
                                        cout << "SORRY, I DONT UNDERSTAND WHAT YOU MEAN, PLEASE TYPE AGAIN" << endl;
                                        cout << endl;
                                        cout << right << setw(33) << "HERE IS YOUR AQUATIC ANIMAL" << endl;
                                        cout << setfill('-') << setw(44) << "" << endl;
                                        for (int i = 0; i < 6; ++i)
                                        {
                                            if(arr6[i].check_environment(user_temperature, user_ph) == true)
                                            {
                                                cout << left << setfill (' ') << setw(20) << arr2[i].animal_name << " $" << arr2[i].animal_price << "|";
                                                cout << right << setfill(' ') << setw(23) << "type" << arr2[i].animal_number << endl;
                                            }

                                        }

                                    }

                                    shoppingStore shop2(stuff, money, my_cart, initial_account);
                                    shoppingStore total = myacc + shop2;
                                    cout << total; // here we using a pointer from shopping store type, which will add animal in user fish tank
                                    /*for (int i = user_element; i < (user_element + stuff); ++i)
                                    {
                                        arr[i] = my_cart[i-user_element];
                                    }*/
                                    for (int i = user_element; i < (user_element+stuff); ++i)
                                    {
                                        arr[i] = my_cart[i - user_element];
                                    }
                                    user_element += stuff;
                                    initial_account = myshop.buy(money,initial_account); 
                                    // here using the buy function to decrease account balance
                                }

                                /*else if(mes == "BUY FOOD" || mes == "buy food")
                                {
                                    cout << "HERE IS OUR FOOD FOR AQUATIC ANIMAL" << endl;
                                    for (int i = 0; i < 2; ++i)
                                    {
                                        cout << arr3[i].food_name << " $" << arr3[i].food_price << endl;
                                        cout << arr3[i].food_name << " type " << arr3[i].num2 << endl;
                                    }
                                    int m3;
                                    cin >> m3;
                                    string m4;
                                    if (m3 == 7)
                                    {
                                        cout << "DO YOU WANNA BUY ??? TYPE YES OR NO" << endl;
                                        cin.ignore();
                                        getline(cin,m4);
                                            if (m4 == "YES" || m4 == "yes")
                                            {
                                                my_food[stuff2] = arr3[0].food_name;
                                                money += 15;
                                                stuff2 += 1;
                                                newgame.setFeed(stuff2);
                                            }
                                            else
                                            {
                                                stuff2 = stuff2;
                                                money = money;
                                            }
                                    }
                                    else if (m3 == 8)
                                    {
                                        cout << "DO YOU WANNA BUY ??? TYPE YES OR NO" << endl;
                                        cin.ignore();
                                        getline(cin,m4);
                                            if (m4 == "YES" || m4 == "yes")
                                            {
                                                my_food[stuff2] = arr3[1].food_name;
                                                money += 20;
                                                stuff2 += 1;
                                                newgame.setFeed(stuff2);
                                            }
                                            else
                                            {
                                                stuff2 = stuff2;
                                                money = money;
                                            }
                                    }
                                    else
                                    {
                                        cout << "SORRY, I DONT UNDERSTAND WHAT YOU MEAN, PLEASE TYPE AGAIN" << endl;
                                        for (int i = 0; i < 6; ++i)
                                        {
                                            cout << arr3[i].food_name << "$" << arr3[i].food_price << endl;
                                            cout << arr3[i].food_name << " type " << arr3[i].num2 << endl;
                                        }

                                    }
                                 
                                } */
                       
                                else if (mes == "SELL ANIMAL" || mes == "sell animal" && user_element >0) // this option is for user sell animal
                                {
                                    int n2;
                                    cout << endl;
                                    cout <<right << setw(33) <<  "HERE IS THE AQUATIC ANIMAL YOU CAN SELL" << endl;
                                    cout << setfill('-') << setw(44) << "" << endl;// this will print out the animal that user have 
                                    for (int i = 0; i < user_element; ++i)
                                    {
                                        cout << left << setfill(' ') << setw(20) << arr[i] << "|"; 
                                        cout << right << setfill(' ') << setw(23) << " type " << i << endl;
                                    }
                                    cin >> n2;
                                    
                                    if (n2  < user_element)
                                    {
                                        
                                        my_sell[n2] = arr[n2];
                                        
                                        stuff2 += 1;
                                        
                                        
                                    }
                                    else
                                    {
                                        cout << "SORRY I DONT UNDERSTAND WHAT YOU SAID, PLEASE TYPE AGAIN..." << endl;
                                        cout << endl;
                                        cout <<right << setw(23) <<  "HERE IS THE AQUATIC ANIMAL YOU CAN SELL" << endl;
                                        cout << setfill('-') << setw(44) << "" << endl;// this will print out the animal that user have 
                                        for (int i = 0; i < user_element; ++i)
                                        {
                                            cout << left << setfill(' ') << setw(20) << arr[i] << "|";
                                            cout << right << setfill(' ') << setw(23) << " type " << i << endl;
                                        }
                                        cin >> n2;
                                        
                                    }
                                    initial_account = myshop.sell(initial_account,arr,user_element,arr5,shop_element); 
                                    // this will follow by the user animal age to see how much they can get after sell
                                    for (int i = 0; i < user_element; ++i)
                                    {
                                        for (int j = i; j < user_element; ++j)
                                        {
                                            if(arr[i] == my_sell[j])
                                            {
                                                arr[j] = arr[j+1];
                                                user_element -= 1;
                                            }
                                        }
                                    }
                                    cout << endl;
                                    cout << right << setw(33) << "HERE IS YOUR RECEIPT" << endl;
                                    // this will print out a receipt that the user buy in this time shopping
                                    cout << setfill('-') << setw(44) << "" << endl;
                                    if(stuff > 0)
                                    {
                                        for (int i = 0; i < stuff; ++i)
                                        {
                                            cout << right << setfill(' ') << setw(22) << my_cart[i] << endl;
                                        }
                                    }
      
                                }
                                else if(mes == "sell animal" || mes == "SELL ANIMAL" && user_element <= 0)
                                {
                                    cout << "SORRY, THERE HAS NO AQUATIC ANIMAL YOU CAN SELL" << endl;
                                    continue;
                                }
                                else
                                // if user type is not buy animal or sell animal, it will let user to retype
                                {
                                    cout << "PLEASE TYPE A CORRECT MESSAGE" << endl;
                                    /*cout << "IF YOU WANNA BUY ANIMAL, TYPE BUY ANIMAL" << endl;
                                    getline(cin,mes);*/
                                    continue;
                                }


                                /*cout << endl;
                                cout << right << setw(33) << "HERE IS YOUR RECEIPT" << endl;
                                cout << setfill('-') << setw(44) << "" << endl;
                                if(stuff > 0)
                                {
                                    for (int i = 0; i < stuff; ++i)
                                    {
                                        cout << right << setfill(' ') << setw(22) << my_cart[i] << endl;
                                    }
                                }*/

                                /*if (stuff2 > 0)
                                {
                                    for (int i = 0; i < stuff2; ++i)
                                    {
                                        cout << my_food[i] << endl;
                                    }
                                }*/
                                /*cout << "HERE IS YOUR COST FROM PREVIOUS TILL NOW:" << endl;
                                cout << money << endl;*/






                                cout << "FINISH SHOPPING ??? TYPE 1 TO LEAVE, TYPE OTHER NUMBER TO STAY..." << endl;
                                // after one time buying, user can choose leave or stay in the store
                                int j;
                                cin >> j;
                                    if(j != 1)
                                    {
                                        cout << "STILL WANNA BUY ??? TYPE YES TO STAY ... TYPE YES TO STORE, TYPE NO TO LEAVE" << endl;
                                        cin.ignore();
                                        getline(cin,go);
                                        continue;
                                    }
                                
                            }

                            else if (go == "no" || go == "NO")
                            // if user dont wanna go to the store, it will take user back to their fish tank
                            {
                                cout << "WELL, THAT'S OK..." << endl;
                                cout << "THEN LET'S GO BACK TO YOUR FISH TANK" << endl;
                                cout << endl;
                                cout << right << setw(25) << "HERE IS YOUR FISH" << endl;
                                cout << setfill('-') << setw(30) << "" << endl;
                                for (int i = 0; i < user_element; ++i)
                                {
                                    cout <<right << setfill(' ') << setw(20) << arr[i] << endl;
                                }
                                cout << endl;

                                for (int i = 0; i < user_element; ++i) // here are the virtual function using from different fish
                                {
                                    if (arr[i] == "Turtle")
                                    {
                                        turtle my_turtle2;
                                        //my_turtle2.skill();
                                        shoppingStore *pA2 = &my_turtle2;
                                        pA2 -> skill();
                                    }
                                    else if (arr[i] == "Guppy")
                                    {
                                        guppy my_guppy2;
                                        //my_guppy2.skill();
                                        shoppingStore *pB2 = &my_guppy2;
                                        pB2 -> skill();
                                    }
                                    else if(arr[i] == "Koi")
                                    {
                                        koi my_koi2;
                                        //my_koi2.skill();
                                        shoppingStore *pC2 = &my_koi2;
                                        pC2 -> skill();
                                    }
                                    else if(arr[i] == "Clownfish")
                                    {
                                        clownfish my_clown2;
                                        //my_clown2.skill();
                                        shoppingStore *pD2 = &my_clown2;
                                        pD2 -> skill();
                                    }
                                    else if(arr[i] == "Angelfish")
                                    {
                                        angelfish my_angel2;
                                        //my_angel2.skill();
                                        shoppingStore *pE2 = &my_angel2;
                                        pE2 -> skill();
                                    }
                                    else
                                    {
                                        goldfish my_fish2;
                                        //my_fish2.skill();
                                        shoppingStore *pF2 = &my_fish2;
                                        pF2 -> skill();
                                    }
                                }
                                cout << endl;


                                cout << "GOING TO THE NEXT DAY..." << endl;
                                // this will take user to the next day, and will get random animal sick or hungry
                                // every next day is when user go back to their fish tank from store
                                if (user_element > 0)
                                {
                                    initial_account = all.next_day(user_element,arr5,arr,initial_account);
                                }
                                else
                                {
                                    cout << "YOU NEED TO GO TO THE STORE FOR BUYING FISH" << endl;
                                    // if user dont have any animal, it will ask user to buy one or leave the game
                                    int r;
                                    cout << "TYPING NUMER 1, IF YOU WANNA GO, TYPE OTHER NUMBER IF NOT GO" << endl;
                                    cin >> r;
                                    if(r == 1)
                                    {
                                        cout << "WANNA GO TO THE STORE, TYPE YES" << endl;
                                        cin.ignore();
                                        getline(cin,go);
                                        if(go == "yes" || go == "YES")
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            cout << "GOODBYE, SEE YOU NEXT TIME" << endl;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        cout << "THAT'S FINE, TIME TO SAY GOODBYE" << endl;
                                        break;
                                    }
                                }
                                cout << "ANYTIME WANNA GO TO THE STORE PLEASE TYPE 1" << endl;
                                int r;
                                cout << "TYPING NUMER 1, IF YOU WANNA GO, TYPE OTHER NUMBER IF NOT GO" << endl;
                                cin >> r;
                                if(r == 1)
                                {
                                    cout << "WANNA GO TO THE STORE, TYPE YES" << endl;
                                    cin.ignore();
                                    getline(cin,go);
                                    if(go == "yes" || go == "YES")
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        cout << "GOODBYE, SEE YOU NEXT TIME" << endl;
                                        break;
                                    }
                                }
                                else
                                {
                                    cout << "THAT'S FINE, TIME TO SAY GOODBYE THEN" << endl;
                                    break;
                                }
                            }

                            else if (go != "yes" || go != "YES" || go != "NO" || go != "no")
                            {
                                cout << "PLEASE TYPE A CORRECT MESSAGE, YES OR NO ???" << endl;
                                getline(cin,go);
                                continue;
                            }
                        

                    
                    cout << "WELL EVERY STEP IS FINISH" << endl;



                    cout << "GOING BACK TO YOUR FISH TANK..." << endl;
                    cout << endl;
                    for (int i = 0; i < user_element; ++i)
                    {
                        cout << right << setfill(' ') <<  setw(15) << arr[i] << endl;
                    }
                    cout << endl;

                    for (int i = 0; i < user_element; ++i) // here are the virtual function using from different fish
                    {
                        if (arr[i] == "Turtle")
                        {
                            turtle my_turtle;
                            //my_turtle.skill();
                            shoppingStore *pA = &my_turtle;
                            pA -> skill();
                            

                        }
                        else if (arr[i] == "Guppy")
                        {
                            guppy my_guppy;
                            //my_guppy.skill();
                            shoppingStore *pB = &my_guppy;
                            pB -> skill();
                        }
                        else if(arr[i] == "Koi")
                        {
                            koi my_koi;
                            //my_koi.skill();
                            shoppingStore *pC = &my_koi;
                            pC -> skill();
                        }
                        else if(arr[i] == "Clownfish")
                        {
                            clownfish my_clown;
                            //my_clown.skill();
                            shoppingStore *pD = &my_clown;
                            pD -> skill();
                        }
                        else if(arr[i] == "Angelfish")
                        {
                            angelfish my_angel;
                            //my_angel.skill();
                            shoppingStore *pE = &my_angel;
                            pE -> skill();
                        }
                        else
                        {
                            goldfish my_fish;
                            //my_fish.skill();
                            shoppingStore *pF = &my_fish;
                            pF -> skill();
                        }
                    }
                    cout << endl;
 
                    // every time going back to the fish tank, it will go to the next day
                    cout << "GOING TO THE NEXT DAY..." << endl; // same thing here, it will go the next day
                    if(user_element > 0)
                    {
                        initial_account = all.next_day(user_element,arr5,arr,initial_account);
                    }
                    else
                    {
                        cout << "YOU NEED TO GO TO THE STORE FOR BUYING FISH" << endl;
                        int r;
                        cout << "TYPING NUMER 1, IF YOU WANNA GO, TYPE OTHER NUMBER IF NOT WANNA GO" << endl;
                        cin >> r;
                        if(r == 1)
                        {
                            cout << "WANNA GO TO THE STORE, TYPE YES" << endl;
                            cin.ignore();
                            getline(cin,go);
                            if(go == "yes" || go == "YES")
                            {
                                continue;
                            }
                            else
                            {
                                cout << "GOODBYE, SEE YOU NEXT TIME" << endl;
                                break;
                            }
                        }
                        else
                        {
                            cout << "THAT'S FINE, TIME TO SAY GOODBYE" << endl;
                            break;
                        }
                    }
                    cout << "ANYTIME YOU WANNA GO TO THE STORE, PLEASE TYPE 1, TYPE OTHER NUMBER IF WANNA EXIST THE WHOLE GAME" << endl;
                    //after user go to the fish tank, they can only have two options, go to the store ot leave the game
                    int w;
                    cin >> w;
                    if(w == 1)
                    {
                        cout << "WANNA GO TO THE STOR, TYPE YES" << endl;
                        cin.ignore();
                        getline(cin,go);
                        continue;
                    }
                    else if(user_element == 0)
                    {
                        cout << "ALL FISH IS SELLING, TIME TO GO TO THE STORE, PLEASE TYPE YES OR NO" << endl;
                        getline(cin,go);
                        continue;
                    }
                    else if(initial_account == 300)
                    {
                        cout << "YOU MEET THE TARGET, TIME TO SAY GOODBYE" << endl;
                        break;
                    }
                    else if(user_element == 0)
                    // if user dont have any money and animal, which mean user fail the game
                    {
                        for (int i = 0; i < 6; ++i) // here showing all the animal that fix user tank
                        {
                            if(arr5[i].check_environment(user_temperature, user_ph) == true)
                            {
                                if(initial_account < arr2[i].animal_price)
                                {
                                    cout << "GAME OVER :(" << endl;
                                    break;
                                }

                            }

                        }
                    }
                    else if(initial_account == 0 && user_element == 0)
                    {
                        cout << "GAME OVER :(" << endl;
                        break;
                    }
                    else
                    {
                        cout << "TIME TO SAY GOODBYE" << endl;
                        break;
                    }
                }
                    
                cout << "TIME TO SAY GOODBYE THEN, PLEASE TYPE STOP TO END, OTHERWISE I WILL CLOSE THE GAME FOR YOU, WHATEVER WORD YOU TYPE" << endl;
                newgame.save_game(file1,user_element,arr,initial_account);
                getline(cin,message);
                if (message != "stop" || message != "STOP")
                {
                    break;
                }



            

        }



    



   /* int user_element;

    cout << myanimal.next_day() << endl;
    shoppingStore myshopping;
    //myshopping.getmedicine(2, medarr, 1, cart);
    myshopping.getstuff(1, cart, 2, medarr);
    myshopping.print();*/
    return 0;
}