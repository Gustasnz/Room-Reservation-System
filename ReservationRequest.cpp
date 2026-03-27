#include <iostream>
#include "ReservationRequest.hpp"
using namespace std;
//using namespace ReservationRequest;

ReservationRequest::ReservationRequest(string course_name,
                                       string weekday,
                                       int start_hour,
                                       int end_hour,
                                       int student_count){
    this->course_name = course_name;
    this->weekday = weekday;
    this->start_hour = start_hour;
    this->end_hour = end_hour;
    this->student_count = student_count;
}