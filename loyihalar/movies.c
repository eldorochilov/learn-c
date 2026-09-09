#include <ctype.h>
#include <stdio.h>

int main(void) {
  int i;
  int counter = 0;
  char answer;

  char *movies[9] = {
      "Terminator",
      "Gladiator",
      "Titanic",
      "Matrix",
      "Devergent",
      "Argo",
      "Apacalipto",
      "Tor",
      "Abdullajon",
  };

  int movieratings[9];

  char *tempmovies = " Filmlar reytenglari uchun ishlatiladi!";

  int outer, inner, didSwap, temprating;

  printf(" Filmlarni reytingini aniqlashni boshla!\n");

  for (i = 0; i < 9; i++) {
    printf(" %s korganmisiz? (Y/N): ", movies[i]);
    scanf(" %c", &answer);
    if ((toupper(answer)) == 'Y') {
      printf(" Bahoyingiz 1-10 gacha: ");
      scanf(" %d", &movieratings[i]);
      counter++;

      continue;
    } else {
      movieratings[i] = -1;
    }
  }

  for (int outer = 0; outer < 8; outer++) {
    didSwap = 0;
    for (inner = outer; inner < 9; inner++) {
      if (movieratings[inner] > movieratings[outer]) {
        tempmovies = movies[inner];
        temprating = movieratings[inner];
        movies[inner] = movies[outer];
        movieratings[inner] = movieratings[outer];
        movies[outer] = tempmovies;
        movieratings[outer] = temprating;
        didSwap = 1;
      }
    }
    if (didSwap == 0) {
      break;
    }
  }

  printf("\n ** Оскар 2012 **\n");
  for (i = 0; i < counter; i++) {
    printf("%s baholandi %d!\n", movies[i], movieratings[i]);
  }

  return 0;
}
