#ifndef PARSER_HELPER_H
#define PARSER_HELPER_H
#include "symbols.h"


void assing_numeric_value(SymbolEntry *entry, DataType data_type, double value);
void assing_string_value(SymbolEntry *entry, DataType data_type, char* value);

#endif
