#include <stdio.h>
#include <stdlib.h>

// CO2 Conversion calculator

typedef struct {
    float areaSize;
    char areaName[31];
    int houseNum;
    float houseEmissions;
    float totalEmissions;
} Data;
// struct for grouping the area data

//using function prototype for al the functions so it calculates after all the data is inputted
float CarbonEmissionCalc(Data *data);
// function to calculate the carbon emission
float ClimateImpTree(float totalEmissions);
// function for calculating equivalent amount of trees that counteracts the tree emission
float ClimateImpCoal(float totalEmissions);
// function for calculating the equivalent amount of coal-fired power plants
float ClimateImpNature(float totalEmissions);
// function for calculating th equivalent amount of nature-fired power plants
float ClimateImpGarbage(float totalEmissions);
// function for calculating the equivalent amount of waste recycled

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
        float NatureImpact = ClimateImpNature(totalEmissions);
        float GarbageImpact = ClimateImpGarbage(totalEmissions);


        printf("\nArea --> %s\n", data[i].areaName);
        printf("---------------------------");
        printf("Total Emissions: %.2f tons\n", totalEmissions);
        printf("Seedlings grown in 10 years: %.2f\n", TreeImpact); 
        printf("Equivalent to Coal-fired power Plants in one year: %.2f \n", CoalImpact);
        printf("Equivalent to Nature-fired Power Plants in one year: %.2f \n", NatureImpact);
        printf("Equivalent to Waste recycled instead of landfilled: %.2f \n", GarbageImpact);

    }

    return 0;
}

float CarbonEmissionCalc(Data *data) {
    // because it's a pointer i'll be using it as an array so that it could work
    float result = data[0].houseNum * data[0].houseEmissions;
    result = data[0].totalEmissions;
    
    return result;
}


float ClimateImpTree(float totalEmissions) {
    float EqA = 36.4;    //36.4 lbs C/tree/year
        
    return totalEmissions / (EqA / 2000);
    //convert tons to lbs

    // (0.11 [percent of coniferous trees in sampled urban settings] × 23.2 lbs C/coniferous tree/year) + (0.89 [percent of deciduous trees in sampled urban settings] × 38.0 lbs C/deciduous tree/year) = 36.4 lbs C/tree/year
}

float ClimateImpCoal(float totalEmissions) {
    return totalEmissions / 3790003.72;

    //746,630,725.6 metric tons of CO2 × 1/197 power plants = 3,790,003.72 metric tons CO2/power plant
}

float ClimateImpNature(float totalEmissions) {
    return totalEmissions / 382205.02;
    //625,669,621.5 metric tons of CO2 × 1/1,637 power plants = 382,205.02 metric tons CO2/power plant

}

float ClimateImpGarbage(float totalEmissions) {
    return totalEmissions / 2.83;
    //2.83 metric tons CO2 equivalent/ton of waste recycled instead of landfilled
}
