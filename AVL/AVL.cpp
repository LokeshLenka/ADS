// Demonstration of AVL Tree

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
};

typedef struct node *nodeptr;

nodeptr root = NULL;

nodeptr create(int);
nodeptr insert(nodeptr,int);
nodeptr del(nodeptr,int);
nodeptr search(nodeptr,int);
nodeptr rotateLeft(nodeptr);
nodeptr rotateRight(nodeptr);
int balanceFactor(nodeptr);
int height(nodeptr);
void inOrder(nodeptr);
void preOrder(nodeptr);
void postOrder(nodeptr);
//int[] lhtrht(nodeptr);

int main(){
	
	int choice,data;
	nodeptr result = NULL;
	
	while(true){
		
		printf("\n__________AVL TREE ________________");
		printf("\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit");
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
		
		switch(choice){
			
			case 1: printf("\nEnter data to be inserted : ");
					scanf("%d",&data);
					
					root = insert(root,data);
					preOrder(root);
					break;
					
			case 2: printf("\nEnter data to be deleted : ");
					scanf("%d",&data);
					
					root = del(root,data);
					preOrder(root);
					break;
					
			case 3: printf("\nEnter data to be searched : ");
					scanf("%d",&data);
					
					result = search(root,data);
					
					if(result != NULL){
						printf("\n Node is found");
					}
					else{
						printf("\nNode is not found");
					}
					break;
					
			case 4: inOrder(root);
					break;
				
			case 5: preOrder(root);
					break;
					
			case 6: postOrder(root);
					break;
					
			case 7: exit(0);
		}
	}
	return 0;
}


// creates a new node
nodeptr create(int data){
	
	nodeptr newnode = (nodeptr)malloc(sizeof(struct node));
	
	newnode->data = data;
	newnode->height = 0;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

nodeptr rotateRight(nodeptr root){
	
	nodeptr lChild;
	lChild = root->left;
	root->left = lChild->right;
	lChild->right = root;
	
	root->height = height(root);
	lChild->height = height(lChild);
	
	return lChild;
	
}

nodeptr rotateLeft(nodeptr root){
	
	nodeptr rChild;
	rChild = root->right;
	root->right = rChild->left;
	rChild->left = root;
	
	root->height = height(root);
	rChild->height = height(rChild);
	
	return rChild;

}

int balanceFactor(nodeptr root){
	
	int lht,rht;
	 
	if(root == NULL){
		return NULL;
	}
	
	if(root->left == NULL){
		lht = 0;
	}
	else{
		lht = 1 + root->left->height;
	}
	
	if(root->right == NULL){
		rht = 0;
	}
	else{
		rht = 1 + root->right->height;
	}
	
	return lht > rht ? lht : rht;
}

int height(nodeptr root){
	
	int lht,rht;
	 
	if(root == NULL){
		return NULL;
	}
	
	if(root->left == NULL){
		lht = 0;
	}
	else{
		lht = 1 + root->left->height;
	}
	
	if(root->right == NULL){
		rht = 0;
	}
	else{
		rht = 1 + root->right->height;
	}
	
	return lht-rht;
}
	
//int[] lhtrht(nodeptr root){
//	
//	int lht,rht;
//	int arr[];
//	 
//	if(root == NULL){
//		return;
//	}
//	
//	if(root->left == NULL){
//		lht = 0;
//	}
//	else{
//		lht = 1 + root->left->height;
//	}
//	
//	if(root->right == NULL){
//		rht = 0;
//	}
//	else{
//		rht = 1 + root->right->height;
//	}
//	
//	arr[0] = lht;
//	arr[1] = rht;
//	
//	return arr;
//}
//	

nodeptr insert(nodeptr root,int data){
	
	if(root == NULL){
		
		nodeptr newnode;
		newnode = create(data);
		
		if(newnode == NULL){
			return NULL;
		}
		
	return newnode;
	
	}
	
	else if(data > root->data){
		
		root->right = insert(root->right,data);
		
		if(balanceFactor(root) == -2){
			
			if(data > root->right->data){
				
				root = rotateLeft(root);
			}
			
			else{
				
				root->right = rotateRight(root->right);
				root = rotateLeft(root);
				
			}
		}
	}
	
	else{
		
		root->left = insert(root->left,data);
		
		if(balanceFactor(root) == 2){
			
			if(data < root->left->data){
				
				root = rotateRight(root);
				
			}
			
			else{
				
				root->left = rotateLeft(root->left);
				root = rotateRight(root);
		
			}
		}
	}
	
	root->height = height(root);
	return root;
	
}

nodeptr del(nodeptr root,int x){
	
	nodeptr temp;
	temp = NULL;
	
	if(root == NULL){
		return NULL;
	}
	
	if(x > root->data){
		
		root->right = del(root->right,x);
		
		if(balanceFactor(root) == 2){
			
			if(balanceFactor(root->left) >= 0)
				root = rotateRight(root);
			else{
				root->left = rotateLeft(root->left);
				root = rotateRight(root);
			}
		}
	}
	
	else if(x < root->data){
		
		root->left = del(root->left,x);
		
		if(balanceFactor(root) == - 2){
			
			if(balanceFactor(root->right) <= 0)
				root = rotateLeft(root);
			else{
				
				root->right = rotateRight(root->right);
				root = rotateLeft(root);
			}
		}
	}
	
	else{
	
		if(root->right != NULL){
			
			temp = root->right;
			
			while(temp->left != NULL){
				temp = temp->left;
			}
			
			root->data = temp->data;
			root->right = del(root->right,temp->data);
			
			if(balanceFactor(root) == 2){
				
				if(balanceFactor(root->left) >= 0)
					root = rotateRight(root);
					
				else{
					root->left = rotateLeft(root->left);
					root = rotateRight(root);
				}
			}
		}
		else{
			return root->left;
		}
	}
	
	root->height = height(root);
	return root;
}

// search the given key node in BST
nodeptr search(nodeptr,int key){
	
	if(root == NULL)
		return NULL;
		
	if(root->data == key)
		return root;
		
	else{	
	
		if(key > root->data)
			search(root->right,key);
			
		else if(key < root->data)
			search(root->left,key);
			
	}
	
	return NULL;
}

// inorder traversal of the BST
void inOrder(nodeptr root)
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
void preOrder(nodeptr root)
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
void postOrder(nodeptr root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
	



