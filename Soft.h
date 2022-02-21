#include <iostream>
#include "Agency.h"
#include "MountainDestination.h"
#include "IslandDestination.h"
using namespace std;

class Soft{

private:

    Agency agency;

public:


    Soft(Agency agency);

    void addMountainDestinationtoSoft();
    void addIslandDestinationtoSoft();
    void addDestinationtoSoft();
    void deleteDestinationfromSoft();
    void presentDestinations();
    void changeDiscounts();
    void menu();

};