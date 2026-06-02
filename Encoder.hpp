
#ifndef INC_ENCODER_HPP_
#define INC_ENCODER_HPP_
#include "stdint.h"

class _Encoder {
public:
	_Encoder();

	float run(int resolution_, int multiplication_, int16_t cnt);

	void input_resolution_multiplication(int resolution_, int multiplication_);
	void input_angle(int16_t cnt_);
	float get_angle();
private:
	int resolution = 0;
	int multiplication = 0;

	int16_t cnt = 0;
	float angle = 0.0f;
};

#endif /* INC_ENCODER_HPP_ */
