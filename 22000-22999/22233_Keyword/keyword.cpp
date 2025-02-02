#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void get_keywords(int num_of_keywords, unordered_set<string>& keywords) {
    for (int i = 0; i < num_of_keywords; i++) {
        string str;
        cin>>str;
        keywords.insert(str);
    }
}

void remove_keywords(unordered_set<string>& keywords) {
    string article, word;

    cin>>article;
    article.push_back(',');

    for (int i = 0; i < article.length(); i++) {
        const char c = article[i];

        if (c == ',') {
            keywords.erase(word);
            word.clear();
        } else {
            word.push_back(c);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    unordered_set<string> keywords;

    cin>>N>>M;
    get_keywords(N, keywords);

    for (int i = 1; i <= M; i++) {
        remove_keywords(keywords);
        cout<<keywords.size()<<'\n';
    }

    return 0;
}