#ifndef ADJUST_TIMESTAMP_HPP
#define ADJUST_TIMESTAMP_HPP

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/* yをxtのタイムスタンプに変更してretyに入れる */
// NOTE 
// y[0]はyのタイムスタンプ
// xt, y[0]は昇順ソート済みが前提
// xtがy[0]に比べて疎であることが望ましい
template <class T> void adjust_timestamp(vector<T> xt, vector<vector<T> > &y, vector<vector<T> > &rety) 
{
     // retyの確保
     vector<vector<T> > tmp;
     for (int i = 0; i < (int)y.size(); i++) {
         vector<T> vy(xt.size(), NAN);
         tmp.push_back(vy);
     }
     tmp.swap(rety);

     int prevj = 0;
     for (int i = 0; i < (int)xt.size(); i++) {
         /* y[0][j] <= xt[i] < y[0][j+1]を探す。 */
         // 存在しないので門前払い
         if (xt[i] < y[0][0] || xt[i] >= y[0][y[0].size() - 1]) 
             continue;
         int j;
         for (j = prevj; j < (int)y[0].size() - 1; j++) // TODO ここをバイナリサーチに
             if (y[0][j] <= xt[i] && xt[i] < y[0][j+1])
                 break;
         prevj = j;

         // 線形補完
         for (int h = 0; h < (int)y.size(); h++) 
             rety[h][i] = y[h][j] + (xt[i] - y[0][j]) / (y[0][j+1] - y[0][j]) * (y[h][j+1] - y[h][j]);
     }
}

template <class T> T calc_rms(vector<T> x, vector<T> y)
{
    if (x.size() != y.size())
        return -1;
    int num = 0;
    T sum = 0.0;
    for (int i = 0; i < (int)x.size(); i++) {
        if (isnan(x[i]) || isnan(y[i]))
            continue;
        num++;
        sum += (x[i] - y[i]) * (x[i] - y[i]);
    }
    if (!num)
        return -1;

    return sqrt(sum / num);
}

template <class T> T calc_rms(const vector<vector<T> > &x, const vector<vector<T> > &y)
{
    if (!x.size() || !y.size() || x.size() != y.size() || x[0].size() != y[0].size())
        return -1;
    int num = 0;
    T sum = 0.0;
    for (int i = 0; i < (int)x.size(); i++) {
        for (int j = 0; j < (int)x[0].size(); j++) {
            if (isnan(x[i][j]) || isnan(y[i][j]))
                continue;
            num++;
            sum += (x[i][j] - y[i][j]) * (x[i][j] - y[i][j]);
        }
    }
    if (!num)
        return -1;

    return sqrt(sum / num);
}

#endif
