#include<vector>
#include<stdlib.h>

using namespace std;

// Class Node to Create Nodes for Trie Data Structure //
template <class DataType>
class Node{

    public:
        // Declaration of Private Data Members //

        DataType data; // Variable to Store Data of a Particular Node //
        vector<Node<DataType>*> childrens; // Vector to Store the Addresses of a Node's Childrens //
        bool is_end; // Boolean variable to keep the track whether it's an end of an data element or not //

};



template<class DataType>
class Trie{

    private:
        // Declaration of Private Data Members //
        Node<DataType> *root = (Node<DataType>*)malloc(sizeof(Node<DataType>)) ;
        int total_length=0, total_distinct_length=0;

    public:
        // Declaration of Public Member Functions //
        bool insert(DataType data[], int datalen);
        bool is_exists(DataType data[], int datalen);

        int get_distinct_length();
        int get_total_length();

};



// Class Trie's Public Member Functions Definitions //



// Member Function to Insert Data in a Trie && return true if data already exists else false //
template<class DataType>
bool Trie<DataType>::insert(DataType data[], int datalen){

    bool is_exists = true,element_found;
    Node<DataType> *temp = root;
    for(int i=0; i<datalen; i++){

        element_found = false;
        for(int j=0; j<temp->childrens.size(); j++){

            if( temp->childrens[j]->data == data[i] ){

                temp = temp->childrens[j];
                element_found = true;
                break;
            }
        }

        if( element_found == false ){

            Node<DataType> *newnode = (Node<DataType>*)malloc(sizeof(Node<DataType>)) ;
            newnode->data = data[i];
            temp->childrens.push_back(newnode);
            temp = newnode;
            is_exists = false;
        }
    }

    if( ! (is_exists) ){
        total_distinct_length+=1;
    }

    total_length+=1;

    temp->is_end=true;
    return is_exists;
}



// Member Function to search whether an element exists or not in a trie //
template<class DataType>
bool Trie<DataType>::is_exists(DataType data[], int datalen){

    bool is_element_found;
    Node<DataType> *temp = root;

    for(int i=0;i<datalen;i++){
        
        is_element_found = false;

        for(int j=0;j<temp->childrens.size();j++){

            if(temp->childrens[j]->data == data[i]){
                
                is_element_found = true;
                temp = temp->childrens[j];
                break;
            }

        }

        if(is_element_found==false){

            return false;
        }
    }

    if( temp->is_end ){

        return true;
    }

    return false;

}



// Member Function Description //
template<class DataType>
int Trie<DataType>::get_distinct_length(){
    return total_distinct_length;
}



// Member Function Description //
template<class DataType>
int Trie<DataType>::get_total_length(){
    return total_length;
}



// End of Class Trie's Public Member Functions Definitions //






