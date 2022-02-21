#include <iostream>
#include <vector>
#include "Review.h"
using namespace std;

class Destination{
protected:
    string country;
    string city;
    string name;
    float price;
    vector <Review> reviews;

public:

    Destination(string country="", string city="", string name="", float price=0, const vector <Review>& reviews={});
    
    float getPrice();

    virtual istream& read (istream &in);
    virtual ostream& write (ostream &out);

    friend istream &operator>>(istream &in, Destination &destination);
    friend ostream &operator<<(ostream &out, Destination &destination);

};
