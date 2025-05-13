#include <iostream>
using namespace std;
//
#define MAX 5
struct Queue { // define Queue structure
  int front, rear;
  int queue[MAX];
};

Queue q; // declare structure variable
// function to insert an element at the rear of the queue
void enqueue(int data) {
  // check queue is full or not
  if (MAX == q.rear) {
    cout << "\nQueue is full\n";
    return;
  } else {
    q.queue[q.rear] = data;
    q.rear++; // increment rear value
  }
}
// function to delete an element from the front of the queue

void dequeue() {
  // if queue is empty
  if (q.front == q.rear) {
    cout << "\nQueue is empty\n";
    return;
  }

  // remove front element.
  else {
    cout << q.queue[q.front] << "<-- data removed!\n";
    q.queue[q.front] = 0;
    q.front++; // increment front
  }
}
// print all queue elements

void display() {
  int i;
  if (q.front == q.rear) { // check queue if empty
    cout << "\nQueue is Empty\n";
    return;
  }

  // traverse front to rear and print elements
  for (i = q.front; i < q.rear; i++) {
    cout << q.queue[i] << " <-- ";
  }
}
// print front of queue

void front() {
  if (q.front == q.rear) // check if queue is empty
    cout << "\nQueue is Empty\n";

  // diplay front queue
  else
    cout << "\nFront Element is: " << q.queue[q.front];
}

// print rear of queue

void rear() {
  if (q.front == q.rear) // check if queue is empty
    cout << "\nQueue is Empty\n";

  // display rear queue
  else
    cout << "\nRear Element is: " << q.queue[q.rear - 1];
}
int main() {
  q.front = q.rear = 0; // Initialize front and rear to 0.
  int choice, data;

  do {
    // display Queue operations on a menu
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Front\n";
    cout << "4. Rear\n";
    cout << "5. Display Queue\n";
    cout << "6. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: // Call Enqueue Function
      cout << "\nEnter data to enqueue: ";
      cin >> data;
      enqueue(data);
      break;

    case 2: // Call Dequeue Function
      dequeue();
      cout << "\n";
      break;

    case 3: // Call Front Function
      front();
      cout << "\n";
      break;

    case 4: // Call Rear Function
      rear();
      cout << "\n";
      break;

    case 5: // Call Display Function
      display();
      cout << "\n";
      break;

    case 6: // Terminates program
      cout << "\nProgram terminated..";
      break;

    default: // Incorrect Input message
      cout << "\nIncorrect Input\n";
    }

  } while (choice != 6);

  return 0;
}
