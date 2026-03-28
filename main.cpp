#include <iostream>
#include <string>
#include "ReservationSystem.hpp"

int main() {
    int capacities[3] = {30, 50, 80};
    ReservationSystem sys(3, capacities);

    // Test reservations
    sys.reserve(ReservationRequest("Matematica",  "segunda", 7,  9,  25));
    sys.reserve(ReservationRequest("Fisica",      "segunda", 9,  11, 45));
    sys.reserve(ReservationRequest("Quimica",     "terca",   7,  9,  80));
    sys.reserve(ReservationRequest("Historia",    "segunda", 7,  9,  60)); // conflicts room1, should go to room3

    bool ok = sys.reserve(ReservationRequest("Bloqueada", "segunda", 7, 9, 90)); // no room big enough free
    cout << "Reserva impossivel (esperado false): " << (ok ? "true" : "false") << "\n\n";

    sys.printSchedule();

    cout << "--- Cancelando Fisica ---\n\n";
    sys.cancel("Fisica");
    sys.printSchedule();

    return 0;
}