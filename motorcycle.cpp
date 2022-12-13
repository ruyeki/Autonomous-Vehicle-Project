#include <string>
#include <iostream>
#include "motorcycle.h"
#include "person.h"
#include "vehicle.h"

Motorcycle::Motorcycle(std::string argDescription, double argWeight, double argHeight, double argStructuralIntegrity, 
                 double argAirBagQuality, Person argPerson1, Person argPerson2, Person argPerson3, Person argPerson4, 
                 GPS argLocation, bool argHasHelmet): 
                 Vehicle {argDescription, argWeight, argHeight, argStructuralIntegrity, argAirBagQuality, 
                          argPerson1, argPerson2, argPerson3, argPerson4, argLocation} {

    this->hasHelmet = argHasHelmet;
}

Motorcycle::Motorcycle(std::string argDescription, double argWeight, double argHeight, double argStructuralIntegrity, 
                 double argAirBagQuality, Person argPerson1, Person argPerson2, Person argPerson3, 
                 GPS argLocation, bool argHasHelmet): 
                 Vehicle {argDescription, argWeight, argHeight, argStructuralIntegrity, argAirBagQuality, 
                          argPerson1, argPerson2, argPerson3, argLocation} {
                            
    this->hasHelmet = argHasHelmet;
}

Motorcycle::Motorcycle(std::string argDescription, double argWeight, double argHeight, double argStructuralIntegrity, 
                 double argAirBagQuality, Person argPerson1, Person argPerson2, 
                 GPS argLocation, bool argHasHelmet): 
                 Vehicle {argDescription, argWeight, argHeight, argStructuralIntegrity, argAirBagQuality, 
                          argPerson1, argPerson2, argLocation} {
                            
    this->hasHelmet = argHasHelmet;
}

Motorcycle::Motorcycle(std::string argDescription, double argWeight, double argHeight, double argStructuralIntegrity, 
                 double argAirBagQuality, Person argPerson1, 
                 GPS argLocation, bool argHasHelmet): 
                 Vehicle {argDescription, argWeight, argHeight, argStructuralIntegrity, argAirBagQuality, 
                          argPerson1, argLocation} {
                            
    this->hasHelmet = argHasHelmet;
}

Motorcycle::Motorcycle(): Vehicle {} {
    
    this->hasHelmet = false; // Assume the worst if not specified
}

/////////////////////////////////////////////////////////// dumpToJson goes here

Json::Value Motorcycle::dump2JSON()
{
    Json::Value result;
    
    Vehicle parent { (Vehicle) (*this) };
    result = parent.dump2JSON();

    result["Has a helmet"] = this->hasHelmet;

    return result;
}

bool Motorcycle::JSON2Object(Json::Value argJV) {
    //std::cout << argJV.toStyledString() << "\n \n";

    if((argJV.isNull() == true) || (argJV.isObject() != true)) {
        return false;
    }

    if(((argJV["Description"]).isNull()) == true || ((argJV["Description"]).isString() != true)) {
        
        return false;
    }

    this->hasHelmet = (argJV["Has a helmet"]).asBool();
    
    Vehicle * vehicle_ptr = this;
    vehicle_ptr->Vehicle::JSON2Object(argJV);
    
    return true;

}