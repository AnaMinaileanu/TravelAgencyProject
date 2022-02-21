#include <iostream>
#include "Destination.h"
using namespace std;

class MountainDestination : public Destination{

private:

    float mountainHeight;
    float distance;
    int hikeTrails;

public:
    
    MountainDestination(string country="", string city="", string name="", float price=0, vector <Review> reviews={},float mountainHeight=0, float distance=0, int hikeTrails=0){}
                            
    istream &read(istream &in);
    ostream &write(ostream &out);

};
