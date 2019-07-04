#pragma once

int suma(int a, int b) {
	if (b == 0)
		return a;
	return suma(++a, --b);
}

int resta(int a, int b) {
	if (b == 0)
		return a;
	return resta(--a, --b);
}

int mult(int a, int b) {
	if (b == 0)
		return 0;
	return suma(a, mult(a, b - 1));
}

int divi(int a, int b) {
	if (a < b)
		return 0;
	return 1 + divi(a - b, b);
}
