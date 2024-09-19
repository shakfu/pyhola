/*
 * vim: ts=4 sw=4 et tw=0 wm=0
 *
 * libavoid - Fast, Incremental, Object-avoiding Line Router
 *
 * Copyright (C) 2004-2009  Monash University
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * See the file LICENSE.LGPL distributed with the library.
 *
 * Licensees holding a valid commercial license may use this file in
 * accordance with the commercial license agreement provided with the 
 * library.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
 *
 * Author(s):   Michael Wybrow
*/

//! @file  libavoid.h
//! @brief Standard libavoid include file which includes all libavoid 
//!        header files.

/**
 * @namespace Avoid
 * @brief libavoid: Object-avoiding orthogonal and polyline connector 
 *        routing library.
 *
 * You should use libavoid via an instance of the Router class.
 */
#ifndef AVOID_LIBAVOID_H
#define AVOID_LIBAVOID_H

#include <libavoid/libavoid/geomtypes.h>
#include <libavoid/libavoid/shape.h>
#include <libavoid/libavoid/connector.h>
#include <libavoid/libavoid/connend.h>
#include <libavoid/libavoid/graph.h>
#include <libavoid/libavoid/debug.h>
#include <libavoid/libavoid/timer.h>
#include <libavoid/libavoid/vertices.h>
#include <libavoid/libavoid/visibility.h>
#include <libavoid/libavoid/router.h>
#include <libavoid/libavoid/connectionpin.h>
#include <libavoid/libavoid/junction.h>
#include <libavoid/libavoid/viscluster.h>

#endif


