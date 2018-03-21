#include <stdio.h>

#include <stdlib.h>

#define MAX_SIZE 50

typedef struct noeud {
  unsigned char lettre;
  struct noeud *filsg, *frered;
} Noeud, *Arbre;

Arbre alloueNoeud(char *m){
  Noeud *newnoeud;

  /*allocation*/
  newnoeud = malloc(sizeof(*newnoeud));
  if (newnoeud == NULL){
    printf("Problème de mémoire\n");
    exit(1);
  }

  /*initialisation*/
  newnoeud->filsg = NULL;
  newnoeud->frered = NULL;
  newnoeud->lettre = *m;
  /* renvoie l'adresse*/
  return newnoeud;
}

int ajouteMot(Arbre *a, char *m) {
  //si le mot ne contient aucune lettre
  if(m == NULL)
    return 0;

  //si on a atteint la fin du mot à ajouter
  if(*m == '\0') {
    *a = alloueNoeud(m);
    return 1;
  }

//si arbre vide (aucun mot dedans), on ajoute la première
//lettre du nouveau mot à la racine et le reste dans ses fils
//gauches
  if((*a) == NULL) {
    *a = alloueNoeud(m);
    return ajouteMot(&(*a)->filsg, m+1);
  }
  //si arbre pas vide, on regarde si la lettre du noeud
  //actuel est le meme que la lettre qu'on veut mettre.
  //dans ce cas, on passe au fils gauche du noeud actuel.
  //sinon, on passe au frère droit du noeud actuel
  if((*a) != NULL) {
    if((*a)->lettre == *m) {
      return ajouteMot(&(*a)->filsg, m+1);
    }
    else return ajouteMot(&(*a)->frered, m);
  }
}

/*int recherche(Arbre a, char *m) { //a corriger
  //m tableau contenant les lettres du mot m
  if (a == NULL) return -1;
  //trouver la première lettre de m dans a
  if(a->lettre == *m) {
    if(a->filsg != NULL)
      return recherche(a->filsg, m+1);
    if(a->filsg == NULL) {
      printf("Présent\n");
      return 0;
    }
  }
//si on a pas trouvé la première lettre, on va voir le frère droit
  if(a->frered != NULL && a->lettre > *m)
    return recherche(a->frered, m);
//si aucun des frères ne contient la première lettre du mot recherché
  printf("Absent\n");
  return -1;
}*/

int afficheMots(Tarbre a, int current, char *tab[]) {
  if(a == NULL)
    return -1;
  if(a->filsg != NULL) {
    tab[current] = a->lettre;
    afficheMots(a->filsg, current+1, tab);
    }


  if(a->frered != NULL) {
    tab[current] = a->lettre;
    afficheMots(a->frered, current+1, tab);
  }
  //si feuille
  if(a->lettre == '\0') {
    for(int i = 0; i < current; i++) {
      printf("%c ", tab[i]);
    }
    printf("%c\n", a->lettre);
  }
}
//mettre un fichier contenant un texte dans arguments
int main(int argc, char *argv[]) {
  //détecter les mots dans le fichier (suites de chars
  //séparés par des espaces)
  //les mettre chacun dans un tableau de char mot[MAX_SIZE]
  Arbre arbre;
  char *tab[MAX_SIZE];
  ajouteMot(&arbre, "coucou");
  afficheMots(arbre, 0, tab);
}
