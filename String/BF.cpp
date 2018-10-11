#include <iostream>
#include <cstring>
using namespace std;

int IndexBF(char s[], char t[], int pos) {
	if(pos <= 0 || pos > strlen(s)){
		cout<<"Wrong position"<<endl;
		exit(3);
	}
	if(strlen(t) > strlen(s))
		return -1;
	for(int i = pos - 1; i <= strlen(s) - strlen(t); i ++) {
		int temp = i;
		int j = 0;
		while(s[temp] == t[j]){
			temp++;
			j++;
		if(j == strlen(t))
			return temp - j;
		}
	}
	return -1;
}

//better than the first one
int IndexBF2(char s[], char t[], int pos) {
	if(pos <= 0 || pos > strlen(s)){
		cout<<"Wrong position"<<endl;
		exit(3);
	}
	int m = strlen(s);
	int n = strlen(t);
	if(n > m)
		return -1;
	int i = pos - 1;
	int j = 0;
	while(i <= m - n && j < n) {
		if(s[i] == t[j]){
			i++;
			j++;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}
	if(j >= n)
		return i - j;
	else
		return -1;
		
}




int main() {
	cout<<"Today is a good day"<<endl;
	char a[] = "Today";
	char b[] = "da";
	int index = IndexBF2(a, b, 1);
	cout<<index<<endl;
	return 0;
}