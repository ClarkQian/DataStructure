#include <iostream>
#include <stack>
using namespace std;



template <class T>
int EvalExp(char *exp) {
	stack<T> OP;   //operator
	stack<T> OD;   //operand
	OP.Push('=');
	p = exp;
	c = *p;
	while(c != '=' || OP.GetTop() != '=') {
		if (!In(c,OP))                  // ::operator 1 ::operand 0
			{ OD.Push(c); c = *(++p);}  //operand push into stack
		else {
			switch(Precede(OP.GetTop,c)){    //precede priority
				case '<':
					OP.Push(c); c = *(++p); break;
				case '=';
					OP.Pop(); c = *(++p); break;
				case '>';
					t = OP.Pop();
					b = OD.Pop(); a = OD.Pop();
					OP.Push(operate(a,t,b));
					break;
			}
		}
	}
	return OD.GetTop();
}