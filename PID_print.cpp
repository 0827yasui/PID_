
#include "PID_print.hpp"

PIDPrint::PIDPrint() {}

void PIDPrint::input_current_count(int current_count_) {
	current_count = current_count_;
}
void PIDPrint::input_coefficient(float coefficient_) {
	coefficient = coefficient_;
}
void PIDPrint::input_target(float target_) {
	pid.input_target(_wrap_angle(target_));
}
void PIDPrint::input_K(float Kp_, float Ki_, float Kd_) {
	pid.input_Kp(Kp_);
	pid.input_Ki(Ki_);
	pid.input_Kd(Kd_);
}
void PIDPrint::input_delta_t(float delta_t_) {
	if (delta_t_ == 0.0f) {
		delta_t = 0.1f;
		std::cout << "0はダメっす" << std::endl;
	}
	else {
		delta_t = delta_t_;
	}
}
void PIDPrint::decide_sum(float current, int num) {
	sum.resize(current_count);
	angle.resize(current_count + 1);
	angle[0] = _wrap_angle(current);
	float pre_PID_value = 0.0f;
	for (int i = 0; i < current_count; i++) {
		angle[i + 1] = angle[i] + pre_PID_value * num;
		sum[i] = pid.compute(_wrap_angle(angle[i + 1]), delta_t);
		pre_PID_value = sum[i];
	}
}
void PIDPrint::decide_count() {
	count.resize(current_count);
	for (int i = 0; i < current_count; i++) {
		count[i] = (int)(sum[i] * coefficient);
	}
}
void PIDPrint::print() {
	int max_count = return_max_count();
	for (int i = 0; i < current_count; i++) {
		std::cout << "現在角:" << _wrap_angle(angle[i + 1]) << "カウント数" << i << std::endl;

		for (int i2 = max_count; i2 > 0; i2--) {
			if (count[i] < 0 && abs(count[i]) >= i2) {
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << "|";
		for (int i2 = 0; i2 < max_count; i2++) {
			if (count[i] > 0 && abs(count[i]) >= i2) {
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

float PIDPrint::return_max_sum() {
	float max_sum = 0.0f;
	for (int i = 0; i < current_count; i++) {
		if (max_sum < fabs(sum[i])) max_sum = fabs(sum[i]);
	}
	return max_sum;
}
int PIDPrint::return_max_count() {
	int max_count = 0;
	for (int i = 0; i < current_count; i++) {
		if (max_count < abs(count[i])) max_count = abs(count[i]);
	}
	return max_count;
}
float PIDPrint::_wrap_angle(float angle) {
	while (angle > 180.0f) angle -= 360.0f;
	while (angle < -180.0f) angle += 360.0f;
	return angle;
}
