#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Gint {
private:
  string snum;
  int num;
public:
  Gint(){}
  Gint(const string& sno) :snum(sno) {
    num = snum2num(snum);
  }
  
  int nums[4];
  int i=0;

  int get_num() const { return num; }
  string get_snum() const { return snum; }
  int snum2num(const string& sno) const;
	
  friend istream& operator>>(istream& in, Gint& foo);

};

int Gint::snum2num(const string& sno) const {
  
  int a;
  istringstream  ss;
  string::size_type id0x = sno.find("0x"), id0o = sno.find("0o"), id0b = sno.find("0b");
  ss.str(sno);
  if (id0x != string::npos) {//for hex
    ss >> hex >> a;
  }
  else if(id0o != string::npos) {//for oct
    ss.ignore(2, EOF);
    ss >> oct >> a;
  }
	
  else if (id0b != string::npos) {//for bin
    ss.ignore(2, EOF);
    ss >> a;
	
    int all, mod, dd, value , two;
    two = 1;
    value = 0;
    while (a > 0) {
      all = a;
      dd = all / 10;
      mod = all % 10;
      value += mod * two;
      two *= 2;
      a /= 10;
    }
    a = value;
  }

  else ss >> a;//for dec

	
  return a;
}


istream& operator>>(istream& in, Gint& foo) {
  int N = 4;
  string temp;
  in >> temp;
  foo.num=foo.snum2num(temp);
  if(foo.i < N){
    foo.nums[foo.i]=foo.num;
    foo.i+=1;
  }
  else foo.i=0;
  return  in;
}



int main() {
 
  ifstream infile("gint.txt");
  int sum;
  Gint foo;
  string line;
  istringstream istr;

  while (getline(infile, line)) {
    istr.str(line);
    sum = 0;
    while (istr >> foo) {
      sum = sum + foo.get_num();
    }
    istr.clear();
    cout << "sum of " << line ;
    
    cout << " = ";
    cout << foo.nums[0];
    for(int count = 1;count < 4; ++count) cout << " + " << foo.nums[count];
    cout<<" = "<< sum << endl << endl;
  }	
  return 0;
}
