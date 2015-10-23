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


#ifndef VIEWBLOCKS_H
#define VIEWBLOCKS_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL.h>
#include <amino.h>
#include <amino/rx.h>
#include "amino/rx/scene_win.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Opaque structure for a blocks-world viewer */
struct blocks_view;

/* Create a new blocksworld viewer */
struct blocks_view *
blocks_view_create();

/* Destroy new blocksworld viewer */
void
blocks_view_destroy( struct blocks_view * );

/* Draw a colored cell */
void
blocks_view_add_cell( struct blocks_view *viewer,
                      const char *name, int x, int y,
                      double rgba[4] );

/* Add a block to the scene */
void
blocks_view_add_block( struct blocks_view *viewer,
                       const char *name, int x, int y,
                       double rgba[4] );

/* Add a cylinder to the scene */
void
blocks_view_add_cylinder( struct blocks_view *viewer,
                          const char *name, int x, int y,
                          double rgba[4] );

/* Remove an object from the scene */
void
blocks_view_remove( struct blocks_view *viewer,
                    const char *name );

/* Draw a border */
void blocks_view_border( struct blocks_view *viewer,
                         int xmin, int xmax, int ymin, int ymax );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VIEWBLOCKS_H */
