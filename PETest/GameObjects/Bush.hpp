#ifndef __GAME_OBJECT_BUSH_
#define __GAME_OBJECT_BUSH_
#include <stdio.h>
#include <ParalyzedEngine/GameObjects/PEGameObjectController.hpp>
#include <stdlib.h>
class Bush:public PEGameObjectController {
public:
float speed=.01f;
static PEGameObjectController * create(){return new Bush;}
Bush(){
speed=rand()%5; 

    }

void Update(){
    PEGameObjectController::Update();
     PEGameObjectController::x+=speed;
    
 }


 };

 #endif
