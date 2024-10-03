#pragma once
#include "Media.h"
//initalizing the book class that is a child class of media
class Book : public Media {
private:
	int weeksNYT; //new weeks in NYT
public:
	Book();

	Book(char type, string title, string keyName, int rating, string genre, int length, int yearReleased, int weeksNYT);
	//getter and setters
	int getweeksNYT() {
		return weeksNYT;
	}
	void setweeksNYT(int weeks) {
		weeksNYT = weeks;
	}
	//the print statment for book
	void print(ostream& out);
};