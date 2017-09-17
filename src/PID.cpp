#include "PID.h"

using namespace std;
using namespace std::chrono;

/*
* TODO: Complete the PID class.
*/

PID::PID(double Kp, double Ki, double Kd):
  p_error(0), i_error(0), d_error(0), prev_cte(0), total_cte(0),
  Kp(Kp), Ki(Ki), Kd(Kd),
  has_prev_cte(false)
{}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  has_prev_cte = false;
  total_cte = 0.0;
}

void PID::UpdateError(double cte) { 
  //Calculate P
  p_error = -Kp*cte;

  //Calculate D
  milliseconds delta_t;
  steady_clock::time_point current_time = steady_clock::now(); 

  if (!has_prev_cte) {
    prev_cte = cte;
    has_prev_cte = true;
  }
  else {
    delta_t = duration_cast<milliseconds>(current_time - last_time_stamp);
  }
  d_error = -Kd * (cte - prev_cte)/(static_cast<double>(delta_t.count())*1000);
  prev_cte = cte;
  if (last_time_stamp != current_time) {
    last_time_stamp = current_time;
  }

  //Calculae I
  total_cte += cte;

  i_error = -Ki * total_cte;
}

double PID::TotalError() {
  return p_error + i_error + d_error;
}

