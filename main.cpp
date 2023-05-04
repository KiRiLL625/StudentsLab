#include <iostream>
#include "InputFunctions.h"
#include "DatabaseHandler.h"

int main(){
    DatabaseHandler data = DatabaseHandler();
    std::string name = getName();
    uint age = getAge();
    std::string city = getCity();
    std::string homeAddress = getAddress();
    std::string institute = getInstitute();
    std::string caffe = getCoffee();
    std::string cinema = getCinema();
    uint month = getMonth();
    //Student student = Student();
    Student student = Student(age, name, city, homeAddress, institute);
    student.introducing();
    std::cout << "Costs for " << month << " month: " << student.getCosts(data, month, caffe, cinema) << std::endl;
    return 0;
}