#ifndef INC_PID_PRINT_HPP_
#define INC_PID_PRINT_HPP_

#include "PID.hpp"
#include <vector>
#include <iostream>
#include <cmath>

class PIDPrint {
public:
	PIDPrint();
	void input_current_count(int current_count_);
	void input_coefficient(float coefficient_);
	void input_target(float target_);
	void input_K(float Kp_, float Ki_, float Kd_);
	void input_delta_t(float delta_t_);
	void input_tolerance(float tolerance_);
	void input_stable_required(float stable_required_);

	void decide_sum(float current, int num);
	void decide_count();
	void print();

	float return_max_sum();
	int return_max_count();
private:
	PID pid = PID(0.1f, 0.1f, 0.1f, 200.0f);
	int current_count = 0;
	float delta_t = 0.0f;
	float coefficient = 10.0f;

	float tolerance = 0.0f;
	int stable_required = 0;
	float target = 0.0f;

	std::vector<float> angle;
	std::vector<float> sum;
	std::vector<int> count;
	float _wrap_angle(float angle);
};

#endif