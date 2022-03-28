#include <iostream>
#include <sstream>
using namespace std;

template<typename T>
T str2num(const string& foo){
  T num;
  istringstream istr( foo );
  istr >> num;
  return num;

}
//把string轉成數字（整數或浮點數可以）
int main(){
  cout << str2num<double>("23.456") << endl;
  cout <<str2num<int>("23.456") << endl;
  cout << str2num<int>( "234" ) << endl;

  return 0;
}
