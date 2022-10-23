// Copyright
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <climits>

int computeSum(/* Update Here */) {
    int sum = 0;

    /* 
     * Write code here that 
     * computes the sum of
     * a sequence of numbers
     */

    return sum;
}

double computeAverage( /* Update Here */) {
    double average = 0.0;

    /* 
     * Write code here that 
     * computes the average of
     * a sequence of numbers
     */

    return average;
}

int computeMax( /* Update Here */) {
    int max = INT_MIN;

    /* 
     * Write code here that 
     * finds the max of
     * a sequence of numbers
     */

    return max;
}

int computeMin( /* Update Here */) {
    int min = INT_MAX;

    /* 
     * Write code here that 
     * finds the min of
     * a sequence of numbers
     */

    return min;
}

void printResult(std::ostream& out, int sum, int min, double average, int max) {
    /* Write the sum, average, min, and max to file
     * Output file should be:
     *      Sum: [sum]
     *      Min: [min]
     *      Average: [average]     
     *      Max: [max]
     *
     * The brackets [] represent the actual numerical value
     */
    out << /* format output */ << std::endl;
    out << /* format output */ << std::endl;
    out << /* format output */ << std::endl;
    out << /* format output */ << std::endl;
}


int main( /* Update Here - add needed parameters */ ) {

    // Verify the correct number of arguments
    if( /* Update Here - check arguments */ ) {
        // If the arguments were not specified,
        // then print to std::cerr and return


    }

    // Create streams with command line arguments
    

    // Check streams were successfully created
    if( /* Update Here */ ) {
        // If the stream was unsuccessful,
        // then print to std::cerr and return 0

    }

    // Read input file to some data structure
    /* Update Here - need some data structure */
    int num;
    while( ( /* Update Here - read from file stream */ ) ) {
        /* Update Here - store each number from the input file */
    }


    // Compute the sum, average, min, max
    int sum = computeSum( /* Update Here */ );
    double average = computeAverage( /* Update Here */ );
    int min = computeMin( /* Update Here */ );
    int max = computeMax( /* Update Here */ );
    
    // Display results -- DO NOT MODIFY BELOW THIS LINE
    printResult(output, sum, min, average, max);
    printResult(std::cout, sum, min, average, max);
    

}
