/******************************************************************************\
 * $Id: winfixes.h 226 2001-09-25 20:40:41Z blais $
 * $Date: 2001-09-25 16:40:41 -0400 (Tue, 25 Sep 2001) $
 *
 * Copyright (C) 1999-2001  Martin Blais <blais@iro.umontreal.ca>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *****************************************************************************/

#ifndef INCL_XXDIFF_WINFIXES
#define INCL_XXDIFF_WINFIXES

//
// This is REALLY lame, we should use std::min and std::max, but we have to
// start portnig to Windoom at some point.
//
namespace std {

#ifdef min
#undef min
#undef max
#endif

template <class T>
T min( const T& a, const T& b ) {
   if ( a < b ) { return a; } else { return b; }
}

template <class T>
T max( const T& a, const T& b ) {
   if ( a > b ) { return a; } else { return b; }
}

}

#endif