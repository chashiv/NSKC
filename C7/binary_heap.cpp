#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int *harr;
    int capacity;
    int heap_size;

   public:
    MinHeap(int);
    void heapify(int);
    int get_left(int);
    int get_right(int);
    int get_parent(int);
    int extract_min();
    int get_min();
    void insert(int);
    void decrease(int, int);
    void delete_node(int);
    void display();
};

MinHeap::MinHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

int MinHeap::get_left(int loc) { return loc >= heap_size ? -1 : 2 * loc + 1; }

int MinHeap::get_right(int loc) { return loc >= heap_size ? -1 : 2 * loc + 2; }

int MinHeap::get_parent(int loc) {
    if (loc <= 0 && loc >= heap_size)
        return -1;
    else
        return (loc - 1) / 2;
}

int MinHeap::get_min() { return heap_size == 0 ? -1 : harr[0]; }

void MinHeap::heapify(int loc) {
    int left = get_left(loc);
    int right = get_right(loc);
    int min = (left < heap_size && harr[left] < harr[loc]) ? left : loc;
    min = (right < heap_size && harr[right] < harr[min]) ? right : min;
    if (min != loc) {
        swap(harr[loc], harr[min]);
        heapify(min);
    }
}

int MinHeap::extract_min() {
    if (!heap_size) return -1;
    int data = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    heapify(0);
    return data;
}

void MinHeap::insert(int val) {
    if (heap_size == capacity) {
        cout << "Size Overflow!!!\n";
        return;
    }
    int loc = heap_size;
    harr[loc] = val;
    heap_size++;
    while (loc != 0 && harr[loc] < harr[get_parent(loc)]) {
        swap(harr[loc], harr[get_parent(loc)]);
        loc = get_parent(loc);
    }
}

void MinHeap::decrease(int loc, int val) {
    harr[loc] = val;
    while (loc != 0 && harr[loc] < harr[get_parent(loc)]) {
        swap(harr[loc], harr[get_parent(loc)]);
        loc = get_parent(loc);
    }
}

void MinHeap::delete_node(int loc) {
    decrease(loc, INT32_MIN);
    extract_min();
}

void MinHeap::display() {
    for (int i = 0; i < heap_size; i++) {
        cout << harr[i] << " ";
    }
    cout << "\n";
}

int main() {
    MinHeap mh(6);
    mh.insert(20);
    mh.insert(30);
    mh.insert(40);
    mh.insert(25);
    mh.insert(15);
    mh.display();
    // mh.delete_node(0);
    // mh.display();
    return 0;
}

