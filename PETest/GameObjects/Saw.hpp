#ifndef __GAME_OBJECT_SAW_
#define __GAME_OBJECT_SAW_
#include <stdio.h>
#include <ParalyzedEngine/GameObjects/PEGameObjectController.hpp>

class Saw:public PEGameObjectController {
public:
static PEGameObjectController * create(){return new Saw;}
Saw(){

    }

void Update(){
    PEGameObjectController::Update();
    printf("hello from saw\n");
    
 }


 };

 #endif