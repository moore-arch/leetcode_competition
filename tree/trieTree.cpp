/*
 * @Author: your name
 * @Date: 2021-05-28 20:03:47
 * @LastEditTime: 2021-05-28 21:20:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcode_competition/tree/tireTree.cpp
 */
#include <iostream>
#include <string>
#include <array>

using namespace std;


// todo, check errors on leetcode!, but it's right in local!
class Trie: public enable_shared_from_this<Trie> {
private:
    static constexpr int CAPACITY = 26;
    array<shared_ptr<Trie>, CAPACITY> record;
    bool isEnd;

    bool checkWord(const string &word) {
        // check char of word
        for (const char &ch : word) {
            if (ch < 'a' || ch > 'z') {
                return false;
            }
        }
        return true;
    }

public:
    /** Initialize your data structure here. */
    Trie(): isEnd(false) {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (!checkWord(word)) {
            return ;
        }

        shared_ptr<Trie> it = shared_from_this();
        int index = 0;
        for (const char &ch : word) {
            index = ch - 'a';
            if (it->record[index] == nullptr) {
                it->record[index] = make_shared<Trie> ();
            }
            it = it->record[index];
        }
        it->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (!checkWord(word)) {
            return false;
        }
        
        shared_ptr<Trie> it = shared_from_this();
        int index = 0;
        for (const char &ch : word) {
            index = ch - 'a';
            if (it->record[index] == nullptr) {
                return false;
            }
            it = it->record[index];
        }
        return it && it->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (!checkWord(prefix)) {
            return false;
        }
        int index = 0;
        shared_ptr<Trie> it = shared_from_this();
        for (const char &ch : prefix) {
            index = ch - 'a';
            if (it->record[index] == nullptr) {
                return false;
            }
            it = it->record[index];
        }
        return it != nullptr;
    }
};

int main()
{
    shared_ptr<Trie> obj = make_shared<Trie>();
    obj->insert("apple");
    cout << obj->search("apple") << endl;
    cout << obj->search("app") << endl;
    cout << obj->startsWith("app") << endl;
    obj->insert("app");
    cout << obj->search("app") << endl;
    
    return 0;
}