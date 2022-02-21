#include <iostream>
#include "Discount.h"
using namespace std;

class IslandDiscount : public Discount
{

private:
    float Idiscount = 50;

public:
    void setIslandDiscount(int x);
    float getIslandDiscount();
    
};
