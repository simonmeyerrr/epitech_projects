#!/bin/bash

blih -u simon.meyer@epitech.eu repository create $1
blih -u simon.meyer@epitech.eu repository setacl $1 ramassage-tek r
blih -u simon.meyer@epitech.eu repository getacl $1
