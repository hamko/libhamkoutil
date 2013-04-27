#ifndef INPUT_FILE_TO_VEC_HPP
#define INPUT_FILE_TO_VEC_HPP

#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdlib>

using namespace std;

template <class T> void fvec(char* filename, vector<T> &v, int index)
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

template <class T> void fvecvec(char* filename, vector<vector<T> > &vv)
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

#endif