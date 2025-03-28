/*
 * Problem Description
A bracket is considered to be any one of the following characters: (, ), {, },
[, or ]. Two brackets are considered to be a matched pair if the an opening
bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ],
or }) of the exact same type. There are three types of matched pairs of
brackets: [], {},and (). A matching pair of brackets is not balanced if the set
of brackets it encloses are not matched. For example, {[(])} is not balanced
because the contents in between { and } are not balanced. The pair of square
brackets encloses a single, unbalanced opening bracket, (, and the pair of
parentheses encloses a single, unbalanced closing square bracket, ].
By this logic, we say a sequence of brackets is balanced if the following
conditions are met:
- It contains no unmatched brackets.
- The subset of brackets enclosed within the confines of a matched pair of
brackets is also a matched pair of brackets. Given string of brackets, determine
whether the sequence of brackets is balanced. If a string is balanced, print
YES. Otherwise, print NO. Input Format A single string s represents a sequence
of brackets. Output Format Print YES or NO. Sample Input
{[()]}
Sample Output
YES
*/
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

string isBalanced(const string &s) {
  // Map to hold matching pairs of brackets
  unordered_map<char, char> bracket_map = {{')', '('}, {'}', '{'}, {']', '['}};

  stack<char> stack;

  for (char ch : s) {
    // If the character is a closing bracket
    if (bracket_map.count(ch)) {
      // Check if the stack is not empty and the top matches
      if (!stack.empty() && stack.top() == bracket_map[ch]) {
        stack.pop(); // Pop the matched opening bracket
      } else {
        return "NO"; // Unmatched closing bracket
      }
    } else {
      // If it's an opening bracket, push onto the stack
      stack.push(ch);
    }
  }

  // If the stack is empty, all brackets were matched
  return stack.empty() ? "YES" : "NO";
}

int main() {
  string s;
  cout << "Enter a sequence of brackets: ";
  cin >> s;

  // Output the result
  cout << isBalanced(s) << endl;

  return 0;
}
