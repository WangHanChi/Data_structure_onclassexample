// 107303528_HW_bonus.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <set>
using namespace std;

map<wchar_t, int> chstrokes;


struct by_strokes { //按照筆畫排序的方法
    bool operator() (const wstring& a, const wstring& b) const 
    {
        int strokes;
        if (a.size() < b.size())    //讓strokes取筆劃少的那個的筆劃
        {
            strokes = a.size();
        }
        else
        {
            strokes = b.size();
        }
        
        for (int i = 0; i < strokes; ++i)
        {
            if (chstrokes[a[i]] < chstrokes[b[i]])  //按照筆劃來比較
            {
                return true;
            }
            else
            {
                return false;
            }
        }//若都一樣的話，就比其文字的長短
        return (a.size() < b.size() ? true : false);
    }

};
int main()
{
    setlocale(LC_ALL, "zh_TW.UTF-8");   //寬字串所需的設定

    wifstream infile("idioms.dat"); //讀入成語檔
    wifstream infile2("strokes.dat");   //讀入筆劃檔
    infile.imbue(locale("zh_TW.UTF-8"));    //讀檔設定所用的格式

    wstringstream istr1, istr2;
    wstring line, str1, str2;
    wchar_t word;
    int count, s, unicode;


    while (getline(infile2, line))  //讀筆劃檔
    {
        istr1.str(line);
        istr1 >> str1 >> s;
        count = str1.find('+'); //找到+號的位置，並把其下標的位置存在count之中
        str1 = str1.substr(count + 1);  //重新讓str1取得我們所需要的部分

        istr2.str(str1);
        istr2 >> hex >> unicode;    //把讀入的十六進制數字型別轉換後存到word
        word = static_cast<wchar_t>(unicode);
        istr2.clear();

        chstrokes[word] = s;    //把key跟value存入chstrokes這個map之中
        istr1.clear();
    }
    infile2.close();

    map<int, set<wstring, by_strokes> > s2i;
    

    int total;
    wstring idiom;
    while( getline(infile, line))   //讀成語檔
    {
        istr1.str(line);
        istr1 >> idiom;
        total = 0;
        for (int i = 0; i < idiom.size(); ++i)
        {
            total += chstrokes[idiom[i]];   //把筆劃加總
        }

        s2i[total].insert(idiom);   //根據key寫入value
        istr1.clear();
    }


    for (auto itr2 = s2i.begin(); itr2 != s2i.end(); ++itr2)
    {
        wcout << setw(2) << itr2->first << L" 畫 : ";    //輸出map的key，也就是筆劃(小 -> 大)

        for (auto sitr = itr2->second.begin(); sitr != itr2->second.end(); ++sitr)
        {
            wcout << *sitr << " ";  //輸出成語(筆劃少 -> 筆劃多)
        }
        wcout << endl;
    }


    return 0;
}


