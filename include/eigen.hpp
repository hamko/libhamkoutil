#ifndef EIGEN_HPP_INCLUDED
#define EIGEN_HPP_INCLUDED

#include <Eigen/Core>
#define PRINT_MAT(X) cout << #X << ":\n" << X << endl << endl
#define PRINT_MAT2(X,DESC) cout << DESC << ":\n" << X << endl << endl
#define PRINT_FNC    cout << "[" << __func__ << "]" << endl
 
using namespace Eigen;

#endif
