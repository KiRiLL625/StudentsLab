//
// Created by user on 22.04.2023.
//
#include "InputFunctions.h"
#include <iostream>

bool isMonth(uint month) {
    return month >= 1 && month <= 12;
}

uint getAge() {
    int age;
    std::cout << "Enter age: " << std::endl;
    try {
        std::cin >> age;
        if (age < 0) {
            throw std::invalid_argument("Age has to be positive");
        }
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        return getAge();
    }
    return (uint) age;
}

std::string getCity() {
    std::string city;
    std::cout << "Enter city: " << std::endl;
    std::cin >> city;
    return city;
}

uint getMonth() {
    int month = 0;
    while (!isMonth(month)) {
        std::cout << "What month is it?" << std::endl;
        std::cin >> month;
    }
    return month;
}

bool isMonth(int month) {
    return month >= 1 && month <= 12;
}

std::string getCinema(){
    std::string cinema;
    std::cout << "Enter cinema: " << std::endl;
    std::cin >> cinema;
    return cinema;
}

std::string getCoffee(){
    std::string coffe;
    std::cout << "Enter caffe: " << std::endl;
    std::cin >> coffe;
    return coffe;
}

std::string getInstitute(){
    std::string institute;
    std::cout << "Enter institute: " << std::endl;
    std::cin >> institute;
    return institute;
}

std::string getAddress(){
    std::string address;
    std::cout << "Enter address: " << std::endl;
    std::cin >> address;
    return address;
}

std::string getName(){
    std::string name;
    std::cout << "Enter name: " << std::endl;
    std::cin >> name;
    return name;
}
