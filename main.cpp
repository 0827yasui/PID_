
#include <iostream>
#include "PID.cpp"
#include "PID_print.hpp"

int main()
{
	PIDPrint pid_print;
	pid_print.input_delta_t(0.1f);
	pid_print.input_K(1.0f, 0.001f, 0.001f);
	pid_print.input_target(200.0f);
	pid_print.input_current_count(700000);
	pid_print.input_coefficient(1000.0f);

	pid_print.decide_sum(100.0f, 1);
	pid_print.decide_count();

	pid_print.print();

	return 0;
}
