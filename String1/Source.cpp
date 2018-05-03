#include "String.h"

int main()
{
	String s("Hello");
	String s1(5, 'a');
	String s2(5);
	cout << s.getStrRep() << endl;
	cout << s1.getStrRep() << endl;
	cout << s2.getStrRep() << endl;
	s2.getAt(0) = 'z';
	s2.AddCharAt(2, 'b');
	cout << s2.getStrRep() << endl;
	s2.DelCharAt(2);
	cout << s2.getStrRep() << endl;
	s.ConcatStr(" World");
	cout << s.getStrRep() << endl;
	s + s1;
	cout << s.getStrRep() << endl;
	s1 + "Hel";
	cout << s1.getStrRep() << endl;

	system("pause");	
	return 0;
}