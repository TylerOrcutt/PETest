#include "camera.h"

Camera::Camera(float _x, float _y){
x=_x;
y=_y;
}
float Camera::getX(){
    return x;
}
float Camera::getY(){
    return y;
}

void Camera::move(float _x,float _y){
    x=_x;
    y=_y;
}

void Camera::resize(float w,float h){
    
    width=w;
    height=h;
}
void Camera::setX(float _x){
    x=_x;
}
void Camera::setY(float _y){
    y=_y;
}