#include <stdio.h>
#include <iostream>
#include <array>
#include <string>
#include <queue>

using namespace std;
char map[10][20] = {
	{"1111111111111111111"},
	{"1000000000000000001"},
	{"1000000000000000001"},
	{"1000011111111000001"},
	{"1000010000001000001"},
	{"10000100110q1000001"},
	{"1000010011111000001"},
	{"1000010000000000001"},
	{"1s00010000000000001"},
	{"1111111111111111111"}
};

void drawMap() {
	int h, w;

	for (h = 0; h < 10; h++) {
		for (w = 0; w < 20; w++) {
			char temp = map[h][w];
			if (temp == '0') {
				printf(" ");
			}
			else if (temp == '1') {
				printf("#");
			}
			else if (temp == 's') {
				printf("@");
			}
			else if (temp == 'q') {
				printf("O");
			}
		}
		printf("\n");
	}
}

struct Node {
	Node() : depth(0), isVisited(false), isTarget(false), adjacent{} {}
	int depth;
	bool isVisited;
	bool isTarget;
	array<Node*, 4> adjacent;
};

using NodeMap = array<array < Node*, 100>, 100>;
