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
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> copied;
        return dfs(node, copied);
    }

    Node* dfs(Node* node, map<Node*, Node*> &copied){
        if(node == nullptr){
            return nullptr;
        }
        if(copied.count(node)){
            return copied[node];
        }

        Node* copy = new Node(node->val);
        copied[node] = copy;

        for(Node* nei : node->neighbors){
            copy->neighbors.push_back(dfs(nei, copied));
        }

        return copy;
    }
};
