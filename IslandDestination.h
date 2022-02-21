#include <iostream>
#include "Destination.h"
using namespace std;

class IslandDestination : public Destination{

private:
    bool sea_ocean;
    int no_islands;

public:
   
    IslandDestination(string country="", string city="", string name="", float price=0, vector <Review> reviews={},bool sea_ocean=0, int no_islands=0);

    istream &read(istream &in);
    ostream &write(ostream &out);
};
