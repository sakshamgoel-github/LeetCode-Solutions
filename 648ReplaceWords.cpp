#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Trie {
private:
    // TrieNode class
    class TrieNode {
    public:
        bool isEndOfWord;
        std::unordered_map<char, TrieNode*> children;
        
        TrieNode() : isEndOfWord(false) {}
    };

    TrieNode* root;

public:
    // Constructor
    Trie() {
        root = new TrieNode();
    }

    // Destructor
    ~Trie() {
        deleteTrie(root);
    }

    // Insert a word into the Trie
    void insert(const std::string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(const std::string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        return currentNode->isEndOfWord;
    }

    // Check if any word starts with the given prefix
    bool startsWith(const std::string& prefix) {
        TrieNode* currentNode = root;
        for (char ch : prefix) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        return true;
    }

private:
    // Helper function to delete all nodes in the Trie
    void deleteTrie(TrieNode* node) {
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        delete node;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie obj;
        for(string &word: dictionary){
            obj.insert(word);
        }
        string result = "",word;
        stringstream ss(sentence);
        while(getline(ss, word, ' ')){
            string prefix = "";
            bool flag = false;
            for(char &ch: word){
                prefix += ch;
                if(obj.search(prefix)){
                    result += prefix + " ";
                    flag = true;
                    break;
                }
            }
            if(!flag)
                result += word + " ";
        }
        result.pop_back();
        return result;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}