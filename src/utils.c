#include "utils.h"

State **init_array(int width, int height)
{
    if (width < 3 || height < 3)
    {
        printf("the dimensions must be greater or equal than 3x3");
        return NULL;
    }

    State **array = NULL;

    array = malloc(sizeof(State *) * height);
    if (array == NULL)
    {
        printf("the array can't be allocated");
        return NULL;
    }

    // Allocate and initialize each cell with a random value
    for (int i = 0; i < height; i++)
    {
        array[i] = malloc(sizeof(State) * width);
        if (array[i] != NULL)
        {
            for (int j = 0; j < width; j++)
            {
                array[i][j] = (State)(rand() % 2);
            }
        }
    }

    return array;
}

void display_array(State **array, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            switch (array[i][j])
            {
            case LIVE:
                printf("*  ");
                break;
            case DEATH:
                printf("-  ");
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
}

void play_game(State **array, int width, int height, unsigned int refresh_time)
{
    int iteration = 1;
    while (1)
    {
        printf("\n\n%de iteration\n", iteration);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int neighbor_living = neighbors_living(array, width, height, i, j);
                if (neighbor_living == 3)
                {
                    array[i][j] = LIVE;
                }
                else if (neighbor_living < 2 || neighbor_living > 3)
                {
                    array[i][j] = DEATH;
                }
            }
        }

        sleep(refresh_time);
        display_array(array, width, height);
        iteration++;
    }
}

void free_array(State **array, int height)
{
    for (int i = 0; i < height; i++)
    {
        free(array[i]);
    }
    free(array);
}

/*! Count the number of living neighbor of the cell in case (i, j)
 * 
 */
int neighbors_living(State **array, int width, int height, int i, int j)
{
    int neighbors[8];
    neighbors[0] = array[(i - 1 + height) % height][j];                       // top
    neighbors[1] = array[(i + 1 + height) % height][j];                       // bottom
    neighbors[2] = array[i][(j - 1 + width) % width];                         // left
    neighbors[3] = array[i][(j + 1 + width) % width];                         // right
    neighbors[4] = array[(i - 1 + height) % height][(j - 1 + width) % width]; // left top
    neighbors[5] = array[(i - 1 + height) % height][(j + 1 + width) % width]; // right top
    neighbors[6] = array[(i + 1 + height) % height][(j - 1 + width) % width]; // left bottom
    neighbors[7] = array[(i + 1 + height) % height][(j + 1 + width) % width]; // right bottom

    int neighbor_living = 0;
    for (int i = 0; i < 8; i++)
    {
        if (neighbors[i] == LIVE)
        {
            neighbor_living++;
        }
    }

    return neighbor_living;
}