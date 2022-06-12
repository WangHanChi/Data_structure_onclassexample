#include <iostream>
#include <cassert>
#include <functional>
using namespace std;

template<typename T>
struct Node{
  T dat;
  Node<T> *fptr, *bptr;

  Node() : fptr(NULL), bptr(NULL) {}

  Node( const T& a ) : dat(a), fptr(NULL), bptr(NULL) {}

  
};


template<typename T>
ostream& operator<< (ostream& out, const Node<T>& foo){
  return out << foo.dat ;
}

template<typename T>
ostream& operator<< (ostream& out, const Node<T>* ptr){
  return out << ptr->dat ;
}


template<typename T>
Node<T>*  makenode( const  T& a ){
  Node<T> *ptr = new Node<T>(a) ;
  return ptr ;
}


template<typename T>
class List{
private:
  
  Node<T> *head, *tail;
  int osize;
  Node<T> *nptr;
 
public:
  
  //default constructor
  List() : head(NULL), tail(NULL), osize(0), nptr(NULL) {}

  //constructor
  List<T>(int n, const T& a) : head(NULL), tail(NULL), osize(0) , nptr(NULL) { 
    for( int i = 0 ; i < n; ++i ) push_back(a);
  }


  //copy constructor
  List( const List<T>& foo) : head(NULL), tail(NULL), osize(0) , nptr(NULL) {
    Node<T> *tmp = foo.head;
    while( tmp != NULL ){
      push_back(tmp->dat);
      tmp = tmp->bptr;
    }
  }
  
  //destructor
  ~List()  {
    clear();
  }


  //assignment operator
  List<T>& operator=( const List<T>& foo){
    if( this == &foo) return *this;
    if (head != NULL ) clear();

    Node<T> *tmp = foo.head;//與copy constructor一樣
    while( tmp != NULL ){
      push_back(tmp->dat);
      tmp = tmp->bptr;
    }
    
  }

  //push_back (the most important in list)
  void push_back( const T& a){
    Node<T> *ptr = makenode<T>(a);
    if( osize == 0 ){
      head = tail = ptr;
    }else{
      tail->bptr = ptr;
      ptr->fptr = tail;
      tail = ptr;
    }

    osize += 1;
  }

  //push_front()
  void push_front( const T& a){
    Node<T> *ptr = makenode<T>(a);
    if( osize == 0 ){
      head = tail = ptr;
    }else{
      head->fptr = ptr;
      ptr->bptr = head;
      head = ptr;
    }

    osize += 1;
  } 


  //pop_back
  void pop_back(){
    if( osize == 0 ){
      return;
    }else if( osize == 1 ){
      delete head;
      head = tail = NULL;
    }else{
      tail = tail->fptr;
      delete tail->bptr;
      tail->bptr = NULL;

      //another way
      /*
      Node<T> *tmp = tail->fptr;
      delete tail;
      tail = tmp;
      tail->bptr = NULL;

      */
    }

    osize -= 1;
  }


  //pop_front
  void pop_front(){
    if( osize == 0 ){
      return;
    }else if( osize == 1 ){
      delete head;
      head = tail = NULL;
    }else{
      head = head->bptr;
      delete head->fptr;
      head->fptr = NULL;

      //another way
      /*
      Node<T> *tmp = head->bptr;
      delete head;
      head = tmp;
      head->fptr = NULL;

      */
    }

    osize -= 1;
  }


  //clear()
  void clear(){
    while(osize > 0){
      pop_back();
    }
  }


  //insert
  Node<T>* insert( Node<T>* ptr, const T& val ){
    Node<T>* p = head;
    while( p != ptr ){
      p = p->bptr;
      if( p == NULL) return NULL;
    }
    
    if( ptr == head ){
      push_front(val);
      return head;
    }else{
      Node<T>* tmp = makenode(val);
      ptr->fptr->bptr = tmp;
      tmp->fptr = ptr->fptr;
      ptr->fptr = tmp;
      tmp->bptr = ptr;
      osize += 1;
      return tmp;
    }
  }


  Node<T>* begin() {return head;}
  const Node<T>* begin() const {return head;}

  //append()
  void append( const List<T>& foo){
    Node<T> *ptr = foo.head;
    while(ptr != NULL){
      push_back(ptr->dat);
      ptr = ptr->bptr;
    }
  }

  void del_node( const Node<T>* ptr ){
    if(head == ptr ){
	pop_front();
      }else if( tail == ptr){
	  pop_back();
    }else{
      Node<T> *p = head;
      while( p != ptr){
	p = p->bptr;
	if( p == NULL) return ;
      }
      ptr->fptr->bptr = ptr->bptr;
      ptr->bptr->fptr = ptr->fptr;
      delete ptr;
      osize -= 1;
    }

    
  
  }

  //operator +=
  void operator+= (const List<T>& foo){
    append(foo);
    
  }
  //把資料放在front
  T& front() { return head->dat ; }
  const T& front() const { return head->dat ; }
  //把資料放在back
  T& back() { return tail->dat ; }
  const T& back() const { return tail->dat ; }
  

  
  friend ostream& operator<< (ostream& out , const List<T>& foo){
    Node<T> *ptr = foo.head;
    while( ptr != NULL ){
      out << ptr->dat << " ";
      ptr = ptr->bptr;
    }
    return out;
  }
  
};



int main(){

  List<int> foo;
  for(int i = 0 ; i < 3; ++i ){
    foo.push_back(i+1);
    foo.push_front(i + 10);
  }

  cout << foo << endl;

  for(int i = 0 ; i < 4; ++i){
    foo.pop_back();
  }

  cout << foo << endl;

  List<int> bar(4, 5);
  cout << bar <<endl;
  bar.front() = 2;
  bar.back() = 7;

  cout << bar <<endl;


  List<int> c(bar);
  cout <<c << endl;

  c = foo;
  cout << c << endl;

  c.append(bar);
  cout << c << endl;

  c+=bar;
  cout << c <<endl;

  Node<int> *ptr = c.begin();
  c.insert(ptr, 9);
  c.insert(ptr, 8);
  cout << c << endl;
  c.del_node(ptr);
  cout << c << endl;
  c.del_node(c.begin());
  cout << c << endl;
  /*
  Node<int> foo(5);
  cout << foo << endl;


  Node<int> *p = makenode(3);
  cout << p << endl;
  */
 


  return 0;
}
