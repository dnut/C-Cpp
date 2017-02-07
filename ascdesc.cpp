#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::istream; 
using std::vector; using std::string;
using std::sort;

typedef vector<string>::const_iterator vs_iter;

std::unordered_set<char> scenders = {
	'b', 'd', 'f', 'h', 'k', 'l', 't', 'g', 'j', 'p', 'q', 'y'
};

string invert(string const& s) {
	string ret;
	for (string::const_iterator i = --s.end(); i >= s.begin(); --i) {
		ret += *i;
	}
	return ret;
}

bool test(string const& s) {
	for (string::const_iterator i = s.begin(); i != s.end(); ++i) {
		if (scenders.find(*i) != scenders.end())
			return 0;
	}
	return 1;
}

vector<string> find(istream& is) {
	vector<string> clean_words;
	string word;
	while (is >> word) {
		if (test(word)) {
			clean_words.push_back(word);
		}
	}
	return clean_words;
}

void print_all(const vector<string>& words) {
	for (vs_iter i = words.begin(); i != words.end(); ++i) {
		cout << *i << " ";
	}
}

bool compare(const string& x, const string& y) {
	return x.size() > y.size();
}

vector<string> biggest(const vector<string>& sorted) {
	vector<string> maxes;
	string::size_type top = sorted[0].size();
	for (vs_iter i = sorted.begin(); i->size() >= top && i != sorted.end(); ++i) {
		maxes.push_back(*i);
	}
	return maxes;
}

int main() {
	vector<string> clean_words = find(cin);
	sort(clean_words.begin(), clean_words.end(), compare);
	print_all(biggest(clean_words));
}
