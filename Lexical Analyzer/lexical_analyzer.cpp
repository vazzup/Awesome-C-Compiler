#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

unordered_set <string> _keywords {
	// Set of keywords
	"include",
	"int",
	"main",
	"return",
};

unordered_set <string> _inbuilt_functions {
	// Set of inbuilt functions
	"printf",
	"scanf",
};

unordered_set <string> _special_symbols {
	// Set of special symbols
	"(",
	")",
	"{",
	"}",
	"<",
	">",
	"#",
	";",
	"+",
	"\"",
	","
};

unordered_set <string> _header_files {
	// Set of header files
	"stdio.h"
};

int main () {
	string s;
	while(getline(cin, s)) {	// Take the input one line at a time
		int len = s.size();
		string temp = "";
		int i;
		bool _delimiter = false, _symbol = false, in_quotes = false;
		for(i=0; i<len; i++) {
			if(s[i] == '\"') {
				// If entering or exiting a string literal
				in_quotes = (in_quotes)? false: true;
				if(in_quotes) {
					temp += '\"';
					continue;
				} 
			}
			if(in_quotes) {
				// If currently inside a string literal
				temp += s[i];
				continue;
			}
			// Figure out what to do with current character
			if(s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
				// Whitespace implies the text until now is nothing special and hence is
				// Probably an Identifier
				if(temp == "") continue;
				else {
					cout << temp << " - here identifier\n";
					temp = "";
					continue;
				}
			} else if(s[i] == ',') {
				// Comma only carries the function of delimiter. 
				// If temp is not empty, Identifier is present
				cout << ", - delimiter\n";
				if(temp == "") continue;
				else {
					cout << temp << " - identifier\n";
					temp = "";
					continue;
				}
			} else  temp +=s[i];

			// Check if temp belongs to any special class
			if(_keywords.find(temp) != _keywords.end()) {
				cout << temp << " - keyword\n";
				temp = "";
			} else if(_special_symbols.find(temp) != _special_symbols.end()) {
				cout << temp << " - special symbol\n";
				temp = "";
			} else if(_header_files.find(temp) != _header_files.end()) {
				cout << temp << " - Header File\n";
				temp = "";
			} else if(_inbuilt_functions.find(temp) != _inbuilt_functions.end()) {
				cout << temp << " - inbuilt function\n";
				temp = "";
			} else if(s[i] == '\"' && !in_quotes) {
				cout << temp << " - String literal\n";
				temp = "";
			}
		}
	}
	return 0;
}
