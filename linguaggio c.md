# Control flow
```c
// Conditional Operator/Ternary Operator
a = b ? c : d;
// is equivalent to:
if (b) 
    a = c;
else   
	a = d;

// loops

// logical operators

// and
2 && 0 /* Returns 0. */
2 && 3 /* Returns 1. */
// or
0 || 1 /* Returns 1. */
// logical not
!1 /* Returns 0. */

```

# I/O
getchar/putchar

Operazioni di lettura/scrittura
```c
char name[10]={"jonas"};
File *file_w = fopen("file.txt","w");
File *file_r = fopen("file2.txt","r");

int scanf (stringa di controllo, indirizzo elementi)

int res1 = fprintf (file_w, "%s", name);
/* fscanf legge stringa da “file_r” e memorizza i caratteri in 'name' fino al carattere spazio, carriage return o tab e termina con NULL. */
int res2 = fscanf  (file_r, "%s", name);
// restituiscono il numero degli elementi effettivamente letti o stampati o numero negativo in caso di errore!!
printf("%s\n",name);
```

# Relational operators

Equals `==`

```c
1 == 0; /* evaluates to 0. */
1 == 1; /* evaluates to 1. */
int x = 5;
int y = 5;
int *xptr = &x, *yptr = &y;
xptr == yptr; //evaluates to 0, the operands hold different location addresses
// evaluates to 1, the operands point at locations that hold the same value
*xptr == *yptr;
// Not equal "!=" effectively returns the opposite result to that of the equals operator
```

Greater than ">"
Less than "<"
Greater than or equal ">="
Less than or equal "<="


**Bytewise operators**

