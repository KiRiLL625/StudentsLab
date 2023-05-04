//
// Created by user on 19.04.2023.
//
#include <string>

#ifndef STUDENTS_LAB_DATABASEHANDLER_H
#define STUDENTS_LAB_DATABASEHANDLER_H

typedef unsigned int uint;

class DatabaseHandler{
private:
	std::string costsPath;
	std::string transportPath;
	std::string institutePath;
	std::string cafeAndCinemaPath;
public:
    DatabaseHandler();
	DatabaseHandler(const std::string& costsPath, const std::string& transportPath, const std::string& institutePath,
					const std::string& cafeAndCinemaPath);
	bool initDatabase() const;
	int getOtherMonthlyCosts(const std::string& city, uint age) const;
	int getHomeFoodCost(const std::string& city) const;
	int getCinemaCost(const std::string& city, const std::string& cinema) const;
	int getCoffeeCost(const std::string& city, const std::string& coffee) const;
	int getInstituteDinnerCost(const std::string& city, const std::string& institute) const;
	int getTransportCost(const std::string& city, const std::string& homeAddress,
                      const std::string& institute) const;
};

#endif //STUDENTS_LAB_DATABASEHANDLER_H