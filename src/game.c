#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"


int main(int argc, char* argv[])
{
  if(argc < 4)
  {
    printf("Usage : ./game <width> <height> <refresh_timer>\n");
    printf("./game 10 8 3\n");
    exit(EXIT_FAILURE);
  }

  srand(time(NULL));

  int width = atoi(argv[1]);
  int height = atoi(argv[2]);
  unsigned int timer = atoi(argv[3]);
  State **array = init_array(width, height);
  play_game(array, width, height, timer);

  free_array(array, height);

  return 0;
}