#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

/*int ajouteMot(Arbre *a, char *m) {
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
}*/

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

/*int afficheMots(Arbre a, int current, char *tab[]) {
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
}*/

//prend le tableau tab contenant un string, traite le string :
//lis le string dans tab jusqu'à tomber sur un ' ', ',', '-'...
//et met le string lu dans une case du tableau word[]
// i indice du caractère dans tab, j indice du mot dans mots[]
/*int fillTab(char mots[][100], int i, int j, char tab[]) {
  int k = 0;
  char word[MAX_SIZE];
  while(tab[i] != ' ' && tab[i] != ','  && tab[i] != '.' && tab[i] != '-' &&
    tab[i] != "\'" && tab[i] != '\n') {
    word[k] = tab[i];
    k++;
    i++;
  }
  word[k] = '\0';
  j++;

  if(tab[i] == '\n') //si c'est la fin de la ligne dans tab
    return j;

  if(&tab[i] == NULL)
    return j;

  else {
    strcpy(&mots[j][100], word); //met le mot word dans la cellule j de mots
    j = fillTab(mots, i, j, tab);
  }
return j;
}*/


int readTextFile(char mots[][100]) {
  char ligne[100];
  int i = 0;
  int j = 0;
  FILE * file;
  file = fopen("texte.txt", "r");
  if(file != NULL) {
    //tant qu'il reste des lignes de texte dans le fichier
    //fgets lit le texte jusqu'à un \n ou jusqu'à la limite de caractères
    //à lire (ici 100), et met la chaine lue dans tab
    while(fgets(ligne, 100, file) != NULL) {
      i = 0;
      int fin = 0;
      while(ligne[fin] != '\0') {
        for(; !isalpha(ligne[i]) ; ++i) {
          if(ligne[i] == '\0')
            break;
        }
        if(ligne[i] == '\0')
          break;
        int fin = i;
        for(; isalpha(ligne[fin]); ++fin)
          ;
        strncpy(&mots[j][0], &ligne[i], fin-i);
        j++;
        i = fin;
      }
    }
  }
  fclose(file);
  return j; //nombre de mots
}

//mettre un fichier contenant un texte dans arguments
int main(int argc, char *argv[]) {
  //détecter les mots dans le fichier (suites de chars
  //séparés par des espaces)
  //les mettre chacun dans un tableau de char mot[MAX_SIZE]
  //Arbre arbre;
  //char *tab[MAX_SIZE];
  int i = 0;
  int j = 0;
  int k = 0;
  char mots[100][100] = {0};
  //ajouteMot(&arbre, "coucou");
  //afficheMots(arbre, 0, tab);
  j = readTextFile(mots);
  for(k = 0; k < j; k++) {
    printf("%s\n", mots[k]);
  }

}
