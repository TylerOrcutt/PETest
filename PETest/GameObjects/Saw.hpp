#ifndef __GAME_OBJECT_SAW_
#define __GAME_OBJECT_SAW_
#include <stdio.h>
#include <ParalyzedEngine/GameObjects/PEGameObjectController.hpp>
#include <stdlib.h>
class Saw:public PEGameObjectController {
public:
 int rots=1;
static PEGameObjectController * create(){return new Saw;}
Saw(){
 rots = rand()%20+1;
   if(rand()%2+1 == 1){
       rots=-rots;
   }
    }

void Update(){
  
    PEGameObjectController::Update();
    PEGameObjectController::rotation+=rots;
    //printf("saw updated\n");
 
    
 }


 };

 #endif