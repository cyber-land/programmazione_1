#include <iostream>

using namespace std;

void selection_sort(int a[], int size) {
  for (int i=0; i<size; i++) {
    int min_i = i+1;
    for (int j=i; j<size; j++) {
      if ( a[j] < a[min_i] ) min_i = j;
    }
    // swap
    int temp = a[min_i];
    a[min_i] = a[i];
    a[i] = temp;
  }
}

int main() {
  int array[] = {5,4,3,2,1};
  selection_sort(array, 5);
  //merge_sort(array, 0, 5);
  for (int i=0; i<5; i++) cout << array[i]; cout << endl;

  return 0;
}
