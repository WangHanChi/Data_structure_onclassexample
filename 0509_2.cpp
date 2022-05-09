#include <iostream>
#include <set>
using namespace std;
#include <fstream>
#include <sstream>

class Student{
private:
  string name;
  int id;
  int age;

public:

  Student() {}
  Student( string s, int i, int a) : name(s), id(i), age(a) {}
  int get_age() const{
    return age;
  }
  friend ostream& operator<< (ostream& out, const Student& foo){
    out << foo.name << " : " << foo.id << " (" << foo.age << ") "<< endl;
    return out;
  }

  friend istream& operator>> (istream& in, Student& foo){
    return in >> foo.name >> foo.id >> foo.age;
  }

  friend bool operator< (const Student& a, const Student& b){
  return a.name < b.name;
}

};





struct by_age{
  bool operator() (const Student& a, const Student& b)const{
    return a.get_age() > b.get_age();
  }
  
};



int main(){
  ifstream infile("student.txt");
  string line;
  istringstream istr;
  Student student;
  multiset<Student> foo;
  multiset<Student, by_age > bar;
  
  while(getline(infile, line)){
    istr.str(line);
    istr >> student;
    //cout << student << endl;
    foo.insert(student);
    bar.insert(student);
    istr.clear();
  }

  for(auto itr = foo.begin(); itr != foo.end(); ++itr){
    cout << *itr << endl;
  }



  cout <<endl;

  
  for(auto itr2 = bar.begin(); itr2 != bar.end(); ++itr2){
    cout << *itr2 << endl;
  }
  
  return 0;
}
