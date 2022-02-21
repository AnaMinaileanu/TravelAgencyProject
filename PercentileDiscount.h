#include <iostream>
#include "Discount.h"
using namespace std;
class PercentileDiscount : public Discount
{
private:
    float Pdiscount = 15;

public:
    void setPercentileDiscount(int x);
    float getPercentileDiscount();
};