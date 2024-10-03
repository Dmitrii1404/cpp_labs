#include "solution.h"

int findAnswer(int divider, int border) {
    if (divider <= 0 || border <= 0) {
        return -1;
    }
    return (border / divider) * divider;
}
