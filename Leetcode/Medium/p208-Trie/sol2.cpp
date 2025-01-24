// Map-based Implementation
class Trie {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd = false;
    };
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) return false;
            node = node->children[c];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c]) return false;
            node = node->children[c];
        }
        return true;
    }
};
