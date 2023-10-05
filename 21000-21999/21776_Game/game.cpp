#include    <iostream>
#include    <string>
#include    <vector>
#include    <set>
#include    <algorithm>

using namespace std;

#define MAX_NUM_OF_PLAYERS  (9+1)
#define MAX_NUM_OF_CARDS    (9+1)

#define ADD 0
#define DEL 1

typedef pair<int,char>   Operation;

static int  N,C;
static vector<int> cards_in_hand[MAX_NUM_OF_PLAYERS];
static vector<Operation> cards[MAX_NUM_OF_CARDS];
static set<string>  results;

#define chr2int(c)  ((int)((c)-'0'))
#define erase_one_chr(str,pos)  ((str).erase((pos),1))

int simulate(const vector<int>& order)
{
    string  ret;
    
    for (int i=0;i<order.size();i++) {        
        vector<Operation>&  cur_card = cards[order[i]];

        for (int k=0;k<cur_card.size();k++) {
            Operation&  cur_op = cur_card[k];
            
            if (cur_op.first == ADD) {
                ret.push_back(cur_op.second);
            } else {
                int pos = chr2int(cur_op.second);

                if (pos >= ret.length()) {
                    results.insert("ERROR");
                    return  0;
                }

                erase_one_chr(ret,pos);
            }
        }
    }

    results.insert(ret.empty()?"EMPTY":ret);
    return  0;
}

int play_game(vector<int>& order,int num_of_cards,int ptr[])
{
    if (order.size() == num_of_cards) {
        simulate(order);
        return  0;
    }

    for (int i=1;i<=N;i++) {
        if (ptr[i] < cards_in_hand[i].size()) {
            order.push_back(cards_in_hand[i][ptr[i]]);
            ptr[i]++;

            play_game(order,num_of_cards,ptr);

            ptr[i]--;
            order.pop_back();
        }
    }

    return  0;
}

int parse(const string& str,int card_idx)
{
    string  buf;
    
    for (int i=0;i<str.length();i++) {
        if (str[i] != ',') {
            buf.push_back(str[i]);
            continue;
        } 

        if (buf.front() == 'A') {   // ADD
            cards[card_idx].push_back({ADD,buf.back()});
        } else {                    // DEL
            cards[card_idx].push_back({DEL,buf.back()});
        }

        buf.clear();
    }

    return  0;
}

int input(void)
{
    int ret = 0;

    cin>>N>>C;

    for (int i=1;i<=N;i++) {
        int num_of_cards;

        cin>>num_of_cards;
        ret += num_of_cards;

        for (int j=1;j<=num_of_cards;j++) {
            int card;

            cin>>card;
            cards_in_hand[i].push_back(card);
        }
    }

    getchar();

    for (int i=1;i<=C;i++) {
        string  str;

        getline(cin,str);
        str.push_back(',');
        parse(str,i);    
    }

    return  ret;
}

int main(void)
{
    int total_num_of_cards;
    int ptr[MAX_NUM_OF_PLAYERS] = {0,};
    vector<int> order;

    total_num_of_cards = input();
    play_game(order,total_num_of_cards,ptr);

    set<string>::iterator   it;

    for (it=results.begin();it!=results.end();it++) {
        cout<<(*it)<<'\n';
    }

    return  0;
}