// https://www.nayuki.io/page/how-to-implement-the-discrete-fourier-transform
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <stdexcept>

using std::size_t;
using std::complex;
using std::cout;
using std::endl;
using std::vector;

// Mutable global variable
static double maxLogError = -INFINITY;

// Random number generation
std::default_random_engine randGen((std::random_device())());



// La funcion devuelve un vector de numeros complejos
vector<complex<double>> computeDft(const vector<complex<double>> &input) {
	// Declaramos el vector que devolveremos
	vector<complex<double> > output;
	// Declaramos un entero sin signo para el tam
	size_t n = input.size();
	for (size_t k = 0; k < n; k++) {  // For each output element
		complex<double> sum(0.0, 0.0);
		for (size_t t = 0; t < n; t++) {  // For each input element
			double angle = 2 * M_PI * t * k / n;
			sum += input[t] * exp(-angle);
		}
		output.push_back(sum);
	}
	return output;
}

static vector<complex<double> > randomComplexes(int n) {
	std::uniform_real_distribution<double> valueDist(-1.0, 1.0);
	vector<complex<double> > result;
	for (int i = 0; i < n; i++)
		result.push_back(complex<double>(valueDist(randGen), valueDist(randGen)));
	return result;
}

int main() {
	cout << "JAJAJAJA" << endl;

	system("PAUSE");
    return 0;
}