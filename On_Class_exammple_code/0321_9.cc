#include <iostream>
#include <sstream>

using namespace std ;

int main() {

  string foo ;
  istringstream  istr ;
  double no1 ;
  bool   ok ;
  char   ch ;
  
  while ( 1 ) {
    cout << "> " ;
    cin >> foo ;
    istr.str(foo) ;
    ok = true ;

    if ( istr >> no1 ) {
      if ( istr >> ch ) ok = false ;
    } else {
      ok = false ;
    }
    istr.clear() ;
    
    cout << ( ok ? ": number " : ": string" ) << endl ;
    
  }
  return 0 ;
}
