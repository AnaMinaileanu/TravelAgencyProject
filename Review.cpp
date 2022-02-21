#include "Review.h"


Review::Review(){
    name = "";
    accomodation_period = 0;
    rating = 0;
}
Review::Review(string _name, int _accomodation_period, float _rating){
    name = _name;
    accomodation_period = _accomodation_period;
    rating = _rating;
}
istream &operator>>(istream &in, Review &p) {
    cout<<"Name: ";
    in>>p.name;
    cout<<"Accomodation Period: ";
    in>>p.accomodation_period;
    cout<<"Rating: ";
    in>>p.rating;
    return in;
}
ostream &operator<<(ostream &out, const Review &p) {
    out<<"Name: "<<p.name<<"\n";
    out<<"Accomodation Period: "<<p.accomodation_period<<"\n";
    out<<"Rating: "<<p.rating<<"\n";
     return out;
}