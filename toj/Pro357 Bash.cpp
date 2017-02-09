#include <iostream>
#include <map>
using namespace std;
struct dir {
	map<string,dir*> M;
	dir* pre;
} *root;
dir* cur = root;
string ctr, str;
void add() {
//	cout << "\t\tadding...\n";
	cur->M[str] = new dir();
	cur->M[str]->pre = cur;
}
void print() {
//	cout << "\t\tprinting...\n";
	cout << "last ls: " << cur->M.size() << '\n';
	for ( auto i=cur->M.begin(); i!=cur->M.end(); i++ )
		cout << i->first << '\n';
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    root = new dir();
    root->pre = root;
    cur = root;
	while ( cin >> ctr ) {
		cin.get();
		if ( ctr == "ls" )	print();	
		else {
			str.clear();
			char c;
			while ( c = cin.get() ) {
				if ( c == '\n' )	break;
				if ( c != '\\' )	str.push_back(c);
			}
			if ( ctr == "mkdir" || ctr == "touch" )	add();
			else {	// cd
				if ( str[0] == '/' )	cur = root;
				string temp = "";
				for ( int i=0; i<str.size(); i++ ) {
//					cout << "\t\tentering...\n";
					if ( str[i] != '/' && str[i] != '\\' )
						temp.push_back(str[i]);
					if ( str[i] == '/' || i == str.size() ) {
						if ( temp == ".." )	cur = cur->pre;
						else if ( temp != "." )	cur = cur->M[temp];
						temp.clear();
					}
				}
			}
		}
	}
	return 0;
}

