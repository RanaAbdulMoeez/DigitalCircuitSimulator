#include "String.h"
#include <iostream>
using namespace std;


int String::stoi(const String s)
{
	int multiplier = 1;
	int num = 0;
	for (int i = len - 1; i > -1; i--)
	{
		num += (Cs[i] - '0') * multiplier;
		multiplier *= 10;
	}
	return num;
}

String String::itos(int num)
{
	String str;
	int temp = num;
	while (temp > 0)
	{
		temp /= 10;
		str.len++;
	}

	temp = num;
	str.Cs = new char[str.len + 1];

	for (int i = str.len - 1; i > -1; i--)
	{
		str.Cs[i] = (temp % 10) + '0';
		temp /= 10;
	}

	str.Cs[str.len] = '\0';
	str.cap = str.len + 1;
	return str;
}

int* String::regrowInt(int* arr, int& size)
{
	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	size++;
	return temp;
}

String::String()
{
	len = 0;
	cap = 1;
	Cs = new char[cap] {'\0'};
}

String::String(const char* arr)
{
	int s = 0;
	while (arr[s] != '\0')
	{
		s++;
	}

	Cs = new char[s + 1];
	for (int i = 0; i < s; i++)
	{
		Cs[i] = arr[i];
	}
	Cs[s] = '\0';
	cap = s + 1;
	len = s;
}

String::String(char ch, int s)
{
	Cs = new char[s + 1];
	for (int i = 0; i < s; i++)
	{
		Cs[i] = ch;
	}
	Cs[s] = '\0';
	len = s;
	cap = s + 1;
}

String::String(const String& other)
{
	Cs = new char[other.cap];
	for (int i = 0; i <= other.len; i++)
	{
		Cs[i] = other.Cs[i];
	}
	len = other.len;
	cap = other.cap;
}

String::String(int num)
{
	this->operator=(itos(num));
}

String::~String()
{
	delete[] Cs;
}

void String::insert_at(int i, char ch)
{
	char* temp = new char[len + 2];
	if (!(i > len))
	{
		for (int j = 0; j < i; j++)
		{
			temp[j] = Cs[j];
		}
		temp[i] = ch;
		for (int j = i + 1; j <= len; j++)
		{
			temp[j] = Cs[j - 1];
		}

		delete[] Cs;
		Cs = temp;
		len++;
		cap = len + 1;
		Cs[len] = '\0';
	}
}

void String::insert_at(int i, const String sub)
{
	char* temp = new char[len + sub.len + 1];
	if (!(i > len))
	{
		int j = 0;
		for (j = 0; j < i; j++)
		{
			temp[j] = Cs[j];
		}

		for (int k = 0; k < sub.len; k++)
		{
			temp[j] = sub.Cs[k];
			j++;
		}

		for (int k = i; k < len; k++)
		{
			temp[j] = Cs[k];
			j++;
		}

		temp[j] = '\0';
		delete[] Cs;
		Cs = temp;
		cap += sub.len;
		len += sub.len;
	}
}

void String::print() const
{
	for (int i = 0; i < len; i++)
	{
		cout << Cs[i];
	}
}

void String::trim()
{
	int	sIndex = 0;
	int eIndex = len;
	for (int i = 0; i <= len; i++)
	{
		if ((Cs[i] != '\t') && (Cs[i] != '\n') && (Cs[i] != ' '))
		{
			sIndex = i;
			break;
		}
	}
	for (int i = len - 1; i > -1; i--)
	{
		if ((Cs[i] != '\t') && (Cs[i] != '\n') && (Cs[i] != ' '))
		{
			eIndex = i;
			break;
		}
	}
	if (sIndex > eIndex)
	{
		sIndex = 0;
		eIndex = 0;
	}
	len = eIndex - sIndex + 1;
	cap = len + 1;
	char* temp = new char[cap];
	int j = 0;
	for (int i = sIndex; i <= eIndex; i++)
	{
		temp[j] = Cs[i];
		j++;
	}
	temp[j] = '\0';
	delete[] Cs;
	Cs = temp;
}

bool String::is_equal(const String& M)
{
	if (len != M.len)
		return false;
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (!(Cs[i] == M.Cs[i]))
				return false;
		}
		return true;
	}
}

bool String::is_less(const String& M)
{
	int size = min(len, M.len);
	for (int i = 0; i < size; i++)
	{
		if (Cs[i] < M.Cs[i])
			return true;
		else if (Cs[i] > M.Cs[i])
			return false;
	}

	if (size == len)
		return true;
	else
		return false;
}

