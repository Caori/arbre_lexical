#include <stdio.h>
#include <stdlib>

#define MAX_SIZE 50

typedef struct noeud {
  unsigned chat lettre;
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

int recherche(Arbre a, char *m) {
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
    return recherche(a->frereg, m);
//si aucun des frères ne contient la première lettre du mot recherché
  printf("Absent\n");
  return -1;
}

//mettre un fichier contenant un texte dans arguments
int main(int argc, char *argv[]) {
  //détecter les mots dans le fichier (suites de chars
  //séparés par des espaces)
  //les mettre chacun dans un tableau de char mot[MAX_SIZE]
  char * mot[MAX_SIZE];

  for(int i = 0; i < argc; i++) {
    mot[i] = argv[i];
  }
}
