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
    int count;
    printf("Enter number of areas to analyze: ");
    scanf("%d", &count);

    Data data = (Data) malloc(count * sizeof(Data));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }


    for (int i = 0; i < count; i++) {
        printf("\nArea #%d\n", i + 1);
        printf("Enter Area Name: ");
        scanf("%s", data[i].areaName);
        printf("Enter Number of Houses: ");
        scanf("%d", &data[i].numHouses);
    }


    return 0;
}
