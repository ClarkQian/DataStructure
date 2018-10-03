#include <iostream>
using namespace std;

template <class T>
class SqStack {
private:
	T *base;
	int top;
	int stacksize;
public:
	SqStack(int m){
		base = new T[m];
		top = 0;
		stacksize = m;
	}
	~SqStack(){
		delete []base;
		top = stacksize = 0;
	}
	void Push(T x);
	T Pop();
	T GetTop();
	int StackEmpty();
	void ClearStack();
	T StackTop();
	void StackTranverse();
};

template <class T>
T SqStack<T>::Pop() {
	if(top == 0){
		cout<<"The stack underflow"<<endl;
		exit(3);
	}
	T x = base[--top];
	//base[top--];
	return x;
}
template <class T>
void SqStack<T>::Push(T x) {
	if(top == stacksize){
		//top > stacksize
		cout<<"The stack overflow"<<endl;
		exit(3);
	}
	base[top++] = x;
	return;
}

template <class T>
T SqStack<T>::GetTop() {
	if(top == 0){
		cout<<"The stack underflow"<<endl;
		exit(3);
	}
	return base[top - 1];
}

template <class T>
int SqStack<T>::StackEmpty(){
	if(top == 0) 
		return 1;
	else 
		return 0;
}

template <class T>
T SqStack<T>::StackTop() {
	if(top == 0) {
		cout<<"The stack underflow"<<endl;
		exit(3);
	}
	T x = base[top--];
	return x;
}

template <class T>
void SqStack<T>::StackTranverse() {
	for(int i = 0; i < top/2; i++){
		T temp;
		temp = *(base+i);

		*(base + i) = *(base+(top - 1 - i)) ;
		*(base + top - 1 - i) = temp;
	}
	return;
}


int main() {
	SqStack<int> test(5);
	test.Push(1);
	test.Push(2);
	test.Push(3);
	test.Push(4);
	test.Push(5);
	cout<<test.GetTop()<<endl;
	cout<<test.Pop()<<endl;
	cout<<test.StackEmpty()<<endl;
	test.StackTranverse();
	cout<<test.Pop()<<endl;
	cout<<test.Pop()<<endl;
	cout<<test.Pop()<<endl;
	cout<<test.Pop()<<endl;
	cout<<test.Pop()<<endl;
	return 0;
}

/*void Push(T x);
	T Pop();
	T GetTop();
	int StackEmpty();
	void ClearStack();
	T StackTop();
	void StackTranverse();
	*/