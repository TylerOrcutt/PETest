#pragma once

class Camera{
private:
float x=0,y=0, width=800, height=600;
public:
Camera(float,float);
float getX();
float getY();
void move(float,float);
void resize(float,float);
void setX(float);
void setY(float);

};