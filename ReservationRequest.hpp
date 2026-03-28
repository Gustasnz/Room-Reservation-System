#pragma once
#include <string>
using namespace std;

class ReservationRequest {
private:
    string course_name;
    string weekday;
    int start_hour;
    int end_hour;
    int student_count;

public:
    ReservationRequest(string course_name, string weekday, int start_hour, int end_hour, int student_count);
    ~ReservationRequest();
    string getCourseName();
    string getWeekday();
    int getStartHour();
    int getEndHour();
    int getStudentCount();
};