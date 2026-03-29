#include <iostream>
#include "ReservationSystem.hpp"

int main() {

    int room_count = 2;
    int capacities[2] = {30, 50};

    ReservationSystem system(room_count, capacities);
    ReservationRequest ed("Data Structures", "quarta", 8, 11, 35);
    ReservationRequest vect("Vectorial Calculus", "segunda", 13, 15, 20);
    ReservationRequest aln("Numerical Linear Algebra", "quarta", 12, 16, 40);
    ReservationRequest prob("Probability Theory", "quarta", 7, 10, 40); // deve dar conflito

    cout << "Adicionando reservas..." << endl; // retorna 1 se conseguir reserva e 0 se não
    cout << "Reserva 1: " << system.reserve(ed) << endl; // esperado: 1
    cout << "Reserva 2: " << system.reserve(vect) << endl; // esperado: 1
    cout << "Reserva 3: " << system.reserve(aln) << endl; // esperado: 1
    cout << "Reserva 4: " << system.reserve(prob) << endl; // esperado: 0
    
    cout << "\n=== Schedule Inicial ===\n";
    system.printSchedule();

    cout << "\nCancelando Data Structures...\n";
    cout << "Cancelamento 1: " << system.cancel("Data Structures") << endl; // esperado: 1
    cout << "Reserva 5: " << system.reserve(prob) << endl; // esperado: 1
    
    cout << "\n=== Schedule Após Cancelamento ===\n";
    system.printSchedule();
    
    return 0;
}