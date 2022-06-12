// 107303528_HW6.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

// aaa.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>


using namespace std;


int count_diff(vector<int>& a, int& b, vector<int>& c, int& d
				,vector<int> & e, int& f, int& g) {
	int sum = 0;
	sum = abs(b - a[g]) + abs(d - c[g]) + abs(f - e[g]);
	//cout << g << " sum : " << sum << endl;
	
	
	
	return sum;

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

		while (infile)
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

		for (int i = 0; i < color_name.size() - 1; ++i)
		{
			//cout << color_name[i] << " : " << color_num0[i]  << " " << color_num1[i] << " " << color_num2[i] <<"/////" << i << endl;
		}



		cout << "> ";
		cin >> input_num0 >> input_num1 >> input_num2;
		//cout << input_num0 << "///" << input_num1 << "///" << input_num2 << endl;

		//dis.push_back(count_diff(color_num0, input_num0, color_num1, input_num1, color_num2, input_num2));
		
		
		for (int i = 0; i < color_name.size() - 1 ; ++i) 
		{
			int tmp = count_diff(color_num0, input_num0, color_num1, input_num1, color_num2, input_num2, i);
			dis.push_back(tmp);
			//cout << dis[i] << endl;
		}


		for (int j = 0; j < color_name.size() - 1; ++j) 
		{
			for (int i = j + 1; i < color_name.size() - 1; ++i) 
			{
				if (dis[ i ] < dis[ j ])
				{
					swap(dis[i], dis[j]);
					swap(color_name[i], color_name[j]);
					swap(color_num0[i], color_num0[j]);
					swap(color_num1[i], color_num1[j]);
					swap(color_num2[i], color_num2[j] );
				}
			}
			
		}


		for (int i = 0; i < color_name.size() - 1 ; ++i)
		{
			//cout << color_name[i] << " [ " << dis[i] << " ] " << color_num0[i] << " " << color_num1[i] << " " << color_num2[i] << endl;
		}

		int standard = dis[0];
		//cout << "standard : " << standard << endl;
		

		if (dis[0] >= 20)
		{
			cout << "無相近顏色" << endl;
			
		}

		for (int i = 0; i < color_name.size() - 1; ++i)
		{
			
			if(dis[i] == standard && dis[i] < 20)
			{
				cout << color_name[i] << " [ " << dis[i] << " ] " << color_num0[i] << " " << color_num1[i] << " " << color_num2[i] << endl;
			}
			
		}

		
	} while (1);


	
	return 0;
}


