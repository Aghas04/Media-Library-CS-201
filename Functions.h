#pragma once
#include "Media.h"
#include "Movie.h"
#include "Book.h"
#include "Song.h"
//define all the functions
int readMediaList(istream& i, ostream& outErr, vector<Media*>& m);

void printAllMedia(string data, ostream& out, ostream& outErr, vector <Media*>& m);

void printMovieList(string data, ostream& out, ostream& outErr, vector <Media*>& m);

void printBookList(string data, ostream& out, ostream& outErr, vector <Media*>& m);

void printSongList(string data, ostream& out, ostream& outErr, vector <Media*>& m);

void printTotals(ostream& out, vector<Media*>& m);

void addNewMedia(string media, ostream& out, ostream& outErr, vector<Media*>& m);

void listMovieStars(string media, ostream& out, ostream& outErr, vector<Media*>& m);

void listKeyName(string media, ostream& out, ostream& outErr, vector<Media*>& m);