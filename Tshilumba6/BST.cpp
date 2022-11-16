
#include "BST.h"
#include <iostream>
#pragma once
#include<string>
#include <iostream>

using namespace std;


BTS::BTS()
{
    root = NULL;
}

//***********************************
//        
//  This function creates a new node
//  with the words received and call
//  insertNode to add it in the tree
//***********************************
void BTS::insert(TElement element) // wrapper function
{
    // call recursive functiion
        insert(root, newNode);
}


//***************************************
//       Function Insert
//  This function insert a word received
//  as a parameter in the tree
//***************************************
void BTS::insert(const TElement element, const TNodePtr & tree)
{
    //EMPTY TREE
    TreeNode * newNode = NULL;
    //newNode = new TreeNode;

    newNode->word = value;
    newNode->left = NULL ;
    newNode->right = NULL;
    
    if(!tree){
        nodePtr = newNode;
    }
    else
    {
        // go right to left regardelss of your value
        if(newNode->word < tree->word)
            insert(tree->left,newNode);
        else
            insert(tree->right, newNode);
    }
}

//******************************************************
// This function look for items in the tree and report
//     if it is present or not also the number
//       of nodes searched to look for it
//     return the word if find and null if not
//******************************************************
TNodePtr BTS::search(TElement element)
{
    TNodePtr * nodePtr = NULL;
    //call the recursive function to find node
    // and return it address or nullptr
    nodePtr = search(item, root);

    return nodePtr;
}

//***************************************
//       Function search
//  This function search in the tree
//  if the file exist or not returns NULL
//  if empty and that node if it is not
//***************************************
TNodePtr BTS::search(TElement element, TNodePtr tree)
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
        if (element < nodePtr->word)
        {
            count++;
            return(search(element, nodePtr->left));
         //   i++;
        }
            else if(element > nodePtr->word)
            {
            return(search(element, nodePtr->right));
           // i++;
            }
    }
    return nodePtr;
}

//********************************
// This function display a sorted
//   listing words of the tree
//********************************
void BTS::preView() // wrapper function
{
    preView(root);
}


//********************************
//    Function DisplayInOrder
//     This function display
//       the tree in order
//********************************
void BTS::preView(TNodePtr tree) const
{

    if(tree)
    {
        cout<<tree->word<<endl;
        preView(tree->left);
        preView(tree->right);
    }
    else
        return;
}


//********************************
// This function display a sorted
//   listing words of the tree
//********************************
void BTS::inView() // wrapper function
{
    inView(root);
}

//********************************
//    Function DisplayInOrder
//     This function display
//       the tree in order
//********************************
void BTS::inView(TNodePtr tree) const
{

    if(tree)
    {
        inView(tree->left);
        cout<<tree->word<<endl;
        inView(tree->right);
    }
    else
        return;
}



//********************************
// This function display a sorted
//   listing words of the tree
//********************************
void BTS::postView() // wrapper function
{
    postView(root);
}


//********************************
//    Function DisplayInOrder
//     This function display
//       the tree in order
//********************************
void BTS::postView(TNodePtr tree) const
{

    if(tree)
    {
        postView(tree->left);
        postView(tree->right);
        cout<<tree->word<<endl;
    }
    else
        return;
}


//************************************
//      Function DeleteNode
//  Wrapper function that calls
//  removesNode and send the root and
//  the word received
//************************************
void BTS::remove(TElement elemenet) //wrapper function
{
    removeNode(element,root);
}

//************************************
//      Function RemoveNode
//  This function remove one node from
//  the tree with the word received as
//  a parameter
//************************************
void BTS::remove(TElement element,TNodePtr & tree)
{


    if(!nodePtr)
    {
        return;
    }
    // find the word you want to delete
    else if(element < nodePtr->word)
    {
        //look left
        remove(element, nodePtr->left);
    }
    else if (element > nodePtr->word)
    {
        //look right
        remove(element, nodePtr->right);
    } // ends here

    else
    {
        removeNode(tree)
    }
}



//*************************************
//       Function EmptyTree
//  deletes all the nodes of the tree
//*************************************
void BTS::removeNode(TNodePTr & tree)
{
    TreeNode * newNode = NULL;
    if(nodePtr->left != NULL && nodePtr->right != NULL)
    {
       // nodes with two leaves
            nodePtr->word = (nodePtr->right)->word; // find the smalest value in the right subtree to our node
            removeNode(nodePtr->word, nodePtr->right); // delete the node that
    }
    else
        {
            
            TreeNode * prevNode = nodePtr ;
            findMinNode(tree, preNode)

        }
}





//*************************************
//       Function EmptyTree
//  deletes all the nodes of the tree
//*************************************
void BTS::findMinNode(TNodePtr & nodePtr, TNodePtr & prevNode);
{
    if(nodePtr->left != NULL)
        nodePtr = nodePtr->left;
    else
        nodePtr = nodePtr->right;
    delete prevNode;
}


//*************************************
//       Function EmptyTree
//  deletes all the nodes of the tree
//*************************************
void BTS::emptyTree()
{
    destroy(root);
}

//***********************************
//      Function Destroy
// deletes the every node one by one
//***********************************
void BTS::destroy(TreeNode*& nodePtr)
{
    if (nodePtr != NULL)
    {
        destroy(nodePtr->left);
        destroy(nodePtr->right);
        delete nodePtr;
    }
}

//***********************************
//          Destructor
//  It deletes the whole tree
//***********************************
BTS::~BTS()
{
    //dtor
    destroy(root);
}
