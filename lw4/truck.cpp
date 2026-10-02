#include "truck.h"

Truck::Truck() : model("Unknown"), engineVolume(0), tonnage(0) {}

Truck::Truck(const std::string& model, double engineVolume, double tonnage)
    : model(model), engineVolume(engineVolume), tonnage(tonnage) {}

std::string Truck::getModel() const {
    return model;
}

double Truck::getEngineVolume() const {
    return engineVolume;
}

double Truck::getTonnage() const {
    return tonnage;
}

double Truck::calculateTax(double baseRate) const {
    return baseRate * engineVolume * (tonnage / 2.0 + 1);
}

std::ostream& operator<<(std::ostream& os, const Truck& truck) {
    os << truck.model << " (" << truck.engineVolume << " л, " << truck.tonnage << " т)";
    return os;
}