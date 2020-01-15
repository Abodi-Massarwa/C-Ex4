//
// Created by Abodi Msarwi on 15/01/2020.
//

// #ifndef UNTITLED_HEADER_H
// #define UNTITLED_HEADER_H
#define CHARS_SIZE 26
#define LINE_SIZE 256
#define FALSE 0
#define TRUE 1
typedef int int_64;
typedef int_64 boolean;
typedef char* String;
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
size_t char_to_alphabit(char x);
Node* newnode(Node* x);
void newnode1(Node** x);
void newnode2(Node** x);
void newtrie(Node** shoresh,Trie** tree);
void insert_word(String word,Node* root);
boolean search(Node** root,String word);
size_t search_count_rec(Node* root,String str, size_t i);
void search_count(String str,Node* root);
void get_words(Node** root);
void erase(char** word,size_t length);
boolean is_in( int length,String word);
int count_chars(String word);
boolean get_line(Node* root);
void free_Trie(Node** n);
void free_all(Node* curs);
int comparator (const void** str1, const void** str2);
void print_words(Node* root,size_t size1);
void print_words_reverse(Node* root,size_t size1);
//#endif //UNTITLED_HEADER_H
