#include "database.h"

// Hardcoded coordinates for demo
std::map<std::string, std::pair<double, double>> locations = {
    {"Library", {29.974, 76.854}},
    {"Cafeteria", {29.975, 76.855}},
    {"Hostel", {25.973, 78.853}}
};

// Initialize edges
std::vector<std::tuple<std::string, std::string, double>> edges = {
    {"Library", "Cafeteria", 0.1},
    {"Cafeteria", "Hostel", 2.0},
    // {"Library", "Hostel", 2.5}
};

std::pair<double, double> Database::getCoordinates(const std::string& location) {
    if (locations.find(location) != locations.end()) {
        return locations[location];
    }
    return {};
}
