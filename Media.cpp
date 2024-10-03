#include "Media.h"
#include "Movie.h"
#include "Book.h"
#include "Song.h"
//set default values
Media::Media() : type('\0'), rating(0), length(0), yearReleased(0) {}
//set values
Media::Media(char type, string title, string keyName, int rating, string genre, int length, int yearReleased) : type(type), title(title), keyName(keyName), rating(rating), genre(genre), length(length), yearReleased(yearReleased) {

}

void Media::print(ostream& out) {
	out << setw(40) << left << title << setw(6) << left << yearReleased << setw(8) << right << rating << setw(6) << right << type << endl;
}


