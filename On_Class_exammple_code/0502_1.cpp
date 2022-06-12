#include <iostream>
#include <vector>

using namespace std;

int main(){

  vector<int> foo;
  for(int i = 0; i < 100; ++i){
    
      foo.push_back(i);
      if(foo.size() == foo.capacity()) {
	cout << foo.size() << endl;
	//當其每相等一次的時候
	//capacity會自動變成兩倍大，故才會輸出成這樣
      }
    }

  return 0;
}
