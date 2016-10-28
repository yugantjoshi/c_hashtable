#include "count.h"
int main(int argc, char const *argv[]) {
  FILE *file;
  file = fopen(argv[1], "r");
  if(file)
  {
    hashTable = (Hash*)malloc(sizeof(Hash));
    int i,totalUnique;
    size = 1000;
    for(i=0; i<size; i++)
    {
      hashTable[i].numElements = 0;
    }
    char line[20];
    while(fgets(line, sizeof(line), file)){
      long decimal = strtol(line, NULL, 0);
      //printf("line %s", line);
      //printf("dec %ld", decimal);
      int index = getHashIndex(decimal);
      int code = insertNode(index, decimal);
      if(code == 5)
      { //printf("code %d\n",code);
        //printf("rehashed, need to insert again\n");
        insertNode(index, decimal);
      }
    }
    totalUnique = countUnique();
    printf("%d", totalUnique);
  }
  return 0;
}
