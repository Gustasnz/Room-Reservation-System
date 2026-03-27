#include "ReservationSystem.hpp"
#include <iostream>

ReservationSystem::ReservationSystem(int room_count, int* room_capacities) {
    this->room_count = room_count;
    this->room_capacities = new int[room_count];
    for (int i = 0; i < room_count; i++) {
        this->room_capacities[i] = room_capacities[i];
    }
}
ReservationSystem::~ReservationSystem() {
    delete[] room_capacities;
}
bool ReservationSystem::reserve(ReservationRequest resquest){
    // a fazer
}
bool ReservationSystem::cancel(string course_name){
    // a fazer
}
void ReservationSystem::printSchedule(){
    // a fazer
}