/*

_____________________CLONE_GRAPH_____________________

Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

Test case format:
For simplicity, each node's value is the same as the node's index (1-indexed). 
For example, the first node with val == 1, the second node with val == 2, and so on.
The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. 
Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. 
You must return the copy of the given node as a reference to the cloned graph.


*/

#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
private: 
    unordered_map<Node*, Node*> node_map;

public:

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node_map.find(node) != node_map.end()) {
            return node_map[node];
        }

        Node* head = new Node();
        head->val = node->val;
        head->neighbors = vector<Node*>();
        node_map[node] = head;

        for (Node* it : node->neighbors) {
            Node* new_node = cloneGraph(it);
            head->neighbors.push_back(new_node);            
        }
        return head;
    }
};