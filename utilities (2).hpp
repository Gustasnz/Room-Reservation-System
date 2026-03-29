#pragma once
#include <string>

using namespace std;

class Reserva {
public:
    string course_name;
    int inicio;
    int fim;
    Reserva* proxima; //ponteiro para apontar para a proxima reserva
    Reserva(string course_name, int inicio, int fim) {
        this->course_name = course_name;
        this->inicio = inicio;
        this->fim = fim;
        this->proxima = nullptr;
    }
    bool contem_horario(int i, int f){ //verifica se um horário entraria em conflito com o horário de uma reserva
        return !(f <= inicio || i >= fim);
    }
};

enum dias_semana{seg, ter, qua, qui, sex};

class Sala {
public:
    Reserva* dias[5]; //cada dia da semana aponta para o primeiro termo da lista encadeada de reservas

    Sala() { //cria uma sala
        for (int i = 0; i < 5; i++) {
            dias[i] = nullptr;
        }
    }
    ~Sala() { //remove uma sala
        for (int i = 0; i < 5; i++) {
            Reserva* reserv = dias[i];
            while (reserv != nullptr) {
                Reserva* next = reserv->proxima;
                delete reserv;
                reserv = next;
            }
        }
    }

    bool adicionarReserva(string course_name, dias_semana dia, int inicio, int fim) {
        if (dias[dia]==nullptr) {
            Reserva* nova = new Reserva(course_name, inicio, fim);
            dias[dia] = nova;
            return true;
        }
        else {
            int j = 0;
            Reserva* reserv=dias[dia];
            Reserva* anterior=nullptr;
            if (fim<=reserv->inicio){
                Reserva* nova = new Reserva(course_name, inicio, fim);
            nova->proxima = reserv;
            dias[dia]=nova;
            return true;
            }
            else{
                while(fim>reserv->inicio && reserv!=nullptr){ //como a lista está ordenada não precisamos verificar ela toda
                    if (reserv->contem_horario(inicio,fim)) {
                        return false;
                    } anterior=reserv;
                    reserv=reserv->proxima;
                }
            
            Reserva* nova = new Reserva(course_name, inicio, fim);
            nova->proxima = reserv;
            anterior->proxima= nova;
            } //aqui estamos acrescentando um elemento na sua devida posição, com isso evitamos realizar um sort posteriormente
            
        } return true; //retornamos booleanos nesses métodos com base em sucesso ou falha na reserva
    }
    
    bool cancelar_reserva(dias_semana dia, string course_name) { //cancela uma reserva e retorna um booleano em caso de sucesso ou falha
        if (dias[dia]==nullptr) {
            return false;
        }
        else{
            Reserva* reserv = dias[dia];
            Reserva* anterior = nullptr;
            while(reserv != nullptr){ //como estamos verificando na semana toda sem especificar horário não podemos aproveitar a ordenação aqui
                if (reserv->course_name == course_name) {
                    if(anterior == nullptr) {
                        dias[dia] = reserv->proxima;
                    }
                    else {
                        anterior->proxima = reserv->proxima; 
                    }
                    delete reserv;
                    return true;
                }
                anterior = reserv;
                reserv = reserv->proxima;
            } return false;
        }
    }
};
