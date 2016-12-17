#include <unordered_map>
using namespace std;
unordered_map<string,string> M;
void Init() {
	M.clear();
}
void InsertWord(string a,string b) {
	M[a] = b;
}
inline string Ask(string a) {
	return (M.find(a)!=M.end()) ? M[a] : "Not found!";
}
