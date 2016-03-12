#include <stdlib.h>
#include <stdio.h>
#include "../node.h"
#include "../lpl_errors.h"
#include "../debug.h"

col_error eval_vivi_add(node **output, const node *l, const node *r){
  unsigned int llength , rlength;
  int value;

  col_int_length(l->value.vector_int,&llength);
  col_int_length(r->value.vector_int,&rlength);

  dbg("Called col_vivi_add lengths: %d %d\n",llength,rlength);



  if(rlength==1 || llength==1){
    if(rlength==llength){
      (*output)->type = vector_int_node;
      col_int_init_scalar(&(*output)->value.vector_int,value);
      return LPL_NO_ERROR;
    }
  }
  else if(rlength==llength){

  }
  else{
  }
  
  _error(output,LPL_NOTIMPLEMENTED_ERROR);
  return LPL_NOTIMPLEMENTED_ERROR;
}
col_error eval_vivd_add(node **output, const node *l, const node *r){
  _error(output,LPL_NOTIMPLEMENTED_ERROR);
  return LPL_NOTIMPLEMENTED_ERROR;
}
col_error eval_vdvi_add(node **output, const node *l, const node *r){
  _error(output,LPL_NOTIMPLEMENTED_ERROR);
  return LPL_NOTIMPLEMENTED_ERROR;
}
col_error eval_vdvd_add(node **output, const node *l, const node *r){
  _error(output,LPL_NOTIMPLEMENTED_ERROR);
  return LPL_NOTIMPLEMENTED_ERROR;
}
