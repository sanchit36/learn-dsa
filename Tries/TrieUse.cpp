#include <bits/stdc++.h>
#include "Trie.h"
using namespace std;

int main()
{
    Trie *t = new Trie();
    t->insertWord("a");
    t->insertWord("as");
    t->insertWord("are");
    t->insertWord("dot");

    cout << t->search("are") << endl;
    cout << t->search("do") << endl;
    cout << t->search("dot") << endl;
    cout << t->search("and") << endl;
    t->removeWord("and");
    t->removeWord("do");
    cout << t->search("and") << endl;
    t->insertWord("do");
    cout << t->search("do") << endl;

    return 0;
}