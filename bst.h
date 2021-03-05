#include "treenode.h"
#include <iostream>

using namespace std;

//BST class
template <typename T>
class BST{
  public:
        BST();// constructor     
        //~BST(); // destractor
        void insert(T);        
        void search(T);     
        void remove (T);   
        TreeNode<T>* removeMin(TreeNode<T>*, TreeNode<T>*);
        void display();

        int traversalCount;

 private:
        int countNode; 
        TreeNode<T>* root;
        void display(TreeNode<T>* );  
        void insert(TreeNode<T>*, T&);   
        bool search (TreeNode<T>* tNode,T &) ; 
        void remove (TreeNode<T>*&, T & );
};

//constructor
template <typename T>
BST<T>::BST()
{
        root = nullptr;
        traversalCount = 0;
        countNode = 0;
}

//private insert
template <typename T>
void BST<T>::insert(TreeNode<T>* tNode, T& data)
{
        if(tNode == nullptr)
        {
         TreeNode<T> *tTemp = new TreeNode<T>(data);  
         tNode = tTemp;
                if(countNode == 0)
                {
                        root = tTemp;
                }//if               
        traversalCount++;
        countNode++;
        }//if
        if (data < tNode->object)// if value is < key
        {       //left subtree
                if (!tNode->leftPtr) //move to left subtree
                {
                        TreeNode<T> *tTemp = new TreeNode<T>(data);
                        tNode->leftPtr = tTemp;
                        traversalCount++;
                }//if
                else{
                        traversalCount++;
                        insert(tNode->leftPtr,data);
                }//else
        }//if
        else if (data > tNode->object)
        {        
                //right subtree
                if (!tNode->rightPtr)
                {
                        TreeNode<T> *tTemp = new TreeNode<T>(data);                         
                        tNode->rightPtr = tTemp;
                        traversalCount++;
                }//if
                else{
                        traversalCount++;
                        insert(tNode->rightPtr, data); 
                }//else
        }//else
}//insert
 
//public insert
template <typename T>
void BST<T>::insert(T key)
{
        insert(root,key);
}//public insert

//private searchs
template <typename T>
bool BST<T>::search(TreeNode<T>* tNode, T& key)
{
        TreeNode<T>* current = root; 
        //traverse the entire tree
        while(current != nullptr)
        {
                //right subtree
                if (key > current->object)
                {
                        current = current->rightPtr;//advance ptr
                        traversalCount++;
                }//if
                else if (key < current->object)
                {
                        current = current->leftPtr;//advance ptr
                        traversalCount++;
                }//else if
                else if (key == current->object) {
                        return true; //key found
                }//else
        }//while
        return false;//not found
}//search

//public search
template <typename T>
void BST<T>::search(T key)
{
        search(root,key);
}//public search

//private remove
template <typename T>
void BST<T>::remove(TreeNode<T>*&root, T &key )//recursive implementation
{
        //move down find the item, check to find # of children based on right and left children.
        //if 0 children delete it, 1 child update its parent, child ptr, if 2 call the helper function.
        if (root != nullptr)
        {
                if(root->object < key) //move to right subtree
                {
                   traversalCount++;
                   remove(root->rightPtr,key);
                }//if
                else if(root->object > key)//move to left subtree
                {
                  traversalCount++;
                  remove(root->leftPtr, key);       
                }//else
                else if(root->leftPtr != nullptr && root->rightPtr != nullptr) //case of 2 children
                {
                        //remove min of right subtree and copy its value into root
                        traversalCount++;
                        TreeNode<T>* minRStree = removeMin(root,root->rightPtr);
                        root->object = minRStree->object; //copy data
                        delete minRStree;
                }//else if
                else {// node to remove (root) only has 0 or 1 child.
                TreeNode<T>* trash = root;
                        if(root->leftPtr != nullptr)
                        {
                                traversalCount++;
                                root = root->leftPtr;
                        }//if
                        else if(root->rightPtr != nullptr)
                        {
                                traversalCount++;
                                root = root->rightPtr;
                        }//else
                delete trash;
                }//else
        }//if
}//remove

//public remove
template <typename T>
void BST<T>::remove(T key)
{
        remove(root,key);
}//public remove

//removeMin
template <typename T>
TreeNode<T>* BST<T>::removeMin(TreeNode<T>* parent, TreeNode<T>* node)
{
        
        if(node != nullptr) 
        {
                if (node->leftPtr == nullptr) //min value found
                {
                        parent->leftPtr = node->rightPtr;
                        traversalCount++;
                        return node;
                }//if
                else 
                { // recursively move to most left child in righ subtree
                        traversalCount++;
                        return removeMin(node,node->leftPtr);
                }//else
        }//if
        else
        {
           
        }//else
        return node;
}//removeMin 

//public display
template <typename T>
void BST<T>::display()
{
        display(root);
        cout << endl;
}//display

//private
template <typename T>
void BST<T>::display(TreeNode<T>* root)
{
        //TreeNode<T>* current = root;
        cout << "[" ;
        if (root != nullptr)
        {
                cout << root->object << " ";  

                if(root->leftPtr!= nullptr && root->rightPtr == nullptr)
                {
                        display(root->leftPtr);
                }//if
                else if(root->leftPtr== nullptr && root->rightPtr != nullptr)
                {
                        display(root->rightPtr);
                }//if
                else if(root->leftPtr != nullptr && root->rightPtr != nullptr)              
                {
                         display(root->leftPtr);
                         display(root->rightPtr);
                }//if
                else cout << "" ;
        }//if
        cout << "]" ;
}//display


