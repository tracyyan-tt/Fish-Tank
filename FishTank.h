#include <iostream>
using namespace std;

#ifndef FISHTANK_H
#define FISHTANK_H

//#include "FishTank.cpp"



class FishTank
// this class will be base class for aquatic animal, and let user type their temperature and ph and volume
{
    private:
    double temperature;
    double phlevel;
    double volume;

    public:
    FishTank();

    FishTank(double _temperature, double _phlevel, double _volume);

    double getTemperature();
 
    double getVolume();

    double getPhlevel();

    void setTemperature(double _temperature);

    void setVolume(double _volume);
    /*{
        volume = _volume;
    };*/

    void setPhlevel(double _phlevel);
};
#endif
