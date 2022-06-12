#include <iostream>
#include <list>

using namespace std;






class Llist{
private:
  list< list<int> > num;
public:


  int no;

  int end_num;
  
  Llist(int n){
    no = n;
    int a = 1;
    for(int i = 0; i < n; ++i){
      list<int> bar;
      for(int j = 0; j <= i; ++j){
	bar.push_back(a++);
      }
      num.push_back(bar);
    }

    end_num = a;
  }

  

  void row_reverse(){
    int a = 1;
    num.erase(num.begin(), num.end());
    end_num = end_num - 1;
    for(int i = no; i > 0; --i){
      list<int> bar;
      for(int j = 0; j < i ; ++j){
	bar.push_back(end_num--);
       
      }
      bar.reverse();
      num.push_back(bar);
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

  Llist foo(6);
  cout << foo << endl;
  
  foo.row_reverse();
  
  cout << foo << endl;
  
  return 0;
}
