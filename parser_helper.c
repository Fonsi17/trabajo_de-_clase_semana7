#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser_helper.h"
#include "symbols.h"


void assing_numeric_value(SymbolEntry *entry,DataType data_type, double value){
  switch(data_type){
    case TYPE_INT: entry->data.i_value =(int)value; break;
    case TYPE_DOUBLE: entry->data.d_value = (double) value; break;
    case TYPE_CHAR: entry->data.c_value = (char) value; break;
    case TYPE_BOOL: entry->data.b_value = (int) value;break;
    case TYPE_STRING: printf("TYPE ERROR: Cannot assing numeric value to string"); break;
  }
}


void assing_string_value(SymbolEntry *entry, DataType data_type, char* value){
  if (data_type == TYPE_STRING) {
      //reassing
      if (entry->data.s_value) free(entry->data.s_value);

      entry->data.s_value = strdup(value);
      free(value);

  } else {
      printf("Type mismatch: Cannot assign string to non-string variable");
      free(value);
  }


}
