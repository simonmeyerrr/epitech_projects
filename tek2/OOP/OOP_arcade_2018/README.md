# Arcade

L'arcade est un projet de seconde année dans le cursus grande école d'EPITECH, et est développé en C++. Ce programme a pour but de pouvoir jouer sur différents jeux tel qu'une borne d'arcade mais possédant la capacité de pouvoir changer de librairies graphiques en cours d'exécution.
Par défaut, l'Arcade possède trois jeux : PacMan, Nibbler et le MineSweeper (Démineur) ainsi que trois librairies graphiques : SFML, NCURSES et la LibCaca.

## Installation

Après avoir télécharger le répertoire dans sa globalité, procédez aux commandes suivantes en fonction de votre utilisation du programme.

Pour compiler l'entièreté du programme :
```bash
$ make
```

Pour compiler le core :
```bash
$ make core
```

Pour compiler les librairies graphiques :
```bash
$ make graphicals
```

Pour compiler les librairies de jeu :
```bash
$ make games
```

## Usage

Pour exécuter le programme, procédez à la commande suivante :

```bash
$ ./arcade lib/lib_arcade_xxxxxxx.so
```
Le "xxxxxxx" étant à remplacer par le nom d'une des librairies présentes dans le dossier /lib. Elle sera modifiable au cours de l'exécution.

## Contribution
Le projet Arcade a été développé par Simon MEYER (simon.meyer@epitech.eu), Léo FORNES (leo.fornes@epitech.eu) et Kevin SPEGT (kevin.spegt@epitech.eu).
Dans le cas où des problèmes seraient rencontrés, reportez-vous à la documentation technique et d'utilisation situé dans le dossier "doc".

## Comptabilité

Le Core, les Jeux et les Librairies graphiques sont entièrement interchangeable et compatibles avec le groupe d'Arcade composé mené par Arnaud SCHEID (arnaud.scheid@epitech.eu).
