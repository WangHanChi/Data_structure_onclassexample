//
//  main.cpp
//  107303528_HW2_2
//
//  Created by 王漢祺 on 2022/3/12.
//

#include <iostream>
using namespace std;


class Bucket{
    
private:
    int max_height;     //滿水位高度
    int water_height;   //實際的水位高
    
public:
    //滿水位高度為m
    //fill為真，水桶為滿水位，若為假，則為空水位
    Bucket(int m, bool fill = false);
    int current_height() const;
    friend Bucket &operator>>(Bucket& a, Bucket& b){        //設定 >> 為把左邊水桶的水倒給右邊水桶
        while (a.water_height > 0 && b.max_height > b.water_height) {
            a.water_height = a.water_height - 1;
            b.water_height = b.water_height + 1;
        }       //假如左邊水桶還有水並且右邊水桶還沒有滿的話，就執行倒水的動作
        return a;
    }
    friend Bucket &operator<<(Bucket& a, Bucket& b){        //設定 << 為把右邊水桶的水倒給左邊水桶
        while (b.water_height > 0 && a.max_height > a.water_height) {
            b.water_height = b.water_height - 1;
            a.water_height = a.water_height + 1;
        }       //假如右邊水桶還有水並且左邊水桶還沒有滿的話，就執行倒水的動作
        return a;
    }
    
};

Bucket::Bucket(int m, bool fill ){
    max_height = m;         //設定最高水位
    if (fill == true) {     //如果fill為true，即為滿水位，預設為false
        water_height = m;   //所以a, b, c都是空的
    }else if(fill == false){
        water_height = 0;
    }
    
}

int Bucket::current_height()const{
    return water_height;        //回傳目前的水位高度
}



int main(int argc, const char * argv[]) {
    const bool FILL_UP = true;
    
    Bucket a(5), b(3), c(100);  //設定a, b, c的最高水位，同時設定為空的
    Bucket f(100, FILL_UP);     //設定f的最高水位，同時設定為滿水
    
    cout << a.current_height() << " " << b.current_height() << " " << c.current_height() << endl;
    f >> a >> b;        //f倒向a後，f再倒向b   --> a = 5, b = 3, c = 0
    cout << a.current_height() << " " << b.current_height() << " " << c.current_height() << endl;
    a >> ( b >> c );    //b倒向c後，a再倒向b   --> a = 2, b = 3, c = 3
    cout << a.current_height() << " " << b.current_height() << " " << c.current_height() << endl;
    a >> ( b >> c );    //b倒向c後，a再倒向b   --> a = 0, b = 2, c = 6
    cout << a.current_height() << " " << b.current_height() << " " << c.current_height() << endl;
    ( a << f ) >> b;    //f倒向a後，a再倒向b   --> a = 4, b = 3, c = 6
    
    //列印a, b, c的水位高度
    cout << a.current_height() << " " << b.current_height() << " " << c.current_height() << endl;
    //cout << f.current_height() << endl;
    return 0;
}
