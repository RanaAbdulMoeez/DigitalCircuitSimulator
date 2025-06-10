#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class String {
	int len;
	int cap;
	char* Cs;

private:
	int stoi(const String s);
	String itos(int num);
	int* regrowInt(int* arr, int& size);
public:
	String();
	String(const char* arr);
	String(char ch, int s);
	String(const String& other);
	String(int num);
	~String();
	void insert_at(int i, char ch);
	void insert_at(int i, const String sub);
	void print() const;
	void trim();
	bool is_equal(const String& M);
	bool is_less(const String& M);
	bool is_greater(const String& M);
	String* split(char delim, int& count);
	String* tokenize(const char* delim, int& count);
	String concat(const String& s2);
	String& append(const String& s2);
	int find_first(char ch);
	int find_first(const String& str);
	int find_last(char ch);
	int find_last(const String& str);
	int* find_all(char ch, int& C);
	int* find_all(const String& str, int& C);
	void remove_at(int i);
	void remove_first(char ch);
	void remove_last(char ch);
	void remove_all(char ch);
	void clear();
	void toUpper();
	void toLower();
	String operator =(const String& str);
	char& operator[](int idx);
	char& operator[](int idx) const;
	bool operator==(const String& M);
};

String operator+(String str1, String str2);
#endif