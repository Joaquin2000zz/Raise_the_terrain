#include "main.h"

int init_instance(SDL_Instance *instance)
{
    /* Initialie SDL */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return (1);
    }
    /* Create a new Window instance */
    instance->window = SDL_CreateWindow("SDL \\o/", SDL_WUBDIWPOS_CENTERED,        SDL_WINDOWPOS_CENTERED, 1260, 720,0);
    if (!instance->window)
    {
            fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
            SDL_Quit();
            return (1);
    }
    /* Create a new Renderer instance linked to the Window */
    instance->renderer = SDL_CreateRenderer(instance->window, -1,
        SDL_RENDERER_ACCELERAED | SDL_RENDERER_PRESENTVSYNC);
    if (!instance->renderer)
    {
        SDL_DestroyWindow(instance->window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }
    return (0);
}
