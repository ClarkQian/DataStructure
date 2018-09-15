#include <iostream>
using namespace std;



template <class T>
class SqList {
private:
	T *elem;
	int length;
	int capcity;
public:
	SqList(int capcity);
	void Insert(int i, T e);
	T Delete(int i);
	int Locate(T e);
	void ListDisp();
	~SqList();
};


template <class T>
SqList<T>::SqList(int capcity) {
	this -> capcity = capcity;
	elem = new T[capcity];
	if (!elem){ 
		//throw("Do not get the new memeory!");
		cout<<"Can not ask fro the new memory!"<<endl;
		exit(3);
	}
	length = 0;
};

template <class T>
void SqList<T>::Insert(int i, T e) {
	if (length >= capcity) {
		//throw "out of the capcity";
		cout << "out of the capcity"<<endl;
		exit(3);
	} 
	if (i < 1 || i > length + 1) {
		//thorw "Wrong position";
		cout<<"wrong position!"<<endl;
		exit(3);
	}
		for(int j = length; j > i - 1; j--) {
		//elem[j+1] = elem[j];
		elem[j] = elem[j-1];
	}
	elem[i-1] = e;
	//add length++;
	length++;
	return;
}

template <class T>
T SqList<T>::Delete(int i) {
	//add
	if (length == 0) throw "No element";
	if (i < 1 || i > length) throw "Wrong position";
	T e = elem[i-1];
	//j <= length.
	for(int j = i - 1; j < length; j++) {
		elem[j] = elem[j+1];
	}
	length--;
	return e;
}

// -1 means do not find this element.
template <class T>
int SqList<T>::Locate(T e) {
	for (int i = 0; i < length; i++) {
		if (elem[i] == e)
			//return i
			return i+1;
	}
	return -1;
}
template <class T>
void SqList<T>::ListDisp() {
	for (int i = 0; i < length; i++) 
		cout<<elem[i]<<' ';
	cout<<endl;
	return;
}

template <class T>
SqList<T>::~SqList() {
	delete []elem;
	length = 0;
	capcity = 0;
}


int main(int argc, char const *argv[])
{
	SqList<int> test(100);
	for (int i = 1 ; i < 15; i++) {
		test.Insert(i, i);
	}
	test.ListDisp();
	return 0;
}