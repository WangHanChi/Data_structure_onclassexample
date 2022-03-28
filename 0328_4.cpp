#include <iostream>

using namespace std;





template <typename T>
T square(T a){
  return a*a;
}

template <typename T>
T cubic(T a){
  return a*a*a;
}

int abs(int x ){
  return (x > 0 ? x : -x);
}

template <typename F, typename T>{
T compute(f fn, T x){
    return fn(x);
  }
}

int main(){
  cout << compute(square<double>, 1.1) << endl;
  cout << compute(cubic<int>, -3) << endl;
  cout << compute(abs , -3) << endl;
}
