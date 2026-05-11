# Rendu Projet

## Exercice 2 - Lecture de code et compréhension

_1) Identifiez où sont définies les structures principales du graphe (WeightedGraph / PositionedGraph) et expliquez brièvement leur rôle et comment elles sont utilisées._

Les structures WeightedGraph et PositionedGraph sont définies dans `src/dataStructure/WeightedGraph.hpp` pour WeightedGraph et `src/osm/PositionedGraph.hpp` pour PositionedGraph.

**WeightedGraph.hpp :** Dans la structure, prends plusieurs méthodes :

on peut ajouter des poids aux arêtes (ce qui permet de représenter des distances/ le couts pour ce deplacer),
ajouter des sommets, supprimer des nodes, supprimer des arêtes et relier les nodes entre eux avec des arêtes mais egalment dire la destitaiotn du node avec le to

les méthodes prennent en paramètre un identifiant unique (c'est le nom de notre node comme si on avait pris A,B,C,D,E), ce qui permet de les retrouver facilement.
On peut également récupérer les voisins d’un node, ce qui est utile pour parcourir le graphe.

**PositionedGraph.hpp :** Dans la structure, on peut avoir les positions des nodes, ainsi qu’ajouter de nouveaux nodes, en enlever, enlever des arêtes, et fusionner deux nodes (merge).
Ces fonctions prennent en entrée une structure node avec leur id pour pouvoir les identifier.

_2) Expliquez en quelques lignes le rôle des modules :_

Les différents modules fonctionnent globalement de la même manière. Ils récupèrent un chemin de fichier donné par l’utilisateur, le convertissent en chemin absolu afin de localiser correctement les fichiers sur l’ordinateur, puis effectuent une opération spécifique sur le graphe.

Le module d’extraction charge un fichier OSM et utilise la fonction extract pour générer le graphe correspondant avant de le sauvegarder.
Le module de simplification charge ensuite ce graphe grâce à load_graph, applique les différentes étapes de simplification avec simplify_graph, puis sauvegarde le résultat.
Le module de visualisation charge le graphe simplifié et l’affiche à l’écran grâce à la fonction draw_loop.

_3) Expliquez ce que vous comprenez des différentes étapes de simplification implémentées (fichier src/simplification/simplify.cpp) et les raisons pour lesquelles elles sont utilisées (leur impact sur la structure du graphe, les avantages/inconvénients, etc.)._

Le fichier permet de simplifier le graphe en supprimant notamment des nodes qui ne sont pas nécessaires (par exemple les chemins qui étaient des chemins de fer, en gardant les plus importants, ici les chemins connectés qui forment le plus grand chemin en tout). Il reconnecte des nodes qui sont proches (s’ils sont importants).
Cette simplification est utile car les données OpenStreetMap sont très denses et contiennent de nombreux nœuds ou chemins peu pertinents pour certains traitements algorithmiques.
Le code permet de garder uniquement la route principale et supprime toutes les routes déconnectées du graphe principal.
Il supprime également toutes les routes très petites et qui sont donc inutiles.
Il optimise aussi le graphe, notamment en faisant supprimer les routes qui sont quasiment les mêmes, en faisant donc une ligne droite entre les deux nodes.
Il regroupe les nodes qui sont proches et les fusionne pour n’en former plus qu’un.

**Avantages:**
le graphe devient beaucoup plus lisible et plus léger.
Le nombre de nœuds et d’arêtes diminue, ce qui améliore les performances des algorithmes de parcours ou de calcul de chemin.
Les données open street map étant très détaillées, cette simplification permet de conserver une représentation plus exploitable du réseau routier.
La suppression des nœuds inutiles réduit également le coût mémoire et le temps de calcul.

**Inconvénients** :

Certaines routes ou détails importants peuvent disparaître lors de la simplification.
La fusion de nœuds peut modifier légèrement la géométrie réelle du réseau.
Les choix de seuils (distance, angle, profondeur) restent assez binaire, un mauvais réglage peut enlever beaucoup de detail.
