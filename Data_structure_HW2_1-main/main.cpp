//
//  main.cpp
//  107303528_HW2_1
//
//  Created by 王漢祺 on 2022/3/8.
//

#include <iostream>
using namespace std;
#include <string>   //使用字串的標頭檔
#include <stdlib.h> //使用亂數的標頭檔
#include <time.h>   //使用時間的標頭檔
#include <unistd.h>


//三個骰子的點數為隨機的，而非輸入或是亂數表，所以可能會跑很多次><
class My_Dice{
    
private:
    string personal_name;   //設定名字
    int dice_1;             //骰子1的值
    int dice_2;             //骰子2的值
    int dice_3;             //骰子3的值
    int dice[3];            //儲存骰子值的陣列
    
public:
    My_Dice( string a);     //輸入名字
    void throw_dices();     //執行骰骰子
    string name();          //用以回傳名字
    int output1();          //回傳骰子1的值
    int output2();          //回傳骰子2的值
    int output3();          //回傳骰子3的值
    int val();              //回傳骰子組的點數
    friend ostream &operator<< (ostream& out, const My_Dice& foo){
        out << foo.dice_1 <<" "<< foo.dice_2 <<" "<< foo.dice_3<<" ---> ";
        return out;         //用運算子重載來輸出三個骰子的值
    }
};

//主函式
int main(int argc, const char * argv[]) {
    
    My_Dice p("Amy"), q("Tom"); //賭客名字
    do {
        p.throw_dices();    //p擲骰子
        sleep(2);
        q.throw_dices();    //q擲骰子
        
        cout << p.name() << " " << p << p.val() <<endl;     //印出各個賭客名字，每個骰子的點數與骰子組點數
        cout << q.name() << " " << q << q.val() <<endl << endl;
        
        
    } while (p.val() == 0 || q.val() == 0 || p.val() == q.val() );
        //p.val()或q.val()計算p與q兩個人骰子組的點數
    
    cout << ( p.val() > q.val() ? p.name() : q.name() ) << " wins " << endl;
        //印出勝利一方的名字
    return 0;
}

My_Dice::My_Dice( string a){
    personal_name = a;      //把名字儲存起來
}

void My_Dice::throw_dices(){
    unsigned seed;          //設定真的隨機亂數，否則每次出現的值都是遵循著亂數表
    seed = (unsigned)time(NULL); // 取得時間序列
    srand(seed*1000);
    dice[0] = rand()%6 + 1;     //讓骰子值在1~6之間
    dice[1] = rand()%6 + 1;     //讓骰子值在1~6之間
    dice[2] = rand()%6 + 1;     //讓骰子值在1~6之間
    for (int i = 0; i < 2; i++) {       //把骰子的值由小到大做排序，方便後面得到骰子組的值
        for (int j = 0; j < 2; j++) {
            if (dice[j] > dice[j+1]) {
                swap(dice[j], dice[j+1]);
            }
        }
        if (dice[i] > dice[i+1]) {
            swap(dice[i], dice[i+1]);
        }
    }
    dice_1 = dice[0];
    dice_2 = dice[1];
    dice_3 = dice[2];
}

string My_Dice::name(){
    return personal_name;       //回傳名字
}

int My_Dice::val(){
    if (dice_1 != dice_2 && dice_2 !=dice_3) {
        //三個骰子都不一樣，所以回傳點數為0
        return 0;
    }else if (dice_1 == dice_2 && dice_2 != dice_3){
        //第一個等於第二個，所以回傳點數為第三個
        return dice_3;
    }else if (dice_2 == dice_3 && dice_1 != dice_2){
        //第二個等於第三個，所以回傳點數為第一個
        return dice_1;
    }else if (dice_1 == dice_2 && dice_2 == dice_3){
        //三個骰子都一樣，所以回傳點數第一個
        return dice_1;
    }
    return 0;
}

int My_Dice::output1(){
    return dice_1;
}
int My_Dice::output2(){
    return dice_2;
}
int My_Dice::output3(){
    return dice_3;
}
