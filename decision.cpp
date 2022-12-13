#include <string>
#include <iostream>
#include "decision.h"

Decision::Decision(std::string argMCarDirections, std::string argLMotorDirections, std::string argRMotorDirections) {
    this->MCarDirections = argMCarDirections; // IMPORTANT NOTE BELOW
    // Directions can be any of the following: L (move left), R (move right), F (move forward) or any comninations of these letters
    // You can change these boundaries as you see fit, these are my recommendations
    this->LMotorDirections = argLMotorDirections;
    this->RMotorDirections = argRMotorDirections;
}

Decision::Decision() {
    this->MCarDirections = "Do nothing";
    this->LMotorDirections = "Do nothing";
    this->RMotorDirections = "Do nothing";
}

/////////////////////////////////////////////////////////// dumpToJson goes here

Json::Value Decision::dump2JSON()
{
    Json::Value result;
    
    result["Left motorcycle's directions"] = LMotorDirections;
    result["Right motorcycle's directions"] = RMotorDirections;
    result["Middle car directions"] = MCarDirections;

    return result;
}

bool Decision::JSON2Object(Json::Value argJV) {
    //std::cout << argJV.toStyledString() << "\n \n";

    if((argJV.isNull() == true) || (argJV.isObject() != true)) {
        return false;
    }

    this->MCarDirections = (argJV["Middle car directions"]).asString();
    this->LMotorDirections = (argJV["Left motorcycle's directions"]).asString();
    this->RMotorDirections = (argJV["Right motorcycle's directions"]).asString();
    
    return true;

}