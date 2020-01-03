#include <avltree.h>

int height(node * n){
    if(n == NULL) return 0;
    else return n->height;
}

node * createNewNode(keyType newUrl){
    node * newNode = new node();
    newNode -> url = newUrl;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> height = 1;
    return newNode;
}

int max(int x, int y){
    return (x > y)? x : y;
}

// node * leftRotate(node * a){
//     node * b = a -> right;
//     node * temp = b -> left;

//     //rotate
//     b -> left = a;
//     a -> right = temp;

//     //update height
//     a -> height = max(height(b -> left), height(b -> right)) + 1;
//     b -> height = max(height(a -> left), height(a -> right)) + 1;
//     return b;
// }

node *leftRotate(node *x)  {  
    node *y = x->right;  
    node *T2 = y->left;  
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update heights  
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    // Return new root  
    return y;  
}

// node * rightRotate(node * b){
//     node * a = b -> left;
//     node * temp = a -> right;

//     //rotate
//     a -> right = b;
//     b -> left = temp;

//     //update height
//     //+1 for the root node
//     a -> height = max(height(a -> left), height(a -> right)) + 1;
//     b -> height = max(height(b -> left), height(b -> right)) + 1;
//     return a;
// }

node *rightRotate(node *y)  {  
    node *x = y->left;  
    node *T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Update heights  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    // Return new root  
    return x;  
}

int getBalance(node *N)  {  
    if (N == NULL) return 0;  
    else return height(N->left) - height(N->right);  
}  

node* insert(node* n, keyType url)  {  
    /* 1. Perform the normal BST insertion */
    if (n == NULL)  
        return(createNewNode(url));  
    if (url < n->url)  
        n->left = insert(n->left, url);  
    else if (url > n->url)  
        n->right = insert(n->right, url);  
    else // Equal keys are not allowed in BST  
        return n;  
  
    /* 2. Update height of this ancestor node */
    n->height = 1 + max(height(n->left),  
                        height(n->right));  
  
    /* 3. Get the balance factor of this ancestor  
        node to check whether this node became  
        unbalanced */
    int balance = getBalance(n);  
  
    // If this node becomes unbalanced, then  
    // there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && url < n->left->url)  
        return rightRotate(n);  
  
    // Right Right Case  
    if (balance < -1 && url > n->right->url)  
        return leftRotate(n);  
  
    // Left Right Case  
    if (balance > 1 && url > n->left->url)  
    {  
        n->left = leftRotate(n->left);  
        return rightRotate(n);  
    }  
  
    // Right Left Case  
    if (balance < -1 && url < n->right->url)  
    {  
        n->right = rightRotate(n->right);  
        return leftRotate(n);  
    }  
  
    /* return the (unchanged) node pointer */
    return n;  
}

void printInorder(node * n) { 
    if (n == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(n->left); 
  
    /* then print the data of node */
    cout << n->url << endl; 
  
    /* now recur on right child */
    printInorder(n->right); 
}


// bool insertNode(node * n, keyType url){
//     //cout << "current checking node " << *(node -> getEntry());
//     // Insert to the right 
//     if(url > n -> url){
//         //cout << "entry is larger than node" << *(node -> getEntry()) << endl;
//         if(n -> right == NULL){
//             //cout << "inserting to the right of " << *(node -> getEntry()); 
//             n->right = createNewNode(url);
//             return true;
//         }else{
//             //cout << "keep checking right" << endl;
//             insertNode(n -> right, url);
//         }
//     // Insert to the left subtree
//     }else if(url < n -> url){
//         //cout << "entry is smaller than node" << *(node -> getEntry()) << endl;
//         if(n -> left == NULL){
//            // cout << "inserting to the left of " << *(node -> getEntry()); 
//             n->left = createNewNode(url);
//             return true;
//         }else{
//             //cout << "keep checking left" << endl;
//             insertNode(n -> left, url);
//             //insertNode(node -> getRight(), entry);
//         }
//     }else{
//         //same name, don't insert
//         return false;
//     }
// }

 node * searchTreeByKey (node * n, keyType url){
    if (n == NULL){
        //cout << "empty" << endl;
        return NULL;
    }else if (n -> url == url){
        //cout << "found" << endl;
        return n;
    }else if(n -> url < url){
        //cout << "3" << endl;
        cout << "checking " << n << endl;
        cout << "go right" << endl;
        return searchTreeByKey(n -> right, url);
    }else{
        //cout << "4" << endl;
        cout << "checking " << n << endl;
        cout << "go left" << endl;
        return searchTreeByKey(n -> left, url);
    }
}

node * minValueNode(node* n) {  
    node* current = n;  
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}

node* deleteNode(node* root, keyType url) {  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    // If the key to be deleted is smaller  
    // than the root's key, then it lies 
    // in left subtree  
    if ( url < root->url )  
        root->left = deleteNode(root->left, url);  
  
    // If the key to be deleted is greater  
    // than the root's key, then it lies  
    // in right subtree  
    else if( url > root->url )  
        root->right = deleteNode(root->right, url);  
  
    // if key is same as root's key, then  
    // This is the node to be deleted  
    else
    {  
        // node with only one child or no child  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            node *temp = root->left ?  root->left : root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            free(temp);  
        }  
        else
        {  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            node* temp = minValueNode(root->right);  
  
            // Copy the inorder successor's  
            // data to this node  
            root->url = temp->url;  
  
            // Delete the inorder successor  
            root->right = deleteNode(root->right,  
                                     temp->url);  
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL) return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
} 

ostream & operator << (ostream & out, node * rhs){
    if(rhs == NULL){
        cout << "empty node " << endl;
    }else{
        cout << "Node: " << rhs -> url << endl;
    }
    return out;
}