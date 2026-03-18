#include "Camera.h"

Camera::Camera(float _lag) {
    myView = View(FloatRect({ 0, 0 }, { win_width, win_height }));
    lag = _lag;
}

void Camera::updateCamera(GameObject* myObject) {
    center = { myObject->pos.x + myObject->size.x / 2, myObject->pos.y + myObject->size.y / 2 };

    center.x = std::max(int(win_width) / 2, std::min((int)center.x, level_size_width - win_width / 2));
    center.y = std::max(int(win_height) / 2 , std::min((int)center.y, level_size_heigt - win_height / 2));

    Vector2f current = myView.getCenter();
    current.x += (center.x - current.x) * lag;
    current.y += (center.y - current.y) * lag;

    myView.setCenter(current);
}

void Camera::setCamera(RenderWindow* window) {
    window->setView(myView);
}