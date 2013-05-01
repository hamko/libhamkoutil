#ifndef INPUT_FILE_TO_VEC_HPP
#define INPUT_FILE_TO_VEC_HPP

#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdlib>
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

template <class T> void vecvecf(std::vector<std::vector<T> > &vv, const char* filename)
{
    std::ofstream ofs(filename);

    if (!ofs) {
        std::cerr << "ofs error" << std::endl;
        exit(1);
    }
    for (int i = 0; i < (int)vv.size(); i++) {
        for (int j = 0; j < (int)vv[0].size(); j++) {
            ofs << vv[i][j] << " ";
        }
        ofs << std::endl;
    }

    ofs.close();
}

template <class T> void vecvecf_trans(std::vector<std::vector<T> > &vv, const char* filename)
{
    std::ofstream ofs(filename);

    if (!ofs) {
        std::cerr << "ofs error" << std::endl;
        exit(1);
    }
    for (int j = 0; j < (int)vv[0].size(); j++) {
        for (int i = 0; i < (int)vv.size(); i++) {
            ofs << vv[i][j] << " ";
        }
        ofs << std::endl;
    }

    ofs.close();
}

template <class T> void vecf(std::vector<T> &v, const char* filename)
{
    std::ofstream ofs(filename);

    if (!ofs) {
        std::cerr << "ofs error" << std::endl;
        exit(1);
    }
    for (int i = 0; i < (int)v.size(); i++) 
        ofs << v[i] << std::endl;

    ofs.close();
}


#endif
