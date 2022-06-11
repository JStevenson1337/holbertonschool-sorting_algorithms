/*****************************************************************************
*
*
* ------------------------------- ctsort.c ------------------------------- *
*
*
*****************************************************************************/
#include <stdlib.h>
#include <string.h>
#include "sort.h"
/*****************************************************************************
*
*
* -------------------------------- ctsort -------------------------------- *
*
*
*****************************************************************************/
int ctsort(int *data, int size, int k) {
int*counts,
*temp;
inti,
j;
/*****************************************************************************
*
*
* Allocate storage for the counts.
*
*
*
*****************************************************************************/
if ((counts = (int *)malloc(k * sizeof(int))) == NULL)
return -1;
/*****************************************************************************
*
*
* Allocate storage for the sorted elements.
*
*
*
*****************************************************************************/
if ((temp = (int *)malloc(size * sizeof(int))) == NULL) {
free(counts);
return -1;
}
/*****************************************************************************
*
*
* Initialize the counts.
*
*
*
*****************************************************************************/
for (i = 0; i < k; i++)
counts[i] = 0;
327328
Chapter 12: Sorting and Searching
Example 12-6. Implementation of Counting Sort (continued)
/*****************************************************************************
*
*
* Count the occurrences of each element.
*
*
*
*****************************************************************************/
for (j = 0; j < size; j++)
counts[data[j]] = counts[data[j]] + 1;
/*****************************************************************************
*
*
* Adjust each count to reflect the counts before it.
*
*
*
*****************************************************************************/
for (i = 1; i < k; i++)
counts[i] = counts[i] + counts[i - 1];
/*****************************************************************************
*
*
* Use the counts to position each element where it belongs.
*
*
*
*****************************************************************************/
for (j = size - 1; j >= 0; j--) {
temp[counts[data[j]] - 1] = data[j];
counts[data[j]] = counts[data[j]] - 1;
}
/*****************************************************************************
*
*
* Prepare to pass back the sorted data.
*
*
*
*****************************************************************************/
memcpy(data, temp, size * sizeof(int));
/*****************************************************************************
*
*
* Free the storage allocated for sorting.
*
*
*
*****************************************************************************/
free(counts);
free(temp);
return 0;
}




Not surprisingly, the runtime complexity of radix sort depends on the stable sort-
ing algorithm chosen to sort the digits. Because radix sort applies counting sort
once for each of the p positions of digits in the data, radix sort runs in p times the
runtime complexity of counting sort, or O(pn + pk). Its space requirement is the
same as for counting sort: two arrays of size n and an array of size k.
Example 12-7. Implementation of Radix Sort
/*****************************************************************************
*
*
* ------------------------------- rxsort.c ------------------------------- *
*
*
*****************************************************************************/Implementation and Analysis of Radix Sort
Example 12-7. Implementation of Radix Sort (continued)
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
/*****************************************************************************
*
*
* -------------------------------- rxsort -------------------------------- *
*
*
*****************************************************************************/
int rxsort(int *data, int size, int p, int k) {
int*counts,
*temp;
intindex,
pval,
i,
j,
n;
/*****************************************************************************
*
*
* Allocate storage for the counts.
*
*
*
*****************************************************************************/
if ((counts = (int *)malloc(k * sizeof(int))) == NULL)
return -1;
/*****************************************************************************
*
*
* Allocate storage for the sorted elements.
*
*
*
*****************************************************************************/
if ((temp = (int *)malloc(size * sizeof(int))) == NULL)
return -1;
/*****************************************************************************
*
*
* Sort from the least significant position to the most significant.
*
*
*
*****************************************************************************/
for (n = 0; n < p; n++) {
331332
Chapter 12: Sorting and Searching
Example 12-7. Implementation of Radix Sort (continued)
/**************************************************************************
*
*
* Initialize the counts.
*
*
*
**************************************************************************/
for (i = 0; i < k; i++)
counts[i] = 0;
/**************************************************************************
*
*
* Calculate the position value.
*
*
*
**************************************************************************/
pval = (int)pow((double)k, (double)n);
/**************************************************************************
*
*
* Count the occurrences of each digit value.
*
*
*
**************************************************************************/
for (j = 0; j < size; j++) {
index = (int)(data[j] / pval) % k;
counts[index] = counts[index] + 1;
}
/**************************************************************************
*
*
* Adjust each count to reflect the counts before it.
*
*
*
**************************************************************************/
for (i = 1; i < k; i++)
counts[i] = counts[i] + counts[i - 1];
/**************************************************************************
*
*
* Use the counts to position each element where it belongs.
*
*
*
**************************************************************************/
for (j = size - 1; j >= 0; j--) {
index = (int)(data[j] / pval) % k;
temp[counts[index] - 1] = data[j];
counts[index] = counts[index] - 1;
}Description of Binary Search
333
Example 12-7. Implementation of Radix Sort (continued)
/**************************************************************************
*
*
* Prepare to pass back the data as sorted thus far.
*
*
*
**************************************************************************/
memcpy(data, temp, size * sizeof(int));
}
/*****************************************************************************
*
*
* Free the storage allocated for sorting.
*
*
*
*****************************************************************************/
free(counts);
free(temp);
return 0;
}
