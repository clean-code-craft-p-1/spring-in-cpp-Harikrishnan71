#include <vector>

namespace Statistics {
    // define the Stats structure here. See the tests to infer its properties
    template <class T=float>
    class Stats{
    public:
    T average;
    T max;
    T min;
    Stats(T average, T max, T min); 
    Stats<T> ComputeStatistics(const std::vector<T>&);
}
