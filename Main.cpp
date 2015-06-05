#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main(){
	List<int> list1;

	list1.push_front(100);
	list1.push_front(200);
	list1.push_front(300);
	list1.push_back(777);

	cout << list1.back() << endl;

	list1.pop_back();

	cout << list1.back() << endl;
	cout << list1.front() << endl;

	list1.pop_front();

	cout << list1.front() << endl;

	List<int> list2;

	list2.push_back(616);
	list2.push_front(515);
	list2.push_front(313);
	list2.push_back(777);

	for (List<int>::iterator it = list2.begin(); it != list2.end(); it++){
		cout << *it << " ";
	}

	cout << endl;

	List<string> list3;
	list3.push_back("vidi");
	list3.push_back("vici");
	List<string>::iterator iter = list3.begin();
	list3.insert(iter, "Veni");

	for (List<string>::iterator it = list3.begin(); it != list3.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;

	List<string> list4;
	list4.push_back("Divide");
	list4.push_back("et");
	list4.push_back("impera");
	
	for (List<string>::iterator it = list4.begin(); it != list4.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;

	List<string>::iterator mid = ++list4.begin();
	list4.erase(mid);
	
	for (List<string>::iterator it = list4.begin(); it != list4.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
