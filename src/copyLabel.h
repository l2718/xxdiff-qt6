/******************************************************************************\
 * $Id: copyLabel.h 432 2001-11-30 07:21:57Z blais $
 * $Date: 2001-11-30 02:21:57 -0500 (Fri, 30 Nov 2001) $
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
 ******************************************************************************/

#ifndef INCL_XXDIFF_COPYLABEL
#define INCL_XXDIFF_COPYLABEL

/*==============================================================================
 * EXTERNAL DECLARATIONS
 *============================================================================*/

#ifndef INCL_XXDIFF_DEFS
#include <defs.h>
#endif

#ifndef INCL_QT_QLABEL
#include <qlabel.h>
#define INCL_QT_QLABEL
#endif

/*==============================================================================
 * FORWARD DECLARATIONS
 *============================================================================*/

class QScrollBar;

XX_NAMESPACE_BEGIN

/*==============================================================================
 * CLASS XxCopyLabel
 *============================================================================*/

// <summary> a label that puts its contents into the clipboard when clicked on
// </summary>

class XxCopyLabel : public QLabel {

public:

   /*----- types and enumerations -----*/

   enum {
      SAFETY_OFFSET = 10
   };

   /*----- member functions -----*/

   // Constructor.
   XxCopyLabel( QWidget* parent );

   // Destructor.
   ~XxCopyLabel();

   // See base class.
   // <group>
   virtual QSize sizeHint() const;
   virtual void setText( const QString& );
   virtual void mousePressEvent( QMouseEvent* );
   virtual void resizeEvent( QResizeEvent* );
   // </group>

   // Returns the full text of the label.
   const QString& getFullText() const;

private:

   /*----- classes -----*/

   class Tip;

   /*----- data members -----*/

   Tip*    _tip;
   QString _fulltext;

};

XX_NAMESPACE_END

#endif