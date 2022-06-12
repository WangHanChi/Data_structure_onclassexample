// 107303528_HW3.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <bitset>
using namespace std;

int main() {

    //107303528 機械4A 王漢祺
    //資料結構  作業三

    
    ifstream infile1("hex_data.txt");   //開啟hex_data.txt這個檔案，裡面是十六進位14列的資料
    ofstream outfile1("data.txt");      //存入data.txt這個檔案

    unsigned int a;
    string number;
    infile1.setf(ios_base::uppercase);      //以十六進位讀取檔案

    while (infile1 >> number) {         //把infile1讀取到的資料寫入number
        stringstream ss;
        ss << hex << number;            //把number以十六進位寫入ss
        ss >> a ;                       //把ss寫入a
        outfile1 << a << "\n";          //把a寫入outfile1
        //cout << a << endl;
    }
    
    infile1.close();
    outfile1.close();

    //已經把十六進位14列的檔案(hex_data.txt)轉成十進位存進(data.txt)了
    ifstream infile2("data.txt", ios_base::in | ios_base::binary);
    ofstream outfile2("two_in_one_data", ios_base::out | ios_base::binary);

    unsigned int tmp = 0 ;      //避免出現溢位且已知數字皆為正值，所以使用無號數
    unsigned int  number2;
    unsigned int all;
   
    
    for (int i = 1; i < 15; i++) {
        infile2 >> number2;
        if (i % 2 == 1) {
            tmp = number2;      //為了把兩個數字整合在一起，所以先將奇數行的數字存在tmp中
        }
        else if (i % 2 == 0) {
            all = tmp * 1024 + number2;     //把奇數行與偶數行的數字整合在一起
            //cout << all << endl;
            outfile2.write(reinterpret_cast<char*>(&all), sizeof(all));
            //把檔案以二進位的方式存檔
        }
    }

    infile2.close();
    outfile2.close();
    //已經把整數存成二進制，存在(two_in_one_data.txt)中

    

    //cout << "---------" << endl;
    ifstream infile3("two_in_one_data", ios_base::in | ios_base::binary);       //  以二進位的形式讀取檔案
    int k,i;
    int array[14][1];
    int print[14][10] = {0};
    unsigned int first = 0;
    unsigned int second = 0;

    for (i = 0; i < 7; ++i) {
        infile3.read(reinterpret_cast<char*>(&k), sizeof(k));
        first = k / 1024;
        second = k - (first * 1024);
        array[i*2 ][0] = first;
        array[i * 2 + 1][0] = second;
    }   //將奇數行與偶數行的數字重新分好，回到最原本的14列
    
    int value = 0, m = 0, c = 0, j = 0,t = 0;
    int n = 2;
    
    k = 0;
    for ( i = 0; i < 14; i++)
    {
        j = 0;
        int temp[10] = { 0,0,0,0,0,0,0,0,0,0 };
        value = array[i][0];
        
        while (value > 0)
        {
            c = (value % n);
            temp[j] = c;
            value = value / n;
            j++;
        }   //把數字以0或1的型式儲存在temp這個陣列之中
        t = 0;
        for (j = 9; j >= 0; j--)
        {
            print[i][t] = temp[j];
            t++;
            //把temp中的值裝回去print這個陣列之中
            //要特別注意的是原先temp是反著寫入的
            //所以再填入print這個陣列的時候要相反過來
        }
    }

    
    for ( i = 0; i < 14; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (print[i][j] ==0)    //如果是0的話就印出空格
            {
                cout << " ";
            }
            else if (print[i][j] == 1) {    //如果是1的話就印出*
                cout << "*";
            }
        }
        cout << endl;
    }
    
    return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
