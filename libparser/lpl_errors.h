#ifndef __LPL_ERRORS_H__
#define __LPL_ERRORS_H__


#define LIBLPL_ERRORS \
 X(LPL_NO_ERROR, "No error.") \
 X(LPL_SYNTAX_ERROR, "Syntax error.") \
 X(LPL_DIVBYZERO_ERROR,"Divide by zero.") \
 X(LPL_INVALIDARGS_ERROR,"Invalid arguments.")


/* Append a NUM_ERRORS enum value to 
   get the number of errors defined
   if necessary
   */
#define X(a,b) a,
 typedef enum {LIBLPL_ERRORS LPL_CUSTOM_ERROR , LPL_NUM_ERRORS} lpl_error_codes;
#undef X


#define X(a,b) b,
static const char* lpl_error_strings[] = {LIBLPL_ERRORS "Unspecified custom error."};
#undef X



#endif