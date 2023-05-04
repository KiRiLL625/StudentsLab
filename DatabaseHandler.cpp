//
// Created by user on 19.04.2023.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "DatabaseHandler.h"

DatabaseHandler::DatabaseHandler() {
    this->costsPath = "Costs.csv"; //(C:\Users\user\CLionProjects\students_lab\Costs.csv)
    this->transportPath = "Transport.csv";
    this->institutePath = "Institute.csv";
    this->cafeAndCinemaPath = "Caffe-and-cinema.csv";
    std::cout << "NOTICE: The paths to the data files were set by default" << std::endl;
    /*if (!initDatabase()) {
        exit(3);
    }
    */
}

DatabaseHandler::DatabaseHandler(const std::string& costsPath,
                                 const std::string& transportPath,
                                 const std::string& institutePath,
                                 const std::string& cafeAndCinemaPath) {
    this->costsPath = costsPath;
    this->transportPath = transportPath;
    this->institutePath = institutePath;
    this->cafeAndCinemaPath = cafeAndCinemaPath;
    std::cout << "NOTICE: The paths to the data files were set by user" << std::endl;
    /*if (!initDatabase()) {
        exit(3);
    }
    */
}

/*bool DatabaseHandler::initDatabase() const { //убрать
    std::string paths[] = {costsPath, transportPath, institutePath, cafeAndCinemaPath};
    std::fstream fs;
    for (const auto& path : paths) {
        fs.open(path, std::fstream::in);
        if (!fs.is_open()) {
            std::cout << "ERROR: The file " << path << " was not found" << std::endl;
            return false;
        }
        fs.close();
    }
    return true;
}
*/

int DatabaseHandler::getOtherMonthlyCosts(const std::string &city, uint age) const {
    std::fstream fs;
    fs.open(this->costsPath, std::fstream::in);
    if(!fs.is_open()){
        throw std::invalid_argument("File with costs not found!");
    }
    std::string line;
    char delimiter = ',';
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream stream(line);
        std::string _city, _age, _foodCostPerMonth, _otherCosts;
        getline(stream, _city, delimiter);
        getline(stream, _age, delimiter);
        getline(stream, _foodCostPerMonth, delimiter);
        getline(stream, _otherCosts, delimiter);
        if (age == std::stoi(_age) && city == _city) {
            return stoi(_otherCosts);
        }
    }
    return -1;
}

int DatabaseHandler::getHomeFoodCost(const std::string &city) const {
    std::fstream fs;
    fs.open(this->costsPath, std::fstream::in);
    if(!fs.is_open()){
        throw std::invalid_argument("File with costs not found!");
    }
    std::string line;
    char delimiter = ',';
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream stream(line);
        std::string _city, _age, _otherCosts, _foodCostPerMonth;
        getline(stream, _city, delimiter);
        getline(stream, _age, delimiter);
        getline(stream, _foodCostPerMonth, delimiter);
        getline(stream, _otherCosts, delimiter);
        if (city == _city) {
            return stoi(_foodCostPerMonth);
        }
    }
    return -1; //поменять на int
}

int DatabaseHandler::getCinemaCost(const std::string &city, const std::string &cinema) const {
    std::fstream fs;
    fs.open(this->cafeAndCinemaPath, std::fstream::in);
    if(!fs.is_open()){
        throw std::invalid_argument("File with caffe and cinema costs not found!");
    }
    std::string line;
    char delimiter = ',';
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream stream(line);
        std::string _city, _dump, _cinema, _cost;
        getline(stream, _city, delimiter);
        getline(stream, _dump, delimiter);
        getline(stream, _dump, delimiter);
        getline(stream, _dump, delimiter);
        getline(stream, _cinema, delimiter);
        getline(stream, _cost, delimiter);
        if (city == _city && cinema == _cinema) {
            return stoi(_cost);
        }
    }
    return -1;
}

int DatabaseHandler::getCoffeeCost(const std::string &city, const std::string &coffee) const {
    std::fstream fs;
    fs.open(this->cafeAndCinemaPath, std::fstream::in);
    if(!fs.is_open()){
        throw std::invalid_argument("File with cafe and cinema costs not found!");
    }
    std::string line;
    char delimiter = ',';
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream stream(line);
        std::string _city, _dump, _coffee, _cost;
        getline(stream, _city, delimiter);
        getline(stream, _dump, delimiter);
        getline(stream, _coffee, delimiter);
        getline(stream, _cost, delimiter);
        if (city == _city && coffee == _coffee) {
            return stoi(_cost);
        }
    }
    return -1;
}

int DatabaseHandler::getInstituteDinnerCost(const std::string &city, const std::string &institute) const {
    std::fstream fs;
    fs.open(this->institutePath, std::fstream::in);
    if(!fs.is_open()){
        throw std::invalid_argument("File with institute costs not found!");
    }
    std::string line;
    char delimiter = ',';
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream stream(line);
        std::string _city, _institute, _cost;
        getline(stream, _city, delimiter);
        getline(stream, _institute, delimiter);
        getline(stream, _cost, delimiter);
        if (city == _city && institute == _institute) {
            return stoi(_cost);
        }
    }
    return -1;
}

int DatabaseHandler::getTransportCost(const std::string &city, const std::string &homeAddress,
                                       const std::string &institute) const {
    std::fstream fs;
    fs.open(this->transportPath, std::fstream::in);
    if(!fs.is_open()){
        throw std::invalid_argument("File with transport costs not found!");
    }
    std::string line;
    char delimiter = ',';
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream stream(line);
        std::string _city, _homeAddress, _institute, _cost;
        getline(stream, _city, delimiter);
        getline(stream, _homeAddress, delimiter);
        getline(stream, _institute, delimiter);
        getline(stream, _cost, delimiter);
        if (city == _city && homeAddress == _homeAddress && institute == _institute) {
            return stoi(_cost);
        }
    }
    return -1;
}