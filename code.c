#include <stdio.h>

// carbon emission calculator

typedef struct {
    float areaSize;
    char areaName[31];
    int houseNum;
    float houseEmissions;
    float totalEmissions;
} Data;
// struct for grouping the area data

float CarbonEmissionCalc(Data *data);
float ClimateImpTree(float emissionTons);
float ClimateImpCoal(float emissionTons);

int main () {
    printf("=== Housing Area Carbon Emission Calculator ===\n");
    int count;
    printf("Enter number of areas to analyze: ");
    scanf("%d", &count);

    Data *data = (Data*) malloc(count * sizeof(Data));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("\nArea #%d\n", i + 1);
        printf("Enter area name: ");
        scanf("%s", data[i].areaName);
        printf("Enter area size: ");
        scanf("%d", &data[i].areaSize);
        printf("Enter Number of houses: ");
        scanf("%d", &data[i].houseNum);
        printf("Enter the average emissions of all the houses: ");
        scanf("%d", &data[i].houseEmissions);
    }

    printf("\n=== Climate Impact ===\n");
    printf("");
    
    return 0;
}

float CarbonEmissionCalc(Data *data) {
    return data
}
