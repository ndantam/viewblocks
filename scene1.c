#include "viewblocks.h"
#include <unistd.h>




int main( int argc, char **argv)
{

    double red[4] = {1,0,0,1};

    double goal_color[4] = {0,1,0,1};
    double robot_color[4] = {.5,.5,.5,1};
    double obstacle_color[4] = {0,0,0,1};
    double box_color[4] = {1,0,0,1};

    struct blocks_view *viewer = blocks_view_create();

    blocks_view_border( viewer, -4, 4, -4, 4 );


    /* Goal */
    blocks_view_add_cell( viewer, "goal", 0, 0, goal_color);

    /* Robot */
    blocks_view_add_cylinder( viewer, "robot", -3, 3, robot_color);

    /* Fixed Obstacles */
    blocks_view_add_block( viewer, "obstacle-1", 1, 1, obstacle_color);
    blocks_view_add_block( viewer, "obstacle-2", 2, 0, obstacle_color);
    blocks_view_add_block( viewer, "obstacle-3", 0, -3, obstacle_color);
    blocks_view_add_block( viewer, "obstacle-4", -3, 1, obstacle_color);

    /* Moveable Obstacles */
    blocks_view_add_block( viewer, "box-4", 1, -2, box_color);


    sleep(60);
}
