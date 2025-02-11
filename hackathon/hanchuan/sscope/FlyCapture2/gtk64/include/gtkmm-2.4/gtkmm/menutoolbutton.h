// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_MENUTOOLBUTTON_H
#define _GTKMM_MENUTOOLBUTTON_H


#include <glibmm.h>

/* $Id: menutoolbutton.hg,v 1.2 2006/04/12 11:11:25 murrayc Exp $ */

/* box.h
 *
 * Copyright (C) 2003 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <gtkmm/toolbutton.h>
#include <gtkmm/menu.h>
#include <gtkmm/tooltips.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkMenuToolButton GtkMenuToolButton;
typedef struct _GtkMenuToolButtonClass GtkMenuToolButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class MenuToolButton_Class; } // namespace Gtk
namespace Gtk
{

/** A Gtk::ToolItem containing a toggle button.
 *
 * A MenuToolButton is a Gtk::ToolItem that contains a menu.
 * @ingroup Widgets
 */

class MenuToolButton : public ToolButton
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef MenuToolButton CppObjectType;
  typedef MenuToolButton_Class CppClassType;
  typedef GtkMenuToolButton BaseObjectType;
  typedef GtkMenuToolButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~MenuToolButton();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class MenuToolButton_Class;
  static CppClassType menutoolbutton_class_;

  // noncopyable
  MenuToolButton(const MenuToolButton&);
  MenuToolButton& operator=(const MenuToolButton&);

protected:
  explicit MenuToolButton(const Glib::ConstructParams& construct_params);
  explicit MenuToolButton(GtkMenuToolButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkMenuToolButton*       gobj()       { return reinterpret_cast<GtkMenuToolButton*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkMenuToolButton* gobj() const { return reinterpret_cast<GtkMenuToolButton*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

protected:
  //GTK+ Virtual Functions (override these to change behaviour):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

  //Default Signal Handlers::
#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  virtual void on_show_menu();
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


private:

public:

  /** Creates a new MenuToolButton.
   */
  MenuToolButton();
  
  /** Creates a new MenuToolButton from a StockID.
   *
   * The MenuToolButton will be created according to the @a stock_id properties.
   * 
   * @param stock_id The StockID which determines the look of the MenuToolButton.
   */
  explicit MenuToolButton(const Gtk::StockID& stock_id);
  
  /** Creates a new MenuToolButton with a label.
   *
   * The MenuToolButton will have the label @a label.
   *
   * @param label The string used to display the label for this MenuToolButton.
   */
  explicit MenuToolButton(const Glib::ustring& label);
  
  /** Creates a new MenuToolButton with an image.
   *
   * The MenuToolButton will have the label @a label and an image widget @a icon_widget.
   *
   * @param icon_widget The widget placed as the MenuToolButton's icon.
   * @param label The string used to display the label for this MenuToolButton.
   */
  explicit MenuToolButton(Widget& icon_widget, const Glib::ustring& label = Glib::ustring());

  
  /** Sets the Gtk::Menu that is popped up when the user clicks on the arrow.
   * If @a menu is <tt>0</tt>, the arrow button becomes insensitive.
   * 
   * @newin2p6
   * @param menu The Gtk::Menu associated with Gtk::MenuToolButton.
   */
  void set_menu(Menu& menu);
  
  /** Gets the Gtk::Menu associated with Gtk::MenuToolButton.
   * @return The Gtk::Menu associated with Gtk::MenuToolButton
   * 
   * @newin2p6.
   */
  Menu* get_menu();
  
  /** Gets the Gtk::Menu associated with Gtk::MenuToolButton.
   * @return The Gtk::Menu associated with Gtk::MenuToolButton
   * 
   * @newin2p6.
   */
  const Menu* get_menu() const;

  
#ifndef GTKMM_DISABLE_DEPRECATED

  /** Sets the Gtk::Tooltips object to be used for arrow button which
   * pops up the menu. See Gtk::ToolItem::set_tooltip() for setting
   * a tooltip on the whole Gtk::MenuToolButton.
   * 
   * @newin2p6
   * 
   * Deprecated: 2.12: Use set_arrow_tooltip_text()
   * instead.
   * @deprecated Use set_arrow_tooltip_text() or set_arrow_tooltip_markup() instead
   * @param tooltips The Gtk::Tooltips object to be used.
   * @param tip_text Text to be used as tooltip text for tool_item.
   * @param tip_private Text to be used as private tooltip text.
   */
  void set_arrow_tooltip(Tooltips& tooltips, const Glib::ustring& tip_text, const Glib::ustring& tip_private);
#endif // GTKMM_DISABLE_DEPRECATED


  /** Sets the tooltip text to be used as tooltip for the arrow button which
   * pops up the menu.  See Gtk::ToolItem::set_tooltip() for setting a tooltip
   * on the whole Gtk::MenuToolButton.
   * 
   * @newin2p12
   * @param text Text to be used as tooltip text for button's arrow button.
   */
  void set_arrow_tooltip_text(const Glib::ustring& text);
  
  /** Sets the tooltip markup text to be used as tooltip for the arrow button
   * which pops up the menu.  See Gtk::ToolItem::set_tooltip() for setting a
   * tooltip on the whole Gtk::MenuToolButton.
   * 
   * @newin2p12
   * @param markup Markup text to be used as tooltip text for button's arrow button.
   */
  void set_arrow_tooltip_markup(const Glib::ustring& markup);

  
  /**
   * @par Prototype:
   * <tt>void on_my_%show_menu()</tt>
   */

  Glib::SignalProxy0< void > signal_show_menu();

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The dropdown menu.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Menu*> property_menu() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The dropdown menu.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Menu*> property_menu() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::MenuToolButton
   */
  Gtk::MenuToolButton* wrap(GtkMenuToolButton* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_MENUTOOLBUTTON_H */

