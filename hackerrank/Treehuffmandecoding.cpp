

/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/

void decode_huff(node * root, string s) {
     if(root == NULL || s.empty() || s == ""){
        cout<<"";
        return;
    }
    
    auto temp = root;
    for(auto c : s){
        temp = c == '0' ? temp->left : temp->right;                
        
        if(temp && temp->data){
            cout<<temp->data;
            temp = root;
        }
    }    
}
