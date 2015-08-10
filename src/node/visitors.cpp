#include "node.h"
#include "visitors.h"

void evalVisitor::visit(Node *_elm){dbg("Visited a generic."<<std::endl);}
void evalVisitor::visit(doubleNode *_elm){dbg("Visited a double."<<std::endl); S.push(_elm);}
void evalVisitor::visit(intNode *_elm){dbg("Visited a int."<<std::endl); S.push(_elm);}
void evalVisitor::visit(addNode *_elm){
  dbg("Visit addNode." << std::endl);
  Node *l, *r;
  l = S.top();
  l->identify();
  S.pop();

  r = S.top();
  r->identify();
  S.pop();

  S.push((*l)+(*r));
}


void evalVisitor::visit(subNode *_elm){
  dbg("Visit subNode." << std::endl);
  Node *l, *r;
  l = S.top();
  l->identify();
  S.pop();

  r = S.top();
  r->identify();
  S.pop();

  S.push((*l)-(*r));
}

void evalVisitor::visit(divNode *_elm){
  dbg("Visit divNode." << std::endl);
  Node *l, *r;
  l = S.top();
  l->identify();
  S.pop();

  r = S.top();
  r->identify();
  S.pop();

  S.push((*l)/(*r));
}

void evalVisitor::visit(multNode *_elm){
  dbg("Visit multNode." << std::endl);
  Node *l, *r;
  l = S.top();
  l->identify();
  S.pop();

  r = S.top();
  r->identify();
  S.pop();

  S.push((*l)*(*r));
}
