#include "array.h"
#include <stdio.h>
#include <stdlib.h>

Array *init_m() {
  Array *array = (Array *)malloc(sizeof(Array));

  array->size = 0;
  array->counter = 0;
  array->data = NULL;

  return array;
}

static void resize_m(Array *array) {
  if (array->size == 0) {
    array->size = DEFAULT_SIZE_M;
    array->data = (int *)realloc(array->data, sizeof(int) * array->size);

    return;
  }

  array->size *= 2;
  array->data = (int *)realloc(array->data, sizeof(int) * array->size);

  return;
}

void free_m(Array *array) {
  free(array);

  return;
}

void add_m(Array *array, int num) {
  if (array->counter == array->size)
    resize_m(array);

  array->data[array->counter] = num;
  array->counter++;

  return;
}

int pop_m(Array *array) {
  if (array->size == 0)
    exit(1);

  array->counter--;
  return array->data[array->counter + 1];
}

/* insert_m(array, index, num)
 * array: array to be modified
 * index: which index to insert num
 * num: integer to be inserted
 * desc:  insert a number at a specified index in
 *        the dynamic array
 ************************************************/
void insert_m(Array *array, int index, int num) {
  // make sure the array has enough space for another integer
  // if not, resize the array
  if (array->counter + 1 > array->size) {
    resize_m(array);
  }

  // check if index is out of initialized space
  // (soft index out of bounds)
  if (index >= array->counter) {
    exit(1);
  }

  // handle intended case
  // copy the data past the index into a new array
  int temp[array->counter - index];
  for (int i = index; i < array->counter; i++) {
    temp[i - index] = array->data[i];
  }

  array->data[index] = num;

  // move temp data back into array
  for (int i = index + 1; i <= array->counter; i++) {
    array->data[i] = temp[i - index - 1];
  }

  // increment the counter after adding an element
  array->counter++;

  return;
}

/* remove_m(array, val)
 * array: array to remove val from
 * val: value to remove from array
 * desc:  remove the first occurence of the
 *        value in the array
 ******************************************/
void remove_m(Array *array, int val) {
  int found = 0;
  for (int i = 0; i < size_m(array); i++) {
    if (found == 0 && array->data[i] == val) {
      found = 1;
      continue;
    }

    array->data[i - found] = array->data[i];
  }

  array->counter--;
  return;
}

void removeAll_m(Array *array, int val) {
  int found = 0;
  for (int i = 0; i < size_m(array); i++) {
    if (array->data[i] == val) {
      found++;
      continue;
    }

    array->data[i - found] = array->data[i];
  }

  array->counter -= found;
  return;
}

/* size_m(array)
 * array: the array to get the "size" of
 * return: "size" of the array as an integer
 * desc:  return the synthetic size of the array
 *        (how many elements are in use)
 ***********************************************/
int size_m(Array *array) { return array->counter; }

void print_m(Array *array) {
  if (size_m(array) == 0) {
    printf("[]\n");
    return;
  }

  for (int i = 0; i < array->counter; i++) {
    if (i == 0) {
      printf("[%d", array->data[i]);
    } else if (i != array->counter - 1) {
      printf(", %d", array->data[i]);
    } else if (i == array->counter - 1) {
      printf(", %d]\n", array->data[i]);
    }
  }

  return;
}
