#include <iostream>
#include <vector>
#include "Discount.h"
#include "MountainDiscount.h"
#include "IslandDiscount.h"
#include "PercentileDiscount.h"
#include "Destination.h"
using namespace std;

class Agency{

private:

    vector <Discount*> discounts;
    MountainDiscount discountm;
    IslandDiscount discounti;
    PercentileDiscount discountp;
    vector <Destination*> destinations;

public:

    Agency(const vector<Destination*> destinations={});

    MountainDiscount getDiscountm() const;

    IslandDiscount getDiscounti();

    PercentileDiscount getDiscountp();

    int getNoDestinations();

    void deleteDestination(int n);

    template<class Destination>void addDestination(Destination d);

    void setDiscount(Discount &discount, int x );

    int applyDiscount(Destination& destination);

    friend ostream &operator<<(ostream &out, const Agency &a);


};