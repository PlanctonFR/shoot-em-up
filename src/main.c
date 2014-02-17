/*
    This file is part of shoot-em-up.

    shoot-em-up is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    shoot-em-up is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with shoot-em-up.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
    main.c
    ------

    By Victor Bouvier-Deleau (PlanctonFR).

    Role: initializing the SDL and FMOD Ex libraries and launching the game
    menu.
*/

/* MinGW32 ============================================================= */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* SDL ================================================================= */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/* FMOD Ex ============================================================= */
#include <FMODEx/fmod.h>

/* Project ============================================================= */
#include "../inc/global.h"

int main(int argc, char** argv)
{
    /* INITIALIZATIONS ===================================================== */

    /* Initialize the random number generator  */

    srand((unsigned int)time(0));

    /* Charging sprites */

    SDL_Surface *icon = IMG_Load("res/icon/icon.png");

    /* Initialize the librairies */

    SDL_Window *window = NULL;

    TTF_Font *fontTitle = NULL;
    TTF_Font *fontText = NULL;

    FMOD_SYSTEM *system;
    FMOD_System_Create(&system);

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Couldn't initialize TTF: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    FMOD_System_Init(system, MAX_SOUND_CHANNELS, FMOD_INIT_NORMAL, NULL);

    /* Load the fonts */

    fontTitle = TTF_OpenFont("res/font/xirod.ttf", FONT_TITLE_SIZE);
    fontText = TTF_OpenFont("res/font/xirod.ttf", FONT_TEXT_SIZE);

    /* Set the window icon */

    SDL_SetWindowIcon(window, icon);

    /* Create the window */

    window = SDL_CreateWindow("shoot-em-up_Alpha0.01", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        fprintf(stderr, "Couldn't create a %d x %d window: %s\n", WINDOW_WIDTH,
                WINDOW_HEIGHT, SDL_GetError());
        exit(EXIT_FAILURE);
    }

    /* LAUNCH THE GAME ===================================================== */

    SDL_Delay(3000);
    //intro(screen);

    /* QUIT THE GAME ======================================================= */

    /* Close the devices */

    FMOD_System_Close(system);
    FMOD_System_Release(system);

    TTF_CloseFont(fontText);
    TTF_CloseFont(fontTitle);
    TTF_Quit();

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
