//
// Created by Jongwoo on 2020-03-12.
//
#include <iostream>
#include <vector>
#include <string>

#define MAX_SIZE 20

using namespace std;

char decompressed[MAX_SIZE][MAX_SIZE];

//void decompress(const string& s, int y, int x, int size);

void decompress(string::iterator &it, int y, int x, int size) {
    char head = *(it++);
    if (head == 'b' || head == 'w') {
        for (int dy = 0; dy < size; ++dy)
            for (int dx = 0; dx < size; ++dx)
                decompressed[y + dy][x + dx] = head;
    } else {
        int half = size / 2;
        decompress(it, y, x, half);
        decompress(it, y, x + half, half);
        decompress(it, y + half, x, half);
        decompress(it, y + half, x + half, half);
    }
}

string reverse(string::iterator &it) {
    char head = *it;
    ++it;
    if (head == 'b' || head == 'w')
        return string(1, head);
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}
