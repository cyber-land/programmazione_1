#include <iostream>
#include <cstring>
#include <string>
#include "queue.h"
using namespace std;

int main() {
  Data data = Data("a", "b", 10), data2 = Data( "b", "c", 5), data3 = Data("c", "d", 6);
  cout << equals(data, data) << endl;
  Queue *queue = new Queue();
  queue->put(data);
  queue->put(data2);
  cout << queue->print_head() << endl;
  return 0;
}

