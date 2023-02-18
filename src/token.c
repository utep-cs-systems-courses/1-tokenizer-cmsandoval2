#include "tokenizer.h"
#include <stdio.h>
int main(){
  char str[50];
  printf("$");
  scanf("%s",str);
  puts(str);
  char first=space_char(str);
  if(first==1)
    puts("There is a space");
  else{
    puts("No Spaces or tabs");
  }
  

}
int space_char(char c){
  char *a=&c;
  while(*a++){
    if(c==' '||c=='\t') return 1;
  }
  return 0;

}
