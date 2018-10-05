#include <iostream>
using namespace std;



template <class T>
struct Node
{
	T data;
	Node<T> *next;
};

template <class T>
class LinkQueue{
private:
	Node<T> *front;
	Node<T> *rear;
public:
	LinkQueue();
	~LinkQueue();
	void EnQueue(T x);
	T DeQueue();
	T GetHead();
	T GetLast();
	int QueueEmpty();
	void ClearQueue();
	void QueueDisplay();
};


template <class T>
LinkQueue<T>::LinkQueue(){
	front = new Node<T>;
	rear = front;
	front -> next = NULL;
}

template <class T>
LinkQueue<T>::~LinkQueue(){
	Node<T> *p;
	while(front){
		p = front;
		front = front -> next;
		delete p;
	}
}


template <class T>//insert to the tail.
void LinkQueue<T>::EnQueue(T x){
	Node<T> *s = new Node<T>;
	s -> data = x;
	s -> next = rear -> next;
	rear->next = s;
	rear = s;//This step is easy to be forgetten
	return;
}

template <class T>
T LinkQueue<T>::DeQueue(){
	T x;
	Node<T> *p;
	if(rear == front){
		cout<<"The queue underflow!"<<endl;
		exit(3);
	}
	p = front -> next;
	x = p -> data;
	front -> next = p -> next;
	delete p;
	return x;
}




int main() {
	LinkQueue<int> test;
	test.EnQueue(1);
	test.EnQueue(2);
	test.EnQueue(3);
	test.EnQueue(4);
	cout<<test.DeQueue()<<endl;
	cout<<test.DeQueue()<<endl;
	return 0;
}