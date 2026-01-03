#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef struct __ALBUM Album;

struct __ALBUM {
    string name;
    set<string> photo;
    map<string, Album*> album;
    Album* parent;
};

Album root;

void remove_album(Album* a, int& num_of_removed_album, int& num_of_removed_photo) {
    int cur_num_of_album = a->album.size();
    int cur_num_of_photo = a->photo.size();

    for (auto it = a->album.begin(); it != a->album.end(); it++) {
        remove_album(it->second, num_of_removed_album, num_of_removed_photo);
        delete (it->second);
    }

    num_of_removed_album += cur_num_of_album;
    num_of_removed_photo += cur_num_of_photo;
}

void _remove(const string& s, Album* cur) {
    if (cur->album.empty()) {
        cout << "0 0\n";
        return;
    }

    int num_of_removed_album = 0;
    int num_of_removed_photo = 0;

    if (s == "-1") {
        auto it = cur->album.begin();
        
        remove_album(it->second, num_of_removed_album, num_of_removed_photo);
        num_of_removed_album++;
        
        delete (it->second);
        cur->album.erase(it);  
    } else if (s == "0") {
        for (auto it = cur->album.begin(); it != cur->album.end(); it++) {
            remove_album(it->second, num_of_removed_album, num_of_removed_photo);
            num_of_removed_album++;
            delete (it->second);
        }
 
        cur->album.clear();
    } else if (s == "1") {
        auto it = cur->album.rbegin();
        
        remove_album(it->second, num_of_removed_album, num_of_removed_photo);
        num_of_removed_album++;
        
        delete (it->second);
        cur->album.erase(it->first);
    } else {
        auto it = cur->album.find(s);
        
        if (it != cur->album.end()) {
            remove_album(it->second, num_of_removed_album, num_of_removed_photo);
            num_of_removed_album++;

            delete (it->second);
            cur->album.erase(it);
        }
    }

    cout << num_of_removed_album << ' ' << num_of_removed_photo << '\n';
}

void _delete(const string& s, Album* cur) {
    if (cur->photo.empty()) {
        cout <<"0\n";
        return;
    }

    int n = 0;

    if (s == "-1") {
        cur->photo.erase(cur->photo.begin()), n = 1;
    } else if (s == "0") {
        n = cur->photo.size();
        cur->photo.clear();
    } else if (s == "1") {
        cur->photo.erase(*(cur->photo.rbegin())), n = 1;
    } else {
        auto it = cur->photo.find(s);

        if (it != cur->photo.end()) {
            cur->photo.erase(it), n = 1;
        }
    }

    cout << n << '\n';
}

Album* change_album(const string& s, Album* cur) {
    Album* ret = cur;

    if (s == "..") {
        ret = cur->parent;
    } else if (s == "/") {
        ret = &root;
    } else {
        auto it = cur->album.find(s);

        if (it != cur->album.end()) {
            ret = it->second;
        }
    }

    cout << ret->name << '\n';

    return ret;
}

void insert(const string& s, Album* cur) {
    if (cur->photo.find(s) == cur->photo.end()) {
        cur->photo.insert(s);
    } else {
        cout << "duplicated photo name\n";
    }
}

void make_album(const string& s, Album* cur) {
    if (cur->album.find(s) == cur->album.end()) {
        Album* a = new Album;
        
        a->name = s;
        a->parent = cur;
        cur->album[s] = a;
    } else {
        cout << "duplicated album name\n";
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    Album* cur;

    root.name = "album", root.parent = &root;

    for (cin >> N, cur = &root; N > 0; N--) {
        string c, s;

        cin >> c >> s;

        if (c == "mkalb") {
            make_album(s, cur);
        } else if (c == "rmalb") {
            _remove(s, cur);
        } else if (c == "insert") {
            insert(s, cur);
        } else if (c == "delete") {
            _delete(s, cur);
        } else if (c == "ca") {
            cur = change_album(s, cur);
        }
    }

    return 0;
}