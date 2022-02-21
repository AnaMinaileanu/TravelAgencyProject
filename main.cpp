#include <iostream>
#include <vector>
using namespace std;

class Discount
{
public:
    virtual ostream & write(ostream &out)const{
        return out;
    }
};

class MountainDiscount : public Discount
{
private:
    float Mdiscount = 40;
public:
    void setMountainDiscount(int x){
        Mdiscount = x;
    }
    float getMountainDiscount(){
        return Mdiscount;
    };
};

class IslandDiscount : public Discount
{
private:
    float Idiscount = 50;
public:
    void setIslandDiscount(int x){
        Idiscount = x;
    }
    float getIslandDiscount(){
        return Idiscount;
    };
};

class PercentileDiscount : public Discount
{
private:
    float Pdiscount = 15;
public:
    void setPercentileDiscount(int x){
        Pdiscount = x;
    }
    float getPercentileDiscount(){
        return Pdiscount;
    };
};

class Review {
private:
    string name;
    int accomodation_period;
    float rating;
public:
    Review(){
        name = "";
        accomodation_period = 0;
        rating = 0;
    }
    Review(string _name, int _accomodation_period, float _rating){
        name = _name;
        accomodation_period = _accomodation_period;
        rating = _rating;
    }
    friend istream &operator>>(istream &in, Review &p) {
        cout<<"Name: ";
        in>>p.name;
        cout<<"Accomodation Period: ";
        in>>p.accomodation_period;
        cout<<"Rating: ";
        in>>p.rating;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Review &p) {
        out<<"Name: "<<p.name<<"\n";
        out<<"Accomodation Period: "<<p.accomodation_period<<"\n";
        out<<"Rating: "<<p.rating<<"\n";
        return out;
    }

};


class Destination{
protected:
    string country;
    string city;
    string name;
    float price;
    vector <Review> reviews;
public:
    Destination(): country(""),city(""), name(""), price(0), reviews({}){}

    Destination(string _country, string _city, string _name, float _price, const vector <Review>& _reviews) : country(_country),
    city(_city), name(_name), price(price), reviews(_reviews){}

    float getPrice(){
        return price;
    }

    virtual istream& read (istream &in){

        cout<<"Country: ";
        in>>country;
        cout<<"City: ";
        in>>city;
        cout<<"Name of location: ";
        in>>name;
        cout<<"Price: ";
        in>>price;
        cout<<"Number of reviews: ";
        int number;
        in>>number;
        for (int i=0; i<number; i++){
            Review r;
            cout<< "Review "<<i+1<<": ";
            in>>r;
            reviews.push_back(r);
        }

        return in;
    }
    virtual ostream& write (ostream &out) {
        out<<"Country: "<<country<<"\n";
        out<<"City: "<<city<<"\n";
        out<<"Name of location: "<<name<<"\n";
        out<<"Price: "<<price<<"\n";
        for (int i=0; i<= reviews.size(); i++){

            out<< "Review "<<i+1<<": ";
            out<<reviews[i]<<"\n";
        }
        return out;
    }

    friend istream &operator>>(istream &in, Destination &destination) {
        destination.read(in);
        return in;
    }

    friend ostream &operator<<(ostream &out, Destination &destination) {
        destination.write(out);
        return out;
    }

};



class MountainDestination : public Destination{
private:
    float mountainHeight;
    float distance;
    int hikeTrails;
public:
    MountainDestination(){
        country = "";
        city = "";
        name = "";
        price = 0;
        vector <Review> reviews = {};
        mountainHeight = 0;
        distance = 0;
        hikeTrails = 0;
    };
    MountainDestination(string _country, string _city, string _name, float _price, vector <Review> _reviews,float _mountainHeight, float _distance, int _hikeTrails):
                            Destination(_country, _city, _name, _price, _reviews),
                            mountainHeight(_mountainHeight), distance(_distance), hikeTrails(_hikeTrails){}

