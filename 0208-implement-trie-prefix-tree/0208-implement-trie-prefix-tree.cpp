class Trie {
private:
    vector<Trie*> arr;
    bool isEnd;
public:
    Trie() {
        arr.assign(26,NULL);
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* node = this;
        
        for(char c : word){
            int ind = c - 'a';
            if(node->arr[ind] == nullptr){
                node->arr[ind] = new Trie();
            }
            node = node->arr[ind];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;

        for(char c : word){
            int ind = c - 'a';
            if(node->arr[ind] == nullptr) return false;

            node = node->arr[ind];
        }

        return node->isEnd; 
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;

        for(char c : prefix){
            int ind = c - 'a';
            if(node->arr[ind] == nullptr) return false;

            node = node->arr[ind];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */