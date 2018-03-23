#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 50

int readFile() {
  char mot[MAX_SIZE];
  FILE * file;
  file = fopen("texte.txt", "r");
  if(file == NULL) {
    return EXIT_FAILURE;
  }
  while(fscanf(file, "%s", mot) != EOF) {
  //while(fscanf(file, "%50[^,.]", &mot) != EOF) { fait une boucle infinie
    printf("%s\n", mot);
    //appel fonction pour ajouter mot à arbre
  }

  if(feof(file)) {
    printf("End of file\n");
    fclose(file);
  }

return 0;
}

int main() {
  readFile();

  return 0;
}
