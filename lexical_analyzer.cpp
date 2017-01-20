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
	"include",
	"int",
	"main",
	"return",
};

unordered_set <string> _inbuilt_functions {
	"printf",
	"scanf",
};

unordered_set <string> _special_symbols {
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
	"stdio.h"
};

int main () {
	string s;
	while(getline(cin, s)) {
		int len = s.size();
		string temp = "";
		int i;
		bool _delimiter = false, _symbol = false;
		//cout << (_special_symbols.find("<") == _special_symbols.end()) << "\n";
		for(i=0; i<len; i++) {
			if(s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
				if(temp == "") continue;
				else {
					cout << temp << " identifier\n";
					temp = "";
					continue;
				}
			} else if(_special_symbols.find(s[i]) != special_symbols.end()) {
				_symbol = true;
			} else  temp +=s[i]
			else _delimiter = true;
			if(_keywords.find(temp) != _keywords.end()) {
				cout << temp << " keyword\n";
				temp = "";
			} else if(_special_symbols.find(temp) != _special_symbols.end()) {
				cout << temp << " special symbol\n";
				temp = "";
			} else if(_header_files.find(temp) != _header_files.end()) {
				cout << temp << " Header File\n";
				temp = "";
			} else if(_inbuilt_functions.find(temp) != _inbuilt_functions.end()) {
				cout << temp << " inbuilt function\n";
				temp = "";
			} else if(_delimiter) {
				cout << temp << " identifier\n";
				temp = "";
				cout << ", delimiter\n";
				_delimiter = false;
			}
			//cout << temp << "end\n";
		}
		if(temp == "" || temp == " " || temp == "\n") continue;
		if(_keywords.find(temp) != _keywords.end()) {
			cout << temp << " keyword\n";
			temp = "";
		} else if(_special_symbols.find(temp) != _special_symbols.end()) {
			cout << temp << " special symbol\n";
			temp = "";
		} else if(_header_files.find(temp) != _header_files.end()) {
			cout << temp << " Header File\n";
			temp = "";
		} else if(_inbuilt_functions.find(temp) != _inbuilt_functions.end()) {
			cout << temp << " inbuilt function\n";
			temp = "";
		} else if(_delimiter) {
			cout << temp << " identifier\n";
			temp = "";
			cout << ", delimiter\n";
			_delimiter = false;
		}
	}
	return 0;
}
