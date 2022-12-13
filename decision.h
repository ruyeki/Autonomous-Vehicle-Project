#ifndef _DECISION_H_
#define _DECISION_H_

#include <string>

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>

class Decision {
    public:
        Decision(std::string argMCarDirections, std::string argLMotorDirections, std::string argRMotorDirections);
        // Parameters are strings that represent directions for each vehicle
        Decision();
        ~Decision() {}
        
        std::string MCarDirections;
        std::string LMotorDirections;
        std::string RMotorDirections;


        virtual Json::Value dump2JSON();
        virtual bool JSON2Object(Json::Value);
    protected:
    private:
        
};

#endif //_DECISION_H_