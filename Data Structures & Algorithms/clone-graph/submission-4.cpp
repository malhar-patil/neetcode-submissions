/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
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
    void dfs(Node* node, unordered_map<Node*,Node*>& mapping, unordered_map<Node*,bool>& visited){
        Node* newNode = new Node(node->val);
        mapping[node] = newNode;
        visited[node] = true;

        for(auto it = node->neighbors.begin();it!=node->neighbors.end();it++){
            Node* tempNode = *it;
            if(visited[tempNode]==true){
                continue;
            }
            dfs(tempNode,mapping,visited);
        }

        for(auto it = node->neighbors.begin();it!=node->neighbors.end();it++){
            mapping[node]->neighbors.push_back(mapping[*it]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> mapping;
        unordered_map<Node*,bool> visited;
        dfs(node, mapping, visited);
        return mapping[node];
    }
};
