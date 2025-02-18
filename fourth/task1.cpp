#include <iostream>
#include <stack>
#include <string>

void menu() {
  std::cout << "Menu:\n";
  std::cout << "1. Visit a new website\n";
  std::cout << "2. Go Back\n";
  std::cout << "3. Exit\n";
}

int main() {
  std::stack<std::string> browserStack; // Stack to hold visited URLs
  int choice;
  std::string url; // Declare url outside the switch statement

  while (true) {
    menu(); // Display the menu
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); // Clear the newline character from the input buffer

    switch (choice) {
    case 1:
      std::cout << "Enter the URL of the website: ";
      std::getline(std::cin, url); // Use getline to allow spaces in URLs
      browserStack.push(url);      // Push the URL onto the stack
      break;
    case 2:
      if (!browserStack.empty()) {
        std::cout << "Going back to: " << browserStack.top() << "\n";
        browserStack.pop(); // Remove the top URL from the stack
        if (!browserStack.empty()) {
          std::cout << "Current page at top of stack: " << browserStack.top()
                    << "\n";
        } else {
          std::cout << "No more pages to go back to.\n";
        }
      } else {
        std::cout << "Stack is empty. No pages to go back to.\n";
      }
      break;
    case 3:
      return 0; // Exit the program
    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  }

  return 0;
}
