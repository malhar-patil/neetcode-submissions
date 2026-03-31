class TrieNode{
    public:
    char ch;
    vector<TrieNode*> arr;
    bool isTerminal;

    TrieNode(char ch){
        this->ch=ch;
        this->arr.assign(26,NULL);
        isTerminal=false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('\0');
    }

    void addWordUtil(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'a';
        if(root->arr[index]!=NULL){
            addWordUtil(root->arr[index],word.substr(1));
        }
        else{
            TrieNode* temp = new TrieNode(word[0]);
            root->arr[index]=temp;
            addWordUtil(root->arr[index],word.substr(1));
        }
    }
    void addWord(string word) {
        addWordUtil(root,word);
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        
        if(word[0]!='.'){
            int index = word[0]-'a';
            if(root->arr[index]!=NULL){
                return searchUtil(root->arr[index],word.substr(1));
            }
            else{
                return false;
            }
        }
        else{
            for(int i=0;i<26;i++){ 
                if(root->arr[i]!=NULL){
                    int res = searchUtil(root->arr[i],word.substr(1));
                    if(res){return true;}
                }
            }
        }
        return false;
    }
    bool search(string word) {
        if(word.length()==0){
            return false;
        }
        return searchUtil(root,word);
    }
};
