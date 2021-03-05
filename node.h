#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {

  public: 
    Node<T> *next;
    Node *left;
    Node *right
    T object;  
    Node<T>( T = T() ); 
}; // Node<T> class

template <typename T>
Node<T>::Node( T data )
{
  this->object = data;
  this->next = nullptr;//
  this->left = nullptr;//maybe wrongg??
  this->right = nullptr;//
} // Node<T>::Node

#endif