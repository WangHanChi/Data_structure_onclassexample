

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

//int diff;

struct rgb {
	string color;
	vector<int> rgb_value;
};

struct input {
	vector<int> number;
};

struct diff{
	vector<int> value;
};

/*
struct count {
	int x;
	vector<diff> han;
	
	count(int a) : x(a) {}
	bool operator()(const rgb& foo, const input& yu) const {
		diff = 0;
		for (int i = 0; i < foo.rgb_value.size(); ++i) {
			diff += (abs(foo.rgb_value[i] - yu.number[i]));
		}

		if (diff >= 20) {
			return false;
		}
		else if (diff < 20) {
			return true;
		}
	}
};
*/
int count( rgb& foo, input& yu){
	int sum = 0;
	int i ;
	for(i = 0; i < foo.rgb_value.size(); ++i){
		sum += abs(foo.rgb_value[i] - yu.number[i]);
	}

	return sum;
}


void print(rgb& a, rgb& b, int& diff){
	for(int i = 0; i < a.color.size(); ++i){
		if(diff >= 20){
			cout << "無相近顏色" << endl;
		}else if(diff < 20){
			cout << a.color[i] << "[ " << diff << " ]" << a.rgb_value << endl;		
		}
	}
}


istream& operator>> (istream& in, rgb& foo) {
	while (foo.rgb_value.size()) {
		foo.rgb_value.pop_back();
	}
	int Value;
	string word;

	getline(in, word);
	istringstream str(word);
	str >> foo.color;
	while (str >> Value) {
		foo.rgb_value.push_back(Value);
	}

	return in;
}

istream& operator>> (istream& in, input& yu) {
	while (yu.number.size()) {
		yu.number.pop_back();
	}
	int Value;
	
	while (in >> Value) {
		yu.number.push_back(Value);
	}

	return in;
}


ostream& operator<< (ostream& out, const rgb& foo) {
	out << foo.color << "";
	int sum = 0;
	for (int i = 0; i < foo.rgb_value.size(); ++i) {
		sum += foo.rgb_value[i];
		out << setw(4) << foo.rgb_value[i];
	}

	out << "";
	return out;
}


int main()
{

	ifstream infile("rgb.txt");

	vector<rgb> foo;
	rgb name;

	while (infile >> name) {
		foo.push_back(name);
	}


	int i;

	cout << "this is origin : " << endl;

	for (i = 0; i < foo.size(); ++i) {
		cout << foo[i] << endl;
	}


	do {
		string line;
		istringstream istr;
		vector<input> yu;
		input input_number;

		cout << "> ";
		getline(cin, line);
		istr.str(line);
		while (istr >> input_number) {
			yu.push_back(input_number);
		}
		istr.clear();
		print(foo.begin(), foo.end(), count(rgb& foo, input& yu));



		//		for(i = 0; i < yu.size(); ++i){
		//			cout << yu[i] << " ";
		//		}
		//		cout << endl;
	} while (1);



	return 0;
}
