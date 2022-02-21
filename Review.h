#include <iostream>
using namespace std;

class Review {

private:

    string name;
    int accomodation_period;
    float rating;

public:

    Review();
    Review(string _name, int _accomodation_period, float _rating);
    friend istream &operator>>(istream &in, Review &p);
    friend ostream &operator<<(ostream &out, const Review &p);

};