#include <stdio.h>

// carbon emission calculator

typedef struct {
    float areaSize;
    char areaName[31];
    int houseNum;
    float emmissions;
} Data;
// struct for grouping the area data

float CarbonEmmissionCalc(Data *data);
float ClimateImpTree(float emmissionTons);
float ClimateImpCoal(float emissionTons);

int main () {
    printf("=== Housing Area Carbon Emmission Calculator ===\n");


    return 0;
}
