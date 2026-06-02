#include <iostream>
#include "PID.cpp"
#include "PID_print.hpp"

int main()
{
	PIDPrint pid_print;
	pid_print.input_delta_t(0.1f);
	pid_print.input_K(9.0f, 0.0f, 0.0f);
	pid_print.input_target(100.0f);
	pid_print.input_current_count(7000);
	pid_print.input_coefficient(1000.0f);
	pid_print.input_tolerance(0.3f);
	pid_print.input_stable_required(10);

	pid_print.decide_sum(0.0f, 1);
	pid_print.decide_count();

	pid_print.print();

	return 0;
}
