#include<bits/stdc++.h>
#define Ml 1024

using namespace std;

int main() {
  /*Read the file.*/

  char ch;
  int char_count = 0, word_count = 0, space_count = 0;
  int in_word = 0;
  FILE *fp;
  freopen("file_name.txt","r",stdin);

  char file_name[Ml];
  cin>>file_name;

  fp = fopen(file_name, "r");

  if(fp == NULL) {
    printf("Could not open the file %s\n", file_name);
    return 1;
  };

  while ((ch = fgetc(fp)) != EOF) {
    char_count++;

    if(ch == ' ' || ch == '\t' || ch == '\0' || ch == '\n') {
      if (in_word) {
        in_word = 0;
        word_count++;
      }

      if(ch = ' ') space_count++;

    } else {
      in_word = 1;
    }
  }

  printf("In the file input.txt:\n");
  printf("Number of characters: %d.\n", char_count);
  printf("Number of words: %d.\n", word_count);
  printf("Number of space: %d.\n", space_count);

  return 0;
}