bool String::is_greater(const String& M)
{
	int size = min(len, M.len);
	for (int i = 0; i < size; i++)
	{
		if (Cs[i] > M.Cs[i])
			return true;
		else if (Cs[i] < M.Cs[i])
			return false;
	}

	if (size == len)
		return false;
	else
		return true;
}

String* String::split(char delim, int& count)
{
	count = 1;
	int indices[100];
	indices[0] = -1;
	for (int i = 0; i < len; i++)
	{
		if (Cs[i] == delim)
		{
			indices[count] = i;
			count++;
		}
	}
	indices[count] = len;

	String* strings = new String[count];
	int idx1, idx2, k;
	for (int i = 0; i < count; i++)
	{
		idx1 = indices[i];
		idx2 = indices[i + 1];
		strings[i].Cs = new char[idx2 - idx1];
		k = 0;
		for (int j = idx1 + 1; j < idx2; j++)
		{
			strings[i].Cs[k] = Cs[j];
			k++;
		}
		strings[i].Cs[k] = '\0';
		strings[i].len = idx2 - idx1 - 1;
		strings[i].cap = idx2 - idx1;
	}

	return strings;
}

String* String::tokenize(const char* delim, int& count)
{
	count = 1;
	int indices[100];
	int j;
	indices[0] = -1;
	for (int i = 0; i < len; i++)
	{
		j = 0;
		while (delim[j] != '\0')
		{
			if (Cs[i] == delim[j])
			{
				indices[count] = i;
				count++;
				break;
			}
			j++;
		}
	}
	indices[count] = len;

	String* strings = new String[count];
	int idx1, idx2, k;
	for (int i = 0; i < count; i++)
	{
		idx1 = indices[i];
		idx2 = indices[i + 1];
		strings[i].Cs = new char[idx2 - idx1];
		k = 0;
		for (int j = idx1 + 1; j < idx2; j++)
		{
			strings[i].Cs[k] = Cs[j];
			k++;
		}
		strings[i].Cs[k] = '\0';
		strings[i].len = idx2 - idx1 - 1;
		strings[i].cap = idx2 - idx1;
	}

	return strings;
}

String String::concat(const String& s2)
{
	String temp;
	temp.Cs = new char[len + s2.len + 1];
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		temp.Cs[j] = Cs[i];
		j++;
	}
	for (int i = 0; i < s2.len; i++)
	{
		temp.Cs[j] = s2.Cs[i];
		j++;
	}
	temp.Cs[j] = '\0';
	temp.len = j;
	temp.cap = j + 1;
	return temp;
}

String& String::append(const String& s2)
{
	char* temp = new char[len + s2.len + 1];
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		temp[i] = Cs[i];
		j++;
	}
	for (int i = 0; i < s2.len; i++)
	{
		temp[j] = s2.Cs[i];
		j++;
	}
	temp[j] = '\0';
	delete[] this->Cs;
	this->Cs = temp;
	this->len = j;
	this->cap = j + 1;
	return *this;
}

int String::find_first(char ch)
{
	for (int i = 0; i < len; i++)
	{
		if (Cs[i] == ch)
			return i;
	}
	return -1;
}

int String::find_first(const String& str)
{
	bool flag;
	for (int i = 0; i < len; i++)
	{
		flag = false;
		if (Cs[i] == str.Cs[0])
		{
			flag = true;
			for (int j = 0; j < str.len; j++)
			{
				if (Cs[i + j] != str.Cs[j])
				{
					flag = false;
					break;
				}
			}
		}
		if (flag == true)
			return i;
	}
	return -1;
}

int String::find_last(char ch)
{
	int index = -1;
	for (int i = 0; i < len; i++)
	{
		if (Cs[i] == ch)
			index = i;
	}
	return index;
}

int String::find_last(const String& str)
{
	int index = -1;
	bool flag;
	for (int i = 0; i < len; i++)
	{
		flag = false;
		if (Cs[i] == str.Cs[0])
		{
			flag = true;
			for (int j = 0; j < str.len; j++)
			{
				if (Cs[i + j] != str.Cs[j])
				{
					flag = false;
				}
			}
		}
		if (flag == true)
			index = i;
	}
	return index;
}

