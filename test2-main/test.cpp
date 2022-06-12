
#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>


class Binary_Number{
    
private:
    unsigned int no;
    int bin_integer;
    string bin;
    
public:
    
    Binary_Number(const string& num);
  
    
    friend Binary_Number operator+ (const Binary_Number&a, const Binary_Number& b){
        int x, y = 0;
        x = a.no + b.no;
        
       
        if ( (x/2 >=0) && x%2 ==0) {
            y = y+0;
        }else if((x/2 >=0) && x%2 !=0){
            y = y+1;
        }
        if ((x/4 >=0) && x%4 ==0) {
            y = y+10*0;
        }else if((x/4 >=0) && x%4 !=0){
            y = y+10;
        }
        if((x/8 >=0) && x%8 ==0){
            y = y+100*0;
        }else if((x/8 >=0) && x%8 !=0){
            y = y+100;
        }
        if ((x/16 >=0) && x%16 ==0) {
            y = y+1000*0;
        }else if((x/16 >=0) && x%16 !=0){
            y = y+1000*1;
        }
        if ((x/32 >=0) && x%32 ==0) {
            y = y*10000*0;
        }else if((x/32 >=0) && x%32 !=0){
            y = y+10000*1;
        }
        stringstream output;
        output << y;
        string ss = output.str();
        return Binary_Number(ss);
    }
    
    friend Binary_Number operator* (const Binary_Number&a, const Binary_Number& b){
    
        int number, m, c, i = 0;
        int n = 2;
        int array[32];
        stringstream output;
        number = a.no*b.no;
        m = number;
        while (number > 0){
            
            c = (number % n);
            array[i] = c;
            number = number / n;
            i++;
        }
        for (i--; i >= 0; i--) {          //將陣列倒序輸出
            output << array[i];
        }
        string ss = output.str();
        return Binary_Number(ss);
        
    }

    friend Binary_Number operator- (const Binary_Number&a, const Binary_Number& b){
        int number, m, c, i = 0;
        int n = 2;
        int array[32];
        stringstream output;
        number = a.no-b.no;
        m = number;
        while (number > 0){
            
            c = (number % n);
            array[i] = c;
            number = number / n;
            i++;
        }
        for (i--; i >= 0; i--) {          //將陣列倒序輸出
            output << array[i];
        }
        string ss = output.str();
        return Binary_Number(ss);
        
    }


    friend Binary_Number operator>> (const Binary_Number&a, int b){
      int number, m, c, i = 0;
        int n = 2;
        int array[32];
        stringstream output;
	number = a.no;
        m = number;
        while (number > 0){
            
            c = (number % n);
            array[i] = c;
            number = number / n;
            i++;
	    
        }
	
       
	
        for (i--; i >= b ; i--) {          //將陣列倒序輸出
	  
	  output << array[i];
	    
        }
	
        string ss = output.str();
        return Binary_Number(ss);

    }


  friend Binary_Number operator>>= (const Binary_Number&a,int b){
      int number, m, c, i = 0;
        int n = 2;
        int array[32];
        stringstream output;
	number = a.no;
        m = number;
        while (number > 0){
            
            c = (number % n);
            array[i] = c;
            number = number / n;
            i++;
	    
        }
        
        for (i--; i >= b ; i--) {          //將陣列倒序輸出
            output << array[i];
        }
	
        string ss = output.str();
        return Binary_Number(ss);

    }



    friend Binary_Number operator<< (const Binary_Number&a,int b){
      int number, m, c, i = 0,cc = 0;
      int n = 2;
      int array[32];
      int aaa[b];
      stringstream output;
      string aaaa ="0";
      number = a.no;
      m = number;
      while (number > 0){
            
	c = (number % n);
        array[i] = c;
        number = number / n;
        i++;
	cc++;    
      }
      for (i--; i >= 0 ; i--) {          //將陣列倒序輸出
        output << array[i];
      }
      for( b;b>0;b--){
	output << aaaa;
      }
      string ss = output.str();
      return Binary_Number(ss);

    }


   friend Binary_Number operator<<= (const Binary_Number&a,int b){
      int number, m, c, i = 0,cc = 0;
      int n = 2;
      int array[32];
      int aaa[b];
      stringstream output;
      string aaaa ="0";
      number = a.no;
      m = number;
      while (number > 0){
            
	c = (number % n);
        array[i] = c;
        number = number / n;
        i++;
	cc++;    
      }
      for (i--; i >= 0 ; i--) {          //將陣列倒序輸出
        output << array[i];
      }
      for( b;b>0;b--){
	output << aaaa;
      }
      string ss = output.str();
      return Binary_Number(ss);

    }




  
    friend ostream& operator<< (ostream& out, const Binary_Number& foo){
        
        out << foo.bin << "(" << foo.no << ")";
        return out;
    }

    
};


Binary_Number::Binary_Number(const string& num){
    bin = num;
    bin_integer = stoi(num);
    int value = 0, dev = 0, mod = 0, two = 1, temp;
    while (bin_integer > 0 ) {
        temp = bin_integer;
        dev = temp/10;
        mod = temp%10;
        value += mod*two;
        two *= 2;
        bin_integer /= 10;
    }
    no = value;
}






int main(int argc, const char * argv[]) {
    
  Binary_Number a("10010"), b("110"),c("0") ;
    
    cout << a << endl;      //輸出：10010(18)
    cout << b << endl;      //輸出：110(6)

    cout << endl;
    
    cout << a+b << endl;    //輸出：11000(24)
    cout << a*b << endl;    //輸出：1101100(108)
    cout << a-b << endl;    //輸出：1100(12)
    cout << endl;
	    
    c = a >> 2;
    cout << a << endl;
    cout << c << endl;
   
    cout << endl;
    a >>= 2;
    cout << a << endl;

    cout << endl;
     c = b << 4;
    cout << b << endl;
    cout << c << endl;

    
    b <<= 4;
    cout << b << endl;
    return 0;
}
