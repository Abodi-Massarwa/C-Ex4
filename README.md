# Assignment Summary :

*in this assignment we've discovered a new type of data structures . 
We were amazed by the fact that we can reteive,add,search one word in group with O(m) 
(where m is the length of the desired word), this assignment summed up our skills in dynamically allocation 
and gave as a clear picture of how the Dynamic-Heap works our algorithm is simple and trivial : we receive an input from the standard input (we used fgets and file pointers (FILE*)).

let word x with length of m , before x is inserted in the trie its copied to a global char** variable, after x is inserted 
we traverse in the global char** variable for each i var[i] is printed then we search for it in the Trie with O(m) complexity 
after its found the last Node* consists of Integer field called counter we return the counter and print it beside the word x.

qsort() && strcmp() functions were also used to sort the words in the global char** variable lexicographically 
on the other hand lixcographically reverse used the same algorithm but we simple started printing the words from length till i=0.*

# End of Summary
