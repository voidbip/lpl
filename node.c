#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initNode(node **p){
  if((*p = (node *) malloc(sizeof(node)))==NULL){
    return(1);
  }
  (*p)->l = NULL;
  (*p)->r = NULL;
  (*p)->type = tnull;
  return(0);
}

node* newNode(const char *str,types type, node* l, node* r){
  node *n;
  initNode(&n);

  n->l = l;
  n->r = r;
  n->type = type;

  switch(n->type){
    case top:
      if(0==strcmp("+",str)){
        n->value.op = add;
         printf("  created add node.\n");
      }
      else if(0==strcmp("-",str)){
        n->value.op = minus;
         printf("  created minus node.\n");
      }
      else if(0==strcmp("*",str)){
        n->value.op = mult;
         printf("  created mult node.\n");
      }
      else if(0==strcmp("/",str)){
        n->value.op = odiv;
         printf("  created mult node.\n");
      }
    break;
    case tint:
      n->value.i = atoi(str);
    break;
    case tdouble:
      n->value.d = atof(str);
    break;
    default:
      printf("error creating node.");
  }

  return n;
}

int freeNode(node *n){
  if(n->l != NULL)
    freeNode(n->l);
  if(n->r != NULL)
    freeNode(n->r);
  free(n);
}

void printNode(node* n){
  switch(n->type){
    case top:
      switch(n->value.op){
        case add:
          printNode(n->l);
          printf("+");
          printNode(n->r);
        break;
        case minus:
          printNode(n->l);
          printf("-");
          printNode(n->r);
        break;
        case mult:
          printNode(n->l);
          printf("*");
          printNode(n->r);
        break;
        case odiv:
          printNode(n->l);
          printf("/");
          printNode(n->r);
        break;
        default:
          printf("Error evaluating expression.");
      }
    break;
    case tint:
        printf("%d",n->value.i);
    break;
    case tdouble:
        printf("%f",n->value.d);
    break;
    case terror:
        printf("Something bad happened.\n");
    break;
    default:
      printf("Bad!");
  }
}

node* _add(const node* l, const node* r){
  node *out;
  initNode(&out);
  switch(l->type){
    case tint:
      switch(r->type){
        case tint:
          out->type = tint;
          out->value.i = l->value.i+r->value.i;
        break;
        case tdouble:
          out->type = tdouble;
          out->value.d = l->value.i+r->value.d;
        break;
        default:
          out->type=terror;
        break;

      }
    break;
    case tdouble:
      switch(r->type){
        case tint:
          out->type = tdouble;
          out->value.d = l->value.d+r->value.i;
        break;
        case tdouble:
          out->type = tdouble;
          out->value.d = l->value.d+r->value.d;
        break;
        default:
          out->type=terror;
        break;

      }
    break;
  }
  return(out);
}

node* _minus(const node* l, const node* r){
  node *out;
  initNode(&out);
  switch(l->type){
    case tint:
      switch(r->type){
        case tint:
          out->type = tint;
          out->value.i = l->value.i-r->value.i;
        break;
        case tdouble:
          out->type = tdouble;
          out->value.d = l->value.i-r->value.d;
        break;
        default:
          out->type=terror;
        break;

      }
    break;
    case tdouble:
      switch(r->type){
        case tint:
          out->type = tdouble;
          out->value.d = l->value.d-r->value.i;
        break;
        case tdouble:
          out->type = tdouble;
          out->value.d = l->value.d-r->value.d;
        break;
        default:
          out->type=terror;
        break;

      }
    break;
  }
  return(out);
}


node* _mult(const node* l, const node* r){
  node *out;
  initNode(&out);
  switch(l->type){
    case tint:
      switch(r->type){
        case tint:
          out->type = tint;
          out->value.i = l->value.i*r->value.i;
        break;
        case tdouble:
          out->type = tdouble;
          out->value.d = l->value.i*r->value.d;
        break;
        default:
          out->type=terror;
        break;

      }
    break;
    case tdouble:
      switch(r->type){
        case tint:
          out->type = tdouble;
          out->value.d = l->value.d*r->value.i;
        break;
        case tdouble:
          out->type = tdouble;
          out->value.d = l->value.d*r->value.d;
        break;
        default:
          out->type=terror;
        break;

      }
    break;
  }
  return(out);
}


node* _div(const node* l, const node* r){
  node *out;
  initNode(&out);
  switch(l->type){
    case tint:
      switch(r->type){
        case tint:
          out->type = tint;
          out->value.i = l->value.i/r->value.i;
        break;
        case tdouble:
          out->type = tdouble;
          out->value.d = l->value.i/r->value.d;
        break;
        default:
          out->type=terror;
        break;

      }
    break;
    case tdouble:
      switch(r->type){
        case tint:
          out->type = tdouble;
          out->value.d = l->value.d/r->value.i;
        break;
        case tdouble:
          out->type = tdouble;
          out->value.d = l->value.d/r->value.d;
        break;
        default:
          out->type=terror;
        break;

      }
    break;
  }
  return(out);
}


node* evalNode(const node* n){
  node *out,*l,*r;
  switch(n->type){
    case top:
      switch(n->value.op){
        case add:
           printf("Evaluating add.\n");
          out = _add(l=evalNode(n->l),r=evalNode(n->r));
          freeNode(l);
          freeNode(r);
        break;
        case minus:
           printf("Evaluating minus.\n");
          out = _minus(l=evalNode(n->l),r=evalNode(n->r));
          freeNode(l);
          freeNode(r);
        break;
        case mult:
           printf("Evaluating mult.\n");
          out = _mult(l=evalNode(n->l),r=evalNode(n->r));
          freeNode(l);
          freeNode(r);
        break;
        case odiv:
           printf("Evaluating div.\n");
          out = _div(l=evalNode(n->l),r=evalNode(n->r));
          freeNode(l);
          freeNode(r);
        break;
        default:
          printf("Error evaluating expression.");
      }
    break;
    case tint:
       printf("Evaluating int.\n");
      initNode(&out);
      memcpy(out,n,sizeof(node));
    break;
    case tdouble:
       printf("Evaluating double.\n");
      initNode(&out);
      memcpy(out,n,sizeof(node));
    break;
    default:
      printf("Bad!");
  }
  return out;

}