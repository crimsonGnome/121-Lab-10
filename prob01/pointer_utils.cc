// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include "pointer_utils.h"

#include <iostream>
#include <string>

using std::cout, std::string, std::vector;

void Negate(bool* value) {
  bool temp = *value;
  *value = !temp;
}

void Increment(int* number) {
  int temp = *number;
  *number = temp + 1;
}

double ComputeSum(double* first, double* second) {
  // Your code here. return 0 is a placeholder so the program compiles.
  double answer = *first + *second;
  return answer;
}

void Swap(int* first, int* second) {
  int temp;
  temp = *first;
  *first = *second;
  *second = temp;
}

void MakeSus(std::string* player) {
  string temp = *player;
  temp.append(" is sus");
  *player = temp;
}

std::string* GetLongestString(std::vector<std::string>* strings) {
  // Your code here. return nullptr is a palceholder so the program compiles.
  int answerLength = 0;
  string* longest = nullptr;
  int size = strings->size();

  for (int i = 0; i < size; i++) {
    int temp = strings[i].size();
    if (temp > answerLength) {
      longest = &strings->at(i);
      answerLength = temp;
    }
  }
  return longest;
}
