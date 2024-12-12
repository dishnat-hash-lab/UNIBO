#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <map>
#include <utility>

class Database {
public:
    std::pair<double, double> getCoordinates(const std::string& location);
};

#endif
