// 107303528_HW4.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
bool isNum(string str);                 //宣告一個函式判斷是string還是double

int main() {
    string line;
    double no1, sum;
    istringstream istr;
    string tmp;

    cout << " > ";
    while (getline(cin, line)) {        //取得輸入的這行字串

        istr.str(line);                 //將字串存入istr中
        sum = 0;                        //每次讀取新的字串之後都將把sum歸零
        cout << "sum of ";
        while (1) {
            if (istr >> tmp) {          //不論istr是string還是double都先存入tmp之中


                if (isNum(tmp) == 1) {  //此處需要這個判斷式是因為假如tmp是字串
                                        //但仍使用stof()轉成浮點數的話會出錯，因此加個篩選機制

                    no1 = stof(tmp);    //將tmp轉成double
                    cout << tmp << " ";//輸出tmp
                    sum += no1;         //總和加總
                }
            }
            else {
                if (istr.eof()) break;  //如果讀到了結尾eof，就終止
                istr.clear();           //清除錯誤的旗幟

                istr.ignore();
            }
        }
        istr.clear();
        cout << " = " << sum << endl;   //輸出總和
        cout << " > ";
    }
    return 0;
}


bool isNum(string str)              //判斷是否為double的函式，回傳值為0或1
{
    stringstream ss(str);
    double d;
    char c;
    if (!(ss >> d))                //如果不能把ss存成double的話，就回傳false
    {
        return false;
    }
    if (ss >> c)                    //篩選像是.9.8這種字，.9會在前面被轉換掉，
                                    //此時ss剩下.8，就可以把類似這種的字串過濾掉
    {
        return false;
    }
    return true;
}

//cat 10ee2 -10 c .9 xx .5.8 0.5e+1 +=
//3 cat 2.34 -2 c ++ 0.12e3 tiger -1d-1 0.3ee4 0.3.4 .5