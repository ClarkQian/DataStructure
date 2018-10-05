#include <iostream>
using namespace std;


template <class T>
class CirQueue {
private:
	T *base;
	int front;
	int rear;
	int queuesize;
public:
	CirQueue(int m);
	~CirQueue();
	void EnQueue();
	T DeQueue();
	T GetHead();
	T GetLast();
	int QueueEmpty();
	int QueueFull();
	void ClearQueue();
	void QueueTranverse();
};


template <class T>
CirQueue<T>::CirQueue(int m){
	base = new T[m];
	if(!base){
		cout<<"applying for memory failing"<<endl;
		exit(1);
	}
	front = rear = 0;
	queuesize = m;
}

template <class T>
CirQueue<T>::~CirQueue(){
	delete []base;
	front = rear = 0;
	queuesize = 0;
}

template <class T>
void CirQueue<T>::EnQueue(T x){
	if((rear+1)%queuesize == front) {
		cout<<"Queue overflow"<<endl;
		exit(3);
	}
	base[rear] = x;
	rear = (rear + 1) % queuesize;
	return;
}

template <class T>
T CirQueue<T>::DeQueue(){
	if(rear == front){
		cout<<"Queue downflow"<<endl;
		exit(3);
	}
	T x;
	x = base[front];
	front = (front + 1) % queuesize;
	return x;

}

template <class T>
T CirQueue<T>::GetHead(){
	T x;
	if(front == rear){
		cout<<"The queue downflow"<<endl;
		exit(3);
	}
	x = base[front];
	return x;
}
