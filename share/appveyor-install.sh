#!/bin/sh

source /appveyor.environment
export MSYSTEM

if test "$MSYSTEM"x == "MINGW64"x; then
	i_pkg_postfix="w64-x86_64"
else
	i_pkg_postfix="w64-i686"
fi

pacman -S --noconfirm glib2
pacman -S --noconfirm zip
pacman -S --noconfirm glib2-devel
# pacman -S --noconfirm mingw-w64-glib-networking
# pacman -S --noconfirm mingw-w64-gdk-pixbuf2
pacman -S --noconfirm mingw-$i_pkg_postfix-gtkmm3
pacman -S --noconfirm mingw-$i_pkg_postfix-libgsf
pacman -S --noconfirm mingw-$i_pkg_postfix-libxml2
pacman -S --noconfirm mingw-$i_pkg_postfix-pango
pacman -S --noconfirm mingw-$i_pkg_postfix-pangocairo
pacman -S --noconfirm mingw-$i_pkg_postfix-cairo
pacman -S --noconfirm mingw-$i_pkg_postfix-libxslt
pacman -S --noconfirm gtk-doc
