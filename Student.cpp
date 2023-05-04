//
// Created by user on 20.04.2023.
//
#include <iostream>
#include "Student.h"
#include "StudentUtil.h"

Student::Student(){
    age = 18;
    name = "Kirill";
    city = "Moscow";
    homeAddress = "Novomosino";
    institute = "MIREA";
}

Student::Student(const uint& age, const std::string& name, const std::string& city,
                 const std::string& homeAddress, const std::string& institute) {
    this->age = age;
    this->name = name;
    this->city = city;
    this->homeAddress = homeAddress;
    this->institute = institute;
}

void Student::introducing() {
    std::cout << "Hello, my name is " << name << ", I'm " << age <<
    " years old, I live in " << city << ", my home address is "
    << homeAddress << ", I study in " << institute << std::endl;
}

uint Student::getWeekendCost(const DatabaseHandler& data, const uint& month,
                             const std::string& cinema, const std::string& caffe) const {
    int homeFood = data.getHomeFoodCost(this->city);
    if(homeFood < 0){
        std::cout << "Home food cost not found!" << std::endl;
    }
    int cinemaCost = data.getCinemaCost(this->city, cinema);
    if(cinemaCost < 0){
        std::cout << "Cinema cost not found!" << std::endl;
    }
    int coffeeCost = data.getCoffeeCost(this->city, caffe);
    if(coffeeCost < 0){
        std::cout << "Coffee cost not found!" << std::endl;
    }
    return static_cast<uint>(0.66 * homeFood + cinemaCost + coffeeCost + 0.5);
}

uint Student::getWorkdayCost(const DatabaseHandler &data, const uint &month) const {
    int transportCost = data.getTransportCost(this->city, this->homeAddress, this->institute);
    if(transportCost < 0){
        std::cout << "Transport cost not found!" << std::endl;
    }
    int instituteDinnerCost = data.getInstituteDinnerCost(this->city, this->institute);
    if(instituteDinnerCost < 0){
        std::cout << "Institute dinner cost not found!" << std::endl;
    }
    int homeFood = data.getHomeFoodCost(this->city);
    if(homeFood < 0){
        std::cout << "Home food cost not found!" << std::endl;
    }
    return static_cast<uint>(2 * transportCost +
        instituteDinnerCost + (0.66 * homeFood + 0.5) / StudentUtil::getDaysCount(month));
}

uint Student::getCosts(const DatabaseHandler &data, const uint &month,
                       const std::string& caffe, const std::string &cinema) const {
    const uint daysCount = StudentUtil::getDaysCount(month);
    const uint workDays = StudentUtil::getWorkdays(month);
    const uint weekends = daysCount - workDays;
    int otherCosts = data.getOtherMonthlyCosts(this->city, this->age);
    if(otherCosts < 0){
        std::cout << "Other costs not found!" << std::endl;
    }
    return workDays * getWorkdayCost(data, month) +
           getWeekendCost(data, month, cinema, caffe) + otherCosts;
}