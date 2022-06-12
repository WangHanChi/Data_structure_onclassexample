// exercise6.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <functional>

using namespace std;



struct Words {
    vector<string> strs;
};

struct WordSize {
    int x;
    WordSize(int a) : x(a) {}
    bool operator() (const vector<string>& foo) const {
        for (int i = 0; i < foo.size(); ++i) {
            if (foo[i].size() <= x) {
                return false;
            }
            else {
                return true;
            }
        }
    }

};


template< typename T, typename F>
void print_words(T a, T b, F fn) {
    for (T c = a; c != b; ++c) {
        if (fn(*c)) {
            cout << *c << " ";
        }
    }
}

istream& operator>> (istream& in, Words& foo) {

    while (foo.strs.size()) foo.strs.pop_back();
    
    string num;
    while (in >> num) {
        foo.strs.push_back(num);
    }

    return in;
}


ostream& operator<< ( ostream& out, const Words& foo) {
    
    for (int i = 0; i < foo.strs.size() ; ++i) {
        out << foo.strs[i] << " ";
    }

    return out;
}


int main()
{
    int n = 4;
    string line;
    istringstream istr;
    vector<Words> foo;
    Words word;
    do {
        cout << "> ";
        getline(cin, line);
        istr.str(line);
        while (istr >> word) {
            foo.push_back(word);
        }
        istr.clear();
        
        print_words(foo.begin(), foo.end(), WordSize(n));
        foo.clear();
    } while (1);

}

