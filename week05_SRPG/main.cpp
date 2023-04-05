#include <stdio.h>
#include <iostream>
#include <array>
#include <string>
#include <queue>

using namespace std;

char map[10][21] = {
    "1111111111111111111",
    "1000000000000000001",
    "1000000000000000001",
    "1000011111111000001",
    "1000010000001000001",
    "10000100110q1000001",
    "1000010011111000001",
    "1000010000000000001",
    "1s00010000000000001",
    "1111111111111111111"
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

int main() {
    drawMap();

    // Initialize the node map
    NodeMap nodeMap{};

    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 20; ++col) {
            if (map[row][col] != '1') {
                nodeMap[row][col] = new Node();
            }
        }
    }

    // Set the adjacent nodes for each node
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 20; ++col) {
            Node* currentNode = nodeMap[row][col];

            if (currentNode != nullptr) {
                if (row > 0 && nodeMap[row - 1][col] != nullptr) {
                    currentNode->adjacent[0] = nodeMap[row - 1][col];
                }

                if (col > 0 && nodeMap[row][col - 1] != nullptr) {
                    currentNode->adjacent[1] = nodeMap[row][col - 1];
                }

                if (col < 19 && nodeMap[row][col + 1] != nullptr) {
                    currentNode->adjacent[2] = nodeMap[row][col + 1];
                }

                if (row < 9 && nodeMap[row + 1][col] != nullptr) {
                    currentNode->adjacent[3] = nodeMap[row + 1][col];
                }
            }
        }
    }

    // Set the target node
    Node* targetNode = nullptr;
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 20; ++col) {
            if (map[row][col] == 'q') {
                targetNode = nodeMap[row][col];
                targetNode->isTarget = true;
                break;
            }
        }
    }
    // Set the start node
    Node* startNode = nullptr;
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 20; ++col) {
            if (map[row][col] == 's') {
                startNode = nodeMap[row][col];
                break;
            }
        }
    }

    // Traverse the nodes using BFS algorithm and find the shortest path
    queue<Node*> nodeQueue;
    nodeQueue.push(startNode);

    while (!nodeQueue.empty()) {
        Node* currentNode = nodeQueue.front();
        nodeQueue.pop();

        if (currentNode->isVisited) {
            continue;
        }

        currentNode->isVisited = true;

        if (currentNode->isTarget) {
            cout << "The shortest path has length " << currentNode->depth << endl;
            break;
        }

        for (auto adj : currentNode->adjacent) {
            if (adj != nullptr && !adj->isVisited) {
                adj->depth = currentNode->depth + 1;
                nodeQueue.push(adj);
            }
        }
    }

    // Free the allocated memory for nodes
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 20; ++col) {
            delete nodeMap[row][col];
        }
    }

    return 0;
}