#include "ReservationRequest.hpp"
#include "utilities.hpp"
#include <iostream>

class ReservationSystem {
private:
    int room_count;
    int* room_capacities;
    Sala* salas;
public:
    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();
    bool reserve(ReservationRequest request);
    bool cancel(string course_name);
    void printSchedule();
};