#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


int randomNumber(){
  
  int randomData = open("/dev/random",O_RDONLY);
  printf("/dev/random opened?: %d\n",randomData);
  int randomNumber;
  int size = read(randomData,randomNumber,4);
  printf("randomNumber: %d\n",randomNumber);
  printf("size == 4? size: %d\n",size);
  close(randomData);

  return 0;
}

void main(){

  randomNumber();

}
