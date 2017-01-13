#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

set <string> _keywords {
	"include",
	"break",
	"int",
	"float",
	"void",
	"long",
	"double",
	"short",
	"char",
	"string",
	"main",
	"continue",
	"switch",
	"case",
	"return",
	"bool"
};

set <string> _inbuilt_functions {
	"printf",
	"scanf",
	"strcopy",
	"strlen",
	"abs",
	"ceil",
	"floor"
};

set <string> _special_symbols {
	"(",
	")",
	"{",
	"}",
	"[",
	"]",
	"\\",
	"/",
	"\"",
	"\'",
	"#",
	"%",
	"+",
	"-",
	"*",
	";"
};

bool _inside_function = false, _inside_header = false, _literal = false, _inside_string = false;
int main () {
	string s;
	while(getline(cin, s)) {
		cout << s << "\n";
	}
	return 0;
}
