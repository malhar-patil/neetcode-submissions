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
    void dfs(Node* node, unordered_map<Node*,Node*> &visited){
        Node* newNode = new Node(node->val);
        visited[node]=newNode;
        for(int i=0;i<node->neighbors.size();i++){
            if(visited.find(node->neighbors[i])!=visited.end()){
                continue;
            }
            dfs(node->neighbors[i],visited);
        }

        for(int i=0;i<node->neighbors.size();i++){
            newNode->neighbors.push_back(visited[node->neighbors[i]]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*>visited;
        // unordered_map<Node*,Node*> mapping;
        dfs(node,visited);
        return visited[node];
    }
};
