#include <iostream>

using namespace std;

class B1 {
public:
	virtual void vf() const { cout << "B1::vf()\n"; }
	void f() const { cout << "B1::f()\n"; }
	virtual void pvf()=0;
	//problem - b1 object abstract can't make one
};

class D1 : public B1 {
public:
	void vf() const { cout << "D1::vf()\n"; } // overrides B1::vf()
	void f() const { cout << "D1::f()\n"; } // doesn't override (B1::f() not virtual)
	void pvf() { cout << "D1::pvf()\n"; }
};

class D2 : public D1 {
public:
	void pvf() { cout << "D2::pvf()\n"; }
};

class B2 {
public:
	virtual void pvf()=0;
};

class D21 : public B2{
public:
	string text = "abcde";
	void pvf() { cout << text << endl; }
};

class D22 : public B2{
public:
	int number = 101;
	void pvf() { cout << number << endl; }
};

void f(B2& b2){ 	//call function
	b2.pvf();
}

int main(){
	/*
	B1 b1;

	b1.vf(); //B1::vf()
	b1.f(); //B1::f()
	*/
	// abstract object - pvf()
	
	D1 d1;

	d1.f(); //D1::f()
	d1.vf(); //D1::vf()
	d1.pvf(); //D1::pvf()
	
	B1& b1ref = d1;

	b1ref.f(); //B1::f(), not virtual - no override
	b1ref.vf(); //D1::vf(), overrides B1::vf() virtual
	b1ref.pvf(); //D1::pvf()
	
	D2 d2;
	
	d2.f(); //D1::f()
	d2.vf(); //D1::vf()
	d2.pvf(); //D2::pvf(), overrides D1::pvf()
	
	D21 d21;
	D22 d22;
	
	f(d21); //prints string text
	f(d22); //prints int number
	
	return 0;
}
