Abstract Data Type (ADT)

### alberi binari di ricerca
slide: 12.1, (E)24.1, file degli alberi di ASD)
https://btv.melezinek.cz/

A Binary Search Tree (BST) is a tree-like data structure that contains uniquely valued nodes. The nodes can have at most two children (or branches), one which is a smaller value (typically the left node), and another which houses a larger value (typically the right node).

Tutti gli elementi del sotto-albero sx sono minori (od uguali) del valore del nodo padre, mentre tutti gli elementi del sotto-albero dx sono maggiori del nodo padre.

```c
typedef struct Tree {
    Data value;
    Tree *left;
    Tree *right;
    Tree *parent;
} Tree;
```

|operation|complexity|
|-|-|
|access/search|O(log(n))|
|insert/delete|O(log(n))|

la **profondità** (depth) dei nodi/vertici è il numero di archi (edges) tra il nodo e la radice

The **height** of a node is the number of edges present in the shortest path connecting that node to a leaf node

il **livello** (level) è l'insieme dei nodi alla stessa profondità

l'**altezza/livello** dell'albero (height) è il numero di archi tra la radice (root) e la sua foglia più lontana ( anche detto il massimo tra i livelli di tutti i suoi nodi )

Un **cammino** nell’albero è una sequenza di vertici distinti, in cui i vertici successivi sono connessi da un arco dell’albero

(La lunghezza del) **cammino di un albero** è la somma dei livelli di tutti i nodi dell’albero

```
       5
     /    \
   10      15
  /  \    /  \
20   25  30  35
       \
       45
Depth of node 25 = 2 (archi tra 25 e 5)
Height of node 25 = 1 (archi tra 25 e 45)
level 1 = (10, 15)
height/level of the tree = 3
un cammino (tra 10 e 35) = (10, 5, 15, 35)
è una proprietà degli alberi che esista un solo possibile cammino tra due nodi
cammino dell'albero = 0 + 1*2 + 2*4 + 3*1 = 13
```

**visita in profondità** (Depth-First Search (DFS))
varianti: pre/in/post order
richiede uno stack
```cpp
dfs( Tree t ) {
    if ( t == null ) return;
	print( t ) // pre-order
	dfs( t->left )
	print( t ) // in-order
	dfs( t->right() )
	print( t ) // post-order
}
```

**visita in ampiezza** (level) (Breadth First Search (BFS))
richiede una queue
si visitano i nodi secondo l’ordine in cui essi appaiono sulla carta scandendo gli elementi dalla cima al fondo e da sinistra verso destra.

**ricerca del successore e del predecessore**
ognuna di queste funzioni ha complessità O(height of the tree)
```c
successor (Tree x) {
    // primo caso ( sotto-albero dx )
    if x.right != NULL then
        return minimum( x.right )
    // secondo/terzo caso
    y = x.parent
    while y != NULL and x == y.right do
        x = y, y = p[x]
    return y
}
predecessor (Tree x) {
    // primo caso ( sotto-albero sx )
    if x.left != NULL then
        return maximum( x.right )
    // secondo/terzo caso
    y = x.parent
    while y != NULL and x == y.left do
        x = y, y = x.parent
    return y
}
minimum (Tree x) {
    while x.left != NULL do
        x = x.left
    return x
}
maximum (Tree x) {
    while x.right != NULL do
        x = x.right
    return x
}
```

### linked list
slide: 9.2
concatena gli elementi in zone di memoria che possono essere anche distanti tra loro
a differenza degli array, queste contengono un numero variabile di elementi

|operation|array|singly linked list|doubly linked list|array list|
|-|-|-|-|-|
|indexing|O(1)|O(n)|O(n)|O(1)|
|insert/delete at the end|n/a|O(n)|O(1)|O(1)|
|insert/delete at the beginning|n/a|O(1)|O(1)|O(n)|
|insert/delete in middle|n/a|search time + O(1)|search time + O(1)|O(n)|

```c
typedef struct Node {
	Data data;
	Node * next;
	Node * prev; // for doubly linked list
} Node;
// for doubly linked list
typedef struct List {
  Node* head;
  Node* tail;
} List;
```

le linked-list circolari si chiamano cosi perchè `*prec` della coda (tail) punta alla testa (head) ed il `*next` della testa punta alla coda

le pile (stack) e le code (queue) vengono implementate usando gli array o le linked-list e quindi hanno la relativa complessità nelle operazioni
la loro struttura risulterà diversa (semplificata) perchè rispetto alle liste possono eseguire meno operazioni

### stack/LIFO
slide: 10.1, E18.1, E20.1
è una lista dove l'inserimento (`push`) e l'estrazione (`pop`) avvengono solo dalla testa

```cpp
typedef struct Node {
  Data data;
  Node * next;
  Node (Data d, Node * n) { data = d, next = n; }
} Node;
// inserisce 'data' nella pila e ritorna il nuovo primo elemento
// che il nodo che contiene 'data'
Node* push (Node* node, Data data) {
  return new Node(data, node);
}
// ritorna una copia del primo elemento (se esiste)
Data read (Node* node) {
	assert(node != NULL); // panic
	return node->data;
}
// elimina il primo elemento e ritorna il riferimento al nuovo primo elemento
Node* pop (Node* node) {
	if ( node == NULL) return node;
	Node* next = node->next;
	delete node;
	return next;
}
```

### queue/FIFO
slide: 10.2, E18.2, E19.0
è una lista dove l'inserimento (`enqueue` / `put`) viene esclusivamente in coda (`rear`), mentre estrazione (`dequeue` / `get`) esclusivamente in testa (`front`)

```cpp
// implementazione doppiamente concatenata
typedef struct Queue {
  Node* head;
  Node* tail;
  Queue () { head = NULL; tail = NULL; }
  void put ( Data data );
  Data get ();
} Queue;
typedef struct Node {
    Data data;
    Node * next;
    Node * prev;
    Node (Data d, Node * n, Node * p) { data = d; next = n; prev = p; }
} Node;

void Queue::put ( Data data ) {
  if (tail == NULL) { // if the queue's empty
    Node * n = new Node(data, NULL, NULL);
    tail = head = n;
  } else {
    Node * n = new Node(data, tail, NULL);
    tail = tail->prev = n;
  }
}
Data Queue::get () {
  assert (head != NULL); // panic if the queue is empty
  Data data = head->data;
  Node* backup = head;
  if (head == tail) { // if the queue contains a single element
    tail = head = NULL;
  } else {
    head = head->prev;
    head->next = NULL;
  }
  delete backup;
  return data;
}
```
