#include "symbols.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

//Symbol Table holder
SymbolEntry* root_table= NULL;

SymbolEntry* create_entry(char* name){
  //Asignar en memoria el nodo
  SymbolEntry *node =  (SymbolEntry*) malloc(sizeof(SymbolEntry));

  node->data_type = TYPE_INT;
  node->data.i_value = 0;
  node->identifier = strdup(name);

  //Point next node to the start of the list
  node->next = root_table;

  // set new node  the start of the list
  root_table = node;

  return node;
}

SymbolEntry* find_entry(char* name){
  SymbolEntry *current = root_table;

  while (current != NULL) {
      // Compare the name we found with the name in the current entry
      if (strcmp(current->identifier, name) == 0) {
          return current; // Founds it!
      }
      current = current->next; // Move to the next link
  }
  return NULL; // Not found
}
