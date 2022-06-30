#include <string>
#include "./TrieNode.h"

class Trie
{
private:
    TrieNode *root;
    void insertWord(TrieNode *root, std::string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child, word.substr(1));
    }

    bool search(TrieNode *root, std::string word)
    {
        if (word.size() == 0)
            return root->isTerminal;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
            return search(root->children[index], word.substr(1));
        return false;
    }

    void removeWord(TrieNode *root, std::string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            TrieNode *child = root->children[index];
            removeWord(child, word.substr(1));

            if (child->isTerminal == false)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (child->children[i] != NULL)
                        return;
                }
                delete child;
                root->children[index] = NULL;
            }
        }
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertWord(std::string word)
    {
        insertWord(root, word);
    }

    bool search(std::string word)
    {
        return search(root, word);
    }

    void removeWord(std::string word)
    {
        removeWord(root, word);
    }
};
