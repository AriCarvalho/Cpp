#include <stdio.h>

extern "C" int Add(int,int);
extern "C" int AddAll(int,...);

int main(int v,char **args){
  int i=AddAll(17,13,45);
  printf("i=%d",i);

}

