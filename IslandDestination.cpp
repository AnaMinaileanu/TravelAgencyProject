#include "IslandDestination.h"


IslandDestination::IslandDestination(string country = "", string city = "", string name = "", float price = 0, vector<Review> reviews = {}, bool sea_ocean = 0, int no_islands = 0) : 
    Destination(country, city, name, price, reviews), sea_ocean(sea_ocean), no_islands(no_islands) {}

istream& IslandDestination::read(istream &in){

    Destination::read(in);
    cout << "Island or Sea View (0: Island, 1: Sea): ";
    in >> sea_ocean;
    cout << "Number of Islands in the surrounding are : ";
    in >> no_islands;
    return in;
}

ostream& IslandDestination::write(ostream &out){

    Destination::write(out);
    out << "Island or Sea View (0: Island, 1: Sea): " << sea_ocean << "\n";
    out << "Number of Islands in the surrounding are : " << no_islands << "\n";
    return out;
}
