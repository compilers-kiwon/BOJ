#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    (7)

const string notes_str = "ABCDEFG";

#define get_note_idx(n)     ((int)(notes_str).find((n)))

#define get_diff(cur,next) \
    ((get_note_idx((next))+MAX_SIZE-get_note_idx((cur)))%MAX_SIZE)

#define END "#"

bool    is_beautiful_music(const string& notes)
{
    for (int i=0;i<notes.length()-1;i++) {
        char    cur = notes[i];
        char    next = notes[i+1];
        int     diff = get_diff(cur,next);

        if (diff==0 || diff%2==1) {
            return false;
        }
    }

    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string  notes;

        cin>>notes;
        if (notes == END) break;

        cout<<(is_beautiful_music(notes)?
            "That music is beautiful.":"Ouch! That hurts my ears.")<<'\n';
    }

    return  0;
}