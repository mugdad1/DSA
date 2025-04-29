/*
Part 2: Lab Tasks: (10 points)

Problem 1: Find if there is a triple zero in a Balanced BST that adds to zero

Description

Given a Binary Search Tree (BST), write a function isTripleZero() that returns true if there are 3 nodes in a given BST with sum equals to 0, otherwise returns false. You can modify given Binary Search Tree program in the example section. Test your function by using the node values from the given BST.

For example, isTripleZero() should return true for following BST because there are three nodes with sum 0, the nodes are {-13, 6, 7}.

Input format

The program should accept N integer input (positive and negative value) separated by a space and stop once it reads 0.

Example Input

6 -13 14 -8 13 15 7 0

Output format

The program should display “Triple zero exist” if there are three nodes which sum is equal to 0, else display “Triple Zero does not exist”.

Example Output

Triple zero exist

Example Program Execution

*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* node, int val) {
    if (node == NULL) return new TreeNode(val);
    if (val < node->val) node->left = insert(node->left, val);
    else if (val > node->val) node->right = insert(node->right, val);
    return node;
}

bool isTripleZero(TreeNode* root, unordered_set<int> &s, int target, int k) {
    if (!root) return false;

    if (k == 1) {
        if (s.find(-target - root->val) != s.end()) return true;
        return false;
    }

    s.insert(root->val);
    return isTripleZero(root->left, s, target, k - 1) || isTripleZero(root->right, s, target, k - 1);
}

int main() {
    vector<int> input;
    int num;
    while (cin >> num && num != 0) input.push_back(num);

    TreeNode* root = NULL;
    for(auto &n : input) root = insert(root, n);

    unordered_set<int> s;
    if(isTripleZero(root, s, 0, 3)) {
        cout << "Triple zero exist" << endl;
    } else {
        cout << "Triple Zero does not exist" << endl;
    }

    return 0;
}
