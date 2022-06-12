#include <iostream>
#include <cassert>
using namespace std;

//const int NULL = 0;

template<typename T>
class Vector{
private :

  T *dat;
  int osize;  //occupied size
  int rsize;  //reserved size

public :
  //建構函式
  Vector() : dat(NULL), osize(0), rsize(0) { }
  
  Vector(int s, const T& val):  osize(s), rsize(2*s) {
    
    dat = new T[rsize];
    for(int i = 0 ; i < osize; ++i) dat[i] = val;

  }


  //複製建構子
  Vector( const Vector<T>& foo) : osize(foo.osize), rsize(foo.rsize){
    dat = new T[rsize];
    for(int i = 0 ; i < osize; ++i) dat[i] = foo.dat[i];
  }

  //指定運算子assignment operator (=) 
  Vector<T>& operator=( const Vector<T>& foo){
    if(this == & foo) return *this;
    if(osize > 0)  delete [] dat;

    osize = foo.osize;
    rsize = foo.rsize;
    dat = new T[rsize];
    for(int i  = 0 ; i < osize; ++i) dat[i] = foo.dat[i];
    return *this;
    
  }

  //解構函式
  ~Vector() {if(rsize > 0) delete [] dat ; }

  //下標運算子[]
  T& operator[] ( int i ) { return dat[i]; }
  //下標運算子[] * 要寫兩個分成有const跟沒有const的版本
  const T& operator[] ( int i ) const { return dat[i]; }

  //push_back()
  void push_back( const T& foo){
    if(rsize == 0){
      rsize = 1;
      osize = 1;
      dat = new T[rsize];
      dat[0] = foo;
    }else{
      if( osize == rsize){
	rsize = 2*rsize;
	T *dat2 = new T[rsize];
	for(int i = 0 ; i < osize; ++i) dat2[i] = dat[i];
	dat2[osize] = foo;
	osize = osize + 1 ;
	delete [] dat;
	dat = dat2;
      }else{
	dat[osize] = foo;
	osize += 1;
      }
    }
  }

  //pop_back()
  void pop_back(){
    assert( osize > 0 );
    osize -= 1;
  }

  //.size()
  int size() const { return osize ; }
  //.reserce()
  int reserve() const { return rsize ; }
  //.claer()
  void clear(){
    osize = rsize = 0;
    delete [] dat;
  }
  
  //加等於運算子重載 operator(+=)
  const Vector<T>& operator+=( const Vector<T>& a){
    *this = *this + a;
    return *this;
  }

  //輸出運算子重載 opertaor(<<)
  friend ostream& operator<< (ostream& out, const Vector<T>& foo){
    for(int i = 0 ; i < foo.osize; ++i){
      out << foo.dat[i] << " ";
    }
    return out;
  }

  //加號運算子重載 operator(+)
  friend Vector<T> operator+ (const Vector<T>& a, const Vector<T>& b){
    Vector<T> c = a;
    for(int i = 0 ; i < b.size(); ++i){
      c.push_back(b[i]);
    }
    return c;
  }
    
};




int main(){

  Vector<int> a;
  for(int i = 0 ; i < 10; ++i){
    a.push_back( i + 1 );
    cout << a << " : " << a.size() << " / " << a.reserve() << endl;
    
  }

  Vector<int> b(3, 7);
  Vector<int> c;
  c = a + b;
  cout << c << endl;


  c += b;
  cout << c <<endl;

  c.clear();

  cout << "c : " << c << endl;
 
  /*
  Vector<int> foo(3, 7);
  Vector<int> bar(4, 6);
  
  cout << foo << endl;
  cout << bar << endl;

  
  bar = foo;
  cout << bar <<endl;
  bar[0] = 9;
  bar[1] = bar[0] + 2 ;
  cout << bar << endl;
  */
  return 0;
}
