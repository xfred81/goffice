/*
 * go-optionmenu.h
 *
 * Copyright (C) 2002-2005 Andreas J. Guelzow <aguelzow@taliesin.ca>
 *
 * based extensively on:
 *
 * GTK - The GIMP Toolkit
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * Modified by the GTK+ Team and others 1997-2000.  See the GTK AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/.
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
 * USA
 */

#ifndef _GO_OPTIONMENU_H_
#define _GO_OPTIONMENU_H_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GO_TYPE_OPTION_MENU              (go_option_menu_get_type ())
#define GO_OPTION_MENU(obj)              (G_TYPE_CHECK_INSTANCE_CAST ((obj), GO_TYPE_OPTION_MENU, GOOptionMenu))
#define GO_OPTION_MENU_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), GO_TYPE_OPTION_MENU, GOOptionMenuClass))
#define GO_IS_OPTION_MENU(obj)           (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GO_TYPE_OPTION_MENU))
#define GO_IS_OPTION_MENU_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GO_TYPE_OPTION_MENU))
#define GO_OPTION_MENU_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GO_TYPE_OPTION_MENU, GOOptionMenuClass))

typedef struct _GOOptionMenu       GOOptionMenu;
typedef struct _GOOptionMenuClass  GOOptionMenuClass;

struct _GOOptionMenu
{
	GtkButton button;

	/*< private >*/

	GtkMenuShell *menu;
	GtkMenuItem *selected;
	GtkLabel *button_label;
	gboolean active;
};

struct _GOOptionMenuClass
{
  GtkButtonClass parent_class;

  void (*changed) (GOOptionMenu *option_menu);

  /* Padding for future expansion */
  void (*_gtk_reserved1) (void);
  void (*_gtk_reserved2) (void);
  void (*_gtk_reserved3) (void);
  void (*_gtk_reserved4) (void);
};


GType      go_option_menu_get_type    (void);

GtkWidget *go_option_menu_new         (void);
GtkWidget *go_option_menu_build       (const char *first_entry, ...);

GtkWidget *go_option_menu_get_menu    (GOOptionMenu *option_menu);
void       go_option_menu_set_menu    (GOOptionMenu *option_menu,
				       GtkWidget *menu);
void       go_option_menu_set_history (GOOptionMenu *option_menu,
				       GSList *selection);
GtkWidget *go_option_menu_get_history (GOOptionMenu *option_menu);

void       go_option_menu_select_item (GOOptionMenu *option_menu,
				       GtkMenuItem *item);
GtkWidget *go_option_menu_get_label   (GOOptionMenu *option_menu);


G_END_DECLS

#endif /* _GO_OPTIONMENU_H_ */
