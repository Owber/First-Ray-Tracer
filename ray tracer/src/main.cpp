#include "CApp.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


int main(int argc, char* argv []){
    CApp theApp;
    return theApp.OnExecute();
}