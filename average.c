#include "/Users/ankanamandal/codes/GradeCard/average.h "

float calculateSemesterAverage(const float* marks, int size) {
    float total = 0;
    for (int i = 0; i < size; ++i) {
        total += marks[i];
    }
    return total / size;
}


