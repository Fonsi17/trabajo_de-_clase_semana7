#ifndef SYMBOLS_H
#define SYMBOLS_H

typedef  enum {
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_BOOL
} DataType;



typedef struct SymbolEntry {
  DataType data_type;
  char* identifier;
  int needs_free;
  union {
    int i_value;
    int b_value;
    double d_value;
    char c_value;
    char* s_value;
  }data;

  struct SymbolEntry* next; //Pointer to next extry

} SymbolEntry;


//Prototipos
SymbolEntry* create_entry(char *name);
SymbolEntry* find_entry(char* name);


#endif // SYMBOLS_H
