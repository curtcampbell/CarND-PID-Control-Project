#ifndef PID_H
#define PID_H

#include <chrono>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double prev_cte;
  double total_cte;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  bool has_prev_cte;

  std::chrono::steady_clock::time_point last_time_stamp;
  /*
  * Constructor
  */
  PID(double Kp, double Ki, double Kd);

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
