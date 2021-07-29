class Node{
public:
    map<int, Node*> nodes;

    char letter;

    bool is_end {false};

    explicit Node(char n_letter) : letter(n_letter){}
};


class Trie {
public:
    
    Node *root {nullptr};
    
    /** Initialize your data structure here. */
     Trie() {
        root = new Node(-1);
     }

     /** Inserts a word into the trie. */
     void insert(string word) {
         auto curr = root;

         for (const auto &letter: word) {
             auto pos = letter - 'a';

            auto &node = curr->nodes[pos];
            if (!node) node = new Node(letter);
            curr = node;
         }

         curr->is_end = true;
     }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto curr = root;
        
        for (const auto &letter: word) {
            auto pos = letter - 'a';

            auto nodes_iter = curr->nodes.find(pos);
            if (nodes_iter == curr->nodes.end()) return false;
            curr = nodes_iter->second;
        }
        
        return curr->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto curr = root;

        for (const auto &letter: prefix) {
            auto pos = letter - 'a';

            auto nodes_iter = curr->nodes.find(pos);
            if (nodes_iter == curr->nodes.end()) return false;
            curr = nodes_iter->second;
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
