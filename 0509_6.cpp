#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main(){

  setlocale(LC_ALL, "zh_TW.UTF-8");
  wstring foo[4] = {L"李白 夜思 怨情", L"王維 送別 相思" , L"杜牧 清明", L"杜甫 八陣圖"};


  
  wstring poet,poem;
  wistringstream istr;
  multimap< wstring, wstring > bar;
  for(int i = 0; i < 4 ;++i){
    istr.str( foo[i] );
    istr >> poet;

    while(istr >> poem){
      bar.insert(make_pair(poet, poem));
    }
    istr.clear();
  }


  for(auto itr = bar.begin(); itr!=bar.end(); ++itr){
    wcout << itr->first << " : " <<  itr->second << endl; 
  }



  
  wcout << "> ";

  while(wcin >> poet){
    auto itrs = bar.equal_range(poet);
    for(auto itr = itrs.first; itr != itrs.second; ++itr){
      wcout << itr->first << " : " << itr->second << "  ";
    }

    wcout << endl;
    wcout << "> ";
  }

  
  return 0;
}
