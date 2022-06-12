// 107303528_HW8.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
using namespace std;

double count_diff(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d
	, vector<int>& e, vector<int>& f, int& g, int& h) 
{	//距離計算的公式
	double dr = abs(a[g] - b[h]);
	double dg = abs(c[g] - d[h]);
	double db = abs(e[g] - f[h]);
	double rbar = (a[g] + b[h]) / 2;
	double dis;
	dis = sqrt((2 * dr * dr) + (4 * dg * dg) + (3 * db * db) + (rbar * (dr * dr - db * db) / 256));

	return dis;
}

struct ALL {	//這個沒有儲存距離小於20顏色個數的變數count，下面的ALL2有

	string name;		//儲存顏色的名字
	int num0;			//儲存色碼R
	int num1;			//儲存色碼G
	int num2;			//儲存色碼B
	double dis;			//儲存距離

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


struct ALL2 {
	string self_name;	//儲存顏色的名字
	string name;		//儲存與之距離小於20顏色的名字
	int num0;			//儲存色碼R
	int num1;			//儲存色碼G
	int num2;			//儲存色碼B
	double dis;			//儲存距離
	int count;			//儲存距離小於20顏色的個數
	ALL2(string s, string n, int a, int b, int c, double d, int e) : self_name(s), name(n), num0(a), num1(b), num2(c), dis(d), count(e) {};

};

bool operator< (const ALL2& a, const ALL2& b) {	//pirority_queue的排序依據
	//比較依序 1.距離小於20的個數(大到小)	2.顏色的名字(大到小)	3.距離(小到大)
	if (a.count < b.count)
	{
		return true;
	}
	else if (a.count == b.count)
	{
		if (a.self_name < b.self_name)
		{
			return true;
		}
		else if (a.self_name == b.self_name)
		{
			if (b.dis < a.dis)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else 
	{
		return false;
	}
}



ostream& operator<< (ostream& out, const ALL2& foo) {	//輸出ALL2的輸出運算子
	
	out << setw(4) << setprecision(2) << fixed << foo.dis << "  \t"  << hex << foo.num0 << hex << foo.num1 << hex << foo.num2 << "  \t"  << foo.name;
	//setprecisiom(2) << fixed 是用來取小數點到第二位的
	//<< hex << 是把數字(十進位)轉換成十六進位
	return out;
}


int main() {
		vector<string> color_name;
		vector<int> color_num0;
		vector<int> color_num1;
		vector<int> color_num2;
		vector<int> dis;
		int input_num0;
		int input_num1;
		int input_num2;

		ifstream infile("rgb.txt");
		string name;
		int num;
		double tmp = 0;
		int how_many = 3;
		int output_num = 0;
		while (infile)		//分別讀入資料
		{
			infile >> name;
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


		priority_queue <ALL, vector<ALL>, greater<ALL> > AAA;	//用來儲存顏色名、各色碼值、誤差值
		priority_queue <ALL2, vector<ALL2>, less<ALL2> >BBB;	//用來儲存要輸出的各項資料
		
		for (int i = 0; i < color_name.size() - 1; ++i)
		{
			int first = 0;
			for (int j = 0; j < color_name.size() - 1; ++j)
			{
				if (i == j) break;		//為了排除自己
				tmp = count_diff(color_num0, color_num0, color_num1, color_num1, color_num2, color_num2, i, j);
				if (tmp < 20 && tmp > 0)//在(0, 20)這個區間才會被記入
				{
					first++;
					AAA.push(ALL(color_name[j], color_num0[j], color_num1[j], color_num2[j], tmp));
				}
			}
			//上面取得距離小於20的個數之後，下面便依照個數將之存入，存入後刪除
			for (int k = 0; k < first; ++k)
			{
				BBB.push(ALL2(color_name[i], AAA.top().name, AAA.top().num0, AAA.top().num1, AAA.top().num2, AAA.top().dis, first));
				AAA.pop();
			}
		}

		for (int i = 0; i < 3; ++i)		//題意要求前三種
		{
			cout << setw(2) << "[" << i + 1 << "]    " << setw(6) << BBB.top().self_name << " :" << endl;
			for (int j = 0; j < BBB.top().count; ++j)	//根據其有幾個距離小於20的就重複幾次
			{
				cout << setw(2) << j + 1 << "  " << setw(4) << BBB.top() << endl;
				BBB.pop();
			}
			cout << endl;
			
		}
	return 0;
}

