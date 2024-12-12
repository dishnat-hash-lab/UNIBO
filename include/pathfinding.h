#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <vector>
#include <string>

class PathFinding {
public:
    std::vector<std::string> findShortestPath(const std::pair<double, double>& start, const std::pair<double, double>& end);
    double calculateDistance(const std::vector<std::string>& route);
};

#endif
