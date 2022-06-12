
#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

const int R = 5;
const int C = 4;

class Bitmap {
private:
    static const int bmap[10][R];       //數字0~9的點陣圖儲存方式
    string snum;                        //cin的字串
    int scale;                          //放大倍率
    
public:
    Bitmap(string sno = "", int s = 1) : snum(sno), scale(s) {}

    void setsnum(string sno) {
        snum = sno;
    }

    void setscale(int s) {
        scale = s;
    }
    string output;


    friend Bitmap operator* (const Bitmap& foo, int n) {
      int i , j , k , a ;
      char w;
     for( i = 0 ; i < R ; i++ ){
       for(a = 0 ; a < n ; ++a){
	 for( k = 0 ; k < foo.snum.size() ; k++){
	      for( j = C-1 ; j >= 0 ; --j ){
		w = foo.snum[k] - '0';
		if( (foo.bmap[w][i] >>j )%2 ) {
		  cout <<string(n, static_cast <char>('0'+w)) ;
		}else{
		  cout <<string(n,' ') ;
		}
	   }
	   cout <<" " ;
	 }
	 cout << endl ;
       }
     }
     return foo.output;
    }
    friend ostream& operator<< ( ostream& out, const Bitmap& foo) {
        out << foo.output;
        
        
        return out;
    }
};

int main()
{
    int s;
    string sno;
    Bitmap foo;

    while (1) {
        cout << "> ";
        cin >> sno;
        foo.setsnum(sno);

        for (s = 1; s < 4 ; ++s)
        {
            cout << foo * s << endl;
        }
        cout << endl;
    }
    return 0;
}


const int Bitmap::bmap[10][R] = {
    {15,9,9,9,15}   ,   {2,6,2,2,7}     ,   {15,1,15,8,15} ,
    {15,1,7,1,15}   ,   {9,9,15,1,1}    ,   {15,8,15,1,15} ,
    {15,8,15,9,15}  ,   {15,1,2,4,8}    ,   {15,9,15,9,15} ,
    {15,9,15,1,15}
};
