#ifndef INC_ENCODER_HPP_
#define INC_ENCODER_HPP_

class _Encoder {
public:
	_Encoder();

	float run(int resolution_, int multiplication_, int cnt);

	void input_resolution_multiplication(int resolution_, int multiplication_);
	void input_angle(int cnt_);
	float get_angle();
private:
	int resolution = 0;
	int multiplication = 0;

	int cnt = 0;
	float angle = 0.0f;
};

#endif /* INC_ENCODER_HPP_ */