    istream &read(istream &in) {
        Destination::read(in);
        cout<<"Height of the closest mountain: ";
        in>>mountainHeight;
        cout<<"Distance to the closest mountain: ";
        in>>distance;
        cout<<"Number of hike trails in the surrounding area: ";
        in>>hikeTrails;
        return in;
    }

    ostream &write(ostream &out) {
        Destination::write(out);
        out<<"Height of the closest mountain: "<<mountainHeight<<"\n";
        out<<"Distance to the closest mountain: "<<distance<<"\n";
        out<<"Number of hike trails in the surrounding area: "<<hikeTrails<<"\n";
        return out;
    }

};
class IslandDestination : public Destination{
private:
    bool sea_ocean;
    int no_islands;
public:
    IslandDestination(){
        country = "";
        city = "";
        name = "";
        price = 0;
        vector <Review> reviews = {};
        sea_ocean = 0;
        no_islands = 0;
    }
    IslandDestination(string _country, string _city, string _name, float _price, vector <Review> _reviews,bool _sea_ocean, int _no_islands):
            Destination(_country, _city, _name, _price, _reviews), sea_ocean(_sea_ocean), no_islands(_no_islands){}

    istream &read(istream &in) {
        Destination::read(in);
        cout<<"Island or Sea View (0: Island, 1: Sea): ";
        in>>sea_ocean;
        cout<<"Number of Islands in the surrounding are : ";
        in>>no_islands;
        return in;
    }

    ostream &write(ostream &out) {
        Destination::write(out);
        out<<"Island or Sea View (0: Island, 1: Sea): "<<sea_ocean<<"\n";
        out<<"Number of Islands in the surrounding are : "<<no_islands<<"\n";
        return out;
    }
};

class Agency{
private:
    vector<Discount*> discounts;
    vector <Destination*> destinations;
public:
    Agency(){
        vector <Destination*> destinations = {};
    }

    Agency(const vector<Destination*> _destinations) : destinations(_destinations){}

    int getNoDestinations(){
        return destinations.size();
    }

    void deleteDestination(int n) {
        destinations.erase(destinations.begin()+n-1);
    }
    template<class Destination>void addDestination(Destination d) {
        Destination* newdestination;
        newdestination=new Destination;
        *newdestination=d;
        destinations.push_back(newdestination);
    }

    friend ostream &operator<<(ostream &out, const Agency &a){
        int c=1;
        for(auto i: a.destinations){
            out<<"Destination "<<c<<": ";
            out<<*i<<"\n";
            c++;
        }
        return out;
    }

    void setDiscount(Discount &discount, int x )
    {
        try{  dynamic_cast<MountainDiscount&>(discount).setMountainDiscount(x); }
        catch (bad_cast&) {};
        try{  dynamic_cast<IslandDiscount&>(discount).setIslandDiscount(x); }
        catch (bad_cast&) {};
        try{  dynamic_cast<PercentileDiscount&>(discount).setPercentileDiscount(x); }
        catch (bad_cast&) {};
    }

    void applyDiscount(Destination& destination)
    {
        cout << destination;
        int i, maxim_discount = 0;
        for (i = 0; i <discounts.size(); i++){
            if (dynamic_cast<MountainDiscount*>(discounts[i]) != nullptr){
                if (dynamic_cast<MountainDiscount*>(discounts[i])->getMountainDiscount() > maxim_discount){
                    maxim_discount = dynamic_cast<MountainDiscount*>(discounts[i])->getMountainDiscount();
                }
            }
            else
                if (dynamic_cast<IslandDiscount*>(discounts[i]) != nullptr){
                    if (dynamic_cast<IslandDiscount*>(discounts[i])->getIslandDiscount() > maxim_discount){
                        maxim_discount = dynamic_cast<IslandDiscount*>(discounts[i])->getIslandDiscount();
                    }
                }
            else
                if (dynamic_cast<PercentileDiscount*>(discounts[i]) != nullptr){
                    if ((dynamic_cast<PercentileDiscount*>(discounts[i])->getPercentileDiscount()/100)*destination.getPrice() > maxim_discount){
                        maxim_discount = (dynamic_cast<PercentileDiscount*>(discounts[i])->getPercentileDiscount() / 100) * destination.getPrice();
                    }
                }
            }
        cout << destination.getPrice() - maxim_discount;
    }


};

