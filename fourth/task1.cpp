#include <iostream>
#include <stack>
#include <string>

using namespace std;

void menu() {
  cout << "Menu:\n";
  cout << "1. Visit a new website\n";
  cout << "2. Go Back\n";
  cout << "3. Exit\n";
}

int main() {
  stack<string> browserStack; // Stack to hold visited URLs
  int choice;
  cout<<"k";

  string url; // Declare url outside the switch statement

  while (true) {
    menu(); // Display the menu
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // Clear the newline character from the input buffer

    switch (choice) {
    case 1:
      cout << "Enter the URL of the website: ";
      getline(cin, url); // Use getline to allow spaces in URLs
      browserStack.push(url);      // Push the URL onto the stack
      break;
    case 2:
      if (!browserStack.empty()) {
        cout << "Going back to: " << browserStack.top() << "\n";
        browserStack.pop(); // Remove the top URL from the stack
        if (!browserStack.empty()) {
          cout << "Current page at top of stack: " << browserStack.top()
                    << "\n";
        } else {
          cout << "No more pages to go back to.\n";
        }
      } else {
        cout << "Stack is empty. No pages to go back to.\n";
      }
      break;
    case 3:
      return 0; // Exit the program
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  }

  return 0;
}
