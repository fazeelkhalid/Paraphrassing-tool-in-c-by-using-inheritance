#define Paraphraser_H
#include"dictionary.h"
#include<string.h>
class Paraphraser {
private:
	mString input;
	mString *synoText;
	Dictionary dic;
	int word;
public:
	Paraphraser() {
		word = 0;
		synoText = NULL;
	}
	void enterData() {
		cout << "----------------->> PARAPHRASING TOLL <<-----------------";
		cin >> input;
	}
	void tokanization() {
		char *temp = input.getString();
		
		for (int i = 0; temp[i] != '\0'; i++) {
			if (temp[i] == ' ') {
				word++;
			}
		}
		this->synoText= new mString[word + 1];
		int index = 0;
		string stringtemp;
		for (int i = 0; temp[i-1] != '\0'; i++) {
			
			if (temp[i] == ' ') {
				synoText[index].inputFromParameters(stringtemp);
				stringtemp.clear();
				index++;
			}
			else if (temp[i] == '\0') {
				synoText[index].inputFromParameters(stringtemp);
				stringtemp.clear();
				index++;
			}
			else {
				stringtemp = stringtemp + temp[i];
			}
		}
	}

	void paraphrasing() {
		tokanization();
		this->printnPText();
		dic.readFromFile();
		for (int i = 0; i <= word; i++) {
			int index = dic.searchWord(this->synoText[i]);
			if (index != -1) {
				dic.synonym(index, this->synoText[i]);
			}
		}
	}
	void printnPText() { // print Paraphrasing Text
		char *temp = input.getString();
		int word = 1;
		for (int i = 0; temp[i] != '\0'; i++) {
			if (temp[i] == ' ') {
				word++;
			}
		}
		cout << "\nParaphrasing text : ";
		for (int i = 0; i < word; i++) {
			cout << synoText[i] << " ";
		}
	}
	void originalTex() {
		cout << "original Text : ";
		cout << this->input;
	}
};