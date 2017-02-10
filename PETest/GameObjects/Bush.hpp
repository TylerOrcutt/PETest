#ifndef __GAME_OBJECT_BUSH_
#define __GAME_OBJECT_BUSH_
#include <stdio.h>
#include <ParalyzedEngine/GameObjects/PEGameObjectController.hpp>

class Bush:public PEGameObjectController {
public:
static PEGameObjectController * create(){return new Bush;}
Bush(){

    }

void Update(){
    PEGameObjectController::Update();
    printf("hello from bush\n");
    
 }


 };

 #endif
