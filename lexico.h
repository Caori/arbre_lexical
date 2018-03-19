typedef struct noeud {
  unsigned chat lettre;
  struct noeud *filsg, *frered;
} Noeud, *Arbre;

//alloue dynamiquement un noeud de l'arbre pour un caractère
Arbre alloueNoeud(char *m);

//recherche un mot dans l'arbre lexical
int recherche(Arbre a, char *m);

//ajoute un mot dans l'arbre
int ajoute(Arbre a, char *m);

//affiche les mots de l'arbre dans l'ordre alphabétique
void afficheArbre(Arbre a);

//sauvegarde les mots en ordre alphabétique dans un fichier .L

// sauvegarde l'arbre dans un fichier .DICO

//commande pour compiler : gcc -ansi -Wall Lexique.c -o Lexique
