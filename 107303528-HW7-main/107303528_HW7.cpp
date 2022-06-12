
//  107303528_HW6
//
//  Created by 王漢祺 on 2022/4/28.
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
using namespace std;

double count_diff(vector<int>& a, int& b, vector<int>& c, int& d
	, vector<int>& e, int& f, int& g) {
	//int sum = 0;
	//sum = abs(b - a[g]) + abs(d - c[g]) + abs(f - e[g]);
	//cout << g << " sum : " << sum << endl;
	//上面是舊的計算公式
	//下面是新的計算公式
	double dr = abs(a[g] - b);
	double dg = abs(c[g] - d);
	double db = abs(e[g] - f);
	double rbar = (a[g] + b) / 2;
	double dis;
	dis = sqrt((2 * dr * dr) + (4 * dg * dg) + (3 * db * db) + (rbar * (dr * dr - db * db) / 256));
	
	return dis;
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


int main() {
	do {

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
		double standard = 721;	//宣告一個變數去儲存最小的誤差值
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


		cout << "> ";
		cin >> input_num0 >> input_num1 >> input_num2;
		
		priority_queue <ALL, vector<ALL>, greater<ALL> > AAA;	//用來儲存顏色名、各色碼值、誤差值
		priority_queue <double, vector<double>, greater<double> > DIS;	//	用來儲存誤差

		for (int i = 0; i < color_name.size() - 1; ++i)
		{
			double tmp = count_diff(color_num0, input_num0, color_num1, input_num1, color_num2, input_num2, i);
			dis.push_back(tmp);
			//cout << "dis : " << dis[i] << endl;

			int a1 = color_num0[i];
			int a2 = color_num1[i];
			int a3 = color_num2[i];
			string name = color_name[i];

			if (tmp < standard) {	//用來獲得誤差最小的一個值
				standard = tmp;
			}

			AAA.push(ALL(name, a1, a2, a3, tmp));	//	根據誤差將資料存入AAA中
			DIS.push(tmp);	//根據誤差將值存入DIS中
		}
		int h = 0;
		while (!DIS.empty()) {	//把DIS的值存入dis之中
			dis[h] = DIS.top();
			//cout << DIS.top() << endl;
			DIS.pop();
			h++;
		}

		if (standard >= 20)	//如果最小誤差>20，直接跳出去並且輸出 "無相近顏色"
		{
			cout << "無相近顏色" << endl;

		}

		for (int i = 0; i < color_name.size() - 1; ++i)
		{


			if (dis[i] == standard && dis[i] < 20)	//當誤差<20並且是最小值的時候，資料才會被輸出
			{
				cout << AAA.top() << endl;
				AAA.pop();
			}
			else
			{
				AAA.pop();
			}
		}
	} while (1);
	return 0;
}
