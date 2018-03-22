#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 50

//marche pas mal, mais pb : prend pas les lettres accentuées !
int readTextFile(char mots[][100]) {
  char ligne[100];
  int i = 0;
  int j = 0;
  FILE * file;
  file = fopen("texte.txt", "r");
  if(file != NULL) {
    while(fgets(ligne, 100, file) != NULL) {
      i = 0;
      int fin = 0;
      while(ligne[fin] != '\0') {
        /*for(; ligne[i] == " " && ligne[i] == "," && ligne[i] == ":"
        && ligne[i] == "\'" && ligne[i] == "."; ++i) {*/
        for(; !isalpha(ligne[i]) ; ++i) {
          if(ligne[i] == '\0')
            break;
        }
        if(ligne[i] == '\0')
          break;
        int fin = i;
        /*for(; ligne[i] != " " && ligne[i] != "," && ligne[i] != ":"
        && ligne[i] != "\'" && ligne[i] != "."; ++fin)*/
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

int main(int argc, char *argv[]) {
  int j = 0;
  int k = 0;
  char mots[100][100] = {0};

  j = readTextFile(mots);

  for(k = 0; k < j; k++) {
    printf("%s\n", mots[k]);
  }
  printf("%s\n", mots[3]);
}
