#pragma once
#include "Media.h"

class Song : public Media {
private:
	bool top40;
public:
	Song();

	Song(char type, string title, string keyName, int rating, string genre, int length, int yearReleased, bool top);

	bool gettop40() {
		return top40;
	}
	void settop40(bool top) {
		top40 = top;
	}
	void print(ostream& out); // to print the data
};