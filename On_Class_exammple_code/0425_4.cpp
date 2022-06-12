#include <iostream>
using namespace std;


template <class T>
struct Square{
  T operator() (const T& a) const {
    return a*a;
  }
};


int main(){

  Square<int> foo;

  cout << foo(2) << endl;
  cout << foo.operator() (2) << endl;
  cout << Square<int>() (2) << endl;
  cout << Square<int>() .operator() (2) << endl;
  
  return 0;
}
