/*
Part 2: Lab Tasks (10 points)
Note: Copy this section into a new file then save it. You will only submit this section of the lab manual.
Description:
The exam committee in a school is in the process of collecting some statistics about the final exams. For that, they asked the instructors to provide the number of students who scored below and above the class average. They also asked for the minimum and the maximum scores.

Problem: 
Given the marks of students and the class average, find the number of students scored below the average, the number of students scored above the average, the minimum, and the maximum scores. First, you need to construct the BST that represent the marks of students then find the required output. 

Input: 
First line consists of a single integer n represents the number of students in a class.
Second line consists of n float numbers represent the marks of each student. 
Third line consists of a single float number f represents the class average. 

Output: 
Four integers below, above, min, and max that represent the number of students scored below the average, the number of students scored above the average, the minimum, and the maximum scores respectively.

Example Run: 

SAMPLE output 
4 6 11 50
sample input 
10
23 15 49 11 33 40 50 37 45 18 
32.1
*/
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    float data;
    Node* left, * right;
    Node(float d) : data(d), left(nullptr), right(nullptr) {}
};

class BST {
public:
    int belowAverageCount = 0, aboveAverageCount = 0, minScore = INT_MAX, maxScore = INT_MIN;

    void insert(Node*& root, float data, float avg);
    void countAndMinMax(Node* node, float avg);
};

void BST::insert(Node*& root, float data, float avg) {
    if (root == nullptr)
        root = new Node(data);
    else {
        if (data < root->data)
            insert(root->left, data, avg);
        else
            insert(root->right, data, avg);
    }
}

void BST::countAndMinMax(Node* node, float avg) {
    if (node != nullptr) {
        countAndMinMax(node->left, avg);
        
        if (node->data < avg)
            belowAverageCount++;
        else if (node->data > avg)
            aboveAverageCount++;

        minScore = min(minScore, node->data);
        maxScore = max(maxScore, node->data);

        countAndMinMax(node->right, avg);
    }
}

int main() {
    int n;
    float avg;

    cin >> n;

    vector<float> marks(n);
    for (int i = 0; i < n; ++i)
        cin >> marks[i];

    cin >> avg;

    Node* root = nullptr;
    BST bst;

    // Insert all marks into the tree
    for (float mark : marks) {
        bst.insert(root, mark, avg);
    }

    // Count and find min/max values based on average
    bst.countAndMinMax(root, avg);

    cout << bst.belowAverageCount << " " << bst.aboveAverageCount << " "
         << bst.minScore << " " << bst.maxScore << endl;

    return 0;
}
