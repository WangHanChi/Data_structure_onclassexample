#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

int main(){

  setlocale(LC_ALL, "zh_TW.utf-8");

  /*
    
  list<int> foo = {4,3,2,6,1};

  cout << "method 1 : ";
  for(auto i = foo.begin(); i != foo.end(); ++i){
    cout << *i << " ";
    
  }
  cout << endl;

  cout << "method 2 : ";
  for(auto x: foo) cout << x << " " ;
  cout << endl;


  cout << "method 3 : ";
  copy(foo.begin(), foo.end(), ostream_iterator<int>(cout, " ") );
  cout << endl;
  */

  wcout << "EX2 : " << endl << endl;

    
  wstring bar(L"中央大學");


  wcout << "method 1: ";
  for(auto x: bar) wcout << x << "  ";
  wcout << endl << endl;
  
  wcout << "method 2: ";
  copy(bar.begin(), bar.end(), ostream_iterator<wchar_t, wchar_t>(wcout, L"  "));

  wcout << endl;



  return 0;
}
