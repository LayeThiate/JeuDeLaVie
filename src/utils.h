#ifndef __UTILS__
#define __UTILS__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*! Possible state of a cell
 * 
 */
typedef enum { LIVE, DEATH} State;

/*! \brief Initialize a state array
 * This function allocate and initialize a state array with random value
 */
State **init_array(int width, int height);

/*! Display a state array
 *  Display '*' for lived cell and '-' for dead cell
 */
void display_array(State** array, int width, int height);

/*! Free the memory allocated to a state array

*/
void free_array(State** array, int height);

/*! Launh infinitly the game of life
 * 
 */
void play_game(State** array, int width, int height, unsigned int refresh_time);

#endif