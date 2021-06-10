#include "zos/zos_from_c.h"
#include "SDL.h"

/**
 * This file only exists for testing the application on windows. Within
 * ZenithOS you can run the appropriate start file for the game.
 */

something text;

int main(int argc, char* argv[])
{
    // Emulate the Zenith framebuffer.
    text.fb_alias = CAlloc(1, GR_WIDTH * GR_HEIGHT * sizeof(CBGR24));

    // Draw a test line
    I64 i, j;
    CBGR24 cRed;
    cRed.b = cRed.g = 0;
    cRed.r = 255;

    for (i = 0; i < GR_HEIGHT; i++)
    {
        text.fb_alias[GR_WIDTH * i + i] = cRed;
    }

    // Configure SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Zenith DOOM",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GR_WIDTH, GR_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture* framebuffer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_BGRA32,
        SDL_TEXTUREACCESS_STATIC, GR_WIDTH, GR_HEIGHT);

    // Event system
    SDL_Event event;
    int gameover = 0;

    while (!gameover)
    {
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                gameover = 1;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                case SDLK_q:
                    gameover = 1;
                    break;
                }
                break;
            }
        }

        // Copy framebuffer to window
        SDL_UpdateTexture(framebuffer, NULL, text.fb_alias, GR_WIDTH *
            sizeof(CBGR24));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, framebuffer, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(framebuffer);
    SDL_Quit();

    return 0;
}