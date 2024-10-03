#include "Book.h"




//setting default vaalues
Book::Book() : Media() {
	this->type = 'B';
	this->title = "title";
	this->keyName = "keyName";
	this->rating = 0;
	this->genre = "genre";
	this->length = 0;
	this->yearReleased = 0;
	this->weeksNYT = 0;
}
//setting the values if they are passed
Book::Book(char type, string title, string keyName, int rating, string genre, int length, int yearReleased, int weeks) : Media(type, title, keyName, rating, genre, length, yearReleased) {
	this->type = type;
	this->title = title;
	this->keyName = keyName;
	this->rating = rating;
	this->genre = genre;
	this->length = length;
	this->yearReleased = yearReleased;
	this->weeksNYT = weeks;
}
//making the print statment for the object
void Book::print(ostream& out) {
	out << setw(40) << left << title << setw(6) << left << yearReleased << setw(8) << right << rating << setw(6) << right << type << setw(8) << " ";

	out << setw(20) << left << weeksNYT;

		
	out << endl;

}