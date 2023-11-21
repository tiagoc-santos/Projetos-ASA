#include <iostream>
#include <vector>

int maximizeValue(std::vector<int> areas,
                  std::vector<int> values, int plateArea, int numTypes){
    
    int i;
    std::vector<int> calculatedValues = std::vector<int>(plateArea + 1, 0);

    for(i = 1; i <= plateArea; i++){
        for(int j = 0; j < numTypes; j++){
            if(areas[j] <= i){
                calculatedValues[i] = std::max(calculatedValues[i], 
                                               calculatedValues[i - areas[j]] + values[j]);
            }
        }
    }
    return calculatedValues[i-1];
}

int main(){
    int plateColumn = 0, plateLine = 0, plateArea = 0, numTypes = 0,
    value = 0, maxValue = 0, line = 0, column = 0;
    
    std::cin >> plateColumn;
    std::cin >> plateLine;
    std::cin >> numTypes;
    
    plateArea = plateColumn * plateLine;

    std::vector<int> areas = std::vector<int>(numTypes, 0);
    std::vector<int> values = std::vector<int>(numTypes, 0);

    for(int i = 0; i < numTypes; i++){
        std::cin >> column;
        std::cin >> line;
        std::cin >> value;
        if((column > plateColumn && column > plateLine) || 
            (line > plateLine && line > plateColumn)){
            continue;
        }
        areas[i] = column*line;
        values[i] = value;
    }
    maxValue = maximizeValue(areas, values, plateArea, numTypes);
    std::cout << maxValue << std::endl;
    return 0;
}