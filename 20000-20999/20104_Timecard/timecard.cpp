#include "timecard.h"

using namespace std;

static int N;

void init(int n) {
	N = n;
}

string convert(string s) {
	for (int i=0;i<s.length();i++) {
        if (isupper(s[i])) {
            s[i] = tolower(s[i]);
        }
    }
    
	return s;
}