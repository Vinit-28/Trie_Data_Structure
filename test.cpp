#include<iostream>
#include<vector>
#include "Trie.h"

using namespace std;


int main(){

    Trie<char> trie;
    
    
    
    cout<<"\nResult of insertion of abcd ( successfull->1 || unsuccessfull->0 ) :: "<<trie.insert( (char*)"abcd", 4 );
    cout<<"\nResult of insertion of abc ( successfull->1 || unsuccessfull->0 ) :: "<<trie.insert( (char*)"abc", 3 );
    cout<<"\nResult of insertion of ab ( successfull->1 || unsuccessfull->0 ) :: "<<trie.insert( (char*)"ab", 2 );
    cout<<"\nResult of insertion of abcde ( successfull->1 || unsuccessfull->0 ) :: "<<trie.insert( (char*)"abcde", 5 );

    cout<<"\nResult of insertion of Reapeated Element abcde ( successfull->1 || unsuccessfull->0 ) :: "<<trie.insert((char*)"abcde",5);


    vector<vector<char>> routes = trie.get_paths();

    cout<<"\n\nSequence of Nodes in the Trie ::\n\n";

    for(int i=0; i<routes.size(); i++){

        for(int j=0; j<routes[i].size(); j++){
            
            cout<<routes[i][j]<<"\t";
        }
        cout<<endl;
    }

    
    cout<<endl;
    return 0;
}

