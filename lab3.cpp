

// Copyright
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <climits>

int computeSum(std::vector<int> values) {
    int sum = 0;
    for (int i = 0; i < values.size(); i++)
        sum += values[i];
    return sum;
}

double computeAverage(std::vector<int> values, int sum) {
    double average = 0.0;
    average = static_cast<double> (sum) / (values.size());
    return average;
}

int computeMax(std::vector<int> values) {
    int max = INT_MIN;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] > max)
            max = values[i];
    }
    return max;
}

int computeMin(std::vector<int> values) {
    int min = INT_MAX;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] < min)
           min= values[i];
    }
    return min;
}

void printResult(std::ostream& out, int sum, int min, double average, int max) {
    out << "Sum: " << sum << std::endl;
    out << "Min: " << min << std::endl;
    out << "Average: " << average << std::endl;
    out << "Max: " << max << std::endl;
}


int main(int argc, char *argv[]) {
    // Verify the correct number of arguments
    if (argc != 3) {
        std::cerr << "Specify input and output files" << std::endl;
        return 0;
    }
    // Create streams with command line arguments
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);

    // Check streams were successfully created
    if (!input.good() || !output.good()) {
        // If the stream was unsuccessful,
        // then print to std::cerr and return 0
        std::cerr << "Error opening input or output streams" << std::endl;
        return 0;
    }

    // Read input file to some data structure
    std::vector<int> values(0);
    int num;
    while (input >> num)
        values.push_back(num);
    // input.close();

    // Compute the sum, average, min, max
    int sum = computeSum(values);
    double average = computeAverage(values, sum);
    int min = computeMin(values);
    int max = computeMax(values);

    // Display results -- DO NOT MODIFY BELOW THIS LINE
    printResult(output, sum, min, average, max);
    printResult(std::cout, sum, min, average, max);
}
