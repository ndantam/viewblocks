/* -*- mode: C; c-basic-offset: 4; -*- */
/* ex: set shiftwidth=4 tabstop=4 expandtab: */
/*
 * Copyright (c) 2015, Rice University
 * All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *
 *    * Neither the name of copyright holder the names of its
 *      contributors may be used to endorse or promote products
 *      derived from this software without specific prior written
 *      permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 *
 */


#include "viewblocks.h"

#define BLOCK_SIZE .1
#define GRID_WIDTH .005
#define GRID_DIM 25
#define CELL_HEIGHT .001

struct blocks_view {
    struct aa_rx_sg *scenegraph;
    struct aa_rx_win * win ;
};

/* Create a new blocksworld viewer */
struct blocks_view *
blocks_view_create()
{
    struct blocks_view *bv = (struct blocks_view *)malloc( sizeof(struct blocks_view) );
    bv->scenegraph = aa_rx_sg_create();


    double dim[2] = {BLOCK_SIZE*GRID_DIM, BLOCK_SIZE*GRID_DIM};
    double delta[2] = {BLOCK_SIZE, BLOCK_SIZE};

    struct aa_rx_geom_opt *opt = aa_rx_geom_opt_create();

    aa_rx_geom_opt_set_color3(opt, 0, 0, 0);

    double v[3] = {BLOCK_SIZE/2, BLOCK_SIZE/2, 0};
    aa_rx_sg_add_frame_fixed( bv->scenegraph,
                              "", "__grid__",
                              aa_tf_quat_ident, v );
    aa_rx_geom_attach( bv->scenegraph, "__grid__",
                       aa_rx_geom_grid(opt, dim, delta, GRID_WIDTH) );

    aa_rx_geom_opt_destroy(opt);

    bv->win = aa_rx_win_default_create ( "BlocksWorld", 640, 480 );

    aa_rx_sg_init(bv->scenegraph);
    aa_rx_win_sg_gl_init(bv->win, bv->scenegraph);
    aa_rx_win_set_sg(bv->win, bv->scenegraph);

    aa_rx_win_start(bv->win);

    return bv;
}

/* Destroy new blocksworld viewer */
void
blocks_view_destroy( struct blocks_view * bv )
{
    aa_rx_win_destroy(bv->win);
    aa_rx_sg_destroy(bv->scenegraph);
    free(bv);
}


struct aa_rx_geom_opt *
create_geom_opt (double rgba[4] )
{
    struct aa_rx_geom_opt *opt = aa_rx_geom_opt_create();
    aa_rx_geom_opt_set_color3( opt, rgba[0], rgba[1], rgba[2] );
    aa_rx_geom_opt_set_alpha( opt, rgba[3] );
    return opt;
}


/* Draw a colored cell */
void
blocks_view_add_cell( struct blocks_view *viewer,
                      const char *name, int x, int y,
                      double rgba[4] )
{
    double v[3] = {x*BLOCK_SIZE, y*BLOCK_SIZE, -CELL_HEIGHT/2};
    double d[3] = {BLOCK_SIZE, BLOCK_SIZE, CELL_HEIGHT};

    aa_rx_win_pause(viewer->win, 1);

    aa_rx_sg_add_frame_fixed( viewer->scenegraph,
                              "", name,
                              aa_tf_quat_ident, v );

    struct aa_rx_geom_opt *opt = create_geom_opt(rgba);
    aa_rx_geom_attach( viewer->scenegraph, name,
                       aa_rx_geom_box(opt, d) );

    aa_rx_sg_init(viewer->scenegraph);
    aa_rx_win_sg_gl_init(viewer->win, viewer->scenegraph);
    aa_rx_win_pause(viewer->win, 0);
    aa_rx_geom_opt_destroy(opt);
}

/* Add a block to the scene */
void
blocks_view_add_block( struct blocks_view *viewer,
                       const char *name, int x, int y,
                       double rgba[4] )
{
    double v[3] = {x*BLOCK_SIZE, y*BLOCK_SIZE, BLOCK_SIZE/2};
    double d[3] = {BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE};

    aa_rx_win_pause(viewer->win, 1);

    aa_rx_sg_add_frame_fixed( viewer->scenegraph,
                              "", name,
                              aa_tf_quat_ident, v );

    struct aa_rx_geom_opt *opt = create_geom_opt(rgba);
    aa_rx_geom_attach( viewer->scenegraph, name,
                       aa_rx_geom_box(opt, d) );

    aa_rx_sg_init(viewer->scenegraph);
    aa_rx_win_sg_gl_init(viewer->win, viewer->scenegraph);
    aa_rx_win_pause(viewer->win, 0);
    aa_rx_geom_opt_destroy(opt);

}

/* Add a cylinder to the scene */
void
blocks_view_add_cylinder( struct blocks_view *viewer,
                          const char *name, int x, int y,
                          double rgba[4] )
{

    double v[3] = {x*BLOCK_SIZE, y*BLOCK_SIZE, 0};
    double d[3] = {BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE};

    aa_rx_win_pause(viewer->win, 1);

    aa_rx_sg_add_frame_fixed( viewer->scenegraph,
                              "", name,
                              aa_tf_quat_ident, v );

    struct aa_rx_geom_opt *opt = create_geom_opt(rgba);
    aa_rx_geom_attach( viewer->scenegraph, name,
                       aa_rx_geom_cylinder(opt, BLOCK_SIZE, BLOCK_SIZE/2) );

    aa_rx_sg_init(viewer->scenegraph);
    aa_rx_win_sg_gl_init(viewer->win, viewer->scenegraph);
    aa_rx_win_pause(viewer->win, 0);
    aa_rx_geom_opt_destroy(opt);
}

/* /\* Remove an object from the scene *\/ */
/* void */
/* blocks_view_remove( struct blocks_view *viewer, */
/*                     const char *name ) */
/* { */
/* } */


void blocks_view_border( struct blocks_view *viewer,
                         int xmin, int xmax, int ymin, int ymax )
{
    assert( xmin < xmax );
    assert( ymin < ymax );

    double black[4] = {0,0,0,1};

    // top
    for( int x = xmin; x <= xmax; x ++ ) {
        char buf[64];
        snprintf( buf, sizeof(buf), "__border-%d-%d",
                  x, ymax );
        blocks_view_add_block( viewer, buf, x, ymax, black);
    }
    // bottom
    for( int x = xmin; x <= xmax; x ++ ) {
        char buf[64];
        snprintf( buf, sizeof(buf), "__border-%d-%d",
                  x, ymin );
        blocks_view_add_block( viewer, buf, x, ymin, black);
    }
    // left
    for( int y = ymin + 1; y < ymax ; y ++ ) {
        char buf[64];
        snprintf( buf, sizeof(buf), "__border-%d-%d",
                  xmin, y );
        blocks_view_add_block( viewer, buf, xmin, y, black);
    }
    // right
    for( int y = ymin + 1; y < ymax ; y ++ ) {
        char buf[64];
        snprintf( buf, sizeof(buf), "__border-%d-%d",
                  xmax, y );
        blocks_view_add_block( viewer, buf, xmax, y, black);
    }
}
