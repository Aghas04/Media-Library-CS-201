#pragma once
#include "Media.h"
//inatilize the movie class which is a child class of media
class Movie : public Media {
private:
	vector<string> stars;
public:
	Movie();

	Movie(char type, string title, string keyName, int rating, string genre, int length, int yearReleased, vector<string> st);

	vector<string> getStars() {
		return stars;
	}
	void setStars(vector<string> st) {
		stars = st;
	}
	void print(ostream& out); // the normal print
	
	void printStars(ostream& out); // this is for the printing of stars in a movie
};