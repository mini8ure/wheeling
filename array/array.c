#include "array.h"
#include <stdio.h>
#include <stdlib.h>

/* init_m()
 * return:  an initialized array struct
 * desc:  allocate an array and initialize it
 *******************************************/
Array *init_m() {
  Array *array = (Array *)malloc(sizeof(Array));

  array->size = 0;
  array->counter = 0;
  array->data = NULL;

  return array;
}

/* resize_m(array)
 * array: the array to be resized
 * desc:  grow the array to either 8 values
 *        or double the current size
 ******************************************/
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

/* free_m(array)
 * array: array to be freed
 * desc:  free an array in memory
 ********************************/
void free_m(Array *array) {
  free(array->data);
  free(array);

  return;
}

/* add_m(array, num)
 * array: array to add num to
 * num: integer to be added to array
 * desc:  add an integer to the end of
 *        an array
 *************************************/
void add_m(Array *array, int num) {
  if (array->counter == array->size)
    resize_m(array);

  array->data[array->counter] = num;
  array->counter++;

  return;
}

/* pop_m(array)
 * array: array to pop a value from
 * desc:  pop a value from the end of
 *        an array
 ************************************/
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
  if (array->counter + 1 > array->size) {
    resize_m(array);
  }

  if (index > array->counter) {
    exit(1);
  }

  if (index == array->counter) {
    add_m(array, num);
    return;
  }

  int temp[array->counter - index];
  for (int i = index; i < array->counter; i++) {
    temp[i - index] = array->data[i];
  }

  array->data[index] = num;

  for (int i = index + 1; i <= array->counter; i++) {
    array->data[i] = temp[i - index - 1];
  }

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

/* removeAll_m(array, val)
 * array: array to remove vals from
 * val: values to remove from array
 * desc:  remove all occurences of val from
 *        the array
 ******************************************/
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

/* clear(array)
 * array: array to be cleared
 * desc:  clear array of all values by
 *        reinitializing the array
 *************************************/
void clear(Array *array) {
  array->size = 0;
  array->counter = 0;
  free(array->data);
  array->data = NULL;
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
