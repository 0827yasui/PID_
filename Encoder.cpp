

#include "Encoder.hpp"

_Encoder::_Encoder() {}

float _Encoder::run(int resolution_, int multiplication_, int cnt) {
	input_resolution_multiplication(resolution_, multiplication_);
	input_angle(cnt);
	return get_angle();
}
void _Encoder::input_resolution_multiplication(int resolution_, int multiplication_) {
	resolution = resolution_;
	multiplication = multiplication_;
}
void _Encoder::input_angle(int cnt_) {
	cnt = cnt_;
}
float _Encoder::get_angle() {
	angle = 360.0f / (float)(resolution * multiplication) * (float)cnt;
	return angle;
}
