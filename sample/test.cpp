#include <hamkoutil.hpp>
#include <vector>

using namespace std;

int main(void)
{
    vector <double> v;
    fvec((char *)"sample.log", v, 1);
    print_vector(v);
    return 0;
}
