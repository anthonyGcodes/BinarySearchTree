#ifndef TREENODE_H
#define TREENODE_H


template<typename T>
class TreeNode {

  public:
    TreeNode<T>(  const T & = T() );
  
    T object;
    TreeNode<T> *parent;
    TreeNode<T> *leftPtr;
    TreeNode<T> *rightPtr;

}; // TreeNode class

template <typename T>
TreeNode<T>::TreeNode( const T & s)
{
  object = s;
  parent = nullptr;
  leftPtr = nullptr;
  rightPtr = nullptr;
}//

#endif 