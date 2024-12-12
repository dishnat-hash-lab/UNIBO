#include "database.h"

// Hardcoded coordinates for demo
std::map<std::string, std::pair<double, double>> locations = {
    {"Library", {29.974, 76.854}},
    {"Cafeteria", {29.975, 76.855}},
    {"Hostel", {29.973, 76.853}}
};

std::pair<double, double> Database::getCoordinates(const std::string& location) {
    if (locations.find(location) != locations.end()) {
        return locations[location];
    }
    return {};
}
