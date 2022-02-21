#include "Soft.h"

Soft::Soft(Agency agency): agency(agency){}



void Soft::addMountainDestinationtoSoft(){
    MountainDestination d;
    cin>>d;
    agency.addDestination(d);
}
void Soft::addIslandDestinationtoSoft(){
    IslandDestination d;
    cin>>d;
    agency.addDestination(d);
}

void Soft::addDestinationtoSoft(){
    cout<<"Choose your type of destination"<<"\n";
    cout<<"1: Mountain Destination"<<"\n";
    cout<<"2: Island Destination"<<"\n";
    int input2;
    if(input2 == 1)
        addMountainDestinationtoSoft();
    else
        addIslandDestinationtoSoft();
}

void Soft::deleteDestinationfromSoft(){

    cout << agency <<"\n";
    int number = agency.getNoDestinations();
    if(number == 0)
        cout<<"There are yet to be destinations in our catalogue"<<"\n";
    else{
        cout<<"Enter the no. of the destination you wish to have erased"<<"\n";
        int input3;
        cin>>input3;
        agency.deleteDestination(input3);
        cout << "Destination no." << input3 << " has been erased" << "\n";
    }
}

void Soft::presentDestinations(){
    int number = agency.getNoDestinations();
    if(number == 0)
        cout<<"There are yet to be destinations in our catalogue"<<"\n";
    else
        cout<<agency;
}

void Soft::changeDiscounts(){

    cout<<"Choose the type of discount to be changed"<<"\n";
    cout<<"1: Mountain discount"<<"\n";
    cout<<"2: Island discount"<<"\n";
    cout<<"3: Percentile Discount"<<"\n";
    cout<<"Your chosen discount type:";
    int input4;
    cin>>input4;
    cout<<"Type in the new discount"<<"\n";
    int new_discount;
    cin>>new_discount;
    cout<<"The modified discount is: "<<new_discount;

    if(input4==1){
        MountainDiscount discountm1 = agency.getDiscountm();
        agency.setDiscount(discountm1,new_discount);
    }
    else if(input4==2){
        IslandDiscount discounti1 = agency.getDiscounti();
        agency.setDiscount(discounti1,new_discount);
    }
    else if(input4 == 3){
        PercentileDiscount discountp1 = agency.getDiscountp();
        agency.setDiscount(discountp1,new_discount);
    }

}

void Soft::menu(){
    while(true){
        int input;
        cout<<"The soft can perform the following tasks: "<<"\n";
        cout<<"Choose a task"<<"\n";
        cout<<"1: Add a destination"<<"\n"; 
        cout<<"2: Delete a destination"<<"\n";
        cout<<"3: Present all available destinations"<<"\n";
        cout<<"4: Change discount values"<<"\n";
        cout<<"5: Exit"<<"\n";
        cout<<"Choose a task of the preceding 5";
        cin>>input;
        cout<<"Your chosen task is "<<input<<"\n";

        if(input == 1)
            addDestinationtoSoft();
        else if(input == 2)
            deleteDestinationfromSoft();
        else if(input == 3)
            presentDestinations();
        else if(input == 4)
            changeDiscounts();
        else if(input == 5)
            break;
    }
}