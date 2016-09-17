#pragma once
#include "camera.h"
#include <ParalyzedEngine/Map/Map.hpp>
class TwoDTest{
PETexture * sp1;
PETexture * charsheet;
  PEShaderProgram program;
Camera * cam;
float px=100,py=100;
PEWindow* pe;
bool mu=false,md=false,mw=false,me=false;
PEMap map;
public:
TwoDTest(PEWindow* _pe, std::string mapfile){
    cam = new Camera(0,0);
pe= _pe;
if(PE_load_shaderProgram(&program,PE_default_vertexShader2D(),PE_default_fragmentShader2D())<0){
  std::cout<<"failed to load shader program\n";
  return ;
}
//#MARK - load map and assests
std::cout<<"loading map\n";
 std::string mapdata = map.load_map(mapfile.c_str());
 std::cout<<"parseing map file\n";
 unsigned long ct= Helper::getTime();
map.parseMap(mapdata);
std::cout<<"Took "<< miliToTime(Helper::getTime()-ct)<<"\n";
std::cout<<"loading assests\n";


 sp1 =PE_load_texture("./images/sp2.png");
 charsheet =PE_load_texture("./images/charsheet.png");
if(sp1==NULL){
   std::cout<<"Failed to load texture\n";
}
std::cout<<"Texture ID: "<<sp1->textureID<<std::endl;
PE_init_sprite_renderer(&program);



}
void Render(){
  glUseProgram(program.programID);
 if(mu){
                  py-=5;
                      if(py<=(*cam).getY()+32){
                    (*cam).setY((*cam).getY()-5);
                  }
                }
                if(md){
                  py+=5;
                    if(py>=(*cam).getY()+pe->gwa.height-96){
                    (*cam).setY((*cam).getY()+5);
                  }
                }
                if(mw){
                  px-=5;
                  if(px<=(*cam).getX()+32){
                    (*cam).setX((*cam).getX()-5);
                  }
                }
                if(me){
                  px+=5;
                       if(px>=(*cam).getX()+pe->gwa.width-96){
                    (*cam).setX((*cam).getX()+5);
                  }
                }

                  glBindTexture(GL_TEXTURE_2D,sp1->textureID);
   std::vector <PEBlock>* blocks = map.getBlocks();
   if(blocks!=nullptr){
     for(int i=0;i<blocks->size();i++){
       PEBlock blk = (*blocks)[i];
 
    // PE_draw_rect(blk.x,blk.y,blk.width,blk.height);
     PE_draw_sprite(sp1,blk.x-(*cam).getX(),blk.y-(*cam).getY(),blk.width,blk.height,blk.imgx,blk.imgy,32,32);
     }
   }

     PE_draw_sprite(charsheet,px-(*cam).getX(),py-(*cam).getY(),64,64 ,1,0,32,32);
}



std::string miliToTime(unsigned long ms){
  int sec=0;
  int min=0;
  if(ms%1000>0){
      sec=floor(ms/1000);
       ms%=1000;
  }
 std::stringstream ss;
 ss<<"0:"<<sec<<"."<<ms;
 return ss.str(); 
}
 void keyPress(int key){
 // std::cout<<"KeyPress callBack " <<key<<"\n";
  if(key=='w'){
    mu=true;
  }
    if(key=='s'){
    md=true;
  }
     if(key=='d'){
    me=true;
  }
     if(key=='a'){
    mw=true;
  }
}
void keyRelease(int key){
  //std::cout<<"KeyRlease callBack"<<key<<"\n";
   if(key==25){
   mu=false;
   }

    if(key==39){
    md=false;
  }
       if(key==40){
    me=false;
  }
     if(key==38){
    mw=false;
  }
}
};