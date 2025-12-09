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
    printf("This Program Converts the amount of CO2 emission in one area to give an image about how much the Area contributed to Climate Changes.");
    printf("\nYou will be asked to enter the area name, size, number of houses, and average emissions of all the houses in tons.");
    printf("\nThe program will then calculate the total emissions, number of trees needed to offset the emissions, and equivalent coal burned.\n");
    printf("=================================================\n");

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

    for (int i = 0; i < count; i++) {
        float totalEmissions = CarbonEmissionCalc(&data[i]);
        float TreeImpact = ClimateImpTree(totalEmissions);
        float CoalImpact = ClimateImpCoal(totalEmissions);


        printf("\nArea: %s\n", data[i].areaName);
        printf("Total Emissions: %.2f tons\n", totalEmissions);
        printf("Trees needed to offset emissions: %.2f\n", TreeImpact); 
        printf("Equivalent coal burned: %.2f tons\n", CoalImpact);

    }

    return 0;
}

float CarbonEmissionCalc(Data *data) {
    return data
}
