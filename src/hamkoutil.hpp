#ifndef HAMKO_UTIL_HPP_INCLUDED
#define HAMKO_UTIL_HPP_INCLUDED

#include <vector>

template <class X> void print_vector(std::vector<X> &toprint);
template <class X> void print_vector_vector(std::vector<std::vector<X> > &toprint);
template <class X> void print_vector_vector_trans(std::vector<std::vector<X> > &toprint);

template <class T> void adjust_timestamp(std::vector<T> xt, std::vector<std::vector<T> > &y, std::vector<std::vector<T> > &rety);
template <class T> T calc_rms(std::vector<T> x, std::vector<T> y);

template <class T> void input_file_to_vector_using(char* filename, std::vector<T> &v, int index);
#define fvec input_file_to_vector_using 
template <class T> void input_file_to_vector_vector(char* filename, std::vector<std::vector<T> > &vv);
#define fvecvec input_file_to_vector_vector

#endif
