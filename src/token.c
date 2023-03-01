#include "tokenizer.h"
#include <stdio.h>
int main(){
  printf("$");
  char str[50];
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
   
   char *st=str;
   printf("First character of next word is: %c \n",*word_start(st));


}
int space_char(char c){
    if(c==' '||c=='\t') return 1;
  return 0;
}
int non_space_char(char c){
  if(c==' '||c=='\t'||c=='\n') return 0;
  return 1;
}
char *word_start(char *str){
  while(*str){
    str++;
    if(str==" ")
      str++;
    return str;

  }
  str=NULL;
  return str;
    
  
  

} 
