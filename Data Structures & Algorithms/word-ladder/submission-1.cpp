class Solution {
public:

    void bfs(string word, unordered_map<string, int>& visited, unordered_map<string, string>& parent, unordered_map<string, vector<string>>& adj){
        queue<string> q;
        visited[word] = 1;
        parent[word] = word;
        q.push(word);

        while(!q.empty()){
            string temp = q.front();
            q.pop();

            for(int i=0;i<adj[temp].size();i++){
                string n = adj[temp][i];
                if(visited.find(n) == visited.end()){
                    visited[n] = 1;
                    parent[n] = temp;
                    q.push(n);
                }
            }
        }
    }
    void buildAdj(unordered_map<string, vector<string>>& adj, string word, int index, vector<string>& wordList){
        
        for(int i=0;i<wordList.size();i++){
            string t = wordList[i];
            if(t.length() != word.length()){continue;}

            int diff = 0;
            for(int j=0;j<t.length();j++){
                if(word[j] != t[j]){
                    diff++;
                }
            }

            if(diff == 1){
                adj[word].push_back(t);
                adj[t].push_back(word);
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;
        wordList.push_back(beginWord);

        for(int i=0;i<wordList.size();i++){
            buildAdj(adj, wordList[i], i+1, wordList);
        }
        unordered_map<string, int> visited;
        unordered_map<string, string> parent;
        bfs(beginWord, visited, parent, adj);
        cout<<adj.size()<<endl;
        if(visited.find(endWord) == visited.end()){return 0;}
        int len = 0;
        string n = endWord;
        while(n!=beginWord){
            len++;
            n = parent[n];
        }
        return len+1;
    }
};
