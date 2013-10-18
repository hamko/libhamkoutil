#include <hamkoutil.hpp>

/****************/
/* Cluster Data */
/****************/
ClusterizerData::ClusterizerData(size_t data_size, int cluster_id)
{
    m_data.resize(data_size, 0);
    setID(cluster_id);
}
ClusterizerData::ClusterizerData(size_t data_size)
{
    m_data.resize(data_size, 0);
}
void ClusterizerData::setData(int index, double val)
{
    m_data.at(index) = val;
}
void ClusterizerData::setID(int cluster_id)
{
    m_cluster_id = cluster_id;
}
ClusterizerData::~ClusterizerData(void)
{
}
size_t ClusterizerData::getSize(void)
{
    return m_data.sz;
}
double ClusterizerData::getData(int i)
{
    return m_data.at(i);
}
int ClusterizerData::getID(void)
{
    return m_cluster_id;
}
double ClusterizerData::calcDistance(ClusterizerData* data)
{
    assert(data->getSize() == this->getSize());

    double sum = 0;
    for (size_t cdi = 0; cdi < getSize(); cdi++) 
        sum += square(this->getData(cdi) - data->getData(cdi));
//    cout << sum << endl;
    return sqrt(sum);
}
void ClusterizerData::print(void)
{
    cout << getID() << ": ";
    for (size_t i = 0; i < m_data.sz; i++) {
        cout << getData(i) << " ";
    }
    cout << endl;
}


