#include "ReservationSystem.hpp"
#include "utilities.hpp"
#include <iostream>

ReservationSystem::ReservationSystem(int room_count, int* room_capacities) { //método para criar ReservationSystem
    this->room_count = room_count;
    this->room_capacities = new int[room_count];
    for (int i = 0; i < room_count; i++) {
        this->room_capacities[i] = room_capacities[i];
    }
    salas = new Sala[room_count];
}
ReservationSystem::~ReservationSystem() {//método para remover ReservationSystem
    delete[] room_capacities;
    delete[] salas;
}
bool ReservationSystem::reserve(ReservationRequest request) { //método para reservas
    string course = request.getCourseName();
    string weekday = request.getWeekday();
    int start = request.getStartHour();
    int end = request.getEndHour();
    int students = request.getStudentCount();
    dias_semana dia;

    if (weekday == "segunda") dia = dias_semana::seg;
    else if (weekday == "terca") dia = dias_semana::ter;
    else if (weekday == "quarta") dia = dias_semana::qua;
    else if (weekday == "quinta") dia = dias_semana::qui;
    else dia = dias_semana::sex;

    for (int i = 0; i < room_count; i++) {
        if (room_capacities[i] < students) {
            continue;
        }
        if (salas[i].adicionarReserva(course, dia, start, end)) {
            //como o método já foi definido para cada sala em utilities, aqui só chamamos ele para toda sala
            return true;
        }
    } return false;
}
bool ReservationSystem::cancel(std::string course_name) {//método para o cancelamento
    for (int i = 0; i < room_count; i++) {
        for (int d = 0; d < 5; d++) {
            if (salas[i].cancelar_reserva((dias_semana)d, course_name)) {
                //como o método já foi definido para cada sala em utilities, aqui só chamamos ele para toda sala
                return true;
            }
        }
    } return false;
}

void ReservationSystem::printSchedule() {//método para a impressão
    const string nomes_dias[5] = {"segunda", "terca", "quarta", "quinta", "sexta"};
    for (int i = 0; i < room_count; i++) {
        cout << "Room " << i + 1 << endl;
        for (int d = 0; d < 5; d++) {
            Reserva* reserv = salas[i].dias[d];
            if (reserv == nullptr) continue;
            cout << nomes_dias[d] << ":" << endl;
            while (reserv != nullptr) {
                cout << reserv->inicio << "h~"
                     << reserv->fim << "h: "
                     << reserv->course_name << endl;
                reserv = reserv->proxima;
            } cout << endl;
        }
    }
}//aqui apenas percorremos a lista e imprimimos. Como esta já está ordenada, a impressão sai ordenada também