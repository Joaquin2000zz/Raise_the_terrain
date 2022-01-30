#ifndef _DEMO_H_
#define _DEMO_H_

#include <SLD2/SDL.h>

typedef struct SDL_Istance
{
    SDL_Window *window;
    SLD_Render *render;
} SLD_Instance;

init init_instance(SDL_Instance *);

#endif
