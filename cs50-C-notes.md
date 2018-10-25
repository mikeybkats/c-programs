## cs50

### data types
***int*** - takes up 4bytes of memory. range of values they can store is limited to 32 bits. Range of -2^32 to 2^32.
***unsigned int*** doubles the positive range of an int
***char*** 1 byte of memory (8 bits) -128 to 128 character range.
***float*** 4 bits of memory - stores floating point values
***double*** double precision of float. twice the memory 64bits.
***void*** a type, not a data type. printf returns void.


##### integer overflow
you can only specify so many numbers after a decimal point

##### learning about arrays, cryptography and debugging
mutable vs unmutable data objects
##### debugging

### cs50 debugger AKA debug50
***this opens the debugger:***
```c
> debug50 _nameofprogram.c
```

### problem set areas of evaluation graded from 1 - 5
scope
correctness
design
style

### cryptography
       secret key =>
input (plaintext) => [ ] => output (ciphertext)

to decrypt:
reverse the outputs and inputs

c language actually has no strings. a string in c is a sequence of characters (chars)

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  string s = get_string();
  if (s != NULL){
    for (int i = 0; i < strlen(s); i++)
    {
      printf("%c\n", s[i]);
    }
  }
}
```

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  string s = get_string();
  if (s != NULL){
    for (int i = 0, n = strlen(s); i < n; i++)
    {
      printf("%c\n", s[i]);
    }
  }
}
```

### Typecasting
allows you to convert one data type to another. like a char to an int.
think about ASCII it's simply code that maps letters to numbers.


##### explicitly cast char to int
```c
#include <stdio.h>

int main(void)
{
  for (int i = 65; i < 65 + 26; i++)
  {
    printf("%c is %i\n", (char) i, i);
  }
}
```


##### implicitly cast char to int:
c and printf are  smart enough to know that the first argument is a char.
```c
#include <stdio.h>

int main(void)
{
  for (int i = 65; i < 65 + 26; i++)
  {
    printf("%c is %i\n", i, i);
  }
}
```

##### Capitalize
```c
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string s = get_string();
if (s != NULL)
{
  for (int i = 0; n = strlen(s); i < n; i++)
  {
    printf("%c", toupper(s[i]));
  }
  printf("\n");
}
```

### strlen

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
  string s = get_string();
  int n = 0;
  // while the loop is still within the confines of the sequence of characters.
  while (s[n] != '\0')
  {
    n++;
  }
  printf("%i\n", n);
}

```

### What is \0 ?
\0 is the "secret breadcrumb" of c that demarcates the beginning and end of a sequence of characters.

### int main(with_arguments)
int main (int argc, string argv[])

```c
#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
  if(argc == z)
  {
    printf("hello, %s\n", argv[1]);
  }
  else{
    printf("hello, world!\n");
  }

}
```

##### anytime you run a program from the command line, you are performing an "argument vector."

a string is an array of chars
argv is an array of strings

### 2Dimensional Arrays

```C
  #include <cs50.h>
  #include <stdio.h>
  #include <string.h>

  int main(int argc, string argv[]){
    //iterate over strings in argv
    for (int i = 0; i < argc; i++){
      //iterate over characters in current string
      for (int j = 0, n = strlen(argv[i]); j < n; j++){
        printf("%c\n", argv[i][j]);
      }
    }
  }
```

### int main (void)
  what does it return? what int? if a return is not specified then it returns zero... if not, then you have an error message.


### valid triangle function
```C
  #include <cs50.h>
  #include <stdio.h>
  #include <math.h>

  bool valid_triangle(float a, float b, float c){
  if ( a <= 0 || b <= 0 || c <= 0){
    printf("A false triangle.\n");
    return false;
  }
  if ( a+b<=c || a+c<=b  || c+b<=a ){
    printf("A false triangle.\n");
    return false;
  }
  printf("A true triangle.\n");
  return true;
  }

  int main(void){
    printf("Enter length of side a: ");
    float side_a = get_float();

    printf("Enter length of side b: ");
    float side_b = get_float();

    printf("Enter length of side c: ");
    float side_c = get_float();

    // printf("Side A is %f\n. Side B is %f\n. Side C is %f\n.", side_a, side_b, side_c);

    valid_triangle(side_a, side_b, side_c);
  }
```

### Scope
Scope is the characteristic of a variable that defines from which functions that variable may be accessed.

- local variables can only be accessed within the functions in which they are created.
- global variables can be accessed (and changed ) by any function in the program.

##### passed by value
local variables are passed by value. meaning:
    - the callee receives a copy of the passed variable not the actual variable itself.
    - the caller variable (original) goes unchanged unless overwritten.

##### c and arrays
C uses a lenient system for arrays. Array position number 1 is represented as [0]. But the last position in the array can be represented by [n-1]. (Tricky! Ha).


### Array declarations
```
type name [size];

float float_array[10];

int friends_ages[12];

```

```C
bool truthtable[10];

truthtable[2] = false;
if (truthtable[7] == true){
  printf("TRUE!\n");
}
truthtable[10] = true;
```

```C
// instantiation syntax
bool truthtable[] = { false, false, false, true };

// individual element syntax
bool truthtable[4];
truthtable[0] = false;
truthtable[1] = false;
truthtable[2] = false;
truthtable[3] = true;

```

```C
// 2 dimensional array.
// this one is like making a battleship game

bool battleship[10][10];

```

```C
// copying an array

int foo[5] = {1,2,3,4,5};
int bar[];

