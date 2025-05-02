# Panoramix

## Description
Panoramix est un projet qui simule le comportement d'un druide et de villageois dans un village gaulois. Le druide est responsable de la préparation d'une potion magique, tandis que les villageois viennent la boire pour se battre.

## Prérequis
- Un système d'exploitation Linux
- GCC (GNU Compiler Collection)
- Make
- Doxygen (pour la documentation)

## Installation
1. Clonez le repository :
```bash
git clone https://github.com/EwanEpitech/Panoramix.git
cd Panoramix
```

2. Compilez le projet :
```bash
make
```

## Utilisation
Le programme prend 4 arguments en ligne de commande :
```bash
./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```

Où :
- `nb_villagers` : Nombre de villageois dans le village
- `pot_size` : Taille maximale de la potion
- `nb_fights` : Nombre de combats que chaque villageois doit faire
- `nb_refills` : Nombre de fois que le druide peut remplir la potion

### Exemple
```bash
./panoramix 3 5 3 1
```
Ceci créera :
- 3 villageois
- Une potion de taille 5
- Chaque villageois fera 3 combats
- Le druide pourra remplir la potion 1 fois

## Documentation
La documentation complète du code est disponible dans le dossier `html/`. Vous pouvez la consulter en ouvrant `html/index.html` dans votre navigateur.

## Fonctionnement
1. Le druide commence à préparer la potion
2. Les villageois arrivent un par un pour boire la potion
3. Quand la potion est vide, le druide la remplit (s'il lui reste des remplissages)
4. Les villageois continuent de boire jusqu'à ce qu'ils aient fait tous leurs combats
5. Le programme se termine quand tous les villageois ont terminé leurs combats

## Auteurs
- Ewan Tirlemont
