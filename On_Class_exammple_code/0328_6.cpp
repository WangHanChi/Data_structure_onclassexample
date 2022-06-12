#include <iostream>
#include <string>

using namespace std;
int main(){
  setlocale( LC_ALL , "zh_TW.UTF-8");
  wstring foo= L"i孫悟空";

  wcout << foo << endl;
  wcout << foo.substr(1) << endl;
  wstring bar = wstring(foo.rbegin() , foo.rend()-1);
  wcout << bar << endl;
  return 0;


}

