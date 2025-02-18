#include <iostream>
#define MAX 3
using namespace std;

struct Stack {
  int S[MAX];
  int top;
};
Stack st;

void push() {
  int item;
  if (st.top == (MAX - 1))
    cout << "Stack Overflow\n";
  else {
    cout << "Enter the item to be pushed in stack: ";
    cin >> item;
    st.top++;
    st.S[st.top] = item;
  }
}
void pop() {
  int item;
  if (st.top == -1) /* stack empty condition */
    cout << "Stack Underflow\n";
  else {
    item = st.S[st.top];
    st.top--;
    cout << "Element popped from stack is:" << item << endl;
  }
}
void display() {
  if (st.top == -1)
    cout << "Stack is empty\n";
  else {
    cout << "Stack elements:\n";
    for (int i = st.top; i >= 0; --i)
      cout << st.S[i] << endl;
  }
}

int main() {
  st.top = -1;
  int choice;
  do {
    cout << "Menu: " << endl;
    cout << "1.Push " << endl;
    cout << "2.Pop " << endl;
    cout << "3.Display " << endl;
    cout << "4.Exit " << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Enter a valid option!" << endl;
      break;
    }
  } while (choice != 4);

  return 0;
}
