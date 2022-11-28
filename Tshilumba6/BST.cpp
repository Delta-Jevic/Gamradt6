#include "BST.h"
#include <iostream>
#include <string>

using namespace std;


BST::BST()
{
    root = NULL;
}

//***********************************
//        
//  This function creates a new node
//  with the words received and call
//  insertNode to add it in the tree
//***********************************
void BST::insert(TElement element) // wrapper function
{
    // call recursive functiion
    insert( element, root);
}


//***************************************
//       Function Insert
//  This function insert a word received
//  as a parameter in the tree
//***************************************
void BST::insert(const TElement val, TNodePtr & tree)
{
	
	if (tree == nullptr)
	{
		tree = new (nothrow) TNode;
		if(tree == nullptr)
		{
			cout << "Memory Full" << endl;
			return;
		}
		tree->element = val;
		tree->left = nullptr;
		tree->right = nullptr;
		return;
	}


	if (val < tree->element)
		insert(val,tree->left);
	else if (val > tree->element)
		insert(val, tree->right);
	
	return;
}

//******************************************************
// This function look for items in the tree and report
//     if it is present or not also the number
//       of nodes searched to look for it
//     return the word if find and null if not
//******************************************************
TNodePtr BST::search( const TElement element, const TNodePtr tree)const
{
    TNodePtr newNode ;
    newNode = new TNode();


    //call the recursive function to find node
    // and return it address or nullptr
    newNode = search(element, root);

    return newNode;
}

//***************************************
//       Function search
//  This function search in the tree
//  if the file exist or not returns NULL
//  if empty and that node if it is not
//***************************************
TNodePtr search(const TElement element, const TNodePtr tree) 
{
    //EMPTY TREE
    TNodePtr * nodePtr = NULL;
    if(!tree)
    {
        cout<<"The tree is empty"<<endl;
        return(NULL);
    }
    else
        // go right to left, depending on your item
        // until you find a value that equal your item
    {
        if (element < tree->element)
        {
            return(search(element, tree->left));
         //   i++;
        }
            else if(element > tree->element)
            {
            return(search(element, tree->right));
           // i++;
            }
    }
    return tree;
}

//********************************
// This function display a sorted
//   listing words of the tree
//********************************
void BST::preView()const // wrapper function
{
    preView(root);
}


//********************************
//    Function DisplayInOrder
//     This function display
//       the tree in order
//********************************
void BST::preView( const TNodePtr tree)const 
{
    if(tree)
    {
        cout<<tree->element<<" -> ";
        preView(tree->left);
        preView(tree->right);
    }
}



//********************************
// This function display a sorted
//   listing words of the tree
//********************************
void BST::inView() const // wrapper function
{
    inView(root);
}

//********************************
//    Function DisplayInOrder
//     This function display
//       the tree in order
//********************************
void BST::inView(const TNodePtr tree) const
{
    if(tree == nullptr)
        return;
    
    else
    {
        if(tree != nullptr)
        {
            inView(tree->left);
            cout<<tree->element<<" -> ";
            inView(tree->right);
        }
    }
}



//********************************
// This function display a sorted
//   listing words of the tree
//********************************
void BST::postView()const // wrapper function
{
    postView(root);
}


//********************************
//    Function DisplayInOrder
//     This function display
//       the tree in order
//********************************
void BST::postView(const TNodePtr root) const
{
	if (root != nullptr)
	{
		postView(root->left);
		postView(root->right);
		cout << root->element << " -> ";
	}
}


//************************************
//      Function DeleteNode
//  Wrapper function that calls
//  removesNode and send the root and
//  the word received
//************************************
void BST::remove( const TElement element) //wrapper function
{
    remove(element,root);
}

//************************************
//      Function RemoveNode
//  This function remove one node from
//  the tree with the word received as
//  a parameter
//************************************
void BST::remove( const TElement element,TNodePtr & tree)
{


    if(!tree)
    {
        return;
    }
    // find the word you want to delete
    else if(element < tree->element)
    {
        //look left
        remove(element, tree->left);
    }
    else if (element > tree->element)
    {
        //look right
        remove(element, tree->right);
    } // ends here
    else
    {
        removeNode(tree);
    }
}



//*************************************
//       Function EmptyTree
//  deletes all the nodes of the tree
//*************************************
void BST::removeNode(TNodePtr & tree)
{
    TNodePtr prevNode ;
    prevNode = new TNode();

    if(tree->left != NULL && tree->right != NULL)
    {
        prevNode = tree;
       // nodes with two leaves
        findMinNode(tree->right, prevNode);
        tree->element = prevNode->element; // find the smalest value in the right subtree to our node
        removeNode(tree->right); // delete the node that
        delete tree;
    }
    else if(tree->right == NULL){
        removeNode(tree->left);
        delete tree;
    }
    else if(tree->left == NULL){
        removeNode(tree->right);
        delete tree;
    }
    else{
        delete tree;
    }

}


//*************************************
//       Function EmptyTree
//  deletes all the nodes of the tree
//*************************************
void BST::findMinNode(TNodePtr & nodePtr, TNodePtr & tmpTree)
{
    if(nodePtr->left == NULL)
    {
        tmpTree = nodePtr->right;
        findMinNode( nodePtr->right, tmpTree );
    }
    else
    {
        findMinNode( nodePtr->left, tmpTree);
    }
        
    
}


//***********************************
//      Function Destroy
// deletes the every node one by one
//***********************************
void BST::destroy(TNodePtr & tPtr)
{
	if (tPtr != nullptr)
	{
		destroy(tPtr->left);
		destroy(tPtr->right);
		delete tPtr;
		tPtr = nullptr;
	}
}

//***********************************
//          Destructor6
//  It deletes the whole tree
//***********************************
BST::~BST()
{
    //dtor
    destroy(root);
}
