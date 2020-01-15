#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHARS_SIZE 26
#define LINE_SIZE 256
#define FALSE 0
#define TRUE 1
typedef char* String;
//#include "globalvars.h"
typedef int int_64;
typedef int_64 boolean;
/**our global String array (array of pointers to chars)
 */
String* WORDS;
int iterator=0;
struct Node
{
    size_t counter;
    boolean is_word;
    struct Node* children[CHARS_SIZE];
};
/**
 * int out trie node we have 2 fields
 * 1) is_word determines if is word or not
 * 2) array of pointers to other nodes such that arr[index]
 * means node that resemples index in alphabit of 26 letters
 */
struct Trie
{
    struct Node* root;

};
typedef struct Node Node;
typedef struct Trie Trie;

size_t char_to_alphabit(char x){
    size_t index= (size_t)(x%32);
    return index-1;
}
////////////////////////////////////////////////
//                                          ////
//          CONSTRUCTORS                    ////
////////////////////////////////////////////////
Node* newnode(Node* x){
    x=(Node*)malloc(sizeof(Node));
    (x)->counter=0;
    return x;
}

void newnode1(Node** x){
    *x=(Node*)malloc(sizeof(Node));
    (*x)->is_word=FALSE;
    (*x)->counter=0;
    return;
}
void newnode2(Node** x){
    x=(Node**)malloc(sizeof(Node*));
    (*x)->is_word=FALSE;
    (*x)->counter=0;
    return;
}
void newtrie(Node** shoresh,Trie** tree){
    *tree=(Trie*)malloc(sizeof(Trie));
    (*tree)->root=*shoresh;
    return;
}
///////////////////////////////////////////////////
//METHOD ZONE:
void insert_word(String word,Node* root){
    Node* n= root;
    size_t i=0;
    size_t index;
    while(word[i]){
        index=char_to_alphabit(word[i]); //converting
        if(i==(strlen(word)-1)){
            //indicates end of word
            if(n->children[index]==NULL){
                (n)->children[index]=newnode(n);
            }
            (n)->children[index]->is_word=TRUE;
            (n)->children[index]->counter++;
        }
        if(!((n)->children[index])){
            (n)->children[index]= newnode(n); //alloc a place for a new one
        }
        //in all ways we traverse in the node we made
        n=(n)->children[index];
        ++i;
    }
}

boolean search(Node** root,String word){
    size_t i=0;
    size_t index;
    Node* n= *root;
    while(word[i])///means while word[i]!='\0';
    {
        index=char_to_alphabit(word[i]);
        if((n)==NULL){
            printf("the Trie is empty !\n");
            return FALSE;
        }
        if((n)->children[index]==NULL){
            printf("word doesn't exist in the Trie\n");
            return FALSE;
        }
        //else at least the first letter exists !
        if(i==(strlen(word)-1)&&((n)->children[index]->is_word==TRUE)){
            //indicates end of word
            return TRUE;
        }
        n=(n)->children[index];
        ++i;

    }

}
size_t search_count_rec(Node* root,String str, size_t i)
{
    size_t index= char_to_alphabit(str[i]);
    if((root)->children[index]==NULL){
        //printf("word doesn't exist in Trie");
        return 0;
    }
    if((i==strlen(str)-1)&&((root)->children[index]->is_word==TRUE))
    {
        return (root)->children[index]->counter;
    }
    return search_count_rec(((root)->children[index]),str,++i);
}
void search_count(String str,Node* root)
{
    size_t i=0;
    size_t counter;
    if(root==NULL){
        printf("Trie is empty :(");
        return;
    }
    //else we traverse recursively till we reach last char of the desired word && the node->children[index]->isword== TRUE
    //then we return the counter field of that node :)
    counter=search_count_rec(root,str,i);
    printf("%s  %ld",str,counter);
}
void get_words(Node** root){
// i'm trying to do (smart) allocation , firstly i'm going to give a huge calloc for the String so it can accept
//any kind of word of any kind of length (26*sizeof(char)) would be alright , then i'm going to calculate the size
// of the string i got and realloc the previous calloc , .... you know what ? forget it  ,that allocation would fall sometimes
//in case we get 1 char as a String ,then we get i>1 (such that i is length of Strings to come) them i'm in danger since

    String word;
    word=(char*)calloc(26,sizeof(char));
    printf("please enter the desired word to search for : ");
    gets(word);
    search_count(word,root);

}
void erase(char** word,size_t length){
    size_t i;
    char* actual=*word;
    for (i = 0; i<length; i++) {
        actual[i]='\0';
    }
}
boolean is_in( int length,String word)
{
    int i,j;
    if(WORDS==0) return FALSE;
    for (i = 0; i<length; i++) {
        if(comparator(&word,&WORDS[i])==0){
            return TRUE;
        }
    }
    return FALSE;
}
int count_chars(String word){
    size_t i;
    int counter=0;
    for (i = 0; word[i]; ++i) {
        counter++;
    }
    return counter;
}
/**
 * in get_line we get the each line from the file_name.txt ,
 * we gather each word in the line and send it to global String arr[]
 * then we use qsort() in order to sort the strings in arr lexicographically
 * after it's sorted we print arr[i] && it's occurrence #
 */
