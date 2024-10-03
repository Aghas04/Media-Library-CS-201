#include "Song.h"




//initalize the song class default values
Song::Song() : Media() {
	this->type = 'S';
	this->title = "title";
	this->keyName = "keyName";
	this->rating = 0;
	this->genre = "genre";
	this->length = 0;
	this->yearReleased = 0;
}
//declare the object with variable passed through
Song::Song(char type, string title, string keyName, int rating, string genre, int length, int yearReleased, bool top) : Media(type, title, keyName, rating, genre, length, yearReleased) {
	this->type = type;
	this->title = title;
	this->keyName = keyName;
	this->rating = rating;
	this->genre = genre;
	this->length = length;
	this->yearReleased = yearReleased;
	this->top40 = top;
}

void Song::print(ostream& out) {
	out << setw(40) << left << title << setw(6) << left << yearReleased << setw(8) << right << rating << setw(6) << right << type << setw(8) << " ";
	if (top40) {
		out << "top 40" << endl;
	}
	else {
		out << "Not in top 40" << endl;
	}

}