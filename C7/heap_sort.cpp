#include <bits/stdc++.h>
using namespace std;

int hsize = 7;

int get_left(int loc) { return loc >= hsize ? -1 : 2 * loc + 1; }
int get_right(int loc) { return loc >= hsize ? -1 : 2 * loc + 2; }
int get_parent(int loc) {
    return loc <= 0 && loc >= hsize ? -1 : (loc - 1) / 2;
}

void heapify(vector<int> &vec, int loc) {
    if (loc >= hsize) return;
    int left = get_left(loc);
    int right = get_right(loc);
    int largest = left < hsize && vec[left] > vec[loc] ? left : loc;
    largest = right < hsize && vec[right] > vec[largest] ? right : largest;
    if (largest != loc) {
        swap(vec[loc], vec[largest]);
        heapify(vec, largest);
    }
}

void build_heap(vector<int> &vec) {
    for (int i = get_parent(hsize); i >= 0; i--) heapify(vec, i);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec{0, 4, 56, 7, 12, -9, 6};
        build_heap(vec);
        for (int i = hsize - 1; i >= 0; i--) {
            swap(vec[0], vec[i]);
            hsize--;
            heapify(vec, 0);
        }
        for (auto ele : vec) cout << ele << " ";
        cout << "\n";
    }
    return 0;
}