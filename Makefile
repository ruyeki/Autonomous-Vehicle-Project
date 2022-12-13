CC = g++ -std=c++14
CFLAGS = -g

LDFLAGS = 	-L~/vcpkg/installed/arm64-osx/lib -ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

INC	=	ecs36b_Common.h
INC_CL	=	JvTime.h person.h gps.h vehicle.h car.h motorcycle.h thing.h decision.h
OBJ	=	JvTime.o person.o gps.o vehicle.o car.o motorcycle.o thing.o decision.o


all: 	hw7stub leftMotorcycle rightMotorcycle middleCar middleCarReturn


hw7stub:		ecs36b_hw7.json
	jsonrpcstub ecs36b_hw7.json --cpp-server=leftMotorcycle --cpp-client=middleCar

middleCar.o:	 middleCar.cpp $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) middleCar.cpp

leftMotorcycle.o:		leftMotorcycle.cpp $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) leftMotorcycle.cpp

rightMotorcycle.o:		rightMotorcycle.cpp $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) rightMotorcycle.cpp

middleCarReturn.o:		middleCarReturn.cpp $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) middleCarReturn.cpp

ecs36b_JSON.o:		ecs36b_JSON.cpp $(INC)
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

gps.o:	gps.cpp gps.h $(INC)
	$(CC) -c $(CFLAGS) gps.cpp

vehicle.o:	vehicle.cpp vehicle.h $(INC)
	$(CC) -c $(CFLAGS) vehicle.cpp

car.o:	car.cpp car.h $(INC)
	$(CC) -c $(CFLAGS) car.cpp

motorcycle.o:	motorcycle.cpp motorcycle.h $(INC)
	$(CC) -c $(CFLAGS) motorcycle.cpp

thing.o:	thing.cpp thing.h $(INC)
	$(CC) -c $(CFLAGS) thing.cpp

decision.o:	decision.cpp decision.h $(INC)
	$(CC) -c $(CFLAGS) decision.cpp

JvTime.o:	JvTime.cpp JvTime.h $(INC)
	$(CC) -c $(CFLAGS) JvTime.cpp

person.o:	person.cpp person.h $(INC)
	$(CC) -c $(CFLAGS) person.cpp

leftMotorcycle:	leftMotorcycle.o ecs36b_JSON.o $(OBJ)
	$(CC) -o leftMotorcycle leftMotorcycle.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

middleCar:	middleCar.o ecs36b_JSON.o $(OBJ)
	$(CC) -o middleCar middleCar.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

rightMotorcycle:	rightMotorcycle.o ecs36b_JSON.o $(OBJ)
	$(CC) -o rightMotorcycle rightMotorcycle.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

middleCarReturn:	middleCarReturn.o ecs36b_JSON.o $(OBJ)
	$(CC) -o middleCarReturn middleCarReturn.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

clean:
	rm -f *.o *~ core middleCar.h leftMotorcycle.h middleCar leftMotorcycle rightMotorcycle middleCarReturn


