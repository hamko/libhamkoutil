#include <vector>
#include <cmath>
template <class T> 
T metric_vector_d2(vector<T>& a, vector<T>& b)
{
    assert(a.size() == b.size());
    T sum = 0;
    for (size_t i = 0; i < a.size(); i++) 
        sum += (a[i] - b[i]) * (a[i] - b[i]);

    return sqrt(sum);
}
