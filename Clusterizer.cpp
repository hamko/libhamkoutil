#include <hamkoutil.hpp>
/****************/
/* Clusterizer  */
/****************/

Clusterizer::Clusterizer(void)
{
}

size_t Clusterizer::getTrainDataSize(void)
{
    return m_train_data.sz;
}

Clusterizer::~Clusterizer(void)
{
    for (size_t i = 0; i < getTrainDataSize(); i++)
        delete m_train_data.at(i);
}

void Clusterizer::addData(ClusterizerData* data)
{
    assert(m_train_data.empty() || m_train_data.at(0)->getSize() == data->getSize());
    m_train_data.pb(data); 
}

void Clusterizer::printTrainData(void)
{
    for (size_t ti = 0; ti < getTrainDataSize(); ti++) 
        m_train_data.at(ti)->print();
}


