#   Assignment Summary 

_in this assignment we've discovered a new type of data structures . 
We were amazed by the fact that we can reteive,add,search one word in group with O(m) 
(where m is the length of the desired word), this assignment summed up our skills in dynamically allocation 
and gave as a clear picture of how the Dynamic-Heap works our algorithm is simple and trivial : we receive an input from the standard input (we used fgets and file pointers (FILE*))._

_let word x with length of m , before x is inserted in the trie its copied to a global char** variable, after x is inserted 
we traverse in the global char** variable for each i var[i] is printed then we search for it in the Trie with O(m) complexity 
after its found the last Node* consists of Integer field called counter we return the counter and print it beside the word x._

_qsort() && strcmp() functions were also used to sort the words in the global char** variable lexicographically 
on the other hand lixcographically reverse used the same algorithm but we simple started printing the words from length till i=0._
___
## Links
---
* **GeeksForGeeks**
  * [Trie](https://www.geeksforgeeks.org/trie-insert-and-search/)
* **TutorialsPoint**
    * [fgets](https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm)
    * [qsort](https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm)
  ---
  <!--Images-->
  ![Trie](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Trie.png)
___
### illustration
1.
```bash
./frequency
```
**the bash command above gives**
```bash
age  2
best  1
foolishness  1
it  4
of  4
the  4
times  2
was  4
wisdom  1
worst  1
ubuntu:~/environment (master) $ ...
```
2.
```bash
./frequency_r
```
**the bash command above gives**
```bash
worst  1
wisdom  1
was  4
times  2
the  4
of  4
it  4
foolishness  1
best  1
age  2
ubuntu:~/environment (master) $ ...
```
---
_Contributed by:_
* Abed El Kareem Massarweh
---

# End of Summary
