#include <iostream>
#include <list>
using namespace std;

class Llist{
private:
  list< list<int> > num;
public:

  Llist(int n){
    int a = 1;
    for(int i = 0; i < n; ++i){
      list<int> bar;
      for(int j = 0; j <= i; ++j){
	bar.push_back(a++);
      }
      num.push_back(bar );
    }
  }


  /*

    Llist(int n){
    int a = 1;
    for(int i = 0; i < n; ++i){
      list<int> bar;
      for(int j = 0; j <= i; ++j){
	bar.push_back(a++);
      }
      num.push_back(bar );
    }
  }

*/

  friend ostream& operator<< (ostream&out, const Llist& foo){

    /*
    list< list<int> >:: const_iterator iter1;
    list<int>::const_iterator iter2;
    for(iter1 = foo.num.begin(); iter1!=foo.num.end(); ++iter1){
      for(iter2 = iter1-> begin(); iter2 != iter1-> end(); ++iter2){
	out << *iter2 << " ";
      }

      out << endl;
    }

    //兩種法都可以用
    */

    for(auto iter1 = foo.num.begin(); iter1 != foo.num.end(); ++iter1){
	for(auto iter2 = iter1 -> begin(); iter2 != iter1 -> end(); ++iter2){
	  out << *iter2 << " ";
	}
	out << endl;
	
    }
    return out;
  }
};





int main(){

  Llist foo(5);
  cout << foo << endl;
  
  return 0;
}
