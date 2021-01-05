
#include <bits/stdc++.h>
using namespace std;

class Car{
  public:
  int val;
  int get1(){
      cout << 1 << endl;
      return 1;
  }

  int get2();
};




int Car::get2(){
    //body
    cout << 2 << endl;
    return 2;
}

int main(){
Car c;
c.get1();
c.get2();


}

