#include "tokenizer.h"
#include <stdio.h>
int main(){
  char str[50];
  printf("$");
  fgets(str,sizeof(str),stdin);
  printf("%s",str);
   for(int i=0;str[i];i++){
  char first=space_char(str[i]);
  if(first==1)
    puts("There is a space");
  }
  
   for(int i=0;str[i];i++){
   char second=non_space_char(str[i]);
  if(second==1)
    puts("No space");
   }
}
int space_char(char c){
  char *a=&c;
  while(*a++){
    if(c==' '||c=='\t') return 1;
  }
  return 0;
}
int non_space_char(char c){
  char *a=&c;
  while(*a++){
    if(c==' '||c=='\t') return 0;
  }
  return 1;
}
 
