#include "String.h"

String::String(const char*str)
{
	length = strlen(str);
	this->m_stringRep = new char[length +1];
	for (int i = 0;i <= length;i++)
		this->m_stringRep[i] = str[i];	
}

String::String(size_t len, char s)
{
	length = len;
	this->m_stringRep = new char[length +1];
	for (int i = 0;i < length;i++)
		m_stringRep[i] = s;
	m_stringRep[length] = '\0';
}

String::String(size_t len)
{
	length = len;
	this->m_stringRep = new char[length];
	for (int i = 0;i < length;i++)
		m_stringRep[i] = 'o';
	m_stringRep[length] = '\0';
}

const char * String::getStrRep()
{
	return m_stringRep;
}

char & String::getAt(size_t pos)
{
	return m_stringRep[pos];
}

String & String::AddCharAt(size_t pos, char c)
{
	char *tmp;
	this->length += 2;
	tmp = new char[ length];
		
	for (int i = 0;i < pos;i++)
	{
		tmp[i] = m_stringRep[i];
	}
	tmp[pos] = c;
	for(int i=pos+1; i<length;i++)
		tmp[i] = m_stringRep[i-1];
	this->m_stringRep = tmp;
	return *this;
}

String & String::DelCharAt(size_t pos)
{
	for (int i = pos;i < length-1;i++)
	{
		m_stringRep[i] = m_stringRep[i+1];
	}
	this->length--;
	m_stringRep[length] = '\0';
	return *this;
}

String & String::operator=(const String & str)
{
	char*tmp;
	this->length = str.length;
	tmp = new char[this->length+1];

	for (int i = 0;i < length;i++)
		tmp[i] = str.m_stringRep[i];
	tmp[length] = '\0';
	delete[] this->m_stringRep;
	m_stringRep = tmp;
	return*this;
}

String & String::ConcatStr(const String & str)
{
	char*tmp;
	int tmp_length;
	tmp_length = length + str.length;
	tmp = new char[tmp_length+1];

	for (int i = 0;i < length;i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = 0;i < str.length;i++)
		tmp[length + i] = str.m_stringRep[i];
	tmp[tmp_length] = '\0';
	delete[] this->m_stringRep;
	m_stringRep = tmp;
	length = tmp_length;
	return*this;	
}

String & String::ConcatStr(const char * str)
{
	char*tmp;
	int tmp_length;
	tmp_length = length + strlen(str);
	tmp = new char[tmp_length + 1];

	for (int i = 0;i < length;i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = 0;i < strlen(str);i++)
		tmp[length + i] = str[i];
	tmp[tmp_length] = '\0';
	delete[] this->m_stringRep;
	m_stringRep = tmp;
	length = tmp_length;
	return*this;
}

String & String::operator+(const String & str)
{
	char*tmp;
	int tmp_length;
	tmp_length = length + str.length;
	tmp = new char[tmp_length + 1];

	for (int i = 0;i < length;i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = 0;i < str.length;i++)
		tmp[length + i] = str.m_stringRep[i];
	tmp[tmp_length] = '\0';
	delete[] this->m_stringRep;
	m_stringRep = tmp;
	length = tmp_length;
	return*this;
}

String & String::operator+(const char * str)
{
	ConcatStr(str);
	return*this;
}

String & String::AddStrAt(const String & str, size_t pos)
{
	int tmp_length= length + str.length;
	char*tmp=new char[tmp_length + 1];
	tmp[tmp_length] = '\0';

		for (int i = 0;i < pos;i++)
			tmp[i] = this->m_stringRep[i];
		for (int i = 0;i < str.length;i++)
			tmp[pos + i] = str.m_stringRep[i];
		for (int i = pos;i < this->length;i++)
			tmp[i + str.length] = this->m_stringRep[i];
		this->length = tmp_length;
		delete[] this->m_stringRep;
		this->m_stringRep = tmp;
	return*this;
}

String & String::AddStrAt(const char * str, size_t pos)
{
	int tmp_length = length + strlen(str);
	char*tmp = new char[tmp_length + 1];
	tmp[tmp_length] = '\0';

	for (int i = 0;i < pos;i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = 0;i < strlen(str);i++)
		tmp[pos + i] = str[i];
	for (int i = pos;i < this->length;i++)
		tmp[i + strlen(str)] = this->m_stringRep[i];
	this->length = tmp_length;
	delete[] this->m_stringRep;
	this->m_stringRep = tmp;
	return*this;
}

String String::Format(const char * specs, ...)
{
	String s(300);
	char *b;
	/*b[0] = '\0';*/
	char buf[100];
	buf[0] = '\0';
	va_list arguments;
	va_start(arguments, specs);

	int ival;
	double dval;

	for (const char *p = specs; *p ;p++) 					//
	{
		*b = *p;
		b++;
		if (*p == '%') 									//Если встретится символ %
		{			
			switch (*++p) 								//То анализируем следующий за этим симолом символ
			{
			case 'd':  ival = va_arg(arguments, int); 			//Если это символ d, то значит параметр int
			{
				/*cout << ival << " ";*/
				_itoa_s(ival, buf, 10);
				int a = strlen(buf);
				buf[a] = '\0';
				strcat(b, buf);
			}break; 					//Выводим параметр типа int на экран
			case 'f':  dval = va_arg(arguments, double); 		//Если это символ f значит параметр double
			{
				/*_itoa_s(dval, buf, 10);
				s.ConcatStr(buf);*/
				sprintf_s(buf, "%f", dval);
				_itoa_s(ival, buf, 10);
				int a = strlen(buf);
				buf[a] = '\0';
				strcat(b, buf);
			}break; 					//Выводим параметр типа double на экран
			}
		}
		else cout << *b << " ";
	}
	va_end(arguments);

	/*char buf[100];
	char tmp;
	int i = 0;
	while (specs[i]!= '%')
	{
		buf[i] = specs[i];
	}
	if(specs[i]=='d')
*/
	return s;
}

void String::operator()(const char * str)
{
	for (int i = 0;i < strlen(str);i++)
		this->m_stringRep[i] = str[i];
}

String::~String()
{
	delete[]m_stringRep;
}
