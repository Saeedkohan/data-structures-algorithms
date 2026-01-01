#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Graph {
    unordered_map<string, unordered_set<string> > adjacencyList;

public:
    bool addVertex(const string &vertex) {
        if (adjacencyList.count(vertex) == 0) {
            adjacencyList[vertex];
            return true;
        }
        return false;
    }

    bool addEdge(const string &vertex1, const string &vertex2) {
        if (adjacencyList.count(vertex1) && adjacencyList.count(vertex2)) {
            adjacencyList.at(vertex1).insert(vertex2);
            adjacencyList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }

    bool removeEdge(const string &vertex1, const string &vertex2) {
        if (adjacencyList.count(vertex1) && adjacencyList.count(vertex2)) {
            adjacencyList.at(vertex1).erase(vertex2);
            adjacencyList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }

    bool removeVertex(const string &vertex) {
        if (!adjacencyList.count(vertex))
            return false;

        for (const auto &otherVertex: adjacencyList.at(vertex)) {
            adjacencyList.at(otherVertex).erase(vertex);
        }

        adjacencyList.erase(vertex);
        return true;
    }

    void printGraph() const {
        for (const auto &[vertex, edges]: adjacencyList) {
            cout << vertex << ": [ ";
            for (const auto &edge: edges) {
                cout << edge << " ";
            }
            cout << "]\n";
        }
    }
};

int main() {
    Graph g;

    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("A");

    g.printGraph();

    g.addEdge("A", "B");
    g.addEdge("A", "C");
    g.addEdge("B", "C");
    g.addEdge("A", "D");

    g.printGraph();

    g.removeEdge("A", "C");
    g.printGraph();


    g.removeEdge("A", "C");
    g.printGraph();

    g.removeVertex("B");
    g.printGraph();
    g.removeVertex("D");

    g.printGraph();

    return 0;
}
