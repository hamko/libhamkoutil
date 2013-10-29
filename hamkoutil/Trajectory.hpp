#pragma once
#include <hamkoutil.hpp>

#define TrajectoryAt(trajectory, time, type, i) (trajectory.at(time)[type].at(i))
enum TrajectoryTypes{
    JOINT_ANGLE,
    JOINT_ANGLE_VEL,
    TACTILE,
    VISUAL,
    OUTPUT_FORCE,
    _MAX_TRAJECTORY_TYPES
};

typedef map<int, vd> State; 
typedef vector<State> Trajectory;

typedef struct _TrajectoryRange {
    Trajectory* traj; // 解放責任はより上位
    Trajectory::iterator beginit;
    Trajectory::iterator endit;
} TrajectoryRange;