for (int j = 0; j < sizeof(foo); j++){
    bar[j] = foo[j];
}
```

##### Passed by reference
arrays are passed by reference. the callee receives the actual array - not a copy.

in other words... arrays are changed on the global level when manipulated within a function.

integers are not... change an int within a function and it will not be reflected in the global value.

##### adding command-line arguments to your program

```C
int main(int argc, string argv[])
//argv means argument vector. it stores an array of strings.
```

```
> ./progam.c arg1 arg2 arg3

```

###  #define
pound(#) define is a method to create a named constant. this constant can't be changed like a variable can.

```C
#define DECKSIZE 52

card deal_cards(deck name)
{
  for (int i = 0; i < DECKSIZE; i++)
  {
    // deal card
  }
}
```

### One way hash function
Also known as message digest, fingerprint or compression function. Takes a string and converts it into a fixed length binary sequence.

# Week three
#### Algorithmic Sorting and searching
What is an algorithm? Simply: a set of instructions for complete a task.

#### Types of sorting and searching:
Bubble sort, selection sort, insertion sort, merge sort, linear search, binary search

## Merge Sort
#### O(n log n) - Ω(n log n)
The most powerful way to sort. Sort smaller arrays and then merge them together in a sorted order.

```c
function mergeSort(){
  while(n > 1){
    // go to the middle of the array
    // sort left half of array
    // sort the right half of the array
    // merge the two halves together
      // from left to right (linearly) if element is smaller shift left
  }
}
```

## Bubble Sort
#### O(n<sup>2</sup>) - Ω(n)
Moves the higher valued elements towards the right and lower value elements generally towards the left.

```c
function bubbleSort(){
  int swap = -1;
  while (swap != 0){
    // repeat until swap counter value is zero:
      // reset swap counter to zero
      // look at each adjacent pair of elements
        // if those two elements are not in order swap them and add one to the swap counter
  }
}
```

## Selection Sort
#### O(n<sup>2</sup>) - Ω(n<sup>2</sup>)
Find the smallest unsorted element and add it to the end of the sorted list.

```c
function selectionSort(){
  for( i from 0 to n-1 ){
    while(no unsorted elements remain){
      // search the unsorted part of the data to find and select the smallest value between i'th and n-1'th
      // swap the smallest value found with the first element of the unsorted part
    }
  }
}
```
##PSET4 
#### xxd - a tool for viewing and editing .bmp files to screen in the command line. it shows the bytes in a file.

format as follows:

```  
$> xxd -c *column-number* -g *groupsize-bytes* -s *seek (place in bytes to start counting)* filename  
```

example command:  

```
$> xxd -c 36 -g 3 -s 54 large.bmp  
``` 

output:  

```  
00000036: 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00  ....................................
0000005a: 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00  ....................................
0000007e: 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00  ....................................
000000a2: 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00  ....................................
000000c6: 00ff00 00ff00 00ff00 00ff00 ffffff ffffff ffffff ffffff 00ff00 00ff00 00ff00 00ff00  ....................................
000000ea: 00ff00 00ff00 00ff00 00ff00 ffffff ffffff ffffff ffffff 00ff00 00ff00 00ff00 00ff00  ....................................
0000010e: 00ff00 00ff00 00ff00 00ff00 ffffff ffffff ffffff ffffff 00ff00 00ff00 00ff00 00ff00  ....................................
00000132: 00ff00 00ff00 00ff00 00ff00 ffffff ffffff ffffff ffffff 00ff00 00ff00 00ff00 00ff00  ....................................
00000156: 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00  ....................................
0000017a: 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00  ....................................
0000019e: 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00  ....................................
000001c2: 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00 00ff00  .................................... 
```

notes:  
columns needs to be divisible by the number of group size bytes. divide columns by the group size and this is is the number of columns per row output. hence - 36 / 3 = 12 which is why the previous output is 12 columns.

#### dif *file.file file.file*- is a tool for comparing two files line by line.  
if the files are the same there is no output.

## Structs  
Structs allow you to arrange the bytes in a data structure so the order takes on new meaning and becomes a kind of structure. It's like timbre in music. It's what makes a trumpet sound like a trumpet. Or in computer science what makes a .psd a .psd and a .bmp a .bmp or different.

```
"Why are these structs useful? Well, recall that a file is just a sequence of bytes  
(or, ultimately, bits) on disk. But those bytes are generally ordered in such a way  
that the first few represent something, the next few represent something else, and so  
on. "File formats" exist because the world has standardized what bytes mean what. Now,  
we could just read a file from disk into RAM as one big array of bytes. And we could  
just remember that the byte at location [i] represents one thing, while the byte at  
location [j] represents another. But why not give some of those bytes names so that we  
can retrieve them from memory more easily? That’s precisely what the  structs in bmp.h  
allow us to do. Rather than think of some file as one long sequence of bytes, we can  
instead think of it as a sequence of structs."  
``` 

# Data Structures
## Linked Lists  
- A clever combination of elements that allows the creation of a kind of dynamically sized array.
- each element in this data structure is a node and each node points to the next node
- each node is a struct with two elements. the first is some data type, the second is a pointer to another node of the same type:  

```c 
typedef struct sllist 
{
  VALUE val;
  struct sllist* next;
}
sllnode;
```

##### making and using a linked list inolves:
1 - creating the list 
2 - searching the list to find an element  
3 - inserting an element into the linked list  
4 - deleting an element  
5 - deleting the list  

##### creation  
```c

sllnode* create(VALUE Val);

// dynamically allocate memory for sllnode  
(sllnode*)malloc(sslnode);

// make sure sllnode != NULL 

// initialize VALUE: fill in the VALUE field 
// initialize next 

// return pointer to node  

```  




 
