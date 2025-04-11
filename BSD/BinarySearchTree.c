#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *nodeptr;

//Globally initilazed root pointer
nodeptr root = NULL;

//Function Prototyping 
nodeptr createNode(int);
nodeptr insertNode(nodeptr,int);
nodeptr del(nodeptr,int);
int search(int);
void inOrder(nodeptr);
void postOrder(nodeptr);
void preOrder(nodeptr);
nodeptr smallestNode(nodeptr);
nodeptr largestNode(nodeptr);
int setData();


int main(){
    int ch;
    int data;
    nodeptr result = NULL;

    while(true){
        printf("\n\n______________________ Binary Search Tree ______________________\n");
        printf("\n 1.Insert Elements");
        printf("\n 2.Delete Element");
        printf("\n 3.Search Element");
        printf("\n 4.Get Largest Node");
        printf("\n 5.Get Smallest Node");
        printf("\n\n______________ Traversals ______________\n");
        printf("\n 6.In Order");
        printf("\n 7.Post Order");
        printf("\n 8.Pre Order");
        printf("\n 9.Exit");

        printf("\n\n Enter Choice : ");
        scanf("%d",&ch);
        printf("\n");

        switch(ch){
            case 1: data = setData();
                    root = insertNode(root,data);
                    break;
                
            case 2: data = setData();
                    root = del(root,data);
                    break;

            case 3: data = setData();
                    if(search(data) == 1)
                        printf("\n Data was found.");
                    else
                        printf("\n Data does not found!");
                    break;
            
            case 4: result = largestNode(root);
                    if(result != NULL){
                        printf("\n Largest Data : %d",result->data);
                    }
                    break;
            
            case 5: result = smallestNode(root);
                    if(result != NULL){
                        printf("\n Smallest Data : %d",result->data);
                    }
                    break;
            
            case 6: inOrder(root);
                    break;
            
            case 7: postOrder(root);
                    break;
                
            case 8: preOrder(root);
                    break;

            case 9: exit(0);
                    break;
        }
    }
    return 0;
}


// Creates a New node
nodeptr createNode(int data){
    
    nodeptr newNode = (nodeptr)malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("\n Memory for new node can't be allocated");
        return NULL;
    }

    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;

}

//Inserts the data in the BST
nodeptr insertNode(nodeptr root,int data){

    nodeptr newNode = createNode(data);

    if(root == NULL){
        root = newNode;
        printf("\n Node having data %d was inserted",data);
        return root;
    }

    if(data < root->data){
        root->left = insertNode(root->left,data);
    }

    else if(data > root->data){
        root->right = insertNode(root->right,data);
    }

    printf("\n Node having data %d was inserted",data);
    return root;

}


// Deletes the given key node from the BST
nodeptr del(nodeptr root,int key){

    if(root == NULL){
        return root;
    }

    if(key < root->data){
        root->left = del(root->left,key);
    }

    else if(key > root->data){
        root->right = del(root->right,key);
    }

    else{

        if(root->left == NULL){
            
            nodeptr temp = root->right;
            free(root);
            return temp;

        }

        else if(root->right == NULL){

            nodeptr temp = root->left;
            free(root);
            return temp;

        }

        nodeptr temp = smallestNode(root->right);
        root->data = temp->data;
        root->right = del(root->right,temp->data);
    }

    return root;
}

// search the given key node in BST
int search(int key)
{
    nodeptr temp = root;
 
    while (temp != NULL)
    {
        if (key == temp->data)
        {
            return 1;
        }
        else if (key > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return 0;
}
 
// finds the node with the smallest value in BST
nodeptr smallestNode(nodeptr root)
{
    nodeptr curr = root;
    while (curr != NULL && curr->left != NULL)
   {
        curr = curr->left;
    }
    return curr;
}
 
// finds the node with the largest value in BST
nodeptr largestNode(struct node *root)
{
    nodeptr curr = root;
    while (curr != NULL && curr->right != NULL)
    {
        curr =  curr->right;
    }
    return curr;
}
 
// inorder traversal of the BST
void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ",  root->data);
    inOrder(root->right);
}
 
// preorder traversal of the BST
void preOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
 
// postorder travsersal of the BST
void postOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
 
// getting data from the user
int setData()
{
    int data;
    printf("\nEnter Data: ");
    scanf("%d", &data);
    return data;
}




