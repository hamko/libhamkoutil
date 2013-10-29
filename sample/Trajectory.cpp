#include <hamkoutil.hpp>

double a[5] = {10, 3, 5, 65, 7};
double b[3] = {1, 6, 0};

int main(void)
{
    Trajectory t;

    // 1
    State s1;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) 
        s1[JOINT_ANGLE].push_back(a[i]);
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) 
        s1[JOINT_ANGLE_VEL].push_back(b[i]);
    t.push_back(s1);
    // 2
    State s2;
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) 
        s2[JOINT_ANGLE].push_back(b[i]);
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) 
        s2[JOINT_ANGLE_VEL].push_back(a[i]);
    t.push_back(s2);

    // Print
    cout << TrajectoryAt(t, 1, JOINT_ANGLE_VEL, 2) << endl; // s2のJOINT_ANGLE_VELの添字2
    for (auto state : t) {
        for (auto type : state) {
            for (auto val : type.second) 
                cout << val << " ";
            cout << ";";
        }
        cout << endl;
    }

    return 0;
}
