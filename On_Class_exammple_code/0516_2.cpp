#include <iostream>
#include <iterator>
#include <list>
#include <vector>
using namespace std;

template<class Itr1, class Itr2>
void insert(Itr1 a, Itr1 b, Itr2 j){
  for(Itr1 i = a; i != b;++i, ++j ){
    *j = *i;


  }

}


int main(){
  list<int> foo;
  vector<int> bar(4,1);
  int no[8] = {2,1,3,8,6,4,9,1};


  // foo  = 6 8 3
  insert(no+2, no +5, front_inserter(foo) );
  for(auto x: foo) cout << x << " ";
  cout << endl;

  //  foo = 6 8 3 1 1 1 1
  insert(bar.begin(), bar.end(), back_inserter(foo) );
  for(auto x : foo)cout << x << " ";
  cout << endl;
  




  return 0;
}
