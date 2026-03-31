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
    void helper(unordered_map<Node*,bool> &visited,unordered_map<Node*,Node*> &mapping){
        for(auto iter=mapping.begin();iter!=mapping.end();iter++){
            visited[iter->first]=true;
            vector<Node*>temp = iter->first->neighbors;
            for(int i=0;i<temp.size();i++){
                iter->second->neighbors.push_back(mapping[temp[i]]);
            }
        }
    }
    void dfs(Node* node, unordered_map<Node*,bool> &visited,unordered_map<Node*,Node*> &mapping){
        Node* newNode = new Node(node->val);
        mapping[node]=newNode;
        visited[node]=true;
        vector<Node*> temp = node->neighbors;
        for(int i=0;i<temp.size();i++){
            if(visited[temp[i]]==true){
                continue;
            }
            dfs(temp[i],visited,mapping);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        unordered_map<Node*,bool>visited;
        unordered_map<Node*,Node*> mapping;
        dfs(node,visited,mapping);
        visited.clear();
        helper(visited,mapping);
        return mapping[node];
    }
};
