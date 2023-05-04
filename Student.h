//
// Created by user on 20.04.2023.
//
#include <string>
#include "DatabaseHandler.h"

#ifndef STUDENTS_LAB_STUDENT_H
#define STUDENTS_LAB_STUDENT_H

typedef unsigned int uint;
class Student {
private:
    uint age;
    std::string name;
    std::string city;
    std::string homeAddress;
    std::string institute;
public:
    Student();
    Student(const uint& age, const std::string& name, const std::string& city,
            const std::string& homeAddress, const std::string& institute);

    void introducing();

    uint getWeekendCost(const DatabaseHandler& data, const uint& month,
                        const std::string& caffe, const std::string& cinema) const;

    uint getWorkdayCost(const DatabaseHandler& data, const uint& month) const;

    uint getCosts(const DatabaseHandler& data, const uint& month,
                  const std::string& caffe, const std::string& cinema) const;
};


#endif //STUDENTS_LAB_STUDENT_H
