#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;











int main(){

  setlocale(LC_ALL, "zh_TW.UTF-8");

  wifstream infile("strokes.dat");
  wstring   line;
  wchar_t   wch;
  int       n, m;
  wistringstream istr;


  map<int, vector<wchar_t> > foo;

  
  while(getline(infile, line)){
    istr.str( line.substr(2) );
    istr >> hex >> m >> dec >> n;
    foo[n].push_back( static_cast<wchar_t>(m) );//把m轉形成wchar_t
    istr.clear();
    
  }

  int k ;
  for(auto i = foo.begin(); i != foo.end(); ++i){
    wcout << i->first << " : " << endl;
    k = 1;
    for(auto j = (i->second).begin(); j != (i->second).end(); ++j ){
      wcout << *j << "  ";
      if(k%10 == 0) wcout << endl;
      ++k;
    }

    wcout << endl;
  }


  //回家測試看看
  return 0;
}
