#include "stdafx.h"

string get_cpu_name()
{
	uint32_t data[4] = { 0 };

	_asm //anything under _asm in the curly braces is assembly language.
	{
		cpuid;
		mov data[0], ebx;
		mov data[4], edx;
		mov data[8], ecx;
	}

	return string((const char*) data);
}

void assembler()
{
	cout << "CPU is " << get_cpu_name() << endl;
}


int main(int argc, char* argv[])
{
	assembler();

	getchar();
	return 0;
}