class TrieNode{
    public:
    char ch;
    vector<TrieNode*> arr;
    bool isTerminal;

    TrieNode(char ch){
        this->ch=ch;
        arr.assign(26,NULL);
        isTerminal=false;
    }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'a';
        if(root->arr[index]!=NULL){
            insertUtil(root->arr[index],word.substr(1));
        }
        else{
            TrieNode* temp = new TrieNode(word[0]);
            root->arr[index]=temp;
            insertUtil(root->arr[index],word.substr(1));
        }
    }
    void insert(string word) {
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index = word[0]-'a';
        if(root->arr[index]!=NULL){
            return searchUtil(root->arr[index],word.substr(1));
        }
        else{
            return false;
        }
    }
    bool search(string word) {
        return searchUtil(root,word);
    }

    bool startsWithUtil(TrieNode* root, string word){
        if(word.length()==0){
            return true;
        }

        int index=word[0]-'a';
        if(root->arr[index]!=NULL){
            return startsWithUtil(root->arr[index],word.substr(1));
        }
        else{
            return false;
        }
    }
    bool startsWith(string prefix) {
        return startsWithUtil(root,prefix);
    }
};