Symbol Operator
`&` bitwise AND
`|` bitwise inclusive OR
`^` bitwise exclusive OR (XOR)
`~` bitwise not (one's complement)
`<<` logical left shift
`>>` logical right shift

**Math operations**

```c
#include<math.h>
printf("%i", powl(3,4));
```

# Data Types
slides: 5.1

https://en.cppreference.com/w/c/types/integer
The header `stdint.h` provides several fixed-width integer type definitions
Using the system header file `stdbool.h` allows you to use bool as a Boolean data type
For all types but char the signed version is assumed if the signed or unsigned part isomitted.

| type       | native                            | size (bits) | format specifier  | literals |
| ---------- | --------------------------------- | ----------- | ----------------- | -------- |
| bool       |                                   | 1           |                   |          |
| (u)int8_t  | (signed/unsigned) char            | 8           | (hhu) hhi/hhd - c |          |
| (u)int16_t | (signed/unsigned) short (int)     | 16          | (hu) hi/hd        |          |
| (u)int32_t | (signed/unsigned) int             | 32          | (u) i/d           |          |
| (u)int64_t | (signed/unsigned) long (int)      | 64          | (lu) li/ld        | (U)L     |
|            | (signed/unsigned) long long (int) | 64          | (llu) lli/lld     | (U)LL    |
|            | float                             | 32          | f                 | f, F     |
|            | double                            | 64          | lf                |          |
|            | long double                       | 128         | Lf                | l, L     |
| size_t     | unsigned long                     | arch        |                   |          |

**range signed:** \[- (2^size/2-1), 2^size/2-1\] **unsigned:** \[0, 2^size\]
The header file `limits.h` describes the limits of integers
*Conversions, Time and Date, Complex Arithmetic*

**Enumerations**

An enumeration is a user-defined data type consists of integral constants and each integral constant is given a name.

```c
enum color { RED, GREEN, BLUE };
color chosenColor = RED;
```

# Arrays

`type arrName[size];` for declaring a one-dimensional array

```c
int array[] = {[3] = 8, [0] = 9}; // the compiler can deduce the length of the array 
#define ARRLEN 10000
int array[ARRLEN][ARRLEN]; // declaring a matrix (two dimensional array)
size_t i, j;               // iterate the matrix
for (i = 0; i < ARRLEN; ++i) {
    for(j = 0; j < ARRLEN; ++j) {
        array[i][j] = 0;
    }
}
size_t size = sizeof(array); // size of `array` in bytes
size_t length = sizeof(array) / sizeof(array[0]); // number of elements in `array`
memset(array, 0, sizeof array); // 0-out the array
// C doesn't perform any boundary checks, accessing contents outside of the declared array is undefined
```

# Strings

A C-string is the convention to have a one-dimensional array of characters which is terminated by a null-character, by a `\0`

String literals will always be NUL-terminated by the compiler.

```c
#include<string.h>
// declare a character array and initialize its contents using a string literal
char foo[] = "hello";
foo[0] = 'y';
// any attempt to modify a string literal has undefined behavior
// declare a string literal (a pointer to the first element of the array)
/* const */ char *foo = "hello";
foo[0] = 'y'; // Undefined behavior
foo = "World!"; // but we can change what foo points to
```

**length**

```c
unsigned long len = strlen(foo);
printf("The length is %lu", len);
// strlen counts all the bytes so, if the string contains any Unicode characters,
// strlen will not tell you how many characters are in the string
```

**copies**

you cannot use the = operator to copy strings using the = operator will only save the address (pointer) of a string

```c
// shallow copy
char c[] = "abc", *d;
d = c; /* Only copies the address of the string - there is still only one string stored in memory */
// deep copy
char s1[20] = "GeeksforGeeks", s2[20];
memcpy(s2, s1, strlen(s2)); // uguale dimensione
memcpy(s2, s1, sizeof(s2)); // se la dimensione è diversa
```

**Copy and Concatenation**

```c
char mystring[10];
strcpy(mystring, "foo"); /* Copy "foo" into `mystring`, until a NUL character is encountered. */
printf("%s\n", mystring); // foo
// At this point, we used 4 chars of `mystring`, the 3 characters of "foo",and the NUL terminating byte.
strcat(mystring, "bar"); /* Append "bar" to `mystring`. */
printf("%s\n", mystring); //foobar
// We now use 7 characters: "foo" requires 3, "bar" requires 3 and the NUL character ('\0') at the end.
strcpy(mystring, "bar"); /* Copy "bar" into `mystring`, overwriting the former contents. */
printf("%s\n", mystring); //bar
```

**Iterating Over the Characters in a String**

```c
char * string = "hello world"; /* This 11 chars long, excluding the 0-terminator. */
size_t length = strlen(string);
int i = 0;
for (; i < length; i++) {
    printf("%c", string[i]);
}printf("\n");
while (string[i] != '\0') {
    printf("%c\n", string[i]);
    i++;
}
```

**string literals and how convert them to char arrays**

```c
char str[] = "abcdef"; // chars array (mutable)
char *ptl = str; // pointer to the same address
printf("str: size (%li byte) value (%s) address (%p) that point to (%c) \n",
sizeof(str), str, &str, *str );
printf("ptl: size (%li byte) value (%s) address (%p) that point to (%c) of address (%p) \n\n",
sizeof(ptl), ptl, &ptl, *ptl, ptl );

char *lit = "fedcba"; // string literal (read only)
printf("lit: size (%li byte) value (%s) address (%p) that point to (%c) of address (%p) \n",
sizeof(lit), lit, &lit, *lit, lit );

/** pointer arithmetic
quando si somma e sottrea interi ad un puntatore si moltiplica il 
valore per il numero di byte che occupa il tipo del puntatore */
printf("pointer arithmetic: address (%p) point to (%c) distance (%ld byte) \n\n",
(lit+2), *(lit+2), (lit+2)-(lit) );
// aggiungendo 2 al puntatore di chars si aggiunge (2 * 1 byte)
```

compile to something like
```
str: size (7 byte) value (abcdef) address (0x7ffeb6ffe4e1) that point to (a)    
ptl: size (8 byte) value (abcdef) address (0x7ffeb6ffe4d0) that point to (a) 
of address (0x7ffeb6ffe4e1)

lit: size (8 byte) value (fedcba) address (0x7ffeb6ffe4d8) that point to (f) 
of address (0x55df13b3b0a3)
pointer arithmetic: address (0x55df13b3b0a4) point to (d) distance (2 byte)
```

# Structs

Structures provide a way to group a set of related variables of diverse types into a single unit of memory. The structure as a whole can be referenced by a single name or pointer; the structure members can be accessed individually too. Structures can be passed to functions and returned from functions.

```c
struct ex3 {
    int foo;
    char bar;
    int flex[];
};
struct ex3 e3 = {1, 2}; /* valid: initialize foo=1, bar=2 members */
e3.flex[0] = 2; /* undefined behavior again */
```

You may instead choose to use malloc, calloc, or realloc to allocate the structure with extra storage and later free it, which allows you to use the flexible array member as you wish:

```c
/* valid: allocate 5 structure type ex3 objects along with an array of 3 ints per object */
struct ex3 *pe3 = malloc(5 * (sizeof(*pe3) + sizeof(int[3])));
pe3[0]->flex[0] = 3; /* valid */
```

When you have a variable containing a struct, you can access its fields using `.` (the dot operator)

However, if you have a pointer to a struct, this will not work. You have to use `->` (the arrow operator) to access its fields.

## Accesso ai campi

& è l’operatore unario di referenziazione. La sua operazione complementare è la
dereferenziazione o indirezione, effettuabile con l’operatore unario *

Gli operatori binari `.` e `->` svolgono la stessa funzione di `&` e `**` quando l’operando sinistro è
una struttura (o simile) e servono ad accedere all'operando destro che deve essere un
membro dell'operando sinistro.
La scrittura `->` vuol dire dereferenziazione e accesso al campo

# Functions
slides: 6.2

regole di visibilità (scope)
- il blocco
- la funzione
- il file
- il programma
alcune keyword ( come `extern` ) possono alterare quest'ordine

# Pointers

[https://www.geeksforgeeks.org/lvalue-and-rvalue-in-c-language/](https://www.geeksforgeeks.org/lvalue-and-rvalue-in-c-language/)
[https://disi.unitn.it/~riccardi/page7/page12/page12.html](https://disi.unitn.it/~riccardi/page7/page12/page12.html)

le variabili sono composte da:
- nome (identificativo)
- tipo 
- locazione di memoria (left value) (memory address) 

**L-value:** refers to memory location which identifies an object.

A modifiable l-value cannot have an array type, an incomplete type, or a type with the **const** attribute.

-   valore (right value) (memory value)

r-value refers to data value that is stored at some address in memory.

`type variableName = value;`

dereferencing pointer means change what the pointer point to

```c
char str[] = "abcdef"; // chars array (mutable)
char *ptl = str; // pointer to the same address
printf("str: size (%li byte) value (%s) address (%p) that point to (%c) \n",
    sizeof(str), str, &str, *str );
printf("ptl: size (%li byte) value (%s) address (%p) that point to (%c) of address (%p) \n\n",
    sizeof(ptl), ptl, &ptl, *ptl, ptl );
```

compile to something like
```
str: size (7 byte) value (abcdef) address (0x7ffea2939a49) that point to (a) 
ptl: size (8 byte) value (abcdef) address (0x7ffea2939a28) that point to (a)
    of address (0x7ffea2939a49)
```

# Files
slides: 8.2

Uno stream è una sorgente o destinazione di dati associato ad una periferica ( file ).
Ogni stream termina con un `EOF` (end of file)
- binario (sequenza di bytes) (non c'è traduzione dell'informazione)
- testuale (sequenza di caratteri)

Opening Modes in Standard I/O

|Mode|Meaning of Mode|During Inexistence of file|
|-|-|-|
|`r`|Open for reading|If the file does not exist, `fopen()` returns NULL|
|`rb`|Open for reading in binary mode|If the file does not exist, `fopen()` returns NULL.|
|`w`|Open for writing|If the file exists, its contents are overwritten. If the file does not exist, it will be created.|
|`wb`|Open for writing in binary mode.|If the file exists, its contents are overwritten. If the file does not exist, it will be created.|
|`a`|Open for append|Data is added to the end of the file. If the file does not exist, it will be created.|
|`ab`|Open for append in binary mode|Data is added to the end of the file. If the file does not exist, it will be created.|
|`r+`|Open for both reading and writing.|If the file does not exist, `fopen()` returns NULL.|
|`rb+`|Open for both reading and writing in binary mode.|If the file does not exist, `fopen()` returns NULL.|
|`w+`|Open for both reading and writing.|If the file exists, its contents are overwritten. If the file does not exist, it will be created.|
|`wb+`|Open for both reading and writing in binary mode.|If the file exists, its contents are overwritten. If the file does not exist, it will be created.|
|`a+`|Open for both reading and appending.|If the file does not exist, it will be created.|
|`ab+`|Open for both reading and appending in binary mode.|If the file does not exist, it will be created.|

Flushing significa scrivere i dati sul file, questo viene fatto automaticamente quando il file viene chiuso, ma in caso di errori (crash) non viene fatto il flush ed i dati potrebbero non venire scritti

Un FILE è una struttura che contiene:
- Campo per Modalità di utilizzo: Lettura, scrittura o lettura e scrittura
- Un campo per la Posizione corrente: Punta al prossimo byte da leggere o scrivere sul file
- Un campo indicatore di errore (per lettura e/o scrittura)
- Un campo contenente un indicatore di end-of-file (eof).

**write functions**

|function|operation|
|-|-|
| int puts (char \*s, FILE \*fp)|write text to file|
|putc(char, file)|write char to file|

Tutte restituiscono EOF come errore

**write**
```c
#include <stdio.h> /* for perror(), fopen(), fputs() and fclose() */
#include <stdlib.h> /* for the EXIT_* macros */
#define FILENAME "example.txt"
int main () {
/* Open file for writing and obtain file pointer */
FILE *file = fopen(path, "w");
/* Print error message and exit if fopen() failed */
if (!file) {
	perror(path);
	return EXIT_FAILURE;
}
if (puts("Output in file.", file) == EOF) {
	perror(path);
	return EXIT_FAILURE;
}
// You can use fprintf on a file just like you might on a console with printf.
fprintf(file, "Wins: %d\nTies: %d\nLosses: %d\n", 3, 7, 2);

fflush(file); // manual flushing

if (fclose(file)) {
	perror(path);
	return EXIT_FAILURE;
}
return 0; }
```

**read functions**

char \*fgets (char \*s, int length, FILE \*fp)

Legge al più length-1 caratteri dallo stream specificato e li memorizza nell’array s finche’ non incontra un carattere newline o EOF, oppure finche’ non vengono letti al piu’ n-1 byte.
Viene aggiunto NULL alla fine array. 
Restituisce NULL come errore.
Attenzione il carattere newline incontrato viene incluso nella stringa s.

getc(FILE \*fp)
 
read a char from file

**read**
```c
void print_all(FILE *stream) {
	int c;
	while ((c = getc(stream)) != EOF)
		putchar(c);
}

FILE *fp;
if ((fp = fopen("file.txt", "r")) == NULL) {
	perror("Error opening file");
	exit(EXIT_FAILURE);
}
print_all(fp);
fclose(fp);
```

**I/O file binari**

**Operazioni di gestione dei file**

• int remove (file_name)
• int rename (old_name, new_name)

# Headers

```c
#ifndef TIPO
#define TIPO

// code

#endif
```

# Recursion
