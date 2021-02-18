#!/bin/bash

rm -f bomberman.desktop
touch bomberman.desktop
echo -n "[Desktop Entry]
Encoding=UTF-8
Version=1.0
Type=Application
Terminal=false
Exec=" >> bomberman.desktop
echo -n $PWD >> bomberman.desktop
echo -n "/bomberman
Name=Bomberman
Icon=" >> bomberman.desktop
echo -n $PWD >> bomberman.desktop
echo "/assets/textures/icon.png" >> bomberman.desktop
sudo mv bomberman.desktop /usr/share/applications/
