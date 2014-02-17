/**
 *  This file is part of shoot-em-up.
 *
 *  shoot-em-up is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  any later version.
 *
 *  shoot-em-up is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with shoot-em-up.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 *  global.h
 *  --------
 *
 *  By Victor Bouvier-Deleau (PlanctonFR).
 *
 *  Role: defining the global variables.
 */

#ifndef DEF_GLOBAL
#define DEF_GLOBAL

    #define MAX_SOUND_CHANNELS 32
    #define WINDOW_WIDTH 1280
    #define WINDOW_HEIGHT 720
    #define COLOR_DEPTH 32
    #define FONT_TITLE_SIZE 48
    #define FONT_TEXT_SIZE 24

    #define PLAYER_SHOTS_SPEED 30
    #define PLAYER_RESPAWN_TIME 100

    enum{UP, DOWN, LEFT, RIGHT};

#endif
