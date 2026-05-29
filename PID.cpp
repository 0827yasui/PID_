#include "PID.hpp"

PID::PID(float Kp_, float Ki_, float Kd_, float target_)
	: Kp(Kp_), Ki(Ki_), Kd(Kd_), target(target_) {
	current = 0.0f;
	error = 0.0f;
	PID_p = 0.0f;
	PID_i = 0.0f;
	PID_d = 0.0f;
	PID_value = 0.0f;
}

float PID::compute(float current_, float delta_t) {
	input_error(current_);
	p_control();
	i_control(delta_t);
	d_control(delta_t);
	return PID_control();
}

void PID::input_error(float current_) {	// åªç›äpìxÇÕ-360Å`360
	current = current_;
	pre_error = error;
	error = target - current;
	error = wrap_angle(error);
}
void PID::p_control() {
	PID_p = error;
}
void PID::i_control(float delta_t) {
	PID_i += error * delta_t;
}
void PID::d_control(float delta_t) {
	float diff = error - pre_error;
	diff = wrap_angle(diff);
	PID_d = diff / delta_t;
}
float PID::PID_control() {
	PID_value = Kp * PID_p + Ki * PID_i + Kd * PID_d;
	if (PID_value < -100.0f) PID_value = -100.0f;
	else if (PID_value > 100.0f) PID_value = 100.0f;
	return PID_value / 100.0f;
}


void PID::input_target(float target_) {
	target = target_;
}
void PID::input_Kp(float Kp_) {
	Kp = Kp_;
}
void PID::input_Ki(float Ki_) {
	Ki = Ki_;
}
void PID::input_Kd(float Kd_) {
	Kd = Kd_;
}

float PID::get_target() const { return target; }
float PID::get_Kp() const { return Kp; }
float PID::get_Ki() const { return Ki; }
float PID::get_kd() const { return Kd; }
float PID::wrap_angle(float angle) {
	while (angle > 180.0f) angle -= 360.0f;
	while (angle < -180.0f) angle += 360.0f;
	return angle;
}
