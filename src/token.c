#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
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
   
   char *st0=str;
   /* char *st1=str;
   char *st2=str;
   char *st3=str;
   char *st4=str;
   */
   printf("First character of word is: %c \n",*word_start(st0));
   printf("This method should return a space: %c \n",*word_terminator(st0));
   printf("Number of words: %d \n ", count_words(st0));
   for(int i=0;str[i];i++){
     int first=space_char(str[i]);
     if(first==1){
       printf("Should return full word: %s \n",copy_str(st0,i));
       break;
     }
     }
   char** tokens= tokenize(st0);
   print_tokens(tokens);
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
  while(str[0]==' '||str[0]=='\n'||str[0]=='\t'||str[0]=='\r'||str[0]=='\f'||str[0]=='\v'){
    str++;
  }
  return str; 

} 
char *word_terminator(char *word){
  word=word_start(word);
  while(word[0]!=' '&&word[0]!='\n'&&word[0]!='\t'&&word[0]!='\r'&&word[0]!='\f'&&word[0]!='\v'){
    word++;
  }
  return word;
  
}
 int count_words(char *str){
   int counter=0;
    while(str[0]!='\n'){
      str=word_start(str);
      counter++;
      str=word_terminator(str);
      
      }
    return counter;

  }
char *copy_str(char *inStr, short len){
  char* newStr=(char*) malloc(len+1);
  inStr=word_start(inStr);
  for(int i=0;i<len;i++){
  newStr[i]=inStr[i];
  newStr[len]='\0';
  }
  return newStr;  
}
char **tokenize(char* str){
    int num_words = count_words(str);
    char **tokens = (char **) malloc((num_words+1)*sizeof(char *));
    int i;
    for(i = 0; i < num_words; i++) {
      str= word_start(str);
      char *end = word_terminator(str);
      tokens[i] = copy_str(str, end-str);
      str=end;
    }
    tokens[num_words] = NULL;
    return tokens;
}
void print_tokens(char **tokens) {
  int i;
  for(i = 0; tokens[i] != NULL; i++) {
    printf("%s\n", tokens[i]);
  }
}
void free_tokens(char **tokens) {
  int i;
  for(i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }
  free(tokens);
}
