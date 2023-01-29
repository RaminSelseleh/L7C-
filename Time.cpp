/*
 * Time.cpp
 */

#include "Time.h"
#include <iostream>
#include <ostream>
#include <stdexcept>

/**
 * @brief Construct a new Time:: Time object
 * 
 */
Time::Time() : hour(0), minute(0), second(0) {

}

/**
 * @brief Construct a new Time:: Time object
 * 
 * @param hour  hour value
 * @param minute  minute value
 * @param second  second value
 */
Time::Time(unsigned int hour, unsigned int minute, unsigned int second) {
    if (hour < 24) {
        this->hour = hour;
    } else {
        throw std::out_of_range("One of the values is out of bounds");
    }
    
    if (minute < 60) {
        this->minute = minute;
    }
    else {
        throw std::out_of_range("One of the values is out of bounds");
    }

    if (second < 60) {
        this->second = second;
    } else {
        throw std::out_of_range("One of the values is out of bounds");
    }

}

Time::~Time() {
    
}

unsigned int Time::get_hour() {
    return hour;
}

unsigned int Time::get_minute() {
    return minute;
}

unsigned int Time::get_second() {
    return second;
}

void Time::set_24Hour(bool display24) {
    this->display24 = display24;
}



/**
 * @brief 
 * 
 * @param rhs 
 * @return true 
 * @return false 
 */
bool Time::operator==(const Time &rhs) {
    return this->time_to_seconds() == rhs.time_to_seconds();

}

/**
 * @brief 
 * 
 * @param rhs 
 * @return Time 
 */
Time operator +(const Time &lhs, const Time &rhs) {
    unsigned result = (lhs.time_to_seconds() + rhs.time_to_seconds()) % MAX_TIME;
    return Time((result / 3600), ((result % 3600) / 60), (result % 60));
}


Time operator -(const Time &lhs, const Time &rhs) {
    unsigned result = (lhs.time_to_seconds() - rhs.time_to_seconds());
    if (result > MAX_TIME) {
        result = result + MAX_TIME;
    }
    unsigned hou= result / 3600;
    unsigned min = (result % 3600) / 60;
    unsigned sec = (result % 3600) % 60;
    return Time((hou), (min), (sec));
}


/**
 * @brief 
 * 
 * @param os 
 * @param time 
 * @return std::ostream& 
 */
std::ostream& operator <<(std::ostream& os, const Time& time) {
    //bool display24;
    if (time.display24) {
        // is true, output 24 time
        os << time.hour << ":" << time.minute << ":" << time.second;
        
    }
    else {
        // output 12 time
        if (time.hour > 12) {
            int rr;
            rr = time.hour - 12;
            os << rr << ":" << time.minute << ":" << time.second << " PM";
        }
        if (time.hour <= 12) {
            int zz;
            zz = time.hour;
            if (zz == 0) {
                zz = 12;
            }
            os << zz << ":" << time.minute << ":" << time.second << " AM"; 

        } 
        return os;
    }
    return os;

}

unsigned int Time::time_to_seconds() const {
    return second + (minute * 60) + (hour * 3600);
}

/**
 * @brief Construct a new Time:: Time object
 * 
 * @param time 
 */
Time::Time(const Time& time) {
    this-> hour = time.hour;
    this-> minute = time.minute;
    this-> second = time.second; 
}

Time& Time::operator=(const Time& rhs) {
    hour = rhs.hour;
    minute = rhs.minute;
    second = rhs.second;
    return *this;

}
