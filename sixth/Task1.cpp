/*
Part 2: Lab Tasks: (10 points)
Problem: Reversing a Queue
Description
Write a program that will reverse the content of a Queue using the following
standard queue operations. • enqueue(x) : Add an item x to rear of queue. •
dequeue() : Remove an item from front of queue. • empty() : Checks if a queue is
empty or not. For reversing the queue one approach could be to store the
elements of the queue in a temporary data structure in a manner such that if we
re-insert the elements in the queue they would get inserted in reverse order. So
now our task is to choose such data-structure which can serve the purpose.
According to the approach, the data-structure should have the property of ‘LIFO’
as the last element to be inserted in the data structure should be the first
element of the reversed queue. Using the new data structure to store the
elements of the queue temporarily should: • Pop the elements from the queue and
insert into the new data structure. (first element of the data structure is last
element of the queue) • Pop the elements of the data structure to insert back
into the queue. (The last element of the data structure is the first one to be
inserted into the queue) Input Format The program should accept N series of
integer values where 1 < N < 10 separated by a space and stored in a queue. If
the input N integer exceeds the allowed number of input the program should
display an error message.i Example Input Enter N Integer values: 1 2 3 4 5 6 7 8
9 10 Output Format The program should display the reverser order of the queue
elements in a single line separated by a space. (Note: that only queue standards
operations can be used to display the queue elements). Example Output Reverse
Queue: 10 9 8 7 6 5 4 3 2 1 Example Program Execution Enter N Integer values: 10
40 60 20 80 Reverse Queue: 80 20 60 40 10
*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q) {
  stack<int> s;
  while (!q.empty()) {
    s.push(q.front());
    q.pop();
  }
  while (!s.empty()) {
    q.push(s.top());
    s.pop();
  }
}

int main() {
  queue<int> q;
  int n, element;
  cout << "Enter number of elements: ";
  cin >> n;
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) {
    cin >> element;
    q.push(element);
  }
  reverseQueue(q);
  cout << "Reversed queue: ";
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}
