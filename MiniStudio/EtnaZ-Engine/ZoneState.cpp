#include "ZoneState.h"

ZoneState::ZoneState(Parallax* _parallax) : parallax(_parallax) {
}

ZoneState::~ZoneState() {
}

void ZoneState::addZone(sf::FloatRect zRect, Parallax::zone pZone, const std::string& roomFile) {
    zones.push_back({ zRect, pZone, roomFile });
}

bool ZoneState::updateZone(float playerX, float playerY) {
    sf::Vector2f playerPos = { playerX, playerY };

    for (auto& zone : zones) {
        if (zone.zRect.contains(playerPos)) {
            if (zone.parallaxZone == myZone) return false; 

            myZone = zone.parallaxZone;
            myRoomFile = zone.roomFile;
            parallax->loadZone(myZone);
            return true;
        }
    }
    return false;
}
