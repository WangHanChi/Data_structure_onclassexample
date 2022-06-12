
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <set>
using namespace std;

struct Lottery 
{
    string name;
    set<int> num;

    Lottery(string& s, set<int>& n) : name(s), num(n) {}


};

ostream& operator<< (ostream& out, Lottery& foo) 
{
  out << foo.name << " : ";
  for(auto i = foo.num.begin(); i!= foo.num.end(); ++i){
    out << *i << " ";
  }

    return out;
}

struct Lottery2
{
    string name;
    set<int> num;

    Lottery2(string& s, set<int>& n) : name(s), num(n) {}


};

ostream& operator<< (ostream& out, Lottery2& foo) 
{
  //out << foo.name << " : ";
  for(auto i = foo.num.begin(); i!= foo.num.end(); ++i){
    out << *i << " ";
  }

    return out;
}

struct nnn
{
    vector<int> number;

    nnn(vector<int>& nn) : number(nn) {}
};

ostream& operator<< (ostream& out, nnn& foo)
{
    for (int i = 0; i < foo.number.size(); ++i)
    {
        out << setw(3) << foo.number[i] ;
    }

    return out;
}


int main()
{
    unsigned seed;
    seed = (unsigned)time(NULL);
    srand(seed);
    
    vector<Lottery> foo;
    set<int> bar;
    vector<nnn> out;
    vector<nnn> out2;
    vector<int> input;
    vector<int>::iterator iter;
    vector<int> output;
    vector<int> output2;
    vector<int> output3;
    string lucky_name = "LT", general_name;
    vector<int> check;
    int n;
    int count = 0;
    vector<Lottery2> yu;
    
    while( bar.size()  < 6 ){
        n = rand() % 48 + 1;
        bar.insert(n);
    }
    
    foo.push_back(Lottery(lucky_name, bar));
    bar.clear();
    input.clear();
    cout << foo[0] << endl;

    
    for (int i = 1; i < 11; ++i)
    {
        do
        {
            while( bar.size()  < 6 ){
	      n = rand() % 48 + 1;
	      bar.insert(n);
	    }
            //sort(input.begin(), input.end());
            set_intersection(bar.begin(), bar.end(), bar.begin(), bar.end(), back_inserter(check));
        } while (check.size() < 6);

        general_name = to_string(i);
        foo.push_back(Lottery(general_name, bar));
	yu.push_back(Lottery2(general_name, bar));
        input.clear();
	bar.clear();

	
        set_intersection(foo[0].num.begin(), foo[0].num.end(), foo[i].num.begin(), foo[i].num.end(), back_inserter(output));
        output2.push_back(output.size());
        
	  

	
        out.push_back(nnn(output));
	out2.push_back(nnn(output));
        //cout << out[0] << endl;
        
        if (out.size() == 0)
        {
            cout << foo[i] << " ---> " << "[" << output.size() << "]" << endl;
        }
        else 
        {
            cout << foo[i] << " ---> " << "[" << output.size() << "]" << out[0] << endl;
        }
        
        out.clear();
        output.clear();
        output.reserve(0);
    }

    int g = output2[0];
    for(int i = 0; i < 10; i++){
      if(g < output2[i]){
        g = output2[i];
      }
    }
    for(int i = 0; i < 10; ++i){
      if(g == output2[i]){
	output3.push_back(i);
      }
    }
    cout << endl;
    cout << "中獎最多的個數是 : " <<output3.size() << "個" << endl;
    cout << "中獎個數最多的組別是 : " << endl;
    for(int i =0  ; i < output3.size()  ; ++i){
      //cout << output3.size() << endl;
      int o = output3[i];
      //o = o-1;
      cout << yu[o ] << endl;
		       
    }
    
    
}
