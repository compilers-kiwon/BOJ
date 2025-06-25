#include <iostream>
#include <string>
#include <map>
#include <unordered_set>

const int ALLOWED = 5;

void parse(const std::string& str, std::string& name, int& year) {
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        if (isdigit(c)) {
            year = (year * 10) + (int)(c - '0');
        } else {
            name.push_back(c);
        }
    }

    name.pop_back();
}

void input(std::map<std::string, std::unordered_set<int>>& table) {
    int N;

    std::cin>>N;
    getchar();

    for (int i = 1; i <= N; i++) {
        std::string str, name;
        int year = 0;

        getline(std::cin, str);
        parse(str, name, year);
        table[name].insert(year);
    }
}

void print(int case_num, std::map<std::string, std::unordered_set<int>>& table) {
    std::cout<<"Case #"<<case_num<<":\n";
    std::map<std::string, std::unordered_set<int>>::iterator it;

    for (it=table.begin(); it != table.end(); it++) {
        if (it->second.size() < ALLOWED) {
            std::cout<<it->first<<'\n';
        }
    }
}

int main(void) {
    int T;
    std::cin>>T;

    for (int t = 1; t <= T; t++) {
        std::map<std::string, std::unordered_set<int>> table;

        input(table);
        print(t, table);
    }

    return 0;
}