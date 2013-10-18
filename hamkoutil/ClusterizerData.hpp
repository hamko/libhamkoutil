#ifndef CLUSTERIZER_DATA_INCLUDED
#define CLUSTERIZER_DATA_INCLUDED

#include <hamkoutil.hpp>
class ClusterizerData {
    vd m_data;
    int m_cluster_id;
public:
    ClusterizerData(size_t data_size, int cluster_id);
    ClusterizerData(size_t data_size);
    virtual ~ClusterizerData(void);
    size_t getSize(void);
    void setData(int index, double val);
    void setID(int cluster_id);
    double getData(int i);
    int getID(void);
    double calcDistance(ClusterizerData* data);
    void print(void);
};

#endif
