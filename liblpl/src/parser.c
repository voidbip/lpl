#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "debug.h"
int parse(FILE *fp, Queue **result){
  yyscan_t scanner;
  int tok_len;
  char *tok;
  YY_BUFFER_STATE bufferState;
  void* shellParser;
  int lexCode;

  //initDyadicNode(result,NULL,NULL,scalar_null_node);

  yylex_init(&scanner);

  bufferState = yy_create_buffer(fp,YY_BUF_SIZE, scanner);
  yy_switch_to_buffer(bufferState,scanner);

  /*  Set up the parser */
  shellParser = ParseAlloc(malloc);

  //result = (Queue **) malloc(sizeof(Queue *));

  *result = queue_new();

  do {

      lexCode = yylex(scanner);
      tok = strndup(yyget_text(scanner),tok_len=yyget_leng(scanner));

      dbg("Got Token: %s Token length: %d, Lex code: %d \n",tok,tok_len,lexCode);

      Parse(shellParser, lexCode, tok, *result);

  }
  while ( lexCode > 0 );

  if (-1 == lexCode) {
    fprintf(stderr,"The scanner encountered an error.\n");
  }

  /*  Cleanup the scanner and parser */
  yy_delete_buffer(bufferState, scanner);
  yylex_destroy(scanner);
  ParseFree(shellParser, free);
  free(tok);
  return 0;
}
