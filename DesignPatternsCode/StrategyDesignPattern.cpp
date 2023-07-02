#include <iostream>
#include <string>
using namespace std;

class DriveStrategy {
    public: 
        virtual void drive() = 0;
};

class NormalDrive : public DriveStrategy {
    public: 
        void drive(){
            cout<<"Normal drive"<<endl;
        };
};

class SpecialDrive : public DriveStrategy {

    public: 
        void drive(){
            cout<<"Special drive"<<endl;
        };
};

class Vehicle {
    private:
        DriveStrategy *ds;
    public: 
        Vehicle (DriveStrategy *ds){
            this->ds = ds;
        };

        void drive(){
            ds->drive();
        };
};

class SportsVehicle : public Vehicle {
    public: 
        SportsVehicle(): Vehicle(new SpecialDrive()){};
};

class OffroadVehicle : public Vehicle {
    public: 
        OffroadVehicle(): Vehicle(new SpecialDrive()){};
};

class PassengerVehicle : public Vehicle {
    public: 
        PassengerVehicle(): Vehicle(new NormalDrive()){};
};

int main() {
    OffroadVehicle obj;
    obj.drive();

    PassengerVehicle obj2;
    obj2.drive();
    return 0;
};