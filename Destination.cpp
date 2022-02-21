
#include "Destination.h"

Destination::Destination(string country="", string city="", string name="", float price=0, const vector <Review>& reviews={}):
    country(country), city(city), name(name), price(price), reviews(reviews){}

float Destination::getPrice(){
    return price;
}

istream& Destination::read(istream &in){

    cout << "Country: ";
    in >> country;
    cout << "City: ";
    in >> city;
    cout << "Name of location: ";
    in >> name;
    cout << "Price: ";
    in >> price;
    cout << "Number of reviews: ";
    int number;
    in >> number;
    for (int i = 0; i < number; i++)
    {
        Review r;
        cout << "Review " << i + 1 << ": ";
        in >> r;
        reviews.push_back(r);
    }

    return in;
}

ostream& Destination::write(ostream &out){

    out << "The destination country is: " << country << "\n";
    out << "The destination city is: " << city << "\n";
    out << "The name of the location is: " << name << "\n";
    out << "The price of the vacation is: " << price << "\n";
    if(reviews.size()>0){
        out << "The reviews are: " << "\n";
        for (int i = 0; i <= reviews.size(); i++){
            out << "Review " << i + 1 << ": ";
            out << reviews[i] << "\n";
        }
    }
    else
        out<<"There are no reviews\n";
    return out;
    
}

istream &operator>>(istream &in, Destination &destination){

    destination.read(in);
    return in;
}

ostream &operator<<(ostream &out, Destination &destination){

    destination.write(out);
    return out;
}
