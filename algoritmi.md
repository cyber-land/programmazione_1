### algoritmi di ricerca
slide: 11.1

la **chiave** identifica un elemento dell'insieme
la chiave può essere **univoca** se identifica al massimo un singolo elemento oppure **multipla** se può identificare più di un elemento
nel secondo caso bisogna chiarire se si vuole recuperare il primo elemento (che rispetta la proprietà), l'ultimo, uno qualsiasi o tutti.

la ricerca **sequenziale** si usa nel caso di insiemi non ordinati
nel caso si voglia recuperare un singolo elemento allora il caso medio è `n/2` mentre se si vogliono recuperare tutte le occorrenze allora `O(n)`
```c
int sequential_search(array, size, key) { // pseudocode
	for (int i=0; i<size; i++)
		if (array[i] == key) return i;
	return -1; // no match
}
```

la ricerca **binaria** (o dicotomica) viene usata su insiemi ordinati
richiede accessi casuali quindi è inefficiente su [[strutture dati#linked list]]
il caso medio ha complessità `log(n)`
```c
int recursive_binary_search ( int array[],
int start_index, int end_index, int key ) {
	if (end_index > start_index) return -1;
	int middle = ( start_index + end_index )/2;
	
	if (array[middle] == key) // caso base
		return middle;
	if (array[middle] > key)
		return fun(array, start_index, middle-1, key);
	else
		return fun(array, middle+1, end_index, key);
}
```

### algoritmo di ordinamento
slide: 11.3

**selection sort**
Time Complexity: Θ(n²)

Selection Sort operates in a very simple way; it goes through all the elements in a data-set one by one comparing the value of one element to the next checking to see if the element is smaller, it then saves the smallest element found in a variable and when the iteration is complete, it will insert that saved element to its respective position in that data-set swapping positions with the value in that position.

This algorithm has an Θ(n²) because in the worst and best-case-scenario we have to iterate through all the **n** elements in the array and repeat this process **n** number of times, even if the data-set is already sorted there is no telling if it is until all the iterations in the algorithm are complete.

![[selection_sort.gif]]

```c
void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void selectionSort(int arr[], int n) {
	// One by one move boundary of unsorted subarray
	for (int i = 0; i < n-1; i++) {
		// Find the minimum element in unsorted array
		int min_idx = i;
		for (j = i+1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
// Swap the found minimum element with the first element
		if (min_idx != i)
			swap(&arr[min_idx], &arr[i]);
    }
}
```

**merge sort**
Time Complexity: Θ(n log n)

Merge Sort is considered to be one of the fastest sorting algorithms.
The idea of Merge Sort is to divide the data-set into smaller data-sets, sort those smaller data-sets and then join them (merge them) together.
The way this algorithm behaves is by sorting the left side of the data-set first then the right part and then merging them.
Merge sort will divide in two the data-set until all the elements are separate then it will start joining from left to right in pairs then those pairs will merge from left to right until there are only two bigger pairs to join.
If we think about it, this makes it easy to merge because if we have to parts of a data-set that are both sorted we can then compare the first element in one data-set with the other and determine which one is smaller, therefore, pushing that smaller element first into a new data-set.

This algorithm has the same Time Complexity for both worst and best-case scenarios because even if the array is sorted(best-case) the algorithm will still have to do the full procedure to determine whether the data-set is sorted or not.

![[merge_sort.png]]

```c
mergesort(array, start_index, end_index) { // pseudocode
	if (start_index < end_index) {
		middle = floor( (start_index+end_index)/2 )
		mergesort(array, start_index, middle)
		mergesort(array, middle, end_index)
		merge(array, start_index, middle, end_index)
	}
}
```
