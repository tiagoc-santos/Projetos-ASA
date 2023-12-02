#include <iostream>
#include <vector>
using namespace std;

int maximizeValue(int plateColumn, int plateLine, int numTypes, vector<vector<int>>calculatedValues){

    for(int c = 1; c <= plateColumn; c++){
        for(int l = 1; l <= plateLine; l++){
            for(int i = 1; i <= max(c,l)/2; i++){
                int value1 = 0, value2 = 0;
                if(i <= l){
                    value1 = calculatedValues[c][i] + calculatedValues[c][l-i];
                }
                if(i <= c){
                    value2 = calculatedValues[i][l] + calculatedValues[c-i][l];
                }
                calculatedValues[c][l] = max(calculatedValues[c][l], max(value1, value2));
                if(c <= plateLine && l <= plateColumn){
                    calculatedValues[l][c] = calculatedValues[c][l];
                }
            }
        }
    }
    return calculatedValues[plateColumn][plateLine];
}

int main(){
    int plateColumn = 0, plateLine = 0, numTypes = 0,
    value = 0, line = 0, column = 0;
    
    std::cin >> plateColumn;
    std::cin >> plateLine;
    std::cin >> numTypes;
    std::vector<std::vector<int>>calculatedValues(plateColumn + 1, std::vector<int>(plateLine + 1, 0));

    for(int i = 0; i < numTypes; i++){
        std::cin >> column;
        std::cin >> line;
        std::cin >> value;
        if(column <= plateColumn && line <= plateLine){
            calculatedValues[column][line] = value;
        }
        if(column <= plateLine && line <= plateColumn){
            calculatedValues[line][column] = value;
        }
    }
    std::cout << maximizeValue(plateColumn, plateLine, numTypes, calculatedValues) << std::endl;
    return 0;
}