#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int *randomNumber(){
  
  int randomData = open("/dev/random",O_RDONLY);
  int *randomNumber = malloc(sizeof(int)); // needs a pointer not a value
  int size = read(randomData,randomNumber,4);

  if(size == -1)
    printf("error: %s - \n",strerror(errno));

  close(randomData);

  return randomNumber;
}

void main(){
  
  printf("\n");
  
  printf("Generating Random Numbers:\n\n");
  int *arr[10];
  int i;
  for(i = 0; i < 10; i++){
    arr[i] = randomNumber();
    printf("   randomNumber %d: %d\n",i,*arr[i]);
  }

  printf("\n");
  
  printf("Writing to testText.txt\n\n");
  int writeFd = open("testText.txt",O_CREAT | O_EXCL | O_WRONLY,0644);
  int j;
  int size;
  for(j = 0; j < 10; j++){
    size = write(writeFd,arr[j],4);
    if(size == -1)
      printf("error: %s - \n",strerror(errno));
  }

  close(writeFd);

  printf("Reading from testText.txt\n\n");
  int readFd = open("testText.txt",O_RDONLY);
  int k;
  for(k = 0; k < 10; k++){
    int *readTemp = malloc(sizeof(int));
    size = read(readFd,readTemp,4);
    if(size == -1)
      printf("error: %s - \n",strerror(errno));
    printf("   randomNumber %d: %d\n",k,*readTemp);
  }

  printf("\n");
  
  close(readFd);
  
}
