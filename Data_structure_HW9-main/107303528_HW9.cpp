// 107303528_HW9.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
using namespace std;

struct RGB_Color {  //用來儲存rgb顏色名字以及三色色碼值的

    string cname;
    int r, g, b;

    RGB_Color(string s, int a, int b, int c) : cname(s), r(a), g(b), b(c) {}

};

ostream& operator<< (ostream& out, const RGB_Color& foo)
{   //重載其輸出運算子，可以做為檢查是否有成功讀到檔
    out << foo.cname << "  " << foo.r << "  " << foo.g << "  " << foo.b;

    return out;
}


struct CMYK_Color { //用來儲存CMYK顏色名字以及其四色色碼值得

    string name;
    double c, m, y, k;


    CMYK_Color(string s, double a, double b, double c, double d) : name(s), c(a), m(b), y(c), k(d) {}


};

ostream& operator<< (ostream& out, const CMYK_Color& foo)
{   //重載其輸出運算子，讓輸出的檔案可以依照下面的規則寫入
    out << "(" << foo.c << ", " << foo.m << ", " << foo.y << ", " << foo.k << ")  " << foo.name;
    return out;
}





struct RGB_CMYK {
    //RGB轉換到CMYK
    CMYK_Color operator() (const RGB_Color& rgb)
    {

        double r2, g2, b2, c, m, y, k;
        //先將RGB三個數值正規化
        r2 = rgb.r / 255.0;
        g2 = rgb.g / 255.0;
        b2 = rgb.b / 255.0;
        //要找出RGB三色之中最大值
        //先比較R、G兩色
        double big = max(r2, g2);
        //找出R、G之後，再將跟B做比較，取得三色之中最大的值，最後再依照公式求出K的值
        k = 1 - max(big, b2);

        if (k == 1) //若RGB三色都是0的話，k就會是1，為了避免分母出現0的情況，於是直接列出k=1時，cmy的值
        {
            c = 0;
            m = 0;
            y = 0;
        }
        else
        {
            //若k不等於1的話，直接照公式做計算就好
        }
        {
            c = (1 - k - r2) / (1 - k);
            m = (1 - k - g2) / (1 - k);
            y = (1 - k - b2) / (1 - k);

        }
        return (CMYK_Color(rgb.cname, c, m, y, k)); //回傳CMYK_Color
    }

};


int main()
{
    ifstream infile("rgb.dat"); //讀檔
    ofstream outfile("cmyk.dat");   //輸出檔
    int red, green, blue;

    string name, line;
    istringstream istr;
    vector<RGB_Color> colors;
    vector<CMYK_Color> foo;
    vector<int> f;
    while (getline(infile, line))
    {
        istr.str(line);
        istr >> name >> red >> green >> blue;
        colors.push_back(RGB_Color(name, red, green, blue));    //把讀到的istr寫入到colors之中
        istr.clear();
    }
    transform(colors.begin(), colors.end(), ostream_iterator<CMYK_Color>(outfile, "\n"), RGB_CMYK());
    //使用transform把RGB轉換成CMYK
    //其使用方法為transform(起始點, 終止點, 輸出方法, 轉換方法)


    return 0;
}
