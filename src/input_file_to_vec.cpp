#include "hamkoutil.hpp"
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdlib>

using namespace std;

template <class T> void input_file_to_vector_using(char* filename, vector<T> &v, int index)
{
    ifstream ifs(filename);
    string s;
    istringstream is;
    if (ifs.fail()) {
        perror(filename);
        exit(1);
    }
    while (getline(ifs, s)) {
        is.clear(); is.str(s);
        int num = 0;
        char* tmp = strdup(s.c_str());
        for (char* tp = strtok(tmp, (const char*)" "); tp != NULL; tp = strtok(NULL, (const char*)" ")) {
            if (num++ == index) {
                v.push_back(atof(tp));
            }
        }
        free(tmp);
    }
    ifs.close();
}
template void input_file_to_vector_using<double> (char* filename, vector<double> &v, int index);
template void input_file_to_vector_using<float> (char* filename, vector<float> &v, int index);

template <class T> void input_file_to_vector_vector(char* filename, vector<vector<T> > &vv)
{
    ifstream ifs(filename);
    string s;
    istringstream is;
    if (ifs.fail()) {
        perror(filename);
        exit(1);
    }
    while (getline(ifs, s)) {
        is.clear(); is.str(s);
        int num = 0;
        char* tmp = strdup(s.c_str());
        for (char* tp = strtok(tmp, " "); tp != NULL; tp = strtok(NULL, " ")) {
            if ((int)vv.size() <= num) {
                vector<T> v;
                vv.push_back(v);
            }
            vv[num++].push_back(atof(tp));
        }
        free(tmp);
    }
    ifs.close();
}
template void input_file_to_vector_vector<double> (char* filename, vector<vector<double> > &vv);
template void input_file_to_vector_vector<float> (char* filename, vector<vector<float> > &vv);
