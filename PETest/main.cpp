#include <iostream>
#include <string>
#include<X11/X.h>
#include<X11/Xlib.h>
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glu.h>
#include <ParalyzedEngine/ParalyzedEngine.h>
#include <ParalyzedEngine/ParalyzedEngineSpriteRenderer.h>
#include <ParalyzedEngine/Network/WebClient.h>
bool devMode=false;
void handleArgs(int, char **);
int main(int args,char *argv[]){
XEvent                  xev;
    if(args>1){
        handleArgs(args,argv);
    }
    ParalyzedEngineTest();
PE_Sprite_Renderer_init();
PECookie cookie;
init_PECookie(&cookie);
  PEWindow *pe;
//PE_HTTPSRequest("rustednail.ddns.net","serverlist",&cookie,"test=test");
  if(devMode){
  pe= createPEWindow(800,600,"RusticValley DeveloperMode");
  }else{
   pe= createPEWindow(800,600,"RusticValley");

  } 
  while(1) {


     
    
 	        getNextEvent(pe, &xev);
              	XGetWindowAttributes(pe->dpy, pe->win, &pe->gwa);
                glViewport(0, 0, pe->gwa.width, pe->gwa.height);
                  glClearColor(0.0, 0.0, 0.0, 1.0);
                   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
    
 } /* this closes while(1) { */
      	glXMakeCurrent(pe->dpy, None, NULL);
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
}

