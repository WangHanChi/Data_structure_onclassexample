// exercise7.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;



class Llist {
private:
    list< list<int> > num;
    int n;
public:
    
    Llist(int no) : n(no) {
        int x = 1;
        int count = 1;
        list<int> l;
        

        for (int i = 1; i <= n; ++i) {

             for (int j = 1; j < i + 1; ++j) {
                l.push_back(x);
                 x++;
                 
                count++;
                
             }

            num.push_back(l);
        }
             
    }


    friend ostream& operator<< (ostream& out, Llist& foo) {
        int count = 0;
        list <list <int> >::iterator itr;
        for (itr = foo.num.begin(); itr != foo.num.end(); ++itr) {
            list<int> tl = *itr;
            list<int>::iterator it;
            for (it = tl.begin() ; it != tl.end(); ++it) {
                out << *it << " ";
                
            }
            out << endl;
            
        }
        return out;
    }
};


int main()
{
    Llist foo(5);
    cout << foo << endl;
    

    /*
    list<int> l{ 1,2,3,4 };
    list<int> l1{ 5,6,7,8,9};
    list<int> llll{ 10, 11, 12, 13 };
    list<list<int>> lll;
    lll.push_back(l);
    lll.push_back(l1);
    lll.push_back(llll);
    list<list<int>>::iterator itr;
    for (itr = lll.begin(); itr != lll.end(); itr++)
    {
        list<int>tl = *itr;
        list<int>::iterator it;

        for (it = tl.begin(); it != tl.end(); it++)
        {
            cout << *it;
        }
        cout << endl << "End" << endl;
    }
    return 0;

    
    output:
    1234
    End
    56789
    End
    10111213
    End
    

    */

}

