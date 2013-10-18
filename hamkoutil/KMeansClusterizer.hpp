#ifndef K_MEANS_HPP_INCLUDED
#define K_MEANS_HPP_INCLUDED

#include <hamkoutil.hpp>
// ClusterizerData*の管理責任はKMeansClusterizerにある
class KMeansClusterizer : public Clusterizer {
    vector<ClusterizerData*> m_center; // owes KMeansClusterizer and initCenter
    void deleteCenter(void);
    void initCenter(int cluster_num);
    int reviseCenter(void); // 0: done, 1: the others
    int getMinimumClusterID(ClusterizerData* train_data_ti);
public:
    KMeansClusterizer(void);
    ~KMeansClusterizer(void);
    void train(int cluster_num);
    size_t getCenterNum(void);
    void clusterize(ClusterizerData* data);
    void printCenter(void);
};

#endif
