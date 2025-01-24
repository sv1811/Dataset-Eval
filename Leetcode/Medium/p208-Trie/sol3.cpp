// Bit-manipulation Implementation
class Trie {
    struct TrieNode {
        int children = 0;
        TrieNode* next[26] = {};
        bool isEnd = false;
    };
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!(node->children & (1 << idx))) {
                node->children |= (1 << idx);
                node->next[idx] = new TrieNode();
            }
            node = node->next[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!(node->children & (1 << idx))) return false;
            node = node->next[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!(node->children & (1 << idx))) return false;
            node = node->next[idx];
        }
        return true;
    }
};
