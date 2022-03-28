#include <iostream>
#include <sstream>
using namespace std;

template <typename T>

class Point{
private:
	T x, y;
public:
	Point(){}
	Point(const T& a, const T& b):x(a), y(b) {};
	Point<T> clone() const;	

	template <typename S>
	friend ostream& operator<< (ostream& out, const Point<S>& foo){
		return out << "[" << foo.x << ", " << foo.y << "]";
	}

};


template <typename T>
Point<T> Point<T>::clone() const {return *this; }

int main(){
	Point<int> a(3, 4);
	cout << a << endl;

	cout << a.clone() << endl;
	Point<double> b(1.2, 3.4);
	cout << b << endl;
return 0;
}
