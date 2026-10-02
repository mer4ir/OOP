#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include <iostream>

class Truck {
private:
    std::string model;
    double engineVolume; 
    double tonnage;     

public:
    Truck();
    Truck(const std::string& model, double engineVolume, double tonnage);

    std::string getModel() const;
    double getEngineVolume() const;
    double getTonnage() const;

    double calculateTax(double baseRate) const;

    friend std::ostream& operator<<(std::ostream& os, const Truck& truck);
};

#endif 