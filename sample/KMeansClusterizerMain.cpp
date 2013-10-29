#include <hamkoutil.hpp>

int main(void)
{
    srand((unsigned int)time(NULL));

    KMeansClusterizer cl;

    // Train
    for (int i = 0; i < 1000; i++) {
        ClusterizerData* data = new ClusterizerData(2);
        int r = rand() % 3;
        data->setData(0, 200*r+rand()%100);
        data->setData(1, 200*r+rand()%100);
        cl.addData(data);
    }
    cl.train(3);
    cout << "#Train" << endl;
    cl.printTrainData();

    // Test
    vd testdata = {450, 380};
    cout << cl.clusterize(testdata) << "#Test" << endl;
    

    return 0;
}
