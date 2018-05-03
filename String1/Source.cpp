#include "String.h"

int main()
{
	String s("Hello");
	String s5("test");
	s.AddStrAt(s5, 1);
	cout << s.getStrRep() << endl;
	s.AddStrAt(" ", 1);
	cout << s.getStrRep() << endl;
	cout << String::Format("Is %d", 10).getStrRep() << endl;
	/*String s1(5, 'a');
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
	s1.AddStrAt(s2, 2);
	cout << s1.getStrRep() << endl;*/
	system("pause");	
	return 0;
}