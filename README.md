# Sokoban
__A little brain teaser game__

C'est une copie du jeu le sokoban en mode terminal, en utilisant la bibliothèque ncurses.

Si toutes les cases sont sur des emplacements de stockage, le joueur gagne et le programme renvoie 0.  
Sinon, si aucune des cases ne peut plus être déplacée, il perd et le programme renvoie 1.

Le jeu réinitialise en appuyant sur la barre d'espace.  
Le jeu se joue avec les touches directionnelles (GAUCHE, DROITE, HAUT et BAS).

Une carte valide ne contient que les caractères ESPACE, '\n', '#', 'X', 'O' et 'P'.  
Le programme renvoit une erreur si une carte non valide est donné.

Voici un exemple de carte :
<p align="center">
  <img src="https://github.com/RainproDash/Sokoban/assets/91848714/dbe6e112-233f-4f9f-9f95-948e4039709d" alt="Image de démonstration">
</p>

