#include "Agency.h"

Agency::Agency(vector<Destination*> destinations = {}) : destinations(destinations){}

int Agency::getNoDestinations(){

    return destinations.size();
}

MountainDiscount Agency::getDiscountm() const{
    return discountm;
}

IslandDiscount Agency::getDiscounti(){
    return discounti;
}

PercentileDiscount Agency::getDiscountp(){
    return discountp;
}


void Agency::deleteDestination(int n){

    destinations.erase(destinations.begin() + n - 1);
}

template <class Destination>
void addDestination(Destination d)
{
    Destination *newdestination;
    newdestination = new Destination;
    *newdestination = d;
    destinations.push_back(newdestination);
}

void Agency::setDiscount(Discount &discount, int x)
{
    try{
        dynamic_cast<MountainDiscount &>(discount).setMountainDiscount(x);
    }
    catch (bad_cast &){};

    try{
        dynamic_cast<IslandDiscount &>(discount).setIslandDiscount(x);
    }
    catch (bad_cast &){};

    try{
        dynamic_cast<PercentileDiscount &>(discount).setPercentileDiscount(x);
    }
    catch (bad_cast &){};
}

int Agency::applyDiscount(Destination &destination){

    cout << destination;
    int i, maxim_discount = 0;
    for (i = 0; i < discounts.size(); i++){

        if (dynamic_cast<MountainDiscount*>(discounts[i]) != nullptr){

            if (dynamic_cast<MountainDiscount *>(discounts[i])->getMountainDiscount() > maxim_discount){

                maxim_discount = dynamic_cast<MountainDiscount *>(discounts[i])->getMountainDiscount();
            }
        }
        else if (dynamic_cast<IslandDiscount *>(discounts[i]) != nullptr){

            if (dynamic_cast<IslandDiscount *>(discounts[i])->getIslandDiscount() > maxim_discount){

                maxim_discount = dynamic_cast<IslandDiscount *>(discounts[i])->getIslandDiscount();
            }
        }
        else if (dynamic_cast<PercentileDiscount *>(discounts[i]) != nullptr){

            if ((dynamic_cast<PercentileDiscount *>(discounts[i])->getPercentileDiscount() / 100) * destination.getPrice() > maxim_discount){
                maxim_discount = (dynamic_cast<PercentileDiscount *>(discounts[i])->getPercentileDiscount() / 100) * destination.getPrice();
            }
        }
    }
    return destination.getPrice() - maxim_discount;
}


ostream &operator<<(ostream &out, const Agency &a){

    int c = 1;
    for (auto i : a.destinations)
    {
        out << "Destination " << c << ": ";
        out << *i << "\n";
        
        c++;
    }
    return out;
}

