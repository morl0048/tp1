# tp1
tp1 de sécurité

  La première partie consiste à loader un dictionnaire de mots dans un vecteur de string,
de hasher ces mots et de les comparer à la liste de hash fournie dans le pdf du cours.
  La deuxième partie utilise un "Compteur" qui s'initialise avec la valeur de la première
lettre de l'alphabet fourni. Puis, le compteur s'incrémente en passant chacune des lettre
et lorsque toutes les lettre sont passées dans une position, la position suivante s'incré-
mente de 1. Ex: aa, ab, ac, ..., a&, a*, ba, bb, bc, ... Le mot résultant de chaque incré-
mentation est, par la suite, hashé et vérifié dans la liste de hash de la même façon que 
dans la première partie.

1)
a)Les mots de passes récupérés en clair grâce à la partie 1 sont:
cliquez - cb8d48705c534ae480bda3efd5619571
coopere - 711253e85ce0dbc86cdbb27ec9285c8d
desapez - ce44a7233d15bf399a09708e86039511
domptage - 06861a5d5ca1a2e490daa0d64cc1a0b7
droguera - 4c85f8da3fac9521dfba156c34564e41
etirez - cc35f894c9219239ebb858692a86be1b
gourami - ab4f6b1c2b3a66b5bf316e03bbd43e3f
greneur - 6f31ce91f67bf9246ea237850686cc7a
largue - 1f7cf588b860862a2c5ad696462523b8
orientas - d7d7c6ad7c0147cb380f28566296efc3

b)Les mots de passes récupérés en clair grâce à la partie 2 sont:
etirez - cc35f894c9219239ebb858692a86be1b
(EN COURS)

2)
a)Le choix d'un mot de passe avec beaucoup de caractères est conseillé, car une attaque par 
énumération est, malgré ca simplicité, extrèmement longue et couteuse à faire.

b)Pour déjouer ces deux types d'attaques, le mieux serait de ne pas prendre un mot simple 
(un mot du dictionnaire), court (en bas de 8 caractères) et déjà connu (dans la liste des 
mots de passe les plus utilisés au monde). Un mot de passe ne satisfesant pas à ces exigeances 
peut mener à une décription relativement rapide de vos informations personnelles.

c)Une méthode assez simple pour choisir un mot de passe peut être de prendre une partie des 
paroles d'une de vos chanson favorite et de prendre la première lettre de chaque mot pour en 
faire votre mot de passe. Vous pouvez aussi changer les détermiants de ces paroles par des nombres
et/ou symboles. Ex: "Les rois du monde font tout ce qu´ils veulent. Ils ont du monde autour d´eux 
mais ils sont seuls." peut devenir "1r2mftcqvio2ma2miss". Il serait même possible de remplacer les 
apostrophes par des symboles pour agrandir l'alphabet du mot de passe.
