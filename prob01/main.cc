// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include <iostream>

#include "pointer_utils.h"

int main() {
  std::string choice;
  while (choice != "quit") {
    std::cout << "Which problem number do you want to test? (or \"quit\")\n"
              << "1. Negate\n2. Increment\n3. ComputeSum\n4. Swap\n5. "
                 "MakeSus\n6. GetLongestString\n: ";
    std::cin >> choice;
    if (choice == "1") {
      std::string bool_str;
      std::cout << "enter \"true\" or \"false\": ";
      std::cin >> bool_str;
      bool value = bool_str == "true";
      std::cout << "calling Negate... " << std::endl;

      // Call Negate with a pointer to the boolean variable named value.
      bool *valueptr;
      valueptr = &value;
      Negate(valueptr);

      std::cout << "value is now " << (value ? "true" : "false") << std::endl;

    } else if (choice == "2") {
      int number;
      std::cout << "enter a number to increment: ";
      std::cin >> number;
      std::cout << "calling Increment... " << std::endl;

      // Call Increment with a pointer to the integer variable named
      // number.
      int *numberptr;
      numberptr = &number;
      Increment(numberptr);

      std::cout << "the incremented number is " << number << std::endl;
    } else if (choice == "3") {
      double first;
      double second;
      std::cout << "enter a floating point number: ";
      std::cin >> first;
      std::cout << "enter another: ";
      std::cin >> second;
      std::cout << "calling ComputeSum..." << std::endl;

      // TODO: Call ComputeSum with pointers to variables named first and second
      // and place the result in the double variable called sum below.
      double *firstptr;
      double *secondptr;
      firstptr = &first;
      secondptr = &second;
      double sum = ComputeSum(firstptr, secondptr);

      std::cout << "the sum is " << sum << std::endl;
    } else if (choice == "4") {
      int first;
      int second;
      std::cout << "enter the first number: ";
      std::cin >> first;
      std::cout << "enter the second number: ";
      std::cin >> second;
      std::cout << "calling Swap..." << std::endl;

      // TODO: Call the Swap function with pointers variables named to first and
      // second above.
      int *firstptr;
      int *secondptr;
      firstptr = &first;
      secondptr = &second;
      Swap(firstptr, secondptr);

      std::cout << "first: " << first << ", second: " << second << std::endl;
    } else if (choice == "5") {
      std::string name;
      std::cout << "What is your AmongUs name? (no spaces): ";
      std::cin >> name;
      std::cout << "calling MakeSus..." << std::endl;

      // TODO: Call MakeSus with a pointer to the name variable.
      std::string *nameptr;
      nameptr = &name;
      MakeSus(nameptr);

      std::cout << name << std::endl;
    } else if (choice == "6") {
      int count;
      std::cout << "How many strings? ";
      std::cin >> count;
      std::vector<std::string> strings;
      for (int i = 0; i < count; i++) {
        std::string str;
        std::cout << "enter a string (no spaces): ";
        std::cin >> str;
        strings.push_back(str);
      }

      // TODO: Call GetLongestString using a pointer to the vector named
      // strings, and store the result in the string pointer variable named
      // longest below.
      std::vector<std::string> *stringptr;
      stringptr = &strings;
      std::string *longest = GetLongestString(stringptr);

      if (longest != nullptr) {
        std::cout << "the longest is " << *longest << std::endl;
      } else {
        std::cout << "nullptr: there was no longest string" << std::endl;
      }
    } else if (choice != "quit") {
      std::cout << "I didn't understand" << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}
