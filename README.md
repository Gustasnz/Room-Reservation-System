# Reservation System

## Descrição do Projeto

Este projeto implementa um sistema simples de reserva de salas. O sistema permite alocar cursos em diferentes salas ao longo da semana, respeitando:

- Capacidade máxima das salas
- Conflitos de horário
- Organização por dias da semana

Cada reserva contém:
- Nome do curso
- Dia da semana
- Horário de início e fim

Os dados foram organizados de modo que o gerenciamento dos horários (parte central do código) fosse feita por listas encadeadas seguinho a seguinte hierarquia de controle:

ReservationSystem -> Sala -> Dias -> Lista encadeada de reservas

---

## Fluxo de Execução

O programa segue o seguinte fluxo de execução no main.cpp:

1. São agregadas duas salas de aula ao sistema;
2. São inicializadas 4 reservas de sala (das quais as três primeiras são bem sucedidas e a última é para supostamente não ser possível realizar, por conflito de horário);
3. Uma das reservas de sala e horário é cancelada;
4. A reserva que antes não tinha sido possível agora consegue ser encaixada na grade. 

---

## Instruções de Compilação

Para compilar, basta utilizar o comando dado nas instruções do projeto:

```bash
g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o reservation_system
