#define myString_H
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>

using namespace std;
class mString
{

private:
	int length;
	char *String;
	
public:
	mString()
	{
		length = 0;
		String = nullptr;
	}

	mString(char* s, int len) {
		String = s; length = len;
	}
	mString(mString& const obj) {
		this->length = obj.length;
		if (this->String != NULL) {
			String = NULL;
		}
		this->String = new char[this->length + 1];
		this->String[this->length] = '\0';
		for (int i = 0; i < this->length; i++) {
			this->String[i] = obj.String[i];
		}
	}
	void inputFromParameters(string temp) {
		if (String != NULL) {
			delete[]String;
			length = 0;
		}
		for (int i = 0; temp[i] != '\0'; i++) {
			length++;
		}
		String = new char[length + 1];
		for (int i = 0; i < length; i++) {
			String[i] = temp[i];
		}
		String[length] = '\0';
	}

	int stLength()
	{
		if (this->length == 0) {
			int i = 0;
			for (; String[i] != '\0'; i++);
			length = i;
			return i;
		}
		else {
			return this->length;
		}
	}
	void lowerStr() {

		if (String != '\0')
		{
			for (int i = 0; String[i] != '\0'; i++)
			{
				if (String[i] >= 65 && String[i] <= 90)
				{
					String[i] = String[i] + 32;
				}
			}

		}
	}
	void upperStr()
	{
		if (String != '\0')
		{
			for (int i = 0; String[i] != '\0'; i++)
			{
				if (String[i] >= 97 && String[i] <= 122)
				{
					String[i] = String[i] - 32;
				}
			}

		}
		cout << "The given String in uppercase is: " << String << endl;
	}
	void setLength(int length) {
		this->length = length;
	}
	int getLength() {
		return this->length;
	}
	void setString(char*str, int len) {
		this->String = new char[len + 1];
		for (int i = 0; i < str[i - 1] != '\0'; i++) {
			this->String[i] = str[i];
		}
	}
	char* getString() {
		return this->String;
	}
	
	void subString(char* str, int startIndex, int length)
	{
		int i = startIndex;
		int j;
		char* substr;
		for (j = 0; str[i] != '\0' && length > 0; i++, j++)
		{
			substr[j] = str[i];
			length--;
		}
		substr[j] = '\0';
		cout << "\n";
		for (int k = 0; substr[k] != '\0'; k++)
			cout << substr[k];
	}
	bool compare(char *str1, char *str2)
	{
		while (*str1 == *str2)
		{
			if (*str1 == '\0' && *str2 == '\0')
				return true;
			str1++;
			str2++;
		}

		return false;
	}
	char* cancatenate(char* s1, char* s2)
	{
		int i = 0;
		char* outstr = new char[strlen(s1) + strlen(s2) + 1];
		for (i = 0; s1[i] != '\0'; i++)
		{
			outstr[i] = s1[i];
		}
		for (int k = 0; s2[k] != '\0'; k++)
		{
			outstr[i] = s2[k];
		}
		outstr[i] = '\0';
		return outstr;
	}
	char* prepend(char* s1, char* s2)
	{
		int i = 0;
		char* outstr = new char[strlen(s1) + strlen(s2) + 1];
		for (i = 0; s2[2] != '\0'; i++)
		{
			outstr[i] = s2[i];
		}
		for (int k = 0; s1[k] != '\0'; k++)
		{
			outstr[i] = s1[k];
		}
		outstr[i] = '\0';
		return outstr;
	}

	void print() {
		for (int i = 0; String[i] != '\0'; i++)
		{
			cout << String[i];
		}
		cout << '\n';
	}
	mString& operator +(mString &const LHS) {
		mString temp;
		temp.length = this->length + LHS.length;
		temp.String = new char[temp.length + 1];
		int i = 0;
		for (i = 0; i < this->length; i++) {
			temp.String[i] = this->String[i];
		}
		for (int j = 0; j < LHS.length; j++) {
			temp.String[i] = LHS.String[j];
			i++;
		}
		temp.String[i] = '\0';
		return temp;
	}
	void operator = (mString &const LHS) {
		this->length = LHS.length;
		this->String = new char[length + 1];
		for (int i = 0; i < length; i++) {
			this->String[i] = LHS.String[i];
		}
		this->String[this->length] = '\0';
	}
	bool operator == (mString &const LHS) {
		this->lowerStr();
		LHS.lowerStr();
		if (this->length != LHS.length) {
			return 0;
		}
		else {
			for (int i = 0; i < length; i++) {
				if (this->String[i] != LHS.String[i]) {
					return 0;
				}

			}
		}
		return 1;
	}
	bool operator != (mString & LHS) {
		if (*this == LHS) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int size() {
		int Size = 0;
		for (int i = 0; String[i] != '\0'; i++) {
			Size++;
		}
		return Size;
	}
	bool operator<(mString& LHS)
	{
		if (this->length != LHS.length) {
			if (this->length < LHS.length)
			{
				return true;
			}
			else
				return false;
		}
		else {
			for (int i = 0; i < length; i++) {
				if (this->String[i] > LHS.String[i]) {
					return false;
				}
				else if (this->String[i] < LHS.String[i]) {
					return true;
				}
			}
			return false;
		}
	}
	bool operator>(mString& LHS)
	{
		if (this->length != LHS.length) {
			if (this->length > LHS.length)
			{
				return true;
			}
			else
				return false;
		}
		else {
			for (int i = 0; i < length; i++) {
				if (this->String[i] < LHS.String[i]) {
					return false;
				}
				else if (this->String[i] > LHS.String[i]) {
					return true;
				}
			}
			return false;
		}
	}
	char operator [](int s)
	{
		for (int i = 0; i < length; i++)
		{
			if (i == (s - 1))
			{
				return String[i];
			}
		}
	}

	friend ostream& operator << (ostream& oUt, mString& RHS) {
		cout << RHS.String;
		return oUt;
	}
	friend istream& operator >> (istream& oIn, mString& RHS) {
		char *temp = new char[1500];
		cout << "\nEnter String : ";
		cin.getline(temp, 100);
		for (int i = 0; temp[i] != '\0'; i++) {
			RHS.length++;
		}
		if (RHS.String != nullptr) {
			delete[]RHS.String;
		}
		RHS.String = new char[RHS.length + 1];
		for (int i = 0; i < RHS.length; i++) {
			RHS.String[i] = temp[i];
		}
		RHS.String[RHS.length] = '\0';
		return oIn;
	}
	friend ifstream& operator >> (ifstream& fin, mString& RHS) {
		string s;
		fin >> s;
		RHS.length = s.size();
		RHS.String = new char[RHS.length + 1];
		RHS.String[RHS.length] = '\0';
		for (int i = 0; i < RHS.length; i++){
			RHS.String[i] = s[i];
		}
		return fin;
	}
	
};
