#define GLEW_STATIC
#include <iostream>
#include <string>
#include<X11/X.h>
#include<X11/Xlib.h>
 #include<GL/glew.h>
#include<GL/gl.h>
#include<GL/glx.h>

 

#include <ParalyzedEngine/ParalyzedEngine.h>
#include <ParalyzedEngine/SpriteRenderer.h>
#include <ParalyzedEngine/Network/WebClient.h>
#include <ParalyzedEngine/Shaders/ShaderProgram.h>
#include <ParalyzedEngine/Texture.h>
#include <ParalyzedEngine/Map/Map.hpp>

#include "camera.h"
bool devMode=false;
PEMap map;
bool mu=false,md=false,mw=false,me=false;
void handleArgs(int, char **);

void keyPress(int key){
  std::cout<<"KeyPress callBack " <<key<<"\n";
  if(key==25){
    mu=true;
  }
    if(key==39){
    md=true;
  }
     if(key==40){
    me=true;
  }
     if(key==38){
    mw=true;
  }
}
void keyRelease(int key){
  std::cout<<"KeyRlease callBack"<<key<<"\n";
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

int main(int args,char *argv[]){
XEvent                  xev;
    if(args>1){
        handleArgs(args,argv);
    }
std::cout<<"Engine version: " <<PE_ENGINE_VERSION<<std::endl;



PEWindow *pe;
 
Camera cam(0,0);
PECookie cookie;
init_PECookie(&cookie);
//PE_HTTPSRequest("rustednail.ddns.net","serverlist",&cookie,"test=test");
 
  if(devMode){
  pe= createPEWindow(800,600,"PE Map Test DeveloperMode");
  }else{
   pe= createPEWindow(800,600,"PE Map Test");
     } 

PE_window_set_onKeyPress(pe, keyPress);
PE_window_set_onKeyRelease(pe, keyRelease);
   //load shaders
   PEShaderProgram program;
PE_init_shaderProgram(&program);

if(PE_load_shaderProgram(&program,PE_default_vertexShader2D(),PE_default_fragmentShader2D())<0){
  std::cout<<"failed to load shader program\n";
  return -1;
}

PETexture * sp1 =PE_load_texture("./images/sp2.png");
PETexture * charsheet =PE_load_texture("./images/charsheet.png");
if(sp1==NULL){
   std::cout<<"Failed to load texture\n";
}
std::cout<<"Texture ID: "<<sp1->textureID<<std::endl;
  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
             glOrtho(0, pe->gwa.width, pe->gwa.height,0, 0,50);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
 
	  glEnableClientState(GL_VERTEX_ARRAY);
	 	glEnable(GL_DEPTH_TEST);

	  glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
//test Webrequest

PE_init_sprite_renderer(&program);
float px=100,py=100;
   
   
             glClearColor(0.0,0.0, 0.0, 1.0);
  while(pe->WINDOW_CLOSING== PE_FALSE) {


     
    
 	            getNextEvent(pe, &xev);

                if(mu){
                  py-=5;
                      if(py<=cam.getY()+32){
                    cam.setY(cam.getY()-5);
                  }
                }
                if(md){
                  py+=5;
                    if(py>=cam.getY()+pe->gwa.height-96){
                    cam.setY(cam.getY()+5);
                  }
                }
                if(mw){
                  px-=5;
                  if(px<=cam.getX()+32){
                    cam.setX(cam.getX()-5);
                  }
                }
                if(me){
                  px+=5;
                       if(px>=cam.getX()+pe->gwa.width-96){
                    cam.setX(cam.getX()+5);
                  }
                }



              	XGetWindowAttributes(pe->dpy, pe->win, &pe->gwa);
               glViewport(0, 0, pe->gwa.width, pe->gwa.height);
       glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
             glOrtho(0, pe->gwa.width, pe->gwa.height,0, 0,50);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glColor3f(0,1,0);
                  glBindTexture(GL_TEXTURE_2D,sp1->textureID);
   std::vector <PEBlock>* blocks = map.getBlocks();
   if(blocks!=nullptr){
     for(int i=0;i<blocks->size();i++){
       PEBlock blk = (*blocks)[i];
 
    // PE_draw_rect(blk.x,blk.y,blk.width,blk.height);
     PE_draw_sprite(sp1,blk.x-cam.getX(),blk.y-cam.getY(),blk.width,blk.height,blk.imgx,blk.imgy,32,32);
     }
   }

     PE_draw_sprite(charsheet,px-cam.getX(),py-cam.getY(),64,64,1,0,32,32);
                // PE_draw_rect(64,64,32,32);
                   
                // PE_draw_sprite(sp1,128,128,640,480,2,0,32,32);
                       glXSwapBuffers(pe->dpy, pe->win);


    
 } /* this closes while(1) { */
 
//      	glXMakeCurrent(pe->dpy, None, NULL);
 		glXDestroyContext(pe->dpy, pe->glc);
 		XDestroyWindow(pe->dpy, pe->win);
 		XCloseDisplay(pe->dpy);
 		exit(0);

}

void handleArgs(int args,char * argv[]){
     if(args>1 && std::string(argv[1])=="-dev"){
        std::cout<<"Enabling developer mode.\n";

      devMode=true;
    }
    if(devMode && args>3 ){
        if(std::string(argv[2])=="-m"){
           std::cout<<"Loading map: "<<argv[3]<<"\n";
           
           map.load_map(argv[3]);
        }
    }
}

