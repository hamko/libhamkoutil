#include <iostream>
#include <vector>
#include <cmath>
#include "local_optimize.hpp"

using namespace std;

LocalOptimizer::LocalOptimizer(double (*evaluate_func)(vector<double> vec))
    : m_dir(false), m_evaluate_func(evaluate_func)
{
}

void LocalOptimizer::setDirMax(void)
{
    m_dir = true;
}

void LocalOptimizer::setDirMin(void)
{
    m_dir = false;
}

int LocalOptimizer::getStateNum(void)
{
    return (int)m_state.size();
}

void LocalOptimizer::getState(vector<double> &vec)
{
    vec = m_state;
}

void LocalOptimizer::setEvaluateFunc(double (*evaluate_func)(std::vector<double>))
{
    m_evaluate_func = evaluate_func;
}

void LocalOptimizer::addState(double initial_state, double step)
{
    m_state.push_back(initial_state);
    m_step.push_back(step);
}

double LocalOptimizer::optimizeUsing(int index)
{
    if (index < 0 || index >= (int)m_state.size()) {
        cerr << "invalid index" << endl;
        return NAN;
    }
    m_state[index] += m_step[index];
    double plus = m_evaluate_func(m_state);
    m_state[index] -= m_step[index];

    m_state[index] -= m_step[index];
    double minus = m_evaluate_func(m_state);
    m_state[index] += m_step[index];

    if ((m_dir && plus > minus) || (!m_dir && plus < minus)) {
        m_state[index] += m_step[index];
        return plus;
    } else {
        m_state[index] -= m_step[index];
        return minus;
    }
}
