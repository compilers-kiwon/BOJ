#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

static vector<vector<string>>   line;

#define get_spaces(len) (string((len),' '))

int parse(const string& str,vector<string>& words)
{
    string  w;

    for (int i=0;i<str.length();i++) {
        if (str[i] == ' ') {
            if (!w.empty()) {
                words.push_back(w);
                w.clear();
            }
        } else {
            w.push_back(str[i]);
        }
    }

    return  0;
}

int input(void)
{
    for(;;) {
        string  str;
        vector<string>  s;

        getline(cin,str);
        if (str.empty()) break;

        str.push_back(' ');
        parse(str,s);
        line.push_back(s);
    }

    return  0;
}

int add_space(void)
{
    for (int idx=0;;idx++)
    {
        size_t  max_len = 0;

        for (int i=0;i<line.size();i++) {
            vector<string>& cur_line = line[i];

            if (cur_line.size() <= idx) {
                continue;
            }

            max_len = max(max_len,cur_line[idx].length());
        }

        if (max_len == 0) break;

        for (int i=0;i<line.size();i++) {
            vector<string>& cur_line = line[i];

            if (cur_line.size() <= idx) {
                continue;
            }

            cur_line[idx] += get_spaces(max_len+1-cur_line[idx].length());
        }
    }

    return  0;
}

int remove_spaces_at_tail(string& str)
{
    for (;!str.empty()&&str.back()==' ';str.pop_back());
    return  0;
}

int print(void)
{
    for (int i=0;i<line.size();i++) {
        vector<string>& cur_line = line[i];

        for (int j=0;j<cur_line.size();j++) {
            if (j == cur_line.size()-1) {
                remove_spaces_at_tail(cur_line[j]);
            }

            cout<<cur_line[j];
        }

        cout<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    add_space();
    print();

    return  0;
}