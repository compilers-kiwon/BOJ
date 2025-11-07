#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define NUM_OF_POINTS (4)

typedef long long int int64;
typedef pair<int64, int64> Pos;

#define x first
#define y second

pair<double, double> mid;

void get_middle_point(const Pos p[]) {
    for (int i = 0; i < NUM_OF_POINTS; i++) {
        mid.x += (double)p[i].x, mid.y += (double)p[i].y;
    }

    mid.x /= (double)NUM_OF_POINTS, mid.y /= (double)NUM_OF_POINTS;
}

bool is_less(const Pos& p1, const Pos& p2) {
    double a1 = atan2((double)p1.y - mid.y, (double)p1.x - mid.x);
    double a2 = atan2((double)p2.y - mid.y, (double)p2.x - mid.x);
    return (a1 < a2);
}

void get_vectors(const Pos in[], Pos out[]) {
    for (int i = 0; i < NUM_OF_POINTS; i++) {
        out[i].x = in[(i+1)%NUM_OF_POINTS].x - in[i].x;
        out[i].y = in[(i+1)%NUM_OF_POINTS].y - in[i].y;
    }
}

void get_length(const Pos in[], int64 out[]) {
    for (int i = 0; i < NUM_OF_POINTS; i++) {
        out[i] = (in[i].x * in[i].x) + (in[i].y * in[i].y);
    }
}

// What a dot product is 0 means that two vectors make 90 degree.
int64 get_dot_product(const Pos& p1, const Pos& p2) {
    return ((p1.x * p2.x) + (p1.y * p2.y));
}

// What a cross product is 0 means that two vectors are parallel
int64 get_cross_product(const Pos& p1, const Pos& p2) {
    return ((p1.x * p2.y) - (p1.y * p2.x));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Pos in[NUM_OF_POINTS];

    for (int i = 0; i < NUM_OF_POINTS; i++) {
        cin >> in[i].x >> in[i].y;
    }

    get_middle_point(in);
    sort(in, in + NUM_OF_POINTS, is_less);

    Pos vec[NUM_OF_POINTS];
    get_vectors(in, vec);

    int64 length[NUM_OF_POINTS];
    get_length(vec, length);

    bool is_parallel_0 = (get_cross_product(vec[0], vec[2]) == 0);
    bool is_parallel_1 = (get_cross_product(vec[1], vec[3]) == 0);
    bool is_parallelogram = (is_parallel_0 && is_parallel_1);
    bool is_trapezoid = (is_parallel_0 || is_parallel_1);

    bool all_length_same = (length[0] == length[1] &&
                            length[1] == length[2] && length[2] == length[3]);
    bool is_rectangle = (is_parallelogram && (get_dot_product(vec[0], vec[1]) == 0));
    bool is_rhombus = (is_parallelogram && all_length_same);
    bool is_square = (is_rectangle && all_length_same);

    bool kite_0 = (length[0] == length[1] && length[2] == length[3]);
    bool kite_1 = (length[1] == length[2] && length[3] == length[0]);
    bool is_kite = (kite_0 || kite_1);

    if (is_square) {
        cout << "Square\n";
    } else if (is_rectangle) {
        cout << "Rectangle\n";
    } else if (is_rhombus) {
        cout << "Rhombus\n";
    } else if (is_parallelogram) {
        cout << "Parallelogram\n";
    } else if (is_trapezoid) {
        cout << "Trapezoid\n";
    } else if (is_kite) {
        cout << "Kite\n";
    } else {
        cout << "Quadrilateral\n";
    }

    return 0;
}