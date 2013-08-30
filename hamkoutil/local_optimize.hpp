#ifndef LOCAL_OPTIMIZE_HPP_INCLUDED
#define LOCAL_OPTIMIZE_HPP_INCLUDED
#include <vector>

class LocalOptimizer {
private:
    std::vector<double> m_state;
    std::vector<double> m_step;
    bool m_dir; // dir == false : min, dir == true : max
    double (*m_evaluate_func)(std::vector<double> vec);
public:
    LocalOptimizer(double (*evaluate_func)(std::vector<double> vec));
    void setDirMax(void);
    void setDirMin(void);
    int getStateNum(void);
    void getState(std::vector<double> &vec);
    void setEvaluateFunc(double (*evaluate_func)(std::vector<double> vec));
    void addState(double initial_state, double step);
    double optimizeUsing(int index);
};

#endif
