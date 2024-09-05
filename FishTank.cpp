#include "FishTank.h"
#include <stdio.h>
//#include <iostream>
//using namespace std;

FishTank :: FishTank()
{
    temperature = 0.0;
    phlevel = 0.0;
    volume = 0.0;
}
FishTank :: FishTank(double _temperature, double _phlevel, double _volume)
{
    temperature = _temperature;
    phlevel = _phlevel;
    volume = _volume;
}
double FishTank :: getTemperature()
{
    return temperature;
}
double FishTank :: getVolume()
{
    return volume;
}
double FishTank :: getPhlevel()
{
    return phlevel;
}
void FishTank :: setTemperature(double _temperature)
{
    temperature = _temperature;
}
void FishTank :: setVolume(double _volume)
{
    volume = _volume;
}
void FishTank :: setPhlevel(double _phlevel)
{
    phlevel = _phlevel;
}

