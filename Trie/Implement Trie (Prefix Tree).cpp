#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

struct Node{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
private: 
    Node* root;
public: 
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i = 0; i < word.size(); i ++){
            if(!node -> containsKey(word[i])){
                node -> put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node -> setEnd();
    }

    bool search(string word){
        Node * node = root;
        for(int i = 0; i < word.size(); i ++){
            if(!node -> containsKey(word[i])) return false;
            node = node -> get(word[i]);
        }
        return node -> isEnd();
    }

    bool startsWith(string prefix){
        Node* node = root;
        for(int i = 0; i < prefix.size(); i ++){
            if(!node -> containsKey(prefix[i])) return false;
            node = node -> get(prefix[i]);
        }
        return true;
    }

};

void solve(){

}

int main() {
    fast_cin();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}