int* String::find_all(char ch, int& C)
{
	int* indices = nullptr;
	C = 0;
	for (int i = 0; i < len; i++)
	{
		if (Cs[i] == ch)
		{
			indices = regrowInt(indices, C);
			indices[C - 1] = i;
		}
	}
	return indices;
}

int* String::find_all(const String& str, int& C)
{
	int* indices = nullptr;
	C = 0;
	bool flag;
	for (int i = 0; i < len; i++)
	{
		flag = false;
		if (Cs[i] == str.Cs[0])
		{
			flag = true;
			for (int j = 0; j < str.len; j++)
			{
				if (Cs[i + j] != str.Cs[j])
				{
					flag = false;
				}
			}
		}
		if (flag == true)
		{
			indices = regrowInt(indices, C);
			indices[C - 1] = i;
		}
	}
	return indices;
}

void String::remove_at(int i)
{
	if (!(i > len))
	{
		char* temp = new char[len];
		int k = 0;
		for (int j = 0; j < i; j++)
		{
			temp[k] = Cs[j];
			k++;
		}
		for (int j = i + 1; j < len; j++)
		{
			temp[k] = Cs[j];
			k++;
		}
		temp[k] = '\0';
		delete[] Cs;
		Cs = temp;
		len--;
		cap--;
	}

}

void String::remove_first(char ch)
{
	int index = -1;
	for (int i = 0; i < len; i++)
	{
		if (Cs[i] == ch)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		char* temp = new char[len];
		int j = 0;
		for (int i = 0; i < index; i++)
		{
			temp[j] = Cs[i];
			j++;
		}
		for (int i = index + 1; i < len; i++)
		{
			temp[j] = Cs[i];
			j++;
		}
		temp[j] = '\0';
		delete[] Cs;
		Cs = temp;
		len--;
		cap--;
	}
}

void String::remove_last(char ch)
{
	int index = -1;
	for (int i = 0; i < len; i++)
	{
		if (Cs[i] == ch)
		{
			index = i;
		}
	}
	if (index != -1)
	{
		char* temp = new char[len];
		int j = 0;
		for (int i = 0; i < index; i++)
		{
			temp[j] = Cs[i];
			j++;
		}
		for (int i = index + 1; i < len; i++)
		{
			temp[j] = Cs[i];
			j++;
		}
		temp[j] = '\0';
		delete[] Cs;
		Cs = temp;
		len--;
		cap--;
	}
}

void String::remove_all(char ch)
{
	int count = 1;
	int indices[100];
	indices[0] = -1;
	for (int i = 0; i < len; i++)
	{
		if (Cs[i] == ch)
		{
			indices[count] = i;
			count++;
		}
	}
	indices[count] = len;

	int idx1, idx2;
	int k = 0;
	char* temp = new char[len - count + 3];
	for (int i = 0; i < count; i++)
	{
		idx1 = indices[i];
		idx2 = indices[i + 1];
		for (int j = idx1 + 1; j < idx2; j++)
		{
			temp[k] = Cs[j];
			k++;
		}
	}
	temp[k] = '\0';
	delete[] Cs;
	Cs = temp;
	len = k;
	cap = k + 1;


}

void String::clear()
{
	delete[] Cs;
	len = 0;
	cap = 1;
	Cs = new char[cap] {'\0'};
}

void String::toUpper()
{
	for (int i = 0; i < len; i++)
	{
		if (Cs[i] >= 'a' && Cs[i] <= 'z')
			Cs[i] -= 32;
	}
}

void String::toLower()
{
	for (int i = 0; i < len; i++)
	{
		if (Cs[i] >= 'A' && Cs[i] <= 'Z')
			Cs[i] += 32;
	}
}

String String::operator =(const String& str)
{
	if (this != &str) {
		delete[] Cs;
		Cs = new char[str.cap];
		for (int i = 0; i < str.len; i++)
		{
			Cs[i] = str.Cs[i];
		}
		cap = str.cap;
		len = str.len;
		return *this;
	}
}

char& String::operator[](int idx)
{
	if (idx > -1 && idx < cap)
		return Cs[idx];
}

char& String::operator[](int idx) const
{
	if (idx > -1 && idx < cap)
		return Cs[idx];
}

String operator+(String str1, String str2)
{
	String temp;
	temp = str1.concat(str2);
	return temp;
}

bool String::operator==(const String& M) {
	if (len != M.len)
		return false;
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (!(Cs[i] == M.Cs[i]))
				return false;
		}
		return true;
	}
}