boolean get_line(Node* root) {
    char line[LINE_SIZE];//for the whole line
    boolean flag = TRUE;
    size_t i, j;
    size_t iterate;
    static size_t z = 0;
    static int it = 0;
    j = 0;
    char *word = (char *) calloc(26, sizeof(char));
    flag = gets(line); //get a line from the text file
    if (flag) {
        for (i = 0; i <=count_chars(line); i++) {
            if ((line[i] == '\n') || (line[i] == '\t') || (line[i] == ',') || (line[i] == ' ') || (line[i] == '.')) {
                word[j]='\0';
                j = 0;
                //TODO: check duplicates we are not interested in adding similar words
                if (!(is_in(z, word))) {
                    (WORDS) = (char **) realloc(WORDS, (z + 1) * sizeof(String));
                    WORDS[z] = (char *) calloc(strlen(word), sizeof(char));
                    strcpy(WORDS[z], word);
                    z++;
                }
                insert_word(word, root);
                printf("\n");
                memset(word, 0, strlen(word));
                //  z++;
                if ((line[i] == ',') && (line[i + 1] == ' ')) {
                    ++i;
                }
            } else {
                word[j++] = line[i];
            }//collecting 1 word at once to go and search for it in the Trie :)
        }
        iterator=z;
    }
    else {
        iterator = z;
        return flag;
    }
}
void free_Trie(Node** n){
    if((*n)==NULL){
        return;
    }
    for (int i = 0; i <CHARS_SIZE; i++) {
        free_Trie(&((*n)->children[i]));
        free(*n);
    }

}
void free_all(Node* curs)
{
    int i;
    if(!curs) return;


    for (i = 0; i < 26; i++)
        free_all(curs->children[i]);



    free(curs);
}
int comparator (const void** str1, const void** str2){
    const String str11=*(const String**) str1;
    const String str22=*(const String**) str2;
    int ans=strcmp(str11,str22);
    if(ans>0){
        return 1;
    }
    if(ans<0){
        return -1;
    }
    return 0;
}
void print_words(Node* root,size_t size1){
    size_t i;
    size_t size= size1;
    qsort(WORDS,size,sizeof(WORDS[0]),comparator);
    for (i=0; i<size; i++) {
        search_count(WORDS[i],root);
        printf("\n");
    }
}
void print_words_reverse(Node* root,size_t size1){
    int i;
    size_t size= size1;
    qsort(WORDS,size,sizeof(WORDS[0]),comparator);
    for (i=size-1;i>=0; i--) {
        search_count(WORDS[i],root);
        printf("\n");
    }
}
