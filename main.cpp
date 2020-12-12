#include<iostream>
#include"Paraphraser.h"
using namespace std;

int main() {
	Paraphraser p;
	p.enterData();
	p.paraphrasing();
	system("CLS"); // clear screen
	cout << "----------------->> PARAPHRASING TOLL <<-----------------\n\n";
	p.originalTex();
	cout << "\n\n";
	p.printnPText();
	cout << "\n\n\n";
	return 0;
}
