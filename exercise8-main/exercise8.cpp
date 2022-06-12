
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>


using namespace std;


int count_diff(vector<int>& a, int& b, vector<int>& c, int& d
    , vector<int>& e, int& f, int& g) {     //用來計算輸入RGB色碼與資料中的RGB色碼誤差的函式
    int sum = 0;        //每次進到迴圈都重置sum
    sum = abs(b - a[g]) + abs(d - c[g]) + abs(f - e[g]);    //abs為取絕對值，讓三個差值都為正的情況再做相加
    //cout << g << " sum : " << sum << endl;
    return sum;     //回傳sum

}


struct ALL {
    string name;
    int num0;
    int num1;
    int num2;
    double dis;

    ALL(string n, int a, int b, int c, double d) : name(n), num0(a), num1(b), num2(c), dis(d) {};

};

bool operator> (const ALL& a, const ALL& b) {	//pirority_queue的排序依據
    if (a.dis > b.dis) return true;
    else return false;
}

ostream& operator<< (ostream& out, const ALL& foo) {	//輸出ALL的輸出運算子
    out << foo.name << " " << foo.dis << " : " << foo.num0 << " " << foo.num1 << " " << foo.num2;

    return out;
}


template<typename T, typename F>
T sort_color(T a, F dis) {
    for (int j = 0; j < a.size() - 1; ++j)
    {
        for (int i = j + 1; i < a.size() - 1; ++i)
        {
            if (dis[i] < dis[j])
            {
                swap(dis[i], dis[j]);
                swap(a[i], a[j]);

            }
        }

    }

    return a;
}


int main() {

    do {

        vector<string> color_name;  //資料顏色的名字
        vector<int> color_num0;     //資料顏色RGB色碼的R值
        vector<int> color_num1;     //資料顏色RGB色碼的G值
        vector<int> color_num2;     //資料顏色RGB色碼的B值
        vector<int> dis;            //用來儲存誤差和的
        int input_num0;             //輸入的R值
        int input_num1;             //輸入的G值
        int input_num2;             //輸入的B值

        ifstream infile("rgb.txt"); //讀入檔案
        string name;
        int num;
        multimap <int, ALL> foo;
        int standard = 720;
        while (infile)              //每當讀入檔案時，執行while迴圈
        {
            infile >> name;         //將讀入的顏色名字與色碼RGB值依序分配給vector
            color_name.push_back(name);
            infile >> name;
            num = stoi(name);
            color_num0.push_back(num);
            infile >> name;
            num = stoi(name);
            color_num1.push_back(num);
            infile >> name;
            num = stoi(name);
            color_num2.push_back(num);

        }

        //for (int i = 0; i < color_name.size() - 1; ++i)       //  測試讀檔是否正確
        {
            //cout << color_name[i] << " : " << color_num0[i]  << " " << color_num1[i] << " " << color_num2[i] <<"/////" << i << endl;
        }



        cout << "> ";
        cin >> input_num0 >> input_num1 >> input_num2;      //輸入顏色色碼RGB值

        //此段負責將計算誤差並且儲存
        for (int i = 0; i < color_name.size() - 1; ++i)
        {
            int tmp = count_diff(color_num0, input_num0, color_num1, input_num1, color_num2, input_num2, i);
            //誤差和藉由tmp存入dis之中
            dis.push_back(tmp);
            //cout << dis[i] << endl;
            if (tmp <= standard) standard = tmp;

            foo.insert(pair<int, ALL>(tmp, ALL(color_name[i], color_num0[i], color_num1[i], color_num2[i], tmp)));

        }
        
        /*
        for (auto& s : foo) 
        {
            cout << "first : " << s.first << ", second : " << s.second << endl;
        }
        */
        
        /*
        vector<string> test;
        color_name = sort_color(color_name, dis);
        color_num0 = sort_color(color_num0, dis);
        color_num1 = sort_color(color_num1, dis);
        color_num2 = sort_color(color_num2, dis);



        //此段負責排序
        for (int j = 0; j < color_name.size() - 1; ++j)
        {
            for (int i = j + 1; i < color_name.size() - 1; ++i)
            {
                if (dis[i] < dis[j])
                {
                    swap(dis[i], dis[j]);
                    swap(color_name[i], color_name[j]);
                    swap(color_num0[i], color_num0[j]);
                    swap(color_num1[i], color_num1[j]);
                    swap(color_num2[i], color_num2[j]);
                }
            }

        }

        */
        
        
              //將排序好的誤差vector第一個值指派給standard，用來過濾掉誤差和小於20且不是最小誤差的
        //cout << "standard : " << standard << endl;


        if (standard >= 20)           //誤差超過20，輸出“無相近顏色”
        {
            cout << "無相近顏色" << endl;

        }

        for ( auto iter = foo.begin(); iter != foo.end(); ++iter)
        {
            if (iter->first == standard && iter->first < 20)
            {
                cout << iter->second << endl;
            }
            
        }
        
        
    } while (1);    //重複迴圈



    return 0;
}
