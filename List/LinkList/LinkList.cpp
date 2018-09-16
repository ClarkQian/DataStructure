#include <iostream>
using namespace std;


template <class T>
struct Node
{
	T data;
	Node *next;
};

template <class T>
class LinkList {
private:
	Node<T> * Head;
public:
	LinkList();
	~LinkList();
	T GetElem(int i);
	T Delete(int i);
	void Insert(int i, T e);
	void CreateList(int n);
	void ListDisp();
	void Inverse();
};


template <class T>
LinkList<T>::LinkList(){
	Head = new Node<T>;
}
template <class T>
LinkList<T>::~LinkList(){
	/*
	Node<T> *p = Head;
	while(p) {
		Head = Head -> next;
		delete p;
		p = Head;
	}
	Head = NULL;    
	*/
	while(Head) {
		Node<T> *p = Head;
		Head = Head -> next;
		delete p;
	}
	Head = NULL;
	return;
}

template <class T>
T LinkList<T>::GetElem(int i) {
	Node<T> *p = Head -> next;
	int j = 1;
	while(p != NULL && j < i) {
		p = p -> next;
		j++;
	}

	if(p == NULL || j > i){
		cout<<"Wrong position"<<endl;
		exit(3);
	}
	else {
		return p -> data;
	}
}

template <class T>
T LinkList<T>::Delete(int i) {
	T x;
	Node<T>*p, *q;
	p = Head;
	int j = 0;
	while (p -> next && j < i - 1) {
		p = p -> next;
		j++;
	}
	if (!p -> next || j > i - 1) {
		cout <<"Wrong position"<<endl;
		exit(3);
	}
	else {
		q = p -> next;
		//wrong: p = q -> next;
		p -> next = q -> next;
		//wrong: x = p -> data;
		x = q -> data;
		//wrong: delet p;
		delete q;
		return x;
	}
}



template <class T>
void LinkList<T>::CreateList(int n) {
	for(int i = 0; i < 10; i++) {
		Node<T>* s = new Node<T>;
		cin>>s -> data;
		s -> next = Head -> next;
		Head -> next = s;
	}
	return;
}

template <class T>
void LinkList<T>::Insert(int i, T e) {
	Node<T>* p = Head;
	int j = 0;
	while(p && j < i - 1) {
		p = p -> next;
		j++;
	}

	if (!p || j > i - 1) {
		cout<<"Wrong position"<<endl;
		exit(3);
	} else {
		Node<T> *s = new Node<T>;
		s -> data = e;
		s -> next = p -> next;
		p -> next = s;
	}
	return;
}


template <class T>
void LinkList<T>::CreateList(int n) {
	Node<T> *p = Head;	
	for (int i = 0; i < 10; i++) {
		Node<T> *s = new Node<T>;
		cin>>s -> data;
		s -> next = p -> next;
		p -> next = s;
		p = p -> next;
	}
	return;
}

template <class T>
void LinkList<T>::ListDisp() {
	Node<T> *p = Head->next;
	while(p) {
		cout<<p -> data<<' ';
		p = p -> next;
	}
	cout<<endl;
	return;
}

template <class T>
void LinkList<T>:: Inverse() {
	Node<T> *p = Head -> next;
	Node<T> *s = p -> next;
	Node<T> *t = s -> next;
	p -> next = NULL;
	s -> next = p;
	while (t -> next) {
	p = s;
	s = t;
	t = t -> next;
	s -> next = p;
	}
	s -> next = p;
	t -> next = s;
	Head -> next = t;
	return;
}


int main() {
	LinkList<int> a;
	a.CreateList(10);
	a.ListDisp();
	cout<<endl;
	return 0;

}
