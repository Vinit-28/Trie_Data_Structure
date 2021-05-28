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



// Class Trie to Implement the Functionalities of the Trie Data Structure //
template<class DataType>
class Trie{

    private:
        // Declaration of Private Data Members //
        Node<DataType> *root = (Node<DataType>*)malloc(sizeof(Node<DataType>)) ;
        int total_length=0, total_distinct_length=0;
        bool is_found;

        // Declaration of Private Member Functions //
        void visit_every_path(vector<DataType> path, vector<vector<DataType>> &routes, Node<DataType> *curr_pos);
        vector<Node<DataType>*> get_specified_path(DataType data[], int datalen);
        void erase_node_element_from_path(vector<Node<DataType>*> &path, Node<DataType> *node_element);

    public:
        // Declaration of Public Member Functions //
        bool insert(DataType data[], int datalen);
        bool is_exists(DataType data[], int datalen);
        bool remove(DataType data[], int datalen);

        int get_distinct_length();
        int get_total_length();

        vector<vector<DataType>> get_paths();

};



// Class Trie's Member Functions Definitions //



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
    if( is_exists && temp->is_end ){

        // Element is Repeated //
        return false; 
    }

    else if ( is_exists == false ){
        
        // Element is Unique //
        temp->is_end=true;
        total_distinct_length+=1, total_length+=1; 
        return true; 
    }

    else{

        // Element exists but not repeated //
        temp->is_end=true;
        total_length+=1;
    }

    return true;
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



// Member Function to get the distinct length or total distinct elements present in the trie //
template<class DataType>
int Trie<DataType>::get_distinct_length(){
    return total_distinct_length;
}



// Member Function to get the total length of the trie or total elements presents in the trie //
template<class DataType>
int Trie<DataType>::get_total_length(){
    return total_length;
}



// Member Function to get all the paths or routes available in the trie //
template<class DataType>
vector<vector<DataType>> Trie<DataType>::get_paths(){

    vector<vector<DataType>> routes;
    visit_every_path({}, routes, root);
    return routes;
}



// Member Function to visit each node or path recursively //
template<class DataType>
void Trie<DataType>::visit_every_path(vector<DataType> path, vector<vector<DataType>> &routes, Node<DataType> *curr_pos){
    
    if( curr_pos->is_end ){
        
        routes.push_back(path);
    }

    for(int i=0; i<curr_pos->childrens.size(); i++){

        path.push_back(curr_pos->childrens[i]->data);
        visit_every_path(path,routes,curr_pos->childrens[i]);
        path.pop_back();
    }

}



// Member Function to get the path/route of an specific data //
template<class DataType>
vector<Node<DataType>*> Trie<DataType>::get_specified_path(DataType data[], int datalen){

    vector<Node<DataType>*> path;
    Node<DataType> *temp = root;
    bool element_found;


    for(int i=0; i<datalen; i++){

        element_found = false;
        for(int j=0; j<temp->childrens.size(); j++){

            if(data[i] == temp->childrens[j]->data){

                temp = temp->childrens[j];
                element_found = true;
                break;
            }
        }
        if(element_found == false){

            is_found=false;
            return path;
        }

        path.push_back(temp);
    }
    is_found=true;
    return path;

}



// Member Function to erase the node elements from the path/route //
template<class DataType>
void Trie<DataType>::erase_node_element_from_path(vector<Node<DataType>*> &path, Node<DataType> *node_element){

    int path_len = path.size();
    for(int i=0; i<path_len; i++){

        if( node_element == path[i] ){

            path.erase(path.begin()+i);
            return;
        }
    }
}



// Member Function to remove data from the trie //
template<class DataType>
bool Trie<DataType>::remove(DataType data[], int datalen){

    vector<Node<DataType>*> path = get_specified_path(data,datalen);
    
    if(is_found==false)
        return is_found;

    int path_len = path.size();

    if( path[path_len-1]->childrens.empty() == false ){

        path[path_len-1]->is_end=false;
    }
    else{

        if( path_len==1 ){

            erase_node_element_from_path(root->childrens,path[0]);
        }
        else{

            
            erase_node_element_from_path(path[path_len-2]->childrens, path[path_len-1]);
            path_len-=1;

            for(int i=path_len-1; i>=0; i--){
                
                if( path[i]->childrens.empty() == false || path[i]->is_end == true ){
                    
                    return true;
                }
                else{

                    if( i==0 ){
                        
                        erase_node_element_from_path(root->childrens,path[i]);
                    }
                    else{

                        erase_node_element_from_path(path[i-1]->childrens,path[i]);
                    }
                }

            }

        }
    }
    
    return true;
}



// End of Class Trie's Member Functions Definitions //







