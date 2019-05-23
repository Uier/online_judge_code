#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#define maxn 105
using namespace std;
struct bash {
	vector<bash*> dir;
	set<string> doc;
	string name;
	bash *fa;
};
bash *init(string s, bash *fa) {
	bash tmp = new bash;
	tmp.name = s;
	tmp.dir.clear();
	tmp.doc.clear();
	tmp.fa = fa;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	bash *root = init("/", nullptr);
	string s;
	while ( getline(cin,s) ) {
		switch(s[0]) {
			case 'c' : // cd
				stringstream ss(s);
				vector<string> tmp;
				string sss;
				ss >> sss; // cut off "cd"
				while ( getline(ss, sss, '/') )	tmp.emplace_back(sss);
				break;
			case 'm' : // mkdir
				break;
			case 't' : // touch
				break;
			default :  // ls
				break;
		} 
	}
	return 0;
}

