#include <iostream>
#include "Discount.h"
using namespace std;

class MountainDiscount : public Discount
{
private:
    float Mdiscount = 40;
    
public:
    void setMountainDiscount(int x);
    float getMountainDiscount();
};