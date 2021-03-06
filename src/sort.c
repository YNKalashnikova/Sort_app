#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 400000

void merge(double* arr_double, size_t low, size_t mid, size_t high)
{
    double* b;
    size_t n = MAX_ARRAY_SIZE;
    b = calloc(n, sizeof(double));
    for (size_t i = low; i <= high; i++) {
        b[i] = arr_double[i];
    }
    size_t l, r, i;
    l = low;
    r = mid + 1;
    i = low;
    while ((l <= mid) & (r <= high)) {
        if (b[l] <= b[r]) {
            arr_double[i] = b[l];
            l = l + 1;
        } else {
            arr_double[i] = b[r];
            r = r + 1;
        }
        i = i + 1;
    }
    while (l <= mid) {
        arr_double[i] = b[l];
        l = l + 1;
        i = i + 1;
    }
    while (r <= high) {
        arr_double[i] = b[r];
        r = r + 1;
        i = i + 1;
    }
    free(b);
}

void merge_sort(double* arr_double, size_t low, size_t high)
{
    if (low < high) {
        size_t mid = (low + (high - low) / 2);
        merge_sort(arr_double, low, mid);
        merge_sort(arr_double, mid + 1, high);
        merge(arr_double, low, mid, high);
    }
}

void insertion_sort(double* arr_double, size_t n)
{
    for (size_t i = 1; i < n; i++) {
        double key = arr_double[i];
        size_t j = i - 1;
        while ((j >= 0) && (arr_double[j] > key)) {
            arr_double[j + 1] = arr_double[j];
            j--;
        }
        arr_double[j + 1] = key;
    }
}

void counting_sort(uint32_t* arr_uint, size_t n)
{
    uint32_t max = 0;
    for (uint32_t i = 0; i < n; i++) {
        if (arr_uint[i] > max)
            max = arr_uint[i];
    }
    uint32_t* sm;
    sm = calloc((max + 1), sizeof(uint32_t));
    for (size_t i = 0; i < n; i++) {
        sm[arr_uint[i]]++;
    }
    size_t j = 0;
    for (size_t i = 0; i < max + 1; i++) {
        if (sm[i] > 0) {
            while (sm[i] > 0) {
                arr_uint[j] = i;
                sm[i]--;
                j++;
            }
        }
    }
    free(sm);
}
