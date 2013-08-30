#ifndef INPUT_FILE_TO_VEC_HPP
#define INPUT_FILE_TO_VEC_HPP

#include <iostream>
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

template <class T> void vecvecf(vector<vector<T> > &vv, const char* filename)
{
    ofstream ofs(filename);

    if (!ofs) {
        cerr << "ofs error" << endl;
        exit(1);
    }
    for (int i = 0; i < (int)vv.size(); i++) {
        for (int j = 0; j < (int)vv[0].size(); j++) {
            ofs << vv[i][j] << " ";
        }
        ofs << endl;
    }

    ofs.close();
}

template <class T> void vecvecf_trans(vector<vector<T> > &vv, const char* filename)
{
    ofstream ofs(filename);

    if (!ofs) {
        cerr << "ofs error" << endl;
        exit(1);
    }
    for (int j = 0; j < (int)vv[0].size(); j++) {
        for (int i = 0; i < (int)vv.size(); i++) {
            ofs << vv[i][j] << " ";
        }
        ofs << endl;
    }

    ofs.close();
}

template <class T> void vecf(vector<T> &v, const char* filename)
{
    ofstream ofs(filename);

    if (!ofs) {
        cerr << "ofs error" << endl;
        exit(1);
    }
    for (int i = 0; i < (int)v.size(); i++) 
        ofs << v[i] << endl;

    ofs.close();
}


#endif
