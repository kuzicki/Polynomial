#pragma once
#include <vector>
/*!
	\brief Polynomial class used for polynomial related stuff
	\author Kuzicki
	\version 1.0
	\date september 5, 2023

	This class has all basic functionality for working with polynomials. 
	It has overloaded (), [], +, +=, -, -=, *, *=, /, /=, == operators for simplicity
	Also the class has a public method getSize() for getiing the number of the maximum term in the polynomial
*/

class Polynomial {
public:
	/*!
	Constructor which takes term of the polynomial and vector object with coefficients starting from x^0
	*/
	Polynomial(size_t power, std::vector<float> coeffcients);
	/*!
	Constructor which takes term of the polynomial and array of coefficients starting from x^0
	*/
	Polynomial(size_t power, float* arr);
	/*!
	Constructor which takes term of the polynomial
	*/
	Polynomial(size_t power);
	/*!
	Constructor which takes nothing 
	*/
	Polynomial();
	/*!
	Returns the max term of the polynomial
	\return The max term of the polynomial
	*/
	size_t getSize() const;
	/*!
	Returns value of coefficient with the term of pos
	\param pos Position of the coefficent
	\return Value of coefficient with the term of pos
	*/
	float operator [](size_t pos) const;
	/*!
	Returns a reference to the coefficient which allows to change the value
	\param pos Position of the coefficient
	\return Reference of coefficient with the term of pos
	*/
	float& operator [](size_t pos);
	/*!
	Calculates the value of the polynomial with certain arg
	\param arg Value of argument 
	\return Value of the polynomial
	*/
	float operator()(float arg);
	/*!
	Calculates the sum of the two polynomials
	\param p2 Second polynomial
	\return Polynomial object with the sum of the two polynomials
	*/
	Polynomial operator+(const Polynomial& p2);
	/*!
	Calculates the sum of the two polynomials
	\param p2 Second polynomial
	\return Polynomial reference with the sum of the two polynomials
	*/
	Polynomial& operator+=(const Polynomial& p2);
	/*!
	Calculates the difference of the two polynomials
	\param p2 Second polynomial
	\return Polynomial object with the difference of the two polynomials
	*/
	Polynomial operator-(const Polynomial& p2);
	/*!
	Calculates the difference of the two polynomials
	\param p2 Second polynomial
	\return Polynomial reference with the difference of the two polynomials
	*/
	Polynomial& operator-=(const Polynomial& p2);
	/*!
	Calculates the multiplication of the two polynomials
	\param p2 Second polynomial
	\return Polynomial object with the multiplication of the two polynomials
	*/
	Polynomial operator*(const Polynomial& p2);
	/*!
	Calculates the multiplication of the two polynomials
	\param p2 Second polynomial
	\return Polynomial reference with the multiplication of the two polynomials
	*/
	Polynomial& operator*=(const Polynomial& p2);
	/*!
	Calculates the division of the two polynomials
	\param p2 Second polynomial
	\return Polynomial object with the division of the two polynomials
	*/
	Polynomial operator/(const Polynomial& p2);
	/*!
	Calculates the division of the two polynomials
	\param p2 Second polynomial
	\return Polynomial reference with the division of the two polynomials
	*/
	Polynomial& operator/=(const Polynomial& p2);
	/*!
	Finds out if the objects are equal by checking max term and power accordingly
	\param p2 Second polynomial
	\return A boolean 
	*/
	bool operator==(const Polynomial& p2) const;
private:
	size_t power;
	std::vector<float> coefficients;
	/*!
	A private function mainly used for the division methods which multiplies a polynomial by a monomial
	\param multiplier The coefficient of the monomial
	\param termPower The term of the monomial
	\return Modified object after the multiplication
	*/
	void multiply(float multiplier, size_t termPower);
	/*!
	A private function which raises the value by the power variable
	\param value The value to raise in the power
	\param power The power
	\return A raised value by the power variable
	*/
	float pow(float value, int power);
};