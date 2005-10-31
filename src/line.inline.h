/******************************************************************************\
 * $Id: line.inline.h 374 2001-11-11 07:58:01Z blais $
 * $Date: 2001-11-11 02:58:01 -0500 (Sun, 11 Nov 2001) $
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

/*==============================================================================
 * EXTERNAL DECLARATIONS
 *============================================================================*/


XX_NAMESPACE_BEGIN


/*==============================================================================
 * PUBLIC FUNCTIONS
 *============================================================================*/

/*==============================================================================
 * CLASS XxLine
 *============================================================================*/

//------------------------------------------------------------------------------
//
inline XxLine::XxLine() :
   _type( SAME ),
   _selection( NEITHER ),
   _hunkId( -1 )
{
   // This is just initialization to remove UMRs in Purify.
   for ( int ii = 0; ii < 3; ++ii ) {
      _lineNo[ii] = -1;
      _hordiffs[ii] = 0;
   }
}

//------------------------------------------------------------------------------
//
inline XxLine::~XxLine()
{
   for ( int ii = 0; ii < 3; ++ii ) {
      delete[] _hordiffs[ii];
   }
}

//------------------------------------------------------------------------------
//
inline void XxLine::init()
{
   _hordiffs[0] = _hordiffs[1] = _hordiffs[2] = 0;
}

//------------------------------------------------------------------------------
//
inline XxLine::Type XxLine::getType() const
{
   return _type;
}

//------------------------------------------------------------------------------
//
inline XxLine::Selection XxLine::getSelection() const
{
   return _selection;
}

//------------------------------------------------------------------------------
//
inline void XxLine::setSelection( Selection selection )
{
   if ( _type != SAME ) {
      _selection = selection;
   }
}

//------------------------------------------------------------------------------
//
inline bool XxLine::getSelectedText( XxFno& no, XxFln& fline ) const
{
   if ( _type == SAME ) {
      fline = _lineNo[ 0 ];
      XX_CHECK( fline != -1 ); // sanity check
      no = 0;
      return true;
   }
   if ( _selection == SEL1 || _selection == SEL2 || _selection == SEL3 ) {
      fline = _lineNo[ XxFno(_selection) ];
      no = XxFno(_selection);
      return true;
   }
   if ( _selection == NEITHER ) {
      fline = -1;
      no = -1;
      return true;
   }
   // Unselected.
   fline = -1;
   no = -1;
   return false;
}

//------------------------------------------------------------------------------
//
inline XxFln XxLine::getLineNo( const XxFno no ) const
{
   XX_ASSERT( no == 0 || no == 1 || no == 2 );
   return _lineNo[no];
}

//------------------------------------------------------------------------------
//
inline const int* XxLine::getHorDiffs( const XxFno no ) const
{
   XX_CHECK( no == 0 || no == 1 || no == 2 );
   return _hordiffs[ no ];
}

//------------------------------------------------------------------------------
//
inline bool XxLine::hasHorizontalDiffs( const XxFno no ) const
{
   XX_CHECK( no == 0 || no == 1 || no == 2 );
   return _hordiffs[no] != 0;
}

//------------------------------------------------------------------------------
// 
inline XxHunk XxLine::getHunkId() const
{
   return _hunkId;
}

//------------------------------------------------------------------------------
//
inline void XxLine::setHunkId( XxHunk hunkId )
{
   _hunkId = hunkId;
}

//------------------------------------------------------------------------------
//
inline XxFno XxLine::mapTypeToFileNo( Type type )
{
   XxFno lno = -1;
   switch ( type ) {
      case XxLine::SAME: lno = -1; break;
      case XxLine::DIFF_1: lno = 0; break;
      case XxLine::DIFF_2: lno = 1; break;
      case XxLine::DIFF_3: lno = 2; break;
      case XxLine::DELETE_1: lno = 0; break;
      case XxLine::DELETE_2: lno = 1; break;
      case XxLine::DELETE_3: lno = 2; break;
      case XxLine::INSERT_1: lno = 0; break;
      case XxLine::INSERT_2: lno = 1; break;
      case XxLine::INSERT_3: lno = 2; break;
      case XxLine::DIFF_ALL: lno = -1; break;
      case XxLine::DIFFDEL_1: lno = 0; break;
      case XxLine::DIFFDEL_2: lno = 1; break;
      case XxLine::DIFFDEL_3: lno = 2; break;
      case XxLine::DIRECTORIES: lno = -1; break;
      case XxLine::NB_TYPES: XX_ABORT();
   }
   return lno;
}

XX_NAMESPACE_END
