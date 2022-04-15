/**
Header file for data structure Node
@file: node.h
@author: Justin Too
Date created: 2/28/2021
*/

#ifndef NODE_H
#define NODE_H

template <class T>
class Node{
public:
  T data;
  Node<T>* next;

  Node(T d){
    data = d;
    next = nullptr;
  }
};
#endif
