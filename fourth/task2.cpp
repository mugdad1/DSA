#include <iostream>
#include <vector>
using namespace std;
std::vector<int> game(std::vector<int> list) {
  std::vector<int> result;
  int n = list.size();
  int lucyIndex = 0, jadeIndex = n - 1;

  while (lucyIndex <= jadeIndex) {
    if (list[lucyIndex] > list[jadeIndex]) {
      result.push_back(2);
      ++lucyIndex;
    } else if (list[lucyIndex] < list[jadeIndex]) {
      result.push_back(1);
      --jadeIndex;
    } else {
      result.push_back(0);
      ++lucyIndex;
      --jadeIndex;
    }
  }

  return result;
}

int main() {
  int n;
  cout << "Enter the number of elements in the list: ";
  cin >> n;

  std::vector<int> list(n);
  cout << "Enter the list of numbers separated by space: ";
  for (int i = 0; i < n; ++i) {
    cin >> list[i];
  }

  std::vector<int> output = game(list);

  cout << "Output list: [";
  for (size_t i = 0; i < output.size(); ++i) {
    if (i > 0)
      cout << ", ";
    cout << output[i];
  }
  cout << "]" << endl;

  return 0;
}
