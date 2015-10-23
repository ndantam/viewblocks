#include "viewblocks.h"
#include <unistd.h>




int main( int argc, char **argv)
{

    double red[4] = {1,0,0,1};
    double green[4] = {0,1,0,1};
    double blue[4] = {0,0,1,1};

    double grey[4] = {.5,.5,.5,1};

    double ice[4] = {.5,.5,1,.5};

    struct blocks_view *viewer = blocks_view_create();

    blocks_view_add_cell( viewer, "a-0-0", 0, 0,
                          ice);

    blocks_view_add_block( viewer, "b-1-0", 1, 0,
                           red);

    blocks_view_add_cylinder( viewer, "r-0-1", 0, 1,
                              grey);


    blocks_view_border( viewer, -5, 5, -5, 5 );
    sleep(60);
}
