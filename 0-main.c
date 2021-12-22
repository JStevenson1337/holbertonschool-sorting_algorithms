#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {746, 639, 788, 284, 476, 409, 657, 188, 516, 111, 512, 32, 967, 986, 924, 572, 114, 687, 805, 869, 817, 306, 491, 540, 721, 637, 210, 34, 526, 291, 757, 366, 856, 367, 533, 622, 520, 588, 661, 615, 669, 850, 481, 595, 531, 756, 223, 727, 322, 677, 820, 256, 362, 211, 923, 260, 878, 21, 530, 814, 369, 564, 131, 60, 623, 597, 173, 338, 789};

    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
