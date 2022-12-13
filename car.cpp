#include <string>
#include <iostream>
#include "car.h"
#include "person.h"
#include "vehicle.h"

Car::Car(std::string argDescription, double argWeight, double argHeight, double argStructuralIntegrity, 
                 double argAirBagQuality, Person argPerson1, Person argPerson2, Person argPerson3, Person argPerson4, 
                 GPS argLocation, int argNumPassengers, bool argEmergency): 
                 Vehicle {argDescription, argWeight, argHeight, argStructuralIntegrity, argAirBagQuality,
                          argPerson1, argPerson2, argPerson3, argPerson4, argLocation} {

    this->emergency = argEmergency;
}

Car::Car(std::string argDescription, double argWeight, double argHeight, double argStructuralIntegrity, 
                 double argAirBagQuality, Person argPerson1, Person argPerson2, Person argPerson3, 
                 GPS argLocation, int argNumPassengers, bool argEmergency): 
                 Vehicle {argDescription, argWeight, argHeight, argStructuralIntegrity, argAirBagQuality,
                          argPerson1, argPerson2, argPerson3, argLocation} {

    this->emergency = argEmergency;
}

Car::Car(std::string argDescription, double argWeight, double argHeight, double argStructuralIntegrity, 
                 double argAirBagQuality, Person argPerson1, Person argPerson2, 
                 GPS argLocation, int argNumPassengers, bool argEmergency): 
                 Vehicle {argDescription, argWeight, argHeight, argStructuralIntegrity, argAirBagQuality,
                          argPerson1, argPerson2, argLocation} {

    this->emergency = argEmergency;
}

Car::Car(std::string argDescription, double argWeight, double argHeight, double argStructuralIntegrity, 
                 double argAirBagQuality, Person argPerson1, 
                 GPS argLocation, int argNumPassengers, bool argEmergency): 
                 Vehicle {argDescription, argWeight, argHeight, argStructuralIntegrity, argAirBagQuality,
                          argPerson1, argLocation} {

    this->emergency = argEmergency;
}

Car::Car(): Vehicle {} {
    
    this->emergency = false;
}

/////////////////////////////////////////////////////////// dumpToJson goes here

Json::Value Car::dump2JSON()
{
    Json::Value result;
    
    Vehicle parent { (Vehicle) (*this) };
    result = parent.dump2JSON();

    result["Number of Passengers"] = this->numPassengers;
    result["Is in an emergency"] = this->emergency;

    return result;
}

bool Car::JSON2Object(Json::Value argJV) {
    //std::cout << argJV.toStyledString() << "\n \n";

    if((argJV.isNull() == true) || (argJV.isObject() != true)) {
        return false;
    }

    if(((argJV["Description"]).isNull()) == true || ((argJV["Description"]).isString() != true)) {
        
        return false;
    }

    this->numPassengers = (argJV["Number of Passengers"]).asInt();
    this->emergency = (argJV["Is in an emergency"]).asBool();
    
    Vehicle * vehicle_ptr = this;
    vehicle_ptr->Vehicle::JSON2Object(argJV);
    
    return true;

}