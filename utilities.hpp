//uma lista encadeada da seguinte forma:
//sala é uma classe que possui um ponteiro, tal ponteiro aponta para uma lista de ponteiros(cada ponteiro é um dia da semana)
//cada um dos dias da semana aponta para uma das reservas feitas para aquele dia
//uma reserva é uma classe com atributos diversos e um ponteiro que aponta para a próxima reserva que foi feita
//reserva pode ter um metodo que recebe um horario e verifica se esse horario estaria entre os horarios da reserva
#include <string>

using namespace std;

class Reserva {
public:
    string course_name;
    int inicio;
    int fim;
    Reserva* proxima;
    Reserva(string course_name, int inicio, int fim) {
        this->course_name = course_name;
        this->inicio = inicio;
        this->fim = fim;
        this->proxima = nullptr;
    }
    bool contem_horario(int i, int f){
        return !(f <= inicio || i >= fim);
    }
};

enum dias_semana{seg, ter, qua, qui, sex};

class Sala {
public:
    Reserva* dias[5];

    Sala() {
        for (int i = 0; i < 5; i++) {
            dias[i] = nullptr;
        }
    }

    bool adicionarReserva(string course_name, dias_semana dia, int inicio, int fim) {
        if (dias[dia]==nullptr) {
            Reserva* nova = new Reserva(course_name, inicio, fim);
            dias[dia] = nova;
            return true;
        }
        else {
            int j = 0; // se j = 0 ok, se j = 1 conflito de horários
            Reserva* reserv=dias[dia];
            while(reserv != nullptr){
                if (reserv->contem_horario(inicio,fim)) {
                    return false;
                } reserv=reserv->proxima;
            }
            Reserva* nova = new Reserva(course_name, inicio, fim);
            nova->proxima = dias[dia];
            dias[dia] = nova;
            return true;
        }    
    }
    
    bool cancelar_reserva(dias_semana dia, string course_name) {
        if (dias[dia]==nullptr) {
            return false;
        }
        else{
            Reserva* reserv = dias[dia];
            Reserva* anterior = nullptr;
            while(reserv != nullptr){
                if (reserv->course_name == course_name) {
                    if(anterior == nullptr) {
                        dias[dia] = reserv->proxima;
                    }
                    else {
                        anterior->proxima = reserv->proxima;
                    }
                    //remover reserv
                    delete reserv;
                    return true;
                }
                anterior = reserv;
                reserv = reserv->proxima;
            } return false;
        }
    }
};