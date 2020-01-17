//
// Created by Abodi Msarwi on 15/01/2020.
//
#include <stdio.h>
#include "trie.h"
#define CHARS_SIZE 26
#define LINE_SIZE 256
#define FALSE 0
#define TRUE 1
extern String* WORDS;
extern int iterator;
int main()
{
    Node* root=NULL;
    root= newnode(root);
    Trie* tree=NULL;
    newtrie(&root,&tree);
    while(get_line(root)!=FALSE){}
    print_words(root,iterator);
    for (int i = 0; i <iterator; i++) {
        free(WORDS[i]);
    }
    free(WORDS);
    free_all(root);
    free(tree);
    return 0;
}