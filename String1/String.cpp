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

void String::operator()(const char * str)
{
	for (int i = 0;i < strlen(str);i++)
		this->m_stringRep[i] = str[i];
}

String::~String()
{
	delete[]m_stringRep;
}
