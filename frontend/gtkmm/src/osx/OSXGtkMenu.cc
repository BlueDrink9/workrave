// OSXGtkMenu.cc --- Menus using Gtk+
//
// Copyright (C) 2001 - 2011 Rob Caelers & Raymond Penners
// All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//



#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <iostream>

#include "nls.h"
#include "debug.hh"

#include "OSXGtkMenu.hh"

#include <string>

#include <gdkmm/pixbuf.h>
#include <gtkmm/action.h>
#include <gtkmm/iconset.h>
#include <gtkmm/iconsource.h>
#include <gtkmm/menu.h>
#include <gtkmm/menubar.h>
#include <gtkmm/stock.h>

#include "Menus.hh"
#include "Util.hh"

using namespace std;

#include "gtk-mac-menu.h"
#include "gtkosxapplication.h"
#include "gtk-mac-bundle.h"

//! Constructor.
OSXGtkMenu::OSXGtkMenu(bool show_open, IGUI* gui)
  : MainGtkMenu(show_open)
{
  this->theApp = (GtkosxApplication *)g_object_new(GTKOSX_TYPE_APPLICATION, NULL);
  this->gui = gui;
}

//! Destructor.
OSXGtkMenu::~OSXGtkMenu()
{
}

void
OSXGtkMenu::popup(const guint button, const guint activate_time)
{
  (void) button;
  (void) activate_time;
}

void
OSXGtkMenu::dock_clicked(GtkosxApplication *dock, void *data)
{
  Menus *menus = (Menus *) data;
  menus->on_menu_open_main_window();
}

void
OSXGtkMenu::dock_quit(GtkosxApplication *dock, void *data)
{
  (void) dock;
  // current, segment fault
  // Menus *menus = (Menus *) data;
  // menus->on_menu_quit();
}

void
OSXGtkMenu::create_ui()
{
  Glib::ustring ui_info =
    "<ui>\n"
    "  <menubar name='Menu'>\n"
    "    <menu action='Main'>\n"
    "      <menuitem action='Restbreak'/>\n"
    "      <menuitem action='Exercises'/>\n"
    "      <menuitem action='Statistics'/>\n"
    "    </menu>\n"
    "    <menu action='Mode'>\n"
    "      <menuitem action='Normal'/>\n"
    "      <menuitem action='Quiet'/>\n"
    "      <menuitem action='Suspended'/>\n"
    "    </menu>\n"
    "    <menu action='Network'>\n"
    "      <menuitem action='Join'/>\n"
    "      <menuitem action='Disconnect'/>\n"
    "      <menuitem action='Reconnect'/>\n"
    "      <menuitem action='ShowLog'/>\n"
    "    </menu>\n"
    "    <menuitem action='Reading'/>"
    "  </menubar>\n"
    "</ui>\n";

  ui_manager = Gtk::UIManager::create();
  ui_manager->insert_action_group(action_group);

  ui_manager->add_ui_from_string(ui_info);

  Gtk::MenuBar *menu = dynamic_cast<Gtk::MenuBar*>(ui_manager->get_widget("/Menu"));
  Gtk::MenuItem *item = dynamic_cast<Gtk::MenuItem*>(ui_manager->get_widget("/Apple/Quit"));

  GtkMenuBar *menu_shell = menu->gobj();
  MainWindow *main_window = gui->get_main_window();
  gtk_widget_set_parent(GTK_WIDGET(menu_shell), GTK_WIDGET(main_window->gobj()));
  gtkosx_application_set_menu_bar(this->theApp, GTK_MENU_SHELL(menu_shell));

  #if 0
  ige_mac_menu_set_quit_menu_item(GTK_MENU_ITEM(item->gobj()));

  item = dynamic_cast<Gtk::MenuItem*>(ui_manager->get_widget("/Apple/About"));

  IgeMacMenuGroup *group;
  IgeMacDock      *dock;

  group = ige_mac_menu_add_app_menu_group();
  ige_mac_menu_add_app_menu_item(group,
                                 GTK_MENU_ITEM(item->gobj()),
                                 NULL);

  item = dynamic_cast<Gtk::MenuItem*>(ui_manager->get_widget("/Apple/Preferences"));

  group = ige_mac_menu_add_app_menu_group();
  ige_mac_menu_add_app_menu_item(group,
                                 GTK_MENU_ITEM (item->gobj()),
                                 NULL);

  dock = ige_mac_dock_new ();
  g_signal_connect(dock,
                   "clicked",
                   G_CALLBACK(dock_clicked),
                   this);

  g_signal_connect(dock,
                   "quit-activate",
                   G_CALLBACK(dock_quit),
                   this);
  #endif
}
