#include <string>
#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include "math.h"
#include "gps.h"

GPS::GPS(int newYCoord, int newXCoord) {
  char buffer[1000];
  sprintf (buffer, "(%d, %d)", newXCoord, newYCoord); // Basically std::cout, but instead of 
                                                      // printing to the screen, it prints into a string.
                                                      
  this->name = buffer; // Will be of the form (x, y) for printing purposes if you need them.
  this->YCoord = newYCoord;
  this->XCoord = newXCoord;
}

GPS::GPS() {
  this->name = "(-1, -1)";
  this->YCoord = -1;
  this->XCoord = -1;
}

///////////////////////////////////////////////////////// begin set definitions

void GPS::setYCoord(int argYCoord) {
    this->YCoord = argYCoord;
}

void GPS::setXCoord(int argXCoord) {
    this->XCoord = argXCoord;
}

void GPS::setName(std::string newName) {
    this->name = newName;
}

/////////////////////////////////////////////////////////// end set definitions

/////////////////////////////////////////////////////////// begin get definitions

int GPS::getYCoord() {
    return this->YCoord;
}

int GPS::getXCoord() {
    return this->XCoord;
}

std::string GPS::getName() {
    return this->name;
}

/////////////////////////////////////////////////////////// end get definitions

/////////////////////////////////////////////////////////// dumpToJson goes here

Json::Value GPS::dump2JSON()
{
    Json::Value result;
        result["Location's name"] = this->name;
        result["YCoord"] = this->YCoord;
        result["XCoord"] = this->XCoord;
        
    return result;
}


bool GPS::JSON2Object(Json::Value argJV) {
    //std::cout << argJV.toStyledString() << "\n";
    if((argJV.isNull() == true) || (argJV.isObject() != true)) {
        return false;
    }


        if(((argJV["XCoord"]).isNull()) == true || ((argJV["XCoord"]).isInt() != true) ||
            ((argJV["YCoord"]).isNull() == true) || ((argJV["YCoord"]).isInt() != true) ||
            ((argJV["Location's name"]).isNull() == true) || ((argJV["Location's name"]).isString() != true)) 
        {
            return false;
        }

    this->XCoord = (argJV["XCoord"]).asInt();
    this->YCoord = (argJV["YCoord"]).asInt();
    this->name = (argJV["Location's name"]).asString();

    return true;

}