int main() {
    cout<<"Choose a task"<<"\n";
    cout<<"1: Add a destination"<<"\n"; //+reviews
    cout<<"2: Delete a destination"<<"\n";
    cout<<"3: Present all available destinations"<<"\n";
    cout<<"4: Change discount percents"<<"\n";
    cout<<"5: Exit"<<"\n";
    cout<<"Your chosen task: ";
    int choice;
    Agency LibertyTours;
    MountainDestination m1;
    MountainDestination m2;
    MountainDestination m3;
    IslandDestination i1;
    IslandDestination i2;
    LibertyTours.addDestination(m1);
    LibertyTours.addDestination(m2);
    LibertyTours.addDestination(m3);
    LibertyTours.addDestination(i1);
    LibertyTours.addDestination(i2);
    MountainDiscount discountm;
    IslandDiscount discounti;
    PercentileDiscount discountp;
    do
    {
        cin>>choice;
        if (choice<1 || choice>5)
            cout<<"Task no."<<choice<<" not available."<<"\n";
        if (choice == 1){
            cout<<"Choose your type of destination"<<"\n";
            cout<<"1: Mountain Destination"<<"\n";
            cout<<"2: Island Destination"<<"\n";
            int choice2;
            cin>>choice2;
            if(choice2!=1 && choice2!=2)
                cout<<"Type of destination no."<<choice2<<" not available."<<"\n";
            else
            if(choice2 == 1){
                MountainDestination d;
                cin>>d;
                LibertyTours.addDestination(d);
            }
            else
            if(choice2 == 2){
                IslandDestination d;
                cin>>d;
                LibertyTours.addDestination(d);
            }

        }
        if(choice == 2){
            cout<< LibertyTours<<"\n";
            int nod = LibertyTours.getNoDestinations();
            if(nod == 0)
                cout<<"There are yet to be destinations in our catalogue"<<"\n";
            else
            {
                cout<<"Enter the no. of the destination you wish to have erased"<<"\n";
                int choice3;
                cin>>choice3;
                if(choice3 >=1 && choice3 <= nod) {
                    LibertyTours.deleteDestination(choice3);
                    cout << "Destination no." << choice3 << " has been erased" << "\n";
                }
                else
                    cout<<"There is no destination no."<<choice3<<"\n";
            }
        }

        if(choice == 3){
            int nod = LibertyTours.getNoDestinations();
            if(nod == 0)
                cout<<"There are yet to be destinations in our catalogue"<<"\n";
            else
                cout<<LibertyTours;
        }

        if(choice == 4){
            cout<<"Choose the type of discount to be changed"<<"\n";
            cout<<"1: Mountain discount"<<"\n";
            cout<<"2: Island discount"<<"\n";
            cout<<"3: Percentile Discount"<<"\n";
            cout<<"Your chosen discount type:";
            int choice4;
            cin>>choice4;
            cout<<"Type in the new discount"<<"\n";
            cout<<"The modified discount: ";
            int new_discount;
            cin>>new_discount;
            if(choice4==1)
                LibertyTours.setDiscount(discountm,new_discount);
            else if(choice4==2)
                LibertyTours.setDiscount(discounti,new_discount);
            else
                if(choice4 == 3)
                    LibertyTours.setDiscount(discountp,new_discount);
                else
                    cout<<"There is no such discount"<<"\n";
        }
        if(choice == 5)
            break;

        cout<<"Choose a task"<<"\n";
        cout<<"1: Add a destination"<<"\n"; //+reviews
        cout<<"2: Delete a destination"<<"\n";
        cout<<"3: Present all available destinations"<<"\n";
        cout<<"4: Exit"<<"\n";
        cout<<"Your chosen task: ";

    }while(choice!=5);

    return 0;
}