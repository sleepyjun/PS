#include <iostream>
#include <cmath>

int choice[10];

int main () {
  int size = 3;
  int number = 5;
  // Generate Permutation with Repetition
  // Range is 0 to number-1
  for (int k = 0; k < std::pow(number, size); ++k) {
    for (int i = 0; i < size; ++i) {
      std::cout << choice[i] << ' ';
    }
    std::cout << '\n';
    for (int i = 0; i < size; ++i) {
      choice[i]++;
      if (choice[i] == number) choice[i] = 0;
      else break;
    } 
  }
}
