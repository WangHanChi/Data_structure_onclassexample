// exercise4.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using namespace std;
#include <sstream>
#include <fstream>
#include <string>




class Gint {

private:
    string snum;
    int num;

public:
    Gint() {}

    Gint(const string& sno) : snum(sno) {
        num = snum2num(snum);

    }

    int get_num() const {
        return num;
    }

    string get_snum() const {
        return snum;
    }

    int snum2num(const string& sno) const {
        int a;
        a = stoi(sno);
        return a;
    }
    
    friend istream operator>> (istream& in, Gint& foo) {
        char ss;
        in >> foo.snum >> ss;
        return in;

    }
    
};


int main()
{
    ifstream infile("gint_dat.txt");
    int sum;
    Gint foo;
    string line;
    istringstream istr;

    while (getline(infile, line))
    {
        istr.str(line);
        sum = 0;
        while (istr >> foo) {
            sum = sum + foo.get_num();
        }
        istr.clear();
        cout << "sum of " << line << " = " << sum << endl;
    }

    return 0;
}

