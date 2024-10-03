#include "Movie.h"





Movie::Movie() : Media() {
	this->type = 'M';
	this->title = "title";
	this->keyName = "keyName";
	this->rating = 0;
	this->genre = "genre";
	this->length = 0;
	this->yearReleased = 0;
}

Movie::Movie(char type, string title, string keyName, int rating, string genre, int length, int yearReleased, vector<string> stars) : Media(type, title, keyName, rating, genre, length, yearReleased) {
	this->type = type;
	this->title = title;
	this->keyName = keyName;
	this->rating = rating;
	this->genre = genre;
	this->length = length;
	this->yearReleased = yearReleased;
	this->stars = stars;
}

void Movie::print(ostream& out) {
	out << setw(40) << left << title << setw(6) << left << yearReleased << setw(8) << right << rating << setw(6) << right << type << setw(8) << " ";
	if (stars.size() == 0) {
		out << endl;
	}
	else {
		for (int i = 0; i < stars.size(); i++) {
			out << setw(20) << left << stars[i];
			
		}
		out << endl;
	}

}

void Movie::printStars(ostream& out) {
	for (int i = 0; i < stars.size(); i++) {
		out << stars[i] << endl;
	}
}