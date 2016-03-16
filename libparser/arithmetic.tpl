#include <stdlib.h>
#include "node.h"
#include "lpl_errors.h"

@includes

@start_block
node* eval_@op_node(const node* l, const node* r, Trie *scope){
  TrieValue  sym_val;
  node *out;
  int result;
  col_error e;
  if( lpl_is_error_node(l)) {out = _copy_error(l); return out;}
  if( lpl_is_error_node(r)) {out = _copy_error(r); return out;}

  initNode(&out, NULL, NULL, scalar_null_node);

  if(result=lpl_expand_node(l,&l,scope)){
    lpl_make_error_node(out,result,NULL);
    return out;
  }
  if(result=lpl_expand_node(r,&r,scope)){
    lpl_make_error_node(out,result,NULL);
    return out;
  }

  @switch_statement

  return(out);
}
@end_block