#include <iostream>
#include <vector>
#include "Discount.h"
#include "MountainDiscount.h"
#include "IslandDiscount.h"
#include "PercentileDiscount.h"
#include "Review.h"
#include "Destination.h"
#include "MountainDestination.h"
#include "IslandDestination.h"
#include "Agency.h"
#include "Soft.h"
using namespace std;


int main() {
    
    
    Agency LibertyTours;
    Soft s1(LibertyTours);
    s1.menu();

    return 0;
}