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
bool devMode=false;
void handleArgs(int, char **);
int main(int args,char *argv[]){
XEvent                  xev;
    if(args>1){
        handleArgs(args,argv);
    }
std::cout<<"Engine version: " <<PE_ENGINE_VERSION<<std::endl;

PEWindow *pe;

//std::cout<<PE_default_vertexShader()<<std::endl;
//std::cout<<PE_default_fragmentShader()<<std::endl;


PECookie cookie;
init_PECookie(&cookie);

//PE_HTTPSRequest("rustednail.ddns.net","serverlist",&cookie,"test=test");
  if(devMode){
  pe= createPEWindow(800,600,"PE Map Test DeveloperMode");
  }else{
   pe= createPEWindow(800,600,"PE Map Test");
     } 


   //load shaders
   PEShaderProgram program;
PE_init_shaderProgram(&program);

if(PE_load_shaderProgram(&program,PE_default_vertexShader(),PE_default_fragmentShader())<0){
  std::cout<<"failed to load shader program\n";
  return -1;
}

PETexture * sp1 =PE_load_texture("../images/test/sp2.png");
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

PE_Sprite_Renderer_init(&program);

   
   
             glClearColor(0.0,0.0, 0.0, 1.0);
  while(1) {


     
    
 	            getNextEvent(pe, &xev);
              	XGetWindowAttributes(pe->dpy, pe->win, &pe->gwa);
               glViewport(0, 0, pe->gwa.width, pe->gwa.height);
       glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
             glOrtho(0, pe->gwa.width, pe->gwa.height,0, 0,50);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
              
                  glBindTexture(GL_TEXTURE_2D,sp1->textureID);
                 PE_Sprite_Draw(64,64,32,32);
                         glBindTexture(GL_TEXTURE_2D,1);
                 PE_Sprite_Draw(128,128,64,64);
                       glXSwapBuffers(pe->dpy, pe->win);


    
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

