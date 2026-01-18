#include<iostream>
using namespace std;

class TrieNode{
    public:

    char data;
    bool isTerminalNode;
    TrieNode* children[26];

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminalNode = false;
    }

};

class Trie{
    public:

    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminalNode = true;
            return; 
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }


    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminalNode;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }



    // DO IT BY MY OWN
    bool removeUtil(){

    }

    bool removeWord(){

    }
};

int main(){
    Trie* t = new Trie(); 

    t->insertWord("Ansh");

    cout<<(t->searchWord("Ansh") ? "Present" : "Absent")<<endl;
}


