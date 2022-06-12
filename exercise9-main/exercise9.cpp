// exercise9.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

struct Lottery 
{
    string name;
    vector<int> num;

    Lottery(string& s, vector<int>& n) : name(s), num(n) {}


};

ostream& operator<< (ostream& out, Lottery& foo) 
{
    out <<setw(2) << foo.name << setw(2) << ":" << setw(4) << foo.num[0] << setw(4) << foo.num[1] << setw(4) << foo.num[2]
        << setw(4) << foo.num[3] << setw(4) << foo.num[4] << setw(4) << foo.num[5];

    return out;
}

struct nnn
{
    vector<int> number;

    nnn(vector<int>& nn) : number(nn) {}
};

ostream& operator<< (ostream& out, nnn& foo)
{
    for (int i = 0; i < foo.number.size(); ++i)
    {
        out << setw(3) << foo.number[i] ;
    }

    return out;
}


int main()
{
    unsigned seed;
    seed = (unsigned)time(NULL);
    srand(seed);
    vector<Lottery> foo;
    vector<nnn> out;
    vector<int> input;
    vector<int>::iterator iter;
    vector<int> output;
    string lucky_name = "LT", general_name;
    vector<int> check;
    int n;
    for (int i = 0; i < 6; ++i)
    {
        n = rand() % 48 + 1;
        input.push_back(n);
    }
    sort(input.begin(), input.end());
    foo.push_back(Lottery(lucky_name, input));
    input.clear();
    cout << foo[0] << endl;
    for (int i = 1; i < 11; ++i)
    {
        do
        {
            for (int j = 0; j < 6; ++j)
            {
                n = rand() % 48 + 1;
                input.push_back(n);
            }
            sort(input.begin(), input.end());
            set_intersection(input.begin(), input.end(), input.begin(), input.end(), back_inserter(check));
        } while (check.size() < 6);

        general_name = to_string(i);
        foo.push_back(Lottery(general_name, input));
        input.clear();
        set_intersection(foo[0].num.begin(), foo[0].num.end(), foo[i].num.begin(), foo[i].num.end(), back_inserter(output));
        out.push_back(nnn(output));
        //cout << out[0] << endl;
        
        if (out.size() == 0)
        {
            cout << foo[i] << " ---> " << "[" << output.size() << "]" << endl;
        }
        else 
        {
            cout << foo[i] << " ---> " << "[" << output.size() << "]" << out[0] << endl;
        }
        
        out.clear();
        output.clear();
        output.reserve(0);
    }
    
    
}

