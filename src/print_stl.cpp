#include "hamkoutil.hpp"
#include <iostream>

using namespace std;

template <class X> void print_vector(vector<X> &toprint)
{
    for (int i = 0; i < (int)toprint.size(); i++) 
        cout << toprint[i] << endl;
}
template void print_vector(vector<double> &toprint);
template void print_vector(vector<float> &toprint);
template void print_vector(vector<int> &toprint);

template <class X> void print_vector_vector(vector<vector<X> > &toprint)
{
    for (int i = 0; i < (int)toprint.size(); i++) {
        for (int j = 0; j < (int)toprint[0].size(); j++) 
            cout << toprint[i][j] << " ";
        cout << endl;
    }
}
template void print_vector_vector(vector<vector<double> > &toprint);
template void print_vector_vector(vector<vector<float> > &toprint);
template void print_vector_vector(vector<vector<int> > &toprint);

template <class X> void print_vector_vector_trans(vector<vector<X> > &toprint)
{
    for (int i = 0; i < (int)toprint[0].size(); i++) {
        for (int j = 0; j < (int)toprint.size(); j++) 
            cout << toprint[j][i] << " ";
        cout << endl;
    }
}
template void print_vector_vector_trans(vector<vector<double> > &toprint);
template void print_vector_vector_trans(vector<vector<float> > &toprint);
template void print_vector_vector_trans(vector<vector<int> > &toprint);

