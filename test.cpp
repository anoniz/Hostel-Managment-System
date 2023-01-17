#include<iostream>
using namespace std;

class A {
    void show () {
        cout<<" i am A ";
    }
};
class B {
    public:
    void show () {
        cout<<" i am B ";
    }
    };
class C {void show () {
        cout<<" i am C ";
    }};


class D:public A, public B, private C {
    public:
    void show () {
        cout<<" i am d ";
    }
};

int main () {

D *obj = new D;

(*obj).B::show();

}