// exercise3.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

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

        switch (s)
        {
        case 1 :
            for (i = 0; i < 5; ++i) {
                for (j = 0; j < foo.snum.size(); ++j) {

                    no = foo.snum[j] - '0';

                    bit = bmap[no][i];

                    for (k = 0; k < 4; ++k) {
                        line_map += (bit & (8 >> k) ? "*" : " ");

                    }
                    line_map += " ";
                }
                cout << line_map << endl;
                line_map = "";
            }
            break;
        case 2 :
            for (i = 0; i < 5; ++i) {
                for (j = 0; j < foo.snum.size(); ++j) {

                    no = foo.snum[j] - '0';

                    bit = bmap[no][i];

                    for (k = 0; k < 4; ++k) {
                        line_map += (bit & (8 >> k) ? "**" : "  ");

                    }
                    line_map += " ";

                }
                
                cout << line_map << endl;
                line_map = "";

                for (j = 0; j < foo.snum.size(); ++j) {

                    no = foo.snum[j] - '0';

                    bit = bmap[no][i];

                    for (k = 0; k < 4; ++k) {
                        line_map += (bit & (8 >> k) ? "**" : "  ");

                    }
                    line_map += " ";

                }

                cout << line_map << endl;
                line_map = "";
            }
            break;
        case 3 :
            for (i = 0; i < 5; ++i) {
                for (j = 0; j < foo.snum.size(); ++j) {

                    no = foo.snum[j] - '0';

                    bit = bmap[no][i];

                    for (k = 0; k < 4; ++k) {
                        line_map += (bit & (8 >> k) ? "***" : "   ");

                    }
                    line_map += " ";
                }
                cout << line_map << endl;
                line_map = "";

                for (j = 0; j < foo.snum.size(); ++j) {

                    no = foo.snum[j] - '0';

                    bit = bmap[no][i];

                    for (k = 0; k < 4; ++k) {
                        line_map += (bit & (8 >> k) ? "***" : "   ");

                    }
                    line_map += " ";
                }
                cout << line_map << endl;
                line_map = "";

                for (j = 0; j < foo.snum.size(); ++j) {

                    no = foo.snum[j] - '0';

                    bit = bmap[no][i];

                    for (k = 0; k < 4; ++k) {
                        line_map += (bit & (8 >> k) ? "***" : "   ");

                    }
                    line_map += " ";
                }
                cout << line_map << endl;
                line_map = "";
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

