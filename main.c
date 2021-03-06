#include "main.h"

int main(void)
{
    SDL_Instance instance;

    if (init_instance(&instance) != 0)
        return (1);
    /*
     * C will always be awesome
     * This is an infinite loop
     */
    while ("C is awesome")
    {
        SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
        SDL_RenderClear(instance.renderer);
        /* poll event used to stop to stop the while */
        if (poll_events() == 1)
            break;
        /* function that draw some stuff */
        draw_stuff(instance);
        SDL_RenderPresent(instance.renderer);
    }
    return (0);
}

void draw_stuff(SDL_Instance instance)
{
    SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(instance.renderer, 10, 10, 100, 100);
}

int poll_events()
{
    SDL_Event event;
    SDL_KeyboardEvent key;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                return (1);
            case SDL_KEYDOWN:
                key = event.key;
                /* If 'ESCAPE' is pressed */
                if (key.keysym.scancode == 0x29)
                    return (1);
                break;
        }
    }
    SDL_DestroyRenderer(instance.renderer);
    SDL_DestroyWindow(instance.window);
    SDL_Quit();
    return (0);
}
