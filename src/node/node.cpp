#include "node.h"
#include <iostream>
#include "debug.h"

Node::Node(){dbg("  Node constructor."<<std::endl;);l=NULL;r=NULL;}
Node::~Node(){
  dbg("  Node base destructor."<<std::endl;);
  if(getLeft()!=NULL){
    delete getLeft();
  }
  if(getRight()!=NULL){
    delete getRight();
  }
}
void Node::setLeft(Node *_l){l = _l;}
void Node::setRight(Node *_r){r = _r;}
Node* Node::getLeft(){return l;}
Node* Node::getRight(){return r;}
void Node::identify(){std::cout<<"I am a generic node."<<std::endl;}
Node* Node::operator+(   Node& r)  {
      throw syntaxErrorException();
    }
Node* Node::operator+(  doubleNode& r){
    return r+(*this);
}
 Node* Node::operator+(   intNode& r)  {
    return r+(*this);
}

Node* Node::operator-(   Node& r)  {
      throw syntaxErrorException();
    }
Node* Node::operator-(  doubleNode& r){
    return r-(*this);
}
 Node* Node::operator-(   intNode& r)  {
    return r-(*this);
}

Node* Node::operator/(   Node& r)  {
      throw syntaxErrorException();
    }
Node* Node::operator/(  doubleNode& r){
    return r/(*this);
}
 Node* Node::operator/(   intNode& r)  {
    return r/(*this);
}

Node* Node::operator*(   Node& r)  {
      throw syntaxErrorException();
    }
Node* Node::operator*(  doubleNode& r){
    return r*(*this);
}
 Node* Node::operator*(   intNode& r)  {
    return r*(*this);
}

bool Node::operator==(   Node& r)  {
  dbg("generic node doing generic comparison."<<std::endl;);
  return false; // this should be an error.
}
bool Node::operator==(  doubleNode& r){
    dbg("generic node doing double comparison."<<std::endl;);
    return r==(*this);
}
bool Node::operator==(   intNode& r)  {
    return r==(*this);
}
