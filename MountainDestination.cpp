
#include "MountainDestination.h"

MountainDestination::MountainDestination(string country = "", string city = "", string name = "", float price = 0, vector<Review> reviews = {}, float mountainHeight = 0, float distance = 0, int hikeTrails = 0) : Destination(country, city, name, price, reviews), mountainHeight(mountainHeight), distance(distance), hikeTrails(hikeTrails) {}

istream &MountainDestination::read(istream &in){
    
    Destination::read(in);
    cout << "Height of the closest mountain: ";
    in >> mountainHeight;
    cout << "Distance to the closest mountain: ";
    in >> distance;
    cout << "Number of hike trails in the surrounding area: ";
    in >> hikeTrails;
    return in;
}

ostream &MountainDestination::write(ostream &out){

    Destination::write(out);
    out << "The height of the closest mountain is: " << mountainHeight << "\n";
    out << "The distance to the closest mountain is: " << distance << "\n";
    out << "The number of hike trails in the surrounding area is: " << hikeTrails << "\n";
    return out;
}
