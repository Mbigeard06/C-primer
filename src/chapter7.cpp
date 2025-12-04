#include "chapter7.h"
#include <cassert>
#include <cctype>
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ********** 6.3.3 **********

/* 1)
argType: string (*arr)[10] -> converted to string**
rType: string (&arr)[10] = argType*
*/

string (&array10strings(string (*arr)[10]))[10];

/* 2)
Same function using an alias
*/
typedef int arrT[10];
// equivalent to
using arrT = int[10];
arrT &array10strings1(arrT *arr);

/* 3)
Using a decltype
*/
int odd[] = {1, 3, 5, 7, 9};
decltype(odd) &array10strings2(decltype(odd) *arr);

// ********** PrintVector **********
void printVector(vector<int> v) {

#ifndef NDEBUG
  std::cout << __FUNCTION__ << "\n"
            << __FILE__ << ":" << __LINE__ << "\n"
            << __DATE__ << " " << __TIME__ << std::endl;
#endif

  if (v.empty()) {
    return;
  }
  cout << v.back() << endl;
  v.pop_back();

  printVector(v);
}