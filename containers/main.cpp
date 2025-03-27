#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <chrono>

// Function to calculate the average and standard deviation of a C-style array
void calculate_with_c_style_array(float* arr, size_t size) {
    float sum = 0.0f;
    for (size_t i = 0; i < size; ++i) {
        sum += arr[i];
    }

    float mean = sum / size;

    float variance = 0.0f;
    for (size_t i = 0; i < size; ++i) {
        variance += std::pow(arr[i] - mean, 2);
    }

    float std_dev = std::sqrt(variance / size);

    std::cout << "C-style Array: Average = " << mean << ", Standard Deviation = " << std_dev << std::endl;
}

// Function to calculate the average and standard deviation using std::array
template <size_t N>
void calculate_with_std_array(std::array<float, N>& arr) {
    float sum = 0.0f;
    for (auto val : arr) {
        sum += val;
    }

    float mean = sum / arr.size();

    float variance = 0.0f;
    for (auto val : arr) {
        variance += std::pow(val - mean, 2);
    }

    float std_dev = std::sqrt(variance / arr.size());

    std::cout << "std::array: Average = " << mean << ", Standard Deviation = " << std_dev << std::endl;
}

// Function to calculate the average and standard deviation using std::vector
void calculate_with_vector(const std::vector<float>& vec) {
    float sum = 0.0f;
    for (auto val : vec) {
        sum += val;
    }

    float mean = sum / vec.size();

    float variance = 0.0f;
    for (auto val : vec) {
        variance += std::pow(val - mean, 2);
    }

    float std_dev = std::sqrt(variance / vec.size());

    std::cout << "std::vector: Average = " << mean << ", Standard Deviation = " << std_dev << std::endl;
}

// Function to get current time in nanoseconds
long long get_time_ns() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

int main() {
    const size_t LARGE_SIZE = 250000; // A size that fits in a C-style array on most systems (~250,000)

    // Test data
    float c_style_array[LARGE_SIZE];
    for (size_t i = 0; i < LARGE_SIZE; ++i) {
        c_style_array[i] = static_cast<float>(i);
    }

    // Test with std::array (fixed-size)
    std::array<float, LARGE_SIZE> std_array;
    for (size_t i = 0; i < LARGE_SIZE; ++i) {
        std_array[i] = static_cast<float>(i);
    }

    // Test with std::vector (dynamic-size)
    std::vector<float> std_vector(LARGE_SIZE);
    for (size_t i = 0; i < LARGE_SIZE; ++i) {
        std_vector[i] = static_cast<float>(i);
    }

    // Timing and calling the functions

    // C-style array
    long long start_time = get_time_ns();
    calculate_with_c_style_array(c_style_array, LARGE_SIZE);
    std::cout << "C-style array processing time: " << get_time_ns() - start_time << " ns\n";

    // std::array
    start_time = get_time_ns();
    calculate_with_std_array(std_array);
    std::cout << "std::array processing time: " << get_time_ns() - start_time << " ns\n";

    // std::vector
    start_time = get_time_ns();
    calculate_with_vector(std_vector);
    std::cout << "std::vector processing time: " << get_time_ns() - start_time << " ns\n";

    return 0;
}
