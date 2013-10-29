#ifndef CLUSTERIZER_HPP_INCLUDED
#define CLUSTERIZER_HPP_INCLUDED

#include <vector>
#include "hamkoutil/ClusterizerData.hpp"

class Clusterizer {
protected:
    vector<ClusterizerData*> m_train_data; // owes Clusterizer
public:
    Clusterizer(void);
    virtual ~Clusterizer(void);
    void addData(ClusterizerData* data);
    size_t getTrainDataSize(void);

    virtual void train(int cluster_num) = 0;
    virtual int clusterize(vd& data) = 0;
    void printTrainData(void);
};

#endif
