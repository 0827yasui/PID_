#ifndef INC_PID_HPP_
#define INC_PID_HPP_

class PID {
public:
	PID(float Kp_, float Ki_, float Kd_, float target_);

	float compute(float current_, float delta_t);
	void input_error(float current_);
	void p_control();
	void i_control(float delta_t);
	void d_control(float delta_t);
	float PID_control();

	void input_target(float target_);
	void input_Kp(float Kp_);
	void input_Ki(float Ki_);
	void input_Kd(float Kd_);

	float get_target() const;
	float get_Kp() const;
	float get_Ki() const;
	float get_kd() const;
private:
	float Kp, Ki, Kd;
	float target;
	float current = 0.0f;
	float error = 0.0f;
	float pre_error = 0.0f;

	float PID_p = 0.0f;
	float PID_i = 0.0f;
	float PID_d = 0.0f;
	float PID_value = 0.0f;

	float wrap_angle(float angle);
};

#endif