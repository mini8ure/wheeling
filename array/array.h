#ifndef mini_array_h
#define mini_array_h

#define DEFAULT_SIZE_M 8 // minimum size of the Array

/* Array core data structure
 * core skeleton of the dynamic array
 ************************************/
typedef struct array_mini {
  int size;    // the actual size in memory
  int counter; // the current index in data
  int *data;   // the actual integer-containing array
} Array;

Array *init_m();
void free_m(Array *);

void add_m(Array *, int);
int pop_m(Array *);
void insert_m(Array *, int, int);
void remove_m(Array *, int);
void removeAll_m(Array *, int);
void clear(Array *);

int size_m(Array *);
void print_m(Array *);

#endif
