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
    void trans(string s) {
        output = s;
    }

    friend Bitmap operator* (const Bitmap& foo, int s) {
        string line_map;
        int  i, j, k, bit, no;
	int b = s*5 -1;
	int count = b;
	string text;
	char w;
	
        switch (s)
        {
        case 1 :
            for (i = 0; i < 5; ++i) {
	        
                for (j = 0; j < foo.snum.size(); ++j) {

		    stringstream  ss;
		    string sss;
                    no = foo.snum[j] - '0';
		    ss << no;
		    sss = ss.str();
                    bit = bmap[no][i];
		    
                    for (k = 0; k < 4; ++k) {
		      while(b>0){
			cout << " ";
			b--;
		      }
		        
		      line_map += (bit & (8 >> k) ? sss : " ");

                    }
                    line_map += " ";
		    
                }
		
                cout << line_map << endl;
                line_map = "";
		b = count - 1;
		count = b;
            }
            break;
        case 2 :
            for (i = 0; i < 5; ++i) {
                for (j = 0; j < foo.snum.size(); ++j) {
		  stringstream  ss;
		    string sss;
                    no = foo.snum[j] - '0';
		    ss << no;
		    sss = ss.str();

                    bit = bmap[no][i];

                    for (k = 0; k < 4; ++k) {
		       while(b>0){
			cout << " ";
			b--;
		      }
                        line_map += (bit & (8 >> k) ? sss+sss : "  ");

                    }
                    line_map += " ";

                }
                
                cout << line_map << endl;
                line_map = "";

		b = count - 1;
		count = b;
                for (j = 0; j < foo.snum.size(); ++j) {
		  stringstream  ss;
		    string sss;
                    no = foo.snum[j] - '0';
		    ss << no;
		    sss = ss.str();

                    bit = bmap[no][i];

                    for (k = 0; k < 4; ++k) {
		       while(b>0){
			cout << " ";
			b--;
		      }
                        line_map += (bit & (8 >> k) ? sss+sss : "  ");

                    }
                    line_map += " ";

                }

                cout << line_map << endl;
                line_map = "";
		b = count - 1;
		count = b;
            }
            break;
        case 3 :
            for (i = 0; i < 5; ++i) {
                for (j = 0; j < foo.snum.size(); ++j) {
		  stringstream  ss;
		    string sss;
                    no = foo.snum[j] - '0';
		    ss << no;
		    sss = ss.str();

                    bit = bmap[no][i];

                    for (k = 0; k < 4; ++k) {
		      while(b>0){
			cout << " ";
			b--;
		      }
                        line_map += (bit & (8 >> k) ? sss+sss+sss : "   ");

                    }
                    line_map += " ";
                }
                cout << line_map << endl;
                line_map = "";

	       	b = count - 1;
		count = b;
                for (j = 0; j < foo.snum.size(); ++j) {
		  stringstream  ss;
		    string sss;
                    no = foo.snum[j] - '0';
		    ss << no;
		    sss = ss.str();

                    bit = bmap[no][i];

                    for (k = 0; k < 4; ++k) {
		      while(b>0){
			cout << " ";
			b--;
		      }
                        line_map += (bit & (8 >> k) ? sss+sss+sss : "   ");

                    }
                    line_map += " ";
                }
                cout << line_map << endl;
                line_map = "";
		b = count - 1;
		count = b;

                for (j = 0; j < foo.snum.size(); ++j) {
		  stringstream  ss;
		    string sss;
                    no = foo.snum[j] - '0';
		    ss << no;
		    sss = ss.str();

                    bit = bmap[no][i];

                    for (k = 0; k < 4; ++k) {

		      while(b>0){
			cout << " ";
			b--;
		      }
                       line_map += (bit & (8 >> k) ? sss+sss+sss : "   ");

                    }
                    line_map += " ";
                }
                cout << line_map << endl;
                line_map = "";
		b = count - 1;
		count = b;
            }
            break;
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
