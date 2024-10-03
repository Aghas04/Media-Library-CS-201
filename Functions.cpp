#include "Functions.h"


//read the file and load into vector
int readMediaList(istream& i, ostream& outErr, vector<Media*>& m) {
	vector<string> allLines;
	vector<string> characterline;
	string line, temp, types;
	//read all lines and load intoa  vector
	while (getline(i, line)) {
		allLines.push_back(line);
	}
	for (int x = 0; x < allLines.size(); x++) {
		//go thrugh all the lines  and load
		try {

			stringstream linestream(allLines[x]);
			characterline.clear();
			while (getline(linestream, temp, ',')) {
				characterline.push_back(temp);
			}
			types = characterline[0];
			if (types == "M") {
				vector<string> movieStars;
				Movie* tempM = new Movie();
				tempM->setType(characterline[0][0]);
				for (int j = 1; j < characterline.size(); j++) {

					if (j == 1) {
						tempM->setTitle(characterline[j]);
					}
					if (j == 2) {
						tempM->setKeyName(characterline[j]);
					}
					if (j == 3) {
						int tempInt = stoi(characterline[j]);
						if (!(tempInt <= 10 && tempInt >= 0)) {

							throw runtime_error("invalid rating value");
						}
						tempM->setRating(tempInt);
					}
					if (j == 4) {
						tempM->setGenre(characterline[j]);
					}
					if (j == 5) {
						tempM->setLength(stoi(characterline[j]));
					}
					if (j == 6) {
						int tempInt = stoi(characterline[j]);
						if (!(tempInt <= 2023 && tempInt >= 1500)) {

							throw runtime_error("invalid year value");
						}
						tempM->setYearReleased(stoi(characterline[j]));
					}
					if (j >= 7) {
						movieStars.push_back(characterline[j]);
					}
				}
				tempM->setStars(movieStars);
				m.push_back(tempM);
			}
			if (types == "B") {
				Book* tempM = new Book();
				tempM->setType('B');
				for (int j = 1; j < characterline.size(); j++) {
					if (j == 1) {
						tempM->setTitle(characterline[j]);
					}
					if (j == 2) {
						tempM->setKeyName(characterline[j]);
					}
					if (j == 3) {
						int tempInt = stoi(characterline[j]);
						if (!(tempInt <= 10 && tempInt >= 0)) {
							throw runtime_error("invalid rating value");
						}
						tempM->setRating(tempInt);
					}
					if (j == 4) {
						tempM->setGenre(characterline[j]);
					}
					if (j == 5) {
						tempM->setLength(stoi(characterline[j]));
					}
					if (j == 6) {
						int tempInt = stoi(characterline[j]);
						if (!(tempInt <= 2023 && tempInt >= 1500)) {
							throw runtime_error("invalid year value");
						}
						tempM->setYearReleased(stoi(characterline[j]));
					}
					if (j == 7) {
						tempM->setweeksNYT(stoi(characterline[j]));
					}
				}
				characterline.clear();
				m.push_back(tempM);
			}
			if (types == "S") {
				Song* tempM = new Song();
				tempM->setType('S');
				for (int j = 1; j < characterline.size(); j++) {

					if (j == 1) {
						tempM->setTitle(characterline[j]);
					}
					if (j == 2) {
						tempM->setKeyName(characterline[j]);
					}
					if (j == 3) {
						int tempInt = stoi(characterline[j]);
						if (!(tempInt <= 10 && tempInt >= 0)) {
							throw runtime_error("invalid rating value");
						}
						tempM->setRating(tempInt);
					}
					if (j == 4) {
						tempM->setGenre(characterline[j]);
					}
					if (j == 5) {
						tempM->setLength(stoi(characterline[j]));
					}
					if (j == 6) {
						int tempInt = stoi(characterline[j]);
						if (!(tempInt <= 2023 && tempInt >= 1500)) {
							throw runtime_error("invalid year value");
						}
						tempM->setYearReleased(stoi(characterline[j]));
					}
					if (j == 7) {
						tempM->settop40(stoi(characterline[j]));
					}

				}
				characterline.clear();
				m.push_back(tempM);
			}


		}
		catch (runtime_error& e) {
			outErr << "ERROR: " << allLines[x] << endl;
			outErr << e.what() << endl;
			continue;
		}
		catch (invalid_argument& e) {
			outErr << "ERROR: " << allLines[x] << endl;
			outErr << e.what() << endl;
			continue;
		}
	}

	return 0;
}
//print all the media or sorted media
void printAllMedia(string data, ostream& out, ostream& outErr, vector <Media*>& m) {
	int ratingsort;
	bool sortedprint = false, error = false;
	if (data.length() > 1 && isdigit(data[data.length() - 1])) {
		//erase the letter and the comma
		data.erase(0, 2);
		ratingsort = stoi(data);
		if (ratingsort > 10 || ratingsort <= 0) {
			outErr << "Unable to process command.The rating of : " << ratingsort << " is invalid" << endl;
			error = true;
		}
		else { sortedprint = true; }
	}//if  they want a sotred list
	if (sortedprint) {
		out << setw(63) << setfill('+') << "" << endl;
		out << "      YOUR MEDIA LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << setw(5) << " " << setw(4) << left << "Type" << setw(5) << " " << setw(20) << left << "Other Info" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i]->getRating() >= ratingsort) {
				out << setw(3) << left << i + 1;
				m[i]->print(out);
			}
		}
	}
	else if (!error) {


		out << setw(63) << setfill('+') << "" << endl;
		out << "      YOUR MEDIA LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << setw(5) << " " << setw(4) << left << "Type" << setw(5) << " " << setw(20) << left << "Other Info" << endl;
		for (int i = 0; i < m.size(); i++) {
			out << setw(3) << left << i + 1;
			m[i]->print(out);

		}
	}
	out << endl << endl;

}
//print all the moveies or sorted movies
void printMovieList(string data, ostream& out, ostream& outErr, vector <Media*>& m) {
	int ratingsort;
	bool sortedprint = false, error = false;
	if (data.length() > 1 && isdigit(data[data.length() - 1])) {
		data.erase(0, 2);
		ratingsort = stoi(data);
		//check if rating is valid
		if (ratingsort > 10 || ratingsort <= 0) {
			outErr << "Unable to process command.The rating of : " << ratingsort << " is invalid" << endl;
			error = true;
		}
		else { sortedprint = true; }
	}
	//check if they want sorted print
	if (sortedprint) {
		out << setw(57) << setfill('+') << "" << endl;
		out << "      YOUR MOVIE LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << setw(5) << " " << setw(4) << left << "Type" << setw(5) << " " << setw(20) << left << "Stars" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i]->getType() == 'M' && m[i]->getRating() >= ratingsort) {
				out << setw(3) << left << i + 1;
				m[i]->print(out);
			}
		}
	}
	else if (!error) {
		out << setw(57) << setfill('+') << "" << endl;
		out << "      YOUR MOVIE LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << setw(5) << " " << setw(4) << left << "Type" << setw(5) << " " << setw(20) << left << "Stars" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i]->getType() == 'M') {
				out << setw(3) << left << i + 1;
				m[i]->print(out);
			}
		}
	}
	out << endl << endl;

}
//print a book list or stored list
void printBookList(string data, ostream& out, ostream& outErr, vector <Media*>& m) {
	int ratingsort;
	bool sortedprint = false, error = false;
	if (data.length() > 1 && isdigit(data[data.length() - 1])) {
		data.erase(0, 2);
		//erase the letter and comma then check the valid thing
		ratingsort = stoi(data);
		if (ratingsort > 10 || ratingsort <= 0) {
			outErr << "Unable to process command.The rating of : " << ratingsort << " is invalid" << endl;
			error = true;
		}
		else { sortedprint = true; }
	}
	if (sortedprint) {
		out << setw(57) << setfill('+') << "" << endl;
		out << "      YOUR BOOK LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << setw(5) << " " << setw(4) << left << "Type" << setw(5) << " " << setw(20) << left << "WeeksNYT" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i]->getType() == 'B' && m[i]->getRating() >= ratingsort) {
				out << setw(3) << left << i + 1;
				m[i]->print(out);
			}
		}
	}
	else if (!error) {
		out << setw(57) << setfill('+') << "" << endl;
		out << "      YOUR BOOK LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << setw(5) << " " << setw(4) << left << "Type" << setw(5) << " " << setw(20) << left << "WeeksNYT" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i]->getType() == 'B') {
				out << setw(3) << left << i + 1;
				m[i]->print(out);
			}
		}
	}
	out << endl << endl;

}
//print the songs list or sorted list
void printSongList(string data, ostream& out, ostream& outErr, vector <Media*>& m) {
	int ratingsort;
	bool sortedprint = false, error = false;
	if (data.length() > 1 && isdigit(data[data.length() - 1])) {
		data.erase(0, 2);
		ratingsort = stoi(data);
		//erase the comma and letter then check if valid
		if (ratingsort > 10 || ratingsort <= 0) {
			outErr << "Unable to process command.The rating of : " << ratingsort << " is invalid" << endl;
			error = true;
		}
		else { sortedprint = true; }
	}
	if (sortedprint) {
		out << setw(57) << setfill('+') << "" << endl;
		out << "      YOUR SONG LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << setw(5) << " " << setw(4) << left << "Type" << setw(5) << " " << setw(20) << left << "Is It Present In Top 40" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i]->getType() == 'S' && m[i]->getRating() >= ratingsort) {
				out << setw(3) << left << i + 1;
				m[i]->print(out);
			}
		}
	}
	else if (!error) {
		out << setw(57) << setfill('+') << "" << endl;
		out << "      YOUR SONG LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << setw(5) << " " << setw(4) << left << "Type" << setw(5) << " " << setw(20) << left << "Is It Present In Top 40" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i]->getType() == 'S') {
				out << setw(3) << left << i + 1;
				m[i]->print(out);
			}
		}
	}
	out << endl << endl;

}
//print the total of all the categories
void printTotals(ostream& out, vector<Media*>& m) {
	int mtotal = 0;
	int btotal = 0;
	int stotal = 0;
	for (int i = 0; i < m.size(); i++) {
		if (m[i]->getType() == 'M') {
			mtotal += 1;
		}
		else if (m[i]->getType() == 'B') {
			btotal += 1;
		}
		else if (m[i]->getType() == 'S') {
			stotal += 1;
		}
	}
	out << "YOUR MEDIA LIBRARY" << endl;
	out << setw(4) << left << "#" << setw(8) << left << "TYPE" << endl;
	out << setw(4) << left << mtotal << setw(8) << left << "Movies" << endl;
	out << setw(4) << left << btotal << setw(8) << left << "Books" << endl;
	out << setw(4) << left << stotal << setw(8) << left << "Songs" << endl;
	out << setw(4) << left << mtotal + btotal + stotal << setw(8) << left << "Items" << endl;
}
//add new media with the correct format
void addNewMedia(string media, ostream& out, ostream& outErr, vector<Media*>& m) {
	string line, temp;
	Media* tempM = nullptr; // create a null media pointer that can be changed to a specific type
	//bool acto = false;
	vector<string> parts, actors;
	media.erase(0, 2);//erase the n
	stringstream linestream(media);
	while (getline(linestream, temp, ',')) {
		parts.push_back(temp);
	}
	if (parts[0] == "B") {
		Book* tempM = new Book(); //if type is B then set pointer to book

		try {
			tempM->setweeksNYT(stoi(parts[7]));
			//iterate thrugh the differnt thigns you need to add while making sure they are correct
			for (int j = 0; j < parts.size(); j++) {

				if (j == 0) {
					if (!(parts[0][0] == 'M' || parts[0][0] == 'S' || parts[0][0] == 'B')) {
						throw runtime_error("error");
					}
					tempM->setType(parts[0][0]);
				}
				if (j == 1) {
					tempM->setTitle(parts[j]);
				}
				if (j == 2) {
					tempM->setKeyName(parts[j]);
				}
				if (j == 3) {
					int tempInt = stoi(parts[j]);
					if (!(tempInt <= 10 && tempInt >= 0)) {
						throw runtime_error("error");
					}
					tempM->setRating(tempInt);
				}
				if (j == 4) {
					tempM->setGenre(parts[j]);
				}
				if (j == 5) {
					tempM->setLength(stoi(parts[j]));
				}
				if (j == 6) {
					int tempInt = stoi(parts[j]);
					if (!(tempInt <= 2023 && tempInt >= 1500)) {
						throw runtime_error("error");
					}
					tempM->setYearReleased(stoi(parts[j]));
				}

			}
			m.push_back(tempM);
			out << tempM->getTitle() << " was added to your list" << endl << endl;
		}
		catch (...) {
			outErr << "unable to Proccess command: Invalid item entered for " << parts[1] << endl;
		}
	}
	else if (parts[0] == "S") {
		Song* tempM = new Song(); // initalize the media to song if the type is S

		try {
			//iterate thrugh the differnt thigns you need to add while making sure they are correct
			if (stoi(parts[7]) == true || stoi(parts[7]) == false) {
				tempM->settop40(stoi(parts[7]));
			}
			else {
				throw runtime_error("not a valid boolien");
			}

			for (int j = 0; j < parts.size(); j++) {

				if (j == 0) {
					if (!(parts[0][0] == 'M' || parts[0][0] == 'S' || parts[0][0] == 'B')) {
						throw runtime_error("error");
					}
					tempM->setType(parts[j][0]);
				}
				if (j == 1) {
					tempM->setTitle(parts[j]);
				}
				if (j == 2) {
					tempM->setKeyName(parts[j]);
				}
				if (j == 3) {
					int tempInt = stoi(parts[j]);
					if (!(tempInt <= 10 && tempInt >= 0)) {
						throw runtime_error("error");
					}
					tempM->setRating(tempInt);
				}
				if (j == 4) {
					tempM->setGenre(parts[j]);
				}
				if (j == 5) {
					tempM->setLength(stoi(parts[j]));
				}
				if (j == 6) {
					int tempInt = stoi(parts[j]);
					if (!(tempInt <= 2023 && tempInt >= 1500)) {
						throw runtime_error("error");
					}
					tempM->setYearReleased(stoi(parts[j]));
				}

			}
			m.push_back(tempM);
			out << tempM->getTitle() << " was added to your list" << endl << endl;
		}
		catch (...) {
			outErr << "unable to Proccess command: Invalid item entered for " << parts[1] << endl;
		}
	}
	else if (parts[0] == "M") {
		Movie* tempM = new Movie(); // initalize the pointer to Movie if the type is M
		for (int i = 7; i < parts.size(); i++) {
			actors.push_back(parts[i]);
		}
		tempM->setStars(actors);
		try {
			//iterate thrugh the differnt thigns you need to add while making sure they are correct
			for (int j = 0; j < parts.size(); j++) {

				if (j == 0) {
					if (!(parts[0][0] == 'M' || parts[0][0] == 'S' || parts[0][0] == 'B')) {
						throw runtime_error("error");
					}
					tempM->setType(parts[j][0]);
				}
				if (j == 1) {
					tempM->setTitle(parts[j]);
				}
				if (j == 2) {
					tempM->setKeyName(parts[j]);
				}
				if (j == 3) {
					int tempInt = stoi(parts[j]);
					if (!(tempInt <= 10 && tempInt >= 0)) {
						throw runtime_error("error");
					}
					tempM->setRating(tempInt);
				}
				if (j == 4) {
					tempM->setGenre(parts[j]);
				}
				if (j == 5) {
					tempM->setLength(stoi(parts[j]));
				}
				if (j == 6) {
					int tempInt = stoi(parts[j]);
					if (!(tempInt <= 2023 && tempInt >= 1500)) {
						throw runtime_error("error");
					}
					tempM->setYearReleased(stoi(parts[j]));
				}

			}
			m.push_back(tempM);
			out << tempM->getTitle() << " was added to your list" << endl << endl;
		}
		catch (...) {
			outErr << "unable to Proccess command: Invalid item entered for " << parts[1] << endl;
		}
	}
	else {
		tempM = new Media(); // create a general type but proly not used
		try {
			//iterate thrugh the differnt thigns you need to add while making sure they are correct
			for (int j = 0; j < parts.size(); j++) {

				if (j == 0) {
					if (!(parts[0][0] == 'M' || parts[0][0] == 'S' || parts[0][0] == 'B')) {
						throw runtime_error("error");
					}
					tempM->setType(temp[0]);
				}
				if (j == 1) {
					tempM->setTitle(temp);
				}
				if (j == 2) {
					tempM->setKeyName(temp);
				}
				if (j == 3) {
					int tempInt = stoi(temp);
					if (!(tempInt <= 10 && tempInt >= 0)) {
						throw runtime_error("error");
					}
					tempM->setRating(tempInt);
				}
				if (j == 4) {
					tempM->setGenre(temp);
				}
				if (j == 5) {
					tempM->setLength(stoi(temp));
				}
				if (j == 6) {
					int tempInt = stoi(temp);
					if (!(tempInt <= 2023 && tempInt >= 1500)) {
						throw runtime_error("error");
					}
					tempM->setYearReleased(stoi(temp));
				}

			}
			m.push_back(tempM);
			out << tempM->getTitle() << " was added to your list" << endl << endl;
		}
		catch (...) {
			outErr << "unable to Proccess command: Invalid item entered for " << parts[1] << endl;
		}
	}

}

