#include<iostream>
#include<vector>
#include "Trie.h"

using namespace std;


int main(){

    Trie<char> trie;
    
    
    trie.insert( (char*)"abcd", 4 );
    trie.insert( (char*)"abc", 3 );
    trie.insert( (char*)"ab", 2 );
    trie.insert( (char*)"abcde", 5 );


    vector<vector<char>> routes = trie.get_paths();

    cout<<"\nSequence of Nodes in the Trie ::\n\n";

    for(int i=0; i<routes.size(); i++){

        for(int j=0; j<routes[i].size(); j++){
            
            cout<<routes[i][j]<<"\t";
        }
        cout<<endl;
    }

    
    cout<<endl;
    return 0;
}

