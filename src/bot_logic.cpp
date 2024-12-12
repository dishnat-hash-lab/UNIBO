#include "bot_logic.h"
#include "pathfinding.h"
#include "database.h"

std::string BotLogic::handleUserMessage(const std::string& message) {
    Database db;
    PathFinding pathFinder;

    size_t delimiter = message.find('-');
    if (delimiter == std::string::npos) {
        return "⚠️ Invalid input! Please use the format `start-end` (e.g., Library-Cafeteria).";
    }

    std::string start = message.substr(0, delimiter);
    std::string end = message.substr(delimiter + 1);

    auto startCoords = db.getCoordinates(start);
    auto endCoords = db.getCoordinates(end);

    // if (startCoords == std::make_pair(0.0, 0.0) || endCoords == std::make_pair(0.0, 0.0)) {
    //     return "⚠️ Invalid locations! Please check your input.";
    // }

    auto route = pathFinder.findShortestPath(startCoords, endCoords);
    double distance = pathFinder.calculateDistance(route);

    // Google Maps link
    std::string googleMapsLink = "https://www.google.com/maps/dir/" +
                                  std::to_string(startCoords.first) + "," + std::to_string(startCoords.second) + "/" +
                                  std::to_string(endCoords.first) + "," + std::to_string(endCoords.second);

    std::string response = "Shortest route: ";
    for (const auto& point : route) {
        response += point + " -> ";
    }
    response += "\nTotal distance: " + std::to_string(distance) + " km\n";
    response += "For directions, click here: " + googleMapsLink;

    return response;
}


std::vector<std::string> funMessages = {
    "🚶 Walking is great for health! Keep exploring.",
    "✨ Did you know? This campus has 200+ acres of greenery!",
    "🎓 Fun fact: The library has over 1 lakh books!"
};

std::string randomFunMessage = funMessages[rand() % funMessages.size()];


