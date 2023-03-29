#include <iostream>
#include <string>
#include <Windows.h>
#include <cassert>
typedef unsigned short ushort;
using namespace std;
#include "Data Types.h"
#include "Out of Class.h"

int main() {


	Vector<char> list;// You must give type for list

	list.print();
	list.push_back('c');
	list.push_back('a');
	list.push_back('v');
	list.push_back('i');
	list.push_back('d');
	list.print();

	cin >> list;
	cout << list;

	list.delete_by_index(-3);
	
	list[-2];

	OutOfRange a("out of index!", __LINE__, __TIME__, __FILE__);
	cout << a.what() << endl;


	//list.push_back(1);
	//list.push_back(2);
	//list.push_back(3);
	//list.push_back(4);
	//list.push_front(0);
	//list.print();
	//list.pop_back();
	//list.pop_front();
	//list.print();
	//list.push_back(4);
	//list.push_front(0);
	//list.delete_by_index(0);
	//list.print();
	//list.push_front(0);
	//list.insert_by_index(1, 5);// This function add new element to index.
	//list.insert(0, 1); // But this function change element that in index.
	//list.print();
	//cout << list.find(1) << endl;
	//cout << list.rfind(1) << endl;
	//cout << list.find(-5) << endl;
	//list.print();
	//cout << list.first() << endl;
	//cout << list.last() << endl;
	//cout << list.len() << endl;
	//list.shuffle();
	//list.print();
	//list.sort();
	//list.print();

}