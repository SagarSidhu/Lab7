#include "course.hpp"

using namespace std;

//Constructor
Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{

}

//Copy constructor
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

//Overriding the equals operator
Course & Course::operator =(const Course & m) {
    title = m.title;
    day = m.day;
    start_time = m.start_time;
    finish_time = m.finish_time;

    return *this;
}

//Overriding the comparison operator
bool Course::operator ==(const Course & rhs){

    return day == rhs.day && finish_time >= rhs.start_time && finish_time <= rhs.finish_time;

}

//Overriding the less than operator
bool Course::operator < (const Course & rhs) {

    if(day < rhs.day){
        return true;
    }else if(day == rhs.day){
        return start_time < rhs.start_time;
    }else{
        return false;
    }
}

//Creating function to convert ENUM to string
string Course::convEnum(Course::dayOfWeek day) {
    if(day == 0){
        return "MON";
    }else if(day == 1){
        return "TUE";
    }else if(day == 2){
        return "WED";
    }else if(day == 3){
        return "THUR";
    }else if(day == 4){
        return "FRI";
    }
}

//Overriding the insertion operator
ostream & operator << (ostream &os, const Course & m) {
    os << m.title << " " << Course::convEnum(m.day) << " " << m.start_time << " " << m.finish_time;
    return os;
}

