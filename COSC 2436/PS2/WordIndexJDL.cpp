// Josiah Larimer
// COSC 2436
// programming set 2
// 
// this is like what I did for the quiz 2 EC, but a lot lot better
// copied the string tokenizing function from the textbook, chapter 10.7

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<iomanip>


using namespace std;


void split(const string & s, char delim, vector<string>&tokens)
{
	size_t tokenStart = 0; // Starting position of the next token
		
		// Find the first occurrence of the delimiter.
		size_t delimPosition = s.find(delim);
	
		// While we haven't run out of delimiters...
		while (delimPosition != string::npos)
		{
			// Extract the token.
			string tok = s.substr(tokenStart, delimPosition - tokenStart);
		
			// Push the token onto the tokens vector.
			tokens.push_back(tok);
		
			// Move delimPosition to the next character position.
			delimPosition++;
		
			// Move tokenStart to delimPosition.
			tokenStart = delimPosition;
		
			// Find the next occurrence of the delimiter.
			delimPosition = s.find(delim, delimPosition);
		
			// If no more delimiters, extract the last token.
			if (delimPosition == string::npos)
			{
				// Extract the token.
				string tok = s.substr(tokenStart, delimPosition - tokenStart);
			
				// Push the token onto the vector.
				tokens.push_back(tok);
			}
		}
}



int main() {


	// getting the filename from the user
	string filename;
	cout << endl << "Enter file name: ";
	cin >> filename;
	//filename = "Kennedy.txt";
	//filename = "punctuationTest.txt";

	// opening file
	fstream fin(filename, fstream::in);

	// dumping the file's data into a map
	// one map has the area codes as the key, and the other map has the state/province names as the key
	string hold;
	multimap<string, string> index;
	int lineCount = 1;
	while (getline(fin, hold))
	{
		string countString = to_string(lineCount);

		// splitting the line into words and emplacing them into the map
		vector<string> tokens;
		split(hold, ' ', tokens);
		for (int i = 0; i < size(tokens); i++)
		{
				index.emplace(tokens[i], countString);			
		}
		lineCount++;
	}	

	
	// keeps track of the current key
	string current_key = "";


	// iterates over the multimap and print each key-value pair
	for (auto it = index.begin(); it != index.end(); ++it) {
		// If this is the first key or the key has changed, print the key name
		if (current_key != it->first) {
			current_key = it->first;
			cout << endl << current_key << " : ";
		}
			
		// Print the value for the current key
		cout << it->second << " ";
	}


	// closing the file
	fin.close();

}