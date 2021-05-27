#include<iostream>
#include "Trie.h"

using namespace std;


int main(){

    Trie<char> trie;
    
    cout<<"\nInserting abcd in Trie.... is abcd already exits -> "<<trie.insert((char*)"abcd",4);

    cout<<"\nInserting abc in Trie.... is abc already exits -> "<<trie.insert((char*)"abc",3);

    cout<<"\nInserting ab in Trie.... is ab already exits -> "<<trie.insert((char*)"ab",2);

    cout<<"\nInserting abcde in Trie.... is abcde already exits -> "<<trie.insert((char*)"abcde",5);

    cout<<"\n\nTotal Length -> "<<trie.get_total_length()<<endl;
    cout<<"Total Distinct Length -> "<<trie.get_distinct_length()<<endl;


    cout<<endl;
    return 0;
}
