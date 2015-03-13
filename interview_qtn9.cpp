/*
search for a string in a sorted array of strings containing blank strings
e.g srts[] ={'abc',"","",'qwe',""}
*/
#include <iostream>
#include <string>
#include <string.h>

using namespace std;
string str1[]={"abc","","","","bcde","efg","fghi","","","hijkl","","","jklm","","","","","lmn","mno","nop","","","rtsy"};
string pat("hijkl");

bool search(){
	int low = 0, high =16,mid=0; 
	while(low <= high){
		mid = (low + high) /2;
		while(str1[mid].compareTo("") == 0 && mid<=high)
			mid++;
		if(str1[mid].compareTo(pat) == 0 == 0)
			return true;
		if(str1[mid].compareTo(pat) < 0){
			low = mid+1;
			while(str1[low].compareTo("") == 0 && low<=high)
				low++;
		}
		else if(str1[mid].compare(pat) > 0){
			high = mid-1;
			while(high>=0 && str1[high].compare("") == 0)
				high--;
		}
	}
	return false;
}
int main(){
cout<<search()<<endl;
//cout<<str1[0];//<<str1[1];
return 0;
}