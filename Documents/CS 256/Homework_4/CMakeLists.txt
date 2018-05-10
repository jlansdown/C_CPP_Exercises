cmake_minimum_required(VERSION 3.8)
project(Homework_4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp PoliceOfficer.h PoliceOfficer.cpp ParkedCar.h ParkedCar.cpp ParkingMeter.h ParkingMeter.cpp ParkingTicket.h ParkingTicket.cpp Game21.cpp Game21.h Die.cpp Die.h Ship.cpp Ship.h CruiseShip.cpp CruiseShip.h CargoShip.cpp CargoShip.h)
add_executable(Homework_4 ${SOURCE_FILES})