//print the movie stars of the title given
void listMovieStars(string title, ostream& out, ostream& outErr, vector<Media*>& m) {
	bool movieFound = false;
	title.erase(0, 2);
	for (int i = 0; i < m.size(); i++) {
		if (m[i]->getTitle() == title) {
			movieFound = true;
		}
	}

	if (!movieFound) {
		outErr << "Unable to process command. The movie: " << title << " is not found in your list" << endl;
	}
	else {
		out << setw(57) << setfill('+') << "" << setfill(' ') << endl;
		out << "THE STARS OF THE MOVIE " << title << " ARE:" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i]->getTitle() == title) {
				m[i]->printStars(out);
			}
		}
	}
}
//print the media that the key name was present in
void listKeyName(string name, ostream& out, ostream& outErr, vector<Media*>& m) {
	bool nameFound = false;
	name.erase(0, 2);
	for (int i = 0; i < m.size(); i++) {
		if (m[i]->getKeyName() == name) {
			nameFound = true;
		}
	}

	if (!nameFound) {
		outErr << "Unable to process command. The key name: " << name << " is not a key name in any media in your list" << endl;
	}
	else {
		out << setw(57) << setfill('+') << "" << setfill(' ') << endl;
		out << name << " appears in the following media item(s):" << endl;
		out << setw(8) << left << "TYPE" << setw(30) << left << "TITLE" << setw(8) << left << "RATING" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i]->getKeyName() == name) {
				out << setw(8) << left << m[i]->getType() << setw(30) << left << m[i]->getTitle() << setw(8) << left << m[i]->getRating() << endl;
			}
		}
	}
}