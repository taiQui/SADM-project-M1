# Sac à dos multidimentionnel - Introduction

Pour ce projet, nous devons résoudres de manière optimum le probleme du sac a dos multidimentionel. Nous avons choisis d'implementé la méta heuristique : algorithme génétique pour ce probleme.

Pour rappel, l'algorithme générique fonctionnes comme suit : 

* On part d'un ensemble de solutions ( ici trouvé de manière aléatoire )
* On trouve un parents, en choisissant aléatoirement dans cet ensemble de solutions, 2 * 2 solutions, et on prends la meilleurs des 2 couples.
* On construit de manieres aléatoire un tableau de 0 et de 1 de la tailles d'une solutions, et on prends si l'index est egale a 0 le parent 1,  le cas écheant le parent 2.
* Sur ce fils, nous flippons ici 2 bits choisis aléatoirement
* Sur le fils muté, nous le réparons si jamais les contraintes ne sont plus respecté apres la mutations.
* Nous regardons si le fils ainsi trouvé appartient a notre ensemble de solutions, si ce n'est pas le cas nous echangons la pire solutions de notre ensemble par notre fils
* Si le score de notre meilleures solutions est inférieurs a notre fils, nous echangons aussi le meilleurs avec notre fils.
* Et nous répetons ces actions de manière fini

Nous avons implémenté ce projet dans le langage de programmation **C++**

Pour une meilleurs compréhension, nous pouvons trouvé dans les fichiers : 

*getInput.cpp/hpp*    La gestions du parsages de chaque fichié

*geneticAlgoritm.cpp/hpp*    L'algorithme génétique en lui mêmes

*solution.cpp/hpp*    La class solutions pour géré les actions des solutions

*MB.cpp/hpp*    La classe sac a dos multidimentionnelle, qui comprends toutes les actions comme la mutations, la repartions etc 

Chaque  headers comprends des commentaires comme explications des fonctions.

# Exécutions

```bash
make   # Pour compilé le projets
./prog nomDeFichier timeMax
# nomDeFichier est le fichier à traité
# timeMax est le temps max en seconde pour l'execution du programme
```

Quand le programmes dépasse le temps indiqué en paramètre, il s'arrete et retournes la meilleurs solutions trouvé.

# Retours

Comme convenus dans le sujet, le programmes génère en sortie un fichier texte comprenant sur la premiere ligne, le score suivis d'une virgule puis du nombre d'objet selectionné.

Sur la deuxieme lignes, les objets selectionnés.

Ce fichier ce nommes **solution.txt**

