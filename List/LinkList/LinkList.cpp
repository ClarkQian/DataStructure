#include <iosteram>
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
};


template <class T>
LinkList<T>::LinkList(){
	Head = new Node<T>;
}
template <class T>
LinkList<T>::~LinkList(){
	Node *p = Head;
	while(p) {
		Head = Head -> next;
		delete p;
		p = Head;
	}

	Head = NULL;
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
		return p - >data;
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
		exit(3):
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
void LinkList<T>::Insert(int i,T e) {
	int *p = Head;
	int j = 0;
	while (p && j < i - 1) {
		p = p -> next;
		j++;
	}

	if (!p && j > i - 1) {
		cout<<"Wrong position"<<endl;
		exit(3);
	} else {
		Node<T> *s;
		s -> data = e;
		s -> next = p -> next;
		p -> next = s;
	}
}