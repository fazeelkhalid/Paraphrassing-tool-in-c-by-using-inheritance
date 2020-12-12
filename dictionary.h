#define dictionary_H
#include<iostream>
#include<fstream>
#include"myString.h"
/*******/
//header Files for rendome function
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
/*******/

class Dictionary {
private:
	mString * word;
	mString ** synonyms;
	int randome[100]; // store rendome number; bcz srand and rand give the same sequence
	//when we call rand, srand multiple time in 1 second 
	int index;
	
	
public:
	Dictionary() {
		word = NULL;
		synonyms = NULL;
		index = 0;
		srand(time(NULL));
		for (int i = 0; i < 100; i++) {
			randome[i] = rand();
		}
	}
	
	int rowsInFile() {
		ifstream fin;
		int rows = 0;
		fin.open("input.txt");
		while (!fin.eof()) {
			char a;
			fin >> a;
			if (fin.peek() == '\n') {
				rows++;
			}
		}
		fin.close();
		return rows;
	}
	
	int column(int row) {
		int rows = 0;
		int synonyms = 0;

		ifstream fin;
		fin.open("input.txt");
		while (!fin.eof()) {
			char a;
			fin >> a;
			if (row == rows && fin.peek() == ' ' || row == rows && fin.peek() == '	') {
				synonyms++;
			}
			else if (fin.peek() == '\n') {
				rows++;
			}
		}
		fin.close();
		return synonyms;

	}
	void readFromFile() {
		string temp;
		ifstream fin;
		int rows = this->rowsInFile();
		word = new mString[rows];

		synonyms = new mString*[rows];
		for (int i = 0; i <= rows; i++) {
			int Column = column(i);
			synonyms[i] = new mString[Column];
		}

		fin.open("input.txt");
		
		for (int i = 0; i <= rows; i++) {
			fin >> word[i];
			for (int j = 0; j < column(i); j++) {
				fin >> synonyms[i][j];
			}
		}
	}
	int searchWord(mString& String) {
		int rows = this->rowsInFile();
		for (int i = 0; i <= rows; i++) {
			if (this->word[i] == String) {
				return i;
			}
		}
		return -1;
	}
	void synonym(int row,mString& str) {
		int noOfSynonym = column(row); 
		index++;
		if (index == 100) { // reset index
			index = 0;
		}
		str = synonyms[row][randome[index] % noOfSynonym];	
	}
	
};