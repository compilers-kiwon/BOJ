#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

#define MAX_NUM (1000)

#define PLAYER_YT (0)
#define PLAYER_YJ (1)
#define NUM_OF_PLAYERS (2)

#define THE_OTHER_PLAYER(cur_player) (((cur_player)+1)%NUM_OF_PLAYERS)

const string player[NUM_OF_PLAYERS] = {"yt", "yj"};

bool is_prime[MAX_NUM+1];
unordered_set<int> both, own[NUM_OF_PLAYERS];

void init_prime(void) {
    fill(&is_prime[2], &is_prime[MAX_NUM+1], true);

    for (int i = 2; i <= MAX_NUM; i++) {
        if (is_prime[i] == false) {
            continue;
        }

        for (int j = i + i; j <= MAX_NUM; j += i) {
            is_prime[j] = false;
        }
    }
}

void get_prime_numbers(int p, int lower, int upper) {
    for (int i = lower; i <= upper; i++) {
        if (is_prime[i] == false) {
            continue;
        }

        if (own[THE_OTHER_PLAYER(p)].find(i)
                == own[THE_OTHER_PLAYER(p)].end()) {
            own[p].insert(i);
        } else {
            both.insert(i);
            own[THE_OTHER_PLAYER(p)].erase(i);
        }
    }
}

int play_game(void) {
    int winner;

    for (int p = PLAYER_YT;; p = (p+1) % NUM_OF_PLAYERS) {
        if (!both.empty()) {
            both.erase(*(both.begin()));
        } else {
            if (!own[p].empty()) {
                own[p].erase(*(own[p].begin()));
            } else {
                winner = THE_OTHER_PLAYER(p);
                break;
            }
        }
    }

    return winner;
}

int main(void) {
    init_prime();

    int A, B, C, D;
    
    cin>>A>>B>>C>>D;
    
    get_prime_numbers(0, A, B);
    get_prime_numbers(1, C, D);    
    
    cout<<player[play_game()]<<'\n';
    return 0;
}