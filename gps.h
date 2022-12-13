#ifndef _GPS_H_
#define _GPS_H_

#include <string>

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>

class GPS {
    public:
        GPS(int newYCoord, int newXCoord);
        GPS();
        ~GPS() {}

        void setYCoord(int argYCoord);
        void setXCoord(int argXCoord);
        void setName(std::string argName);

        int getYCoord();
        int getXCoord();
        std::string getName();
        
        virtual Json::Value dump2JSON();
        virtual bool JSON2Object(Json::Value);
    protected:
    private:
        std::string name;
        int YCoord;
        int XCoord;
        
};

#endif //_GPS_H_