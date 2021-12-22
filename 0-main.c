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
    int array[] = {746, 639, 788, 284, 476, 409, 657, 188, 516, 111, 512, 32, 967, 986, 924, 572, 114, 687, 805, 869, 817, 306, 491, 540, 721, 637, 210, 34, 526, 291, 757, 366, 856, 367, 533, 622, 520, 588, 661, 615, 669, 850, 481, 595, 531, 756, 223, 727, 322, 677, 820, 256, 362, 211, 923, 260, 878, 21, 530, 814, 369, 564, 131, 60, 623, 597, 173, 338, 789, 951, 797, 985, 884, 141, 94, 601, 90, 405, 745, 492, 477, 355, 686, 462, 401, 921, 887, 753, 337, 50, 648, 106, 879, 342, 644, 435, 397, 417, 829, 171, 819, 972, 115, 357, 665, 527, 740, 433, 404, 684, 376, 143, 858, 999, 617, 495, 49, 100, 410, 87, 17, 287, 775, 182, 803, 573, 129, 907, 857, 183, 68, 754, 204, 266, 890, 542, 523, 553, 694, 324, 549, 406, 892, 165, 195, 625, 58, 935, 760, 202, 458, 389, 251, 259, 984, 925, 370, 441, 809, 107, 602, 498, 922, 15, 685, 650, 729, 507, 842, 590, 932, 580, 559, 528, 424, 267, 95, 906, 118, 518, 488, 886, 838, 728, 272, 2, 771, 399, 750, 992, 513, 901, 845, 244, 432, 585, 489, 610, 82, 607, 712, 226, 554, 157, 31, 228, 736, 748, 928, 40, 166, 326, 469, 3, 933, 995, 758, 608, 658, 254, 86, 230, 46, 22, 541, 101, 973, 874, 550, 888, 72, 263, 653, 475, 451, 889, 257, 895, 673, 696, 830, 468, 24, 946, 77, 286, 885, 142, 504, 761, 335, 249, 678, 613, 334, 654, 339, 320, 18, 883, 365, 934, 747, 178, 546, 710, 688, 993, 479, 261, 612, 283, 566, 812, 207, 88, 778, 713, 783, 323, 807, 557, 245, 780, 899, 428, 944, 831, 43, 652, 839, 30, 598, 698, 517, 167, 69, 910, 692, 465, 600, 201, 716, 54, 392, 524, 861, 707, 418, 386, 822, 739, 768, 726, 563, 703, 773, 299, 998, 493, 214, 119, 525, 314, 330, 772, 926, 770, 474, 99, 956, 514, 538, 176, 158, 823, 1, 975, 560, 234, 296, 494, 767, 333, 798, 402, 56, 881, 243, 897, 177, 421, 725, 806, 749, 790, 132, 130, 485, 722, 929, 545, 589, 647, 39, 811, 942, 742, 627, 345, 731, 955, 321, 373, 23, 720, 403, 631, 562, 626, 867, 281, 192, 123, 663, 705, 343, 344, 440, 808, 124, 919, 624, 154, 388, 664, 837, 447, 565, 93, 894, 841, 10, 676, 473, 274, 544, 217, 227, 358, 419, 689, 569, 947, 536, 818, 179, 231, 136, 91, 970, 175, 990, 36, 196, 383, 977, 446, 675, 59, 638, 578, 301, 70, 880, 137, 997, 971, 816, 149, 558, 827, 735, 212, 200, 109, 152, 774, 804, 96, 741, 635, 224, 584, 285, 759, 683, 872, 73, 948, 172, 38, 203, 67, 482, 799, 375, 509, 148, 147, 994, 609, 715, 787, 503, 959, 630, 332, 646, 144, 359, 982, 307, 744, 700, 361, 751, 496, 870, 229, 611, 28, 316, 591, 717, 963, 391, 522, 555, 862, 213, 353, 776, 134, 832, 449, 603, 680, 352, 387, 277, 328, 153, 280, 651, 828, 587, 191, 313, 140, 455, 29, 821, 470, 866, 78, 248, 917, 381, 900, 464, 318, 110, 253, 966, 246, 471, 436, 303, 532, 699, 133, 583, 927, 605, 765, 184, 636, 75, 616, 112, 374, 205, 242, 233, 442, 846, 360, 792, 4, 662, 621, 117, 755, 915, 502, 35, 463, 575, 104, 20, 695, 719, 960, 393, 604, 159, 840, 490, 548, 356, 505, 666, 422, 297, 836, 539, 743, 815, 847, 996, 37, 667, 826, 270, 534, 105, 704, 457, 851, 791, 431, 833, 434, 180, 319, 443, 936, 113, 691, 218, 181, 450, 41, 943, 706, 453, 89, 515, 529, 208, 649, 594, 341, 619, 511, 413, 262, 206, 769, 312, 5, 7, 235, 255, 930, 232, 236, 784, 363, 427, 561, 714, 467, 586, 271, 945, 252, 79, 777, 460, 169, 855, 14, 289, 444, 659, 19, 961, 127, 390, 908, 581, 980, 290, 730, 454, 709, 764, 329, 65, 864, 733, 672, 185, 785, 483, 796, 76, 199, 103, 163, 865, 126, 949, 732, 66, 160, 430, 336, 472, 194, 150, 456, 484, 702, 632, 354, 222, 122, 292, 737, 909, 671, 898, 220, 931, 407, 125, 288, 859, 766, 950, 198, 916, 674, 225, 309, 668, 794, 415, 641, 300, 988, 190, 570, 416, 426, 340, 240, 478, 317, 71, 718, 294, 264, 379, 128, 579, 912, 120, 170, 97, 939, 13, 116, 660, 304, 848, 48, 508, 965, 568, 903, 801, 679, 843, 480, 62, 913, 618, 459, 241, 918, 981, 189, 697, 734, 98, 327, 853, 786, 108, 825, 33, 708, 209, 8, 738, 911, 902, 893, 302, 186, 500, 983, 974, 629, 506, 501, 577, 429, 952, 74, 53, 168, 876, 849, 571, 873, 645, 139, 693, 278, 834, 556, 161, 216, 535, 269, 599, 461, 576, 656, 156, 978, 268, 102, 347, 835, 852, 364, 395, 377, 295, 265, 953, 146, 45, 762, 810, 408, 781, 11, 85, 940, 896, 414, 239, 824, 438, 162, 83, 681, 614, 221, 860, 121, 325, 957, 779, 844, 448, 968, 6, 368, 640, 247, 863, 64, 9, 987, 350, 425, 871, 920, 969, 237, 380, 854, 412, 273, 275, 382, 633, 80, 905, 55, 26, 487, 724, 701, 991, 439, 276, 868, 135, 628, 642, 802, 371, 958, 372, 164, 711, 914, 723, 282, 452, 499, 904, 537, 606, 486, 634, 61, 497, 378, 979, 543, 782, 155, 12, 57, 384, 52, 941, 44, 954, 351, 552, 81, 682, 643, 398, 193, 437, 510, 138, 592, 596, 311, 197, 385, 567, 27, 670, 47, 800, 400, 215, 655, 298, 411, 891, 394, 16, 875, 551, 238, 348, 593, 547, 84, 42, 445, 620, 308, 219, 519, 310, 258, 466, 763, 938, 349, 989, 813, 795, 25, 962, 293, 423, 174, 793, 752, 964, 250, 582, 521, 51, 937, 187, 151, 574, 882, 92, 63, 145, 877, 1000, 396, 305, 976, 690, 315, 279, 420, 346, 331};

    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
