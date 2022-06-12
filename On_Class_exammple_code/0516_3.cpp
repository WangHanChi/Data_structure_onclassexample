#include <iostream>
#include <iterator>

using namespace std;

int main(){


  istream_iterator<int> itr(cin);
  int sum = 0;
  for(; itr != istream_iterator<int>(); ++itr)
    sum += *itr;

  cout << "整數合 : " << sum << endl;


  //輸入數字後按下enter，再按下ctrl-d(ubuntu) or ctrl-z(windows)
  //即可得到結果


  cout << endl << endl;
  cout << "EX2" << endl;
  ostream_iterator<char> out(cout, "**");
  for(char ch = 'a'; ch <= 'z'; ++ch, ++out)
    *out = ch;
  

  return 0;
}
