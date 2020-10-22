# Le jeu de la vie

Le jeu de la vie est un automate cellulaire imaginé par John Horton Conway en 1970 et qui est probablement le plus connu de tous les automates cellulaires.<br>
Le jeu de la vie est un jeu au sens mathématique plutôt que ludique. Bien que n'étant pas décrit par la théorie des jeux, certains le décrivent comme un « jeu à zéro joueur ».<br>
lien vers Wikipedia [Wikipédia](https://fr.wikipedia.org/wiki/Jeu_de_la_vie)

## Usage

- Lancement du programme
Pour compiler et exécuter le programme, placez-vous dans le dossier source ensuite exécuter les commandes suivantes sur une ligne de commandes.
~~~~~~~~~~~~~~{ .sh}
make 
./game <width> <height> <refresh_timer>
~~~~~~~~~~~~~~

**width** est la largeur de la grille
**height** est la hauteur de la grille
ils doivent être supérieurs ou égals à 0
**refresh_timer** est temps de raffraichissement de la grille au lancement du jeu.

- Test
Pour tester les fonctions, vous aurez besoin du framework de test [CUnit](http://cunit.sourceforge.net/index.html)
Les testes se font sur le dossier test de la manière suivante : 
~~~~~~~~~~~~~~{ .sh}
make 
./test
~~~~~~~~~~~~~~