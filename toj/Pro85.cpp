#include <string>
using namespace std;
struct Trie {
	bool end;
	string exp;
	Trie* next[26];
	Trie() {
		exp = "";
		end = false;
		fill(next,next+26,nullptr);
	}
	~Trie() {
		for ( int i=0; i<26; i++ )
			if ( next[i] != nullptr )
				delete next[i];
	}
} *root;

void Init() {
	delete root;
	root = new Trie;
}

void InsertWord(string word, string explanation) {
	Trie* cur = root;
	for ( int i=0; i<word.size(); i++ ) {
		if ( cur->next[word[i]-'A'] == nullptr )
			cur->next[word[i]-'A'] = new Trie;
		cur = cur->next[word[i]-'A'];
	}
	cur->end = true;
	cur->exp = explanation;
}

string Ask(string query) {
	Trie* cur = root;
	for ( int i=0; i<query.size(); i++ ) {
		if ( cur->next[query[i]-'A'] == nullptr )
			return "Not found!";
		cur = cur->next[query[i]-'A'];
	}
	if ( cur->exp == "" || !cur->end )
		return "Not found!";
	return cur->exp;
}

