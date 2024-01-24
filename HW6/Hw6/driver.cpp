#include <iostream>
#include <string>
#include<iterator>
#include<bits/stdc++.h>
#include "PFArray.hpp"
#include "PFArray.cpp"

using  namespace std;
using namespace onur;

int main()
{
	try
	{
		cout << "--------------Constructor with a determined size ----------------\n";
		cout << "I created a char PFArray with capacity 4\nAnd i filled up the array with addElement function\n";
		PFArray<char> deneme(4);
		deneme.addElement('o');
		deneme.addElement('n');
		deneme.addElement('u');
		deneme.addElement('r');
		deneme.addElement('a');
		cout << "It exceed the capacity so it resized +50\n";
		cout << "It will be printed with print function which is i used begin() and end() functions\n\n";
		deneme.print();

		cout << "\n--------------No parameter Constructor----------------\n";
		cout << "It will arrange the capacity to 50 and used 0\n";
		PFArray<char> empty;
		cout << "Now i will create no parameter constructed object. It should be empty. I will check it with empty function\n";
		cout << "\n--------------Empty Function----------------\n";
		if(empty.empty())
			cout << "It is empty array\n";
		else
			cout << "It is not empty array\n";

		cout << "\n--------------Copy Constructor----------------\n";
		PFArray<char> deneme_temp(deneme);
		cout << "It call copy constructor. Now i will print it\n";
		deneme_temp.print();

		cout << "\n--------------GetCapacity and Size functions----------------\n";
		cout << "Capacity: "<<deneme.getCapacity() << " Used: " << deneme.size() << endl;


		cout << "\n--------------Clear functions----------------\n";
		cout << "Now i will clear copied array and i will use empty function \n";
		deneme_temp.clear();
		if(deneme_temp.empty())
			cout << "It is empty array\n";
		else
			cout << "It is not empty array\n";


		cout <<"\n-----------------Operator[]------------\n";
		cout << "I will print 2. index of object\n";
		deneme.print();
		cout << "2. Index of array: " << deneme[2] << endl;


		cout <<"\n-----------------Operator=------------\n";
		cout << "I will create an array with capacity 10 and i will use 7 of capacity\n";
		PFArray<char> deneme2(10);
		deneme2.addElement('A');
		deneme2.addElement('B');
		deneme2.addElement('C');
		deneme2.addElement('D');
		deneme2.addElement('E');
		deneme2.addElement('F');
		deneme2.addElement('G');
		cout << "Capacity: "<<deneme2.getCapacity() << " Used: " << deneme2.size() << endl;
		deneme2.print();
		cout << "\nNow i will assign new object to old one and i will print old one\n";
		deneme = deneme2;
		deneme.print(); 


		cout << "\nI created an iterator with no parameter\n";
		cout <<"And I will print my array by using operator!= operator++ operator= operator*\n";
		PFArray<char>::Iterator it;
		for(it = deneme.cbegin(); it != deneme.cend(); it++)
			cout << *it << " ";	
		
		cout <<"\n\nAnd I will print last two elements of array by decreasing iterator with operator-- two times\n";
		--it;
		it --;
		for(; it != deneme.end(); it++)
			cout << *it << " ";	
		cout << "\n\n-------------FIND FUNCTION ----------------\n";
		cout << "Now, I will test find function\n\n";
		deneme.print();
		cout << "\nI will try to find 'K' \n";

		it = find(deneme.begin(), deneme.end(), 'K');

		if(it == deneme.end())
			cout << "It could not find\n";
		else
			cout <<"It found '" << *it <<  "' " << endl;

		cout << "I will try to find 'A' \nAnd I will use move constructor\n";


		it = find(deneme.begin(), deneme.end(), 'A');

		if(it == deneme.end())
			cout << "It could not find\n";
		else
			cout <<"It found '" << *it <<  "' " << endl;

		cout << "\n-------------SORT FUNCTION and FOR EACH----------------\n";
		cout <<"I will create an array of integer\n";

		PFArray<int>::Iterator it1, it2;
		PFArray<int> number(4);
		number.addElement(1);
		number.addElement(6);
		number.addElement(8);
		number.addElement(4);
		number.addElement(3);
		number.addElement(12);
		number.print();

		cout <<"I will use move operator=\n";
		it1 = number.begin();
		it2 = number.begin();
		it1++;
		it1++;

		cout << "\n------------Erase function----------\n";
		cout<< "Second index is pointing and it will be erased\n\n";
		number.erase(it1);
		number.print();

		cout << "\nNow, I will sort array of integer\n\n";

		sort(number.begin(), number.end());

		cout << "Now, I will print array of integer with for each\n\n";
		for(auto x: number)
			cout << x << " ";

	}
	catch(const int i)
	{
		cerr << "Index out\n";
	}
	
	
	return 0;
}

