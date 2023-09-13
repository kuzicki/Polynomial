#include "Polynomial.h"
#include <vector>
#include <iostream>

using namespace std;

Polynomial::Polynomial(size_t power, vector<float> coeffcients) : power(power) {
	this->coefficients = coeffcients;
}

Polynomial::Polynomial(size_t power, float* arr) : power(power) {
	coefficients.resize(power);
	for (int i = 0; i < power; i++) {
		coefficients[i] = arr[i];
	}
}

Polynomial::Polynomial(size_t power) : power(power) {
	coefficients.resize(power);
}

Polynomial::Polynomial() : power(0) { }

size_t Polynomial::getSize() const {
	return power;
}

float Polynomial::operator [](size_t pos) const {
	if (pos < power)
		return coefficients[pos];

	exit(EXIT_FAILURE);
}

float& Polynomial::operator [](size_t pos) {
	if (pos < power)
		return coefficients[pos];

	exit(EXIT_FAILURE);
}

float Polynomial::operator()(float arg) {
	float result = 0;
	for (int i = 0; i < power; i++) {
		result += pow(arg, i) * coefficients[i];
	}
	return result;
}

Polynomial Polynomial::operator+(const Polynomial& p2) {
	size_t power = this->power;
	if (this->power < p2.power) {
		power = p2.power;
	}
	Polynomial result(power);
	for (int i = 0; i < power; i++) {
		if (i < this->power)
			result[i] += coefficients[i];
		if (i < p2.power)
			result[i] += p2.coefficients[i];
	}

	while ((result.power - 1 != -1) && !result[result.power - 1]) {
		result.power--;
	}
	result.coefficients.resize(result.power);

	return result;
}

Polynomial& Polynomial::operator+=(const Polynomial& p2) {
	if (power < p2.power) {
		size_t oldPower = power;
		power = p2.power;
		coefficients.resize(power);
	}

	for (int i = 0; i < power && i < p2.power; i++) {
		coefficients[i] += p2.coefficients[i];
	}

	while ((power - 1 != -1) && !(*this)[power - 1]) {
		power--;
	}
	coefficients.resize(power);

	return *this;
}

Polynomial Polynomial::operator-(const Polynomial& p2) {
	size_t power = this->power;
	if (power < p2.power) {
		power = p2.power;
	}
	Polynomial result(power);
	for (int i = 0; i < power; i++) {
		if (i < this->power)
			result[i] += coefficients[i];
		if (i < p2.power)
			result[i] -= p2.coefficients[i];
	}

	while ((result.power - 1 != -1) && !result[result.power - 1]) {
		result.power--;
	}
	result.coefficients.resize(result.power);
	return result;
}

Polynomial& Polynomial::operator-=(const Polynomial& p2) {
	if (power < p2.power) {
		size_t oldPower = power;
		power = p2.power;
		coefficients.resize(power);
	}

	for (int i = 0; i < power; i++) {

		coefficients[i] -= p2.coefficients[i];
	}

	while ((power - 1 != -1) && !coefficients[this->power - 1])
		power--;

	coefficients.resize(power);
	return *this;
}

Polynomial Polynomial::operator*(const Polynomial& p2) {
	size_t power = this->power + p2.power - 1;
	Polynomial result(power);

	for (int i = 0; i < this->power; i++) {
		for (int j = 0; j < p2.power; j++) {
			result[i + j] += coefficients[i] * p2[j];
		}
	}
	return result;
}

Polynomial& Polynomial::operator*=(const Polynomial& p2) {
	vector<float> oldCoef = this->coefficients;
	size_t oldPower = this->power;
	this->power += p2.power - 1;
	coefficients.resize(this->power);
	fill(coefficients.begin(), coefficients.end(), 0.f);
	for (int i = 0; i < oldPower; i++) {
		for (int j = 0; j < p2.power; j++) {
			coefficients[i + j] += oldCoef[i] * p2[j];
		}
	}
	return *this;
}

Polynomial Polynomial::operator/(const Polynomial& p2) {
	Polynomial dividient = *this;
	size_t quotientPower = dividient.power - p2.power + 1;
	Polynomial quotient(quotientPower);
	Polynomial substruction;

	while (dividient.power >= p2.power) {
		float term = dividient[dividient.power - 1] / p2[p2.power - 1];
		size_t termPower = dividient.power - p2.power;
		quotient[termPower] = term;
		substruction = p2;
		substruction.multiply(term, termPower);
		dividient -= substruction;
	}
	return quotient;
}

Polynomial& Polynomial::operator/=(const Polynomial& p2) {
	size_t quotientPower = this->power - p2.power + 1;
	Polynomial quotient(quotientPower);
	Polynomial substruction;

	while (this->power >= p2.power) {
		float term = (*this)[this->power - 1] / p2[p2.power - 1];
		size_t termPower = this->power - p2.power;
		quotient[termPower] = term;
		substruction = p2;
		substruction.multiply(term, termPower);
		*this -= substruction;
	}
	*this = quotient;
	return *this;
}

bool Polynomial::operator==(const Polynomial& p2) const {
	if (power == p2.power && coefficients == p2.coefficients)
		return true;
	return false;
}

void Polynomial::multiply(float multiplier, size_t termPower) {
	size_t oldPower = power;
	power += termPower;
	coefficients.resize(power);
	move(coefficients.begin(), coefficients.begin() + oldPower, coefficients.begin() + termPower);
	fill(coefficients.begin(), coefficients.begin() + termPower, 0.f);
	for (float& value : this->coefficients) {
		value *= multiplier;
	}
}

float Polynomial::pow(float value, int power) {
	if (power < 1)
		return 1;
	float result = value;
	for (int i = 1; i < power; i++) {
		result *= value;
	}
	return result;
}