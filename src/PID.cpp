#include "PID.h"
#include <iostream>
#define UNINITIALIAED_CTE 0

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;

  p_error = 0;
  i_error = 0;
  d_error = 0;

  prev_cte_ = UNINITIALIAED_CTE;
}

void PID::UpdateError(double cte) {

  // initialize prev_cte if uninitialized
  if (prev_cte_ == UNINITIALIAED_CTE) {
    prev_cte_ = cte;
  }

  p_error = cte;
  i_error += cte;
  d_error = cte - prev_cte_;

  prev_cte_ = cte;
}

double PID::TotalError() {
  double error = Kp_ * p_error + Ki_ * i_error + Kd_ * d_error;
  if (error > 1) error = 1;
  else if (error < -1) error = -1;
  return error;
}
