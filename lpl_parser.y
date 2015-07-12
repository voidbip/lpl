%left ADD SUB.
%left MULT DIV.

%token_type {const char*}

%include
{
  #include <stdio.h>
  #include <stdlib.h>
  #include <assert.h>
  #include <string.h>
  #include "node.h"
}

%syntax_error
{
  result->type = terror;
}

%type expr {node*}
%type start {node*}
%extra_argument {node *result}


start ::= expr(B) . 
    {
      node *temp;
      memcpy(result,temp=evalNode(B),sizeof(node));
      free(temp);
      freeNode(B);
    }


/* Assignment */
expr(A) ::= NUMBER(B). {A = newNode(B,tint,NULL,NULL);}
expr(A) ::= FLOAT(B).  {A = newNode(B,tdouble,NULL,NULL);} 
/* End Assignment */

/* All productions with an expression on the LHS need to be revisited. we are
not setting the node type correctly. We should automatically promote from the
leaf nodes. */

expr(C) ::= expr(A) ADD expr(B). {C = newNode("+",top,A,B);} 
expr(C) ::= expr(A) SUB expr(B). {C = newNode("-",top,A,B);} 
expr(C) ::= expr(A) DIV expr(B). {C = newNode("/",top,A,B);} 
expr(C) ::= expr(A) MULT expr(B). {C = newNode("*",top,A,B);} 

