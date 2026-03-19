#include "Camera.h"
#include <iostream>

Camera::Camera(float _lag) {
    myView = sf::View(sf::FloatRect({ 0, 0 }, { win_width, win_height }));
    lag = _lag;
}

void Camera::updateCamera(GameObject* myObject) {
    center = { myObject->pos.x + myObject->size.x / 2, myObject->pos.y + myObject->size.y / 2 };

    if (myObject->pos.x <= level_size_width / 3.f ) {  // 1920*1080
        center.x = std::clamp(center.x, (float)win_width / 2.0f, (float)level_size_width / 3.0f - (float)win_width / 2.0f);
        center.y = std::clamp(center.y, (float)win_height / 2.0f, (float)level_size_heigt / 4.f - (float)win_height / 2.0f);
    }
	else if (myObject->pos.x >= level_size_width / 3.f && myObject->pos.x <= level_size_width / 1.5f) { // 3840*1080
        center.x = std::clamp(center.x, (float)level_size_width / 3.0f + (float)win_width / 2.0f, (float)level_size_width / 1.5f - (float)win_width / 2.0f);
        center.y = std::clamp(center.y, (float)win_height / 2.0f, (float)level_size_heigt / 4.f - (float)win_height / 2.0f);
    }
    else if (myObject->pos.x >= level_size_width / 1.5f && myObject->pos.y <= level_size_heigt / 2.f ) {
        center.x = std::clamp(center.x, (float)level_size_width / 1.5f + (float)win_width / 2.0f, (float)level_size_width - (float)win_width / 2.0f); // 5760*2160
        center.y = std::clamp(center.y, (float)win_height / 2.0f, (float)level_size_heigt / 2.f - (float)win_height / 2.0f);
    }
    else if ((myObject->pos.y + myObject->size.y) >= level_size_heigt / 2.f ) { // 5760*4320
        center.x = std::clamp(center.x, (float)win_width / 2.0f, (float)level_size_width / 3.f - (float)win_width / 2.0f);
        center.y = std::clamp(center.y, (float)win_height / 2.0f, (float)level_size_heigt - (float)win_height / 2.0f);
    }

   /* center.x = std::max(int(win_width) / 2, std::min((int)center.x, level_size_width - win_width / 2));
    center.y = std::max(int(win_height) / 2 , std::min((int)center.y, level_size_heigt - win_height / 2));*/

    sf::Vector2f current = myView.getCenter();
    current.x += (center.x - current.x) * lag;
    current.y += (center.y - current.y) * lag;

    myView.setCenter(current);


}

void Camera::setCamera(sf::RenderWindow* window) {
    window->setView(myView);
}


void Camera::camHUD(sf::RenderWindow* window){
    window->setView(window->getDefaultView());
}

void Camera::getCameraPos(sf::Vector2f& _pos) const {
    _pos = myView.getCenter();
}
