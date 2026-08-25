/*
// Definition for a Node.
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
*/

class Solution {
private:
    Node* cloneHelper(Node* node, unordered_map<Node*, Node*>& visited){
        if(node == NULL){
            return NULL;
        }
        if(visited.contains(node)){
            return visited[node];
        }
        Node* root = new Node(node->val);
        visited[node] = root;
        for(Node* n: node->neighbors){
            root->neighbors.push_back(cloneHelper(n, visited));
        }
        return root;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;
        return cloneHelper(node, visited);

    }
};
