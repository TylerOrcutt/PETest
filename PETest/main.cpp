#define GLEW_STATIC
#include <iostream>
#include <string>
#include <sstream>
#include<X11/X.h>
#include<X11/Xlib.h>
 #include<GL/glew.h>
#include<GL/gl.h>
#include<GL/glx.h>

 #include <time.h>
#include <limits.h>
#include <math.h>
#include <ParalyzedEngine/ParalyzedEngine.h>
#include <ParalyzedEngine/SpriteRenderer.h>
#include <ParalyzedEngine/Network/WebClient.h>
#include <ParalyzedEngine/Shaders/ShaderProgram.h>
#include <ParalyzedEngine/Texture.h>
#include <ParalyzedEngine/Map/Map.hpp>
#include <ParalyzedEngine/TextRenderer.h>
#include "camera.h"
#include "Helper.hpp"
#include "ThreeDTest.hpp"
#include "TwoDTest.hpp"
bool devMode=false;

std::string mapfile;
bool threedtest=false;
TwoDTest* twoD;
ThreeDTest *threeD;
int frames=0;
int fps=0;
unsigned long lastupdate=0;
void handleArgs(int, char **);
void keyRelease(int key){
   if(!threedtest){
   twoD->keyRelease(key);
 }
}
void keyPress(int key){
     if(!threedtest){
   twoD->keyPress(key);
 }
}

int main(int args,char *argv[]){
XEvent                  xev;
    if(args>1){
        handleArgs(args,argv);
    }
std::cout<<"Engine version: " <<PE_ENGINE_VERSION<<std::endl;



PEWindow *pe;
 

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
 if(!threedtest){
   twoD = new TwoDTest(pe,mapfile);
 }else{
   threeD = new ThreeDTest(pe);
 }

   
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
         // glOrtho(0, pe->gwa.width, pe->gwa.height,0, 0,50);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
 
	  glEnableClientState(GL_VERTEX_ARRAY);
	 //	glEnable(GL_DEPTH_TEST);

	  glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
//test Webrequest

PEShaderProgram  guiShaders;
if(PE_load_shaderProgram(&guiShaders,PE_default_vertexShader2D(),PE_default_fragmentShader2D())<0){
  std::cout<<"failed to load shader program\n";
  return 0;
}
PE_init_sprite_renderer(&guiShaders);
PEFont *font = PE_TextRenderer_init("fonts/DejaVuSans.ttf",16);

 
   
             glClearColor(0.0,0.0, 0.0, 1.0);
  while(pe->WINDOW_CLOSING== PE_FALSE) {


              	XGetWindowAttributes(pe->dpy, pe->win, &pe->gwa);
               glViewport(0, 0, pe->gwa.width, pe->gwa.height);
       glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if(!threedtest){
             glOrtho(0, pe->gwa.width, pe->gwa.height,0, 0,50);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glColor3f(0,1,0);
     
    
 	            getNextEvent(pe, &xev);
 glUseProgram(0);
 glPushMatrix();
                if(!threedtest){

                 twoD->Render();
               }else{
                 threeD->Render();
               }
 glColor4f(1,0,0,1);
  frames++;
  unsigned long ct = Helper::getTime();
  if(ct-lastupdate>=1000){
    
  fps=frames;
      frames=0;
      lastupdate=ct;
  }
      std::stringstream ss;
      ss<<"FPS:"<<fps;

       glViewport(0, 0, pe->gwa.width, pe->gwa.height);
       glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
            glOrtho(0, pe->gwa.width, pe->gwa.height,0, 0,50);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
     glUseProgram(guiShaders.programID);
   PE_Render_Text(font,ss.str().c_str(),pe->gwa.width-75,25);
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
            mapfile = argv[3];
        //   map.load_map(argv[3]);
        }

        
    } else if(devMode && args>2){
          if(std::string(argv[2])=="-3d"){
            threedtest=true;
            std::cout<<"running 3d test\n";
        //   map.load_map(argv[3]);
        }
    }

}

