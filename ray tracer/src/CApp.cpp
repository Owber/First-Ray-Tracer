#include "CApp.h"

//The constructor
CApp::CApp(){

    isRunning = true;
    pWindow = NULL;
    pRenderer = NULL;
}

bool CApp::OnInit(){

    if (SDL_Init(SDL_INIT_VIDEO) == 0){
        return false;
    }

    pWindow = SDL_CreateWindow("First Try Ray Tracer", 1280, 720, 0);

    if (pWindow != NULL){
        pRenderer = SDL_CreateRenderer(pWindow, NULL);
    }
    else{
        return false;
    }

    return true;
}

int CApp::OnExecute(){
    SDL_Event event;

    if (OnInit() == false){
        return -1;
    }

    while(isRunning){
        while (SDL_PollEvent(&event) != 0){
            OnEvent(&event);
        }

        OnLoop();
        OnRender();

 
    }
    return 0;
}

void CApp:: OnEvent(SDL_Event *event){
    if (event -> type == SDL_EVENT_QUIT){
        isRunning = false;
    }
}

void CApp:: OnLoop(){

}

void CApp:: OnRender(){
    //Set background colour to white.
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pRenderer);

    //Show results on screen.
    SDL_RenderPresent(pRenderer);
}

void CApp:: OnExit(){
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    pWindow = NULL;
    SDL_Quit();
}

