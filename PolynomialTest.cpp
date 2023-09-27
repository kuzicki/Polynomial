#include "pch.h"
#include "CppUnitTest.h"
#include "Polynomial.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

std::wstring ToString(const Polynomial& polynomial) {
	std::wstringstream _s;
	for (int i = 0; i < polynomial.getSize(); i++) {
		_s << polynomial[i];
	}
	return _s.str();
}

namespace UnitTest1
{
	TEST_CLASS(TestClass)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			Polynomial p(3, { 1, 2, 3 });
			Assert::AreEqual<size_t>(3, p.getSize());
		}

		TEST_METHOD(TestMethod2)
		{
			Polynomial p(3, { 1, 2, 3 });
			Assert::AreEqual<float>(17.f, p(2));
		}

		TEST_METHOD(TestMethod3)
		{
			Polynomial p1(3, { 1, 4, 5 });
			Polynomial p2(4, { 1, 6, 9, 10 });
			Polynomial result = p1 + p2;
			Polynomial expected(4, { 2, 10, 14, 10 });
			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(TestMethod4)
		{
			Polynomial p1(3, { 1, 4, 5 });
			Polynomial p2(4, { 5, 6, 9, 10 });
			p1 += p2;
			Polynomial expected(4, { 6, 10, 14, 10 });
			Assert::AreEqual(expected,  p1);
		}

		TEST_METHOD(TestMethod5)
		{
			Polynomial p1(3, { 1, 4, 5 });
			Polynomial p2(4, { 5, 6, 9, 10 });
			Polynomial result = p1 - p2;
			Polynomial expected(4, { -4, -2, -4, -10 });
			Assert::AreEqual(result,  expected);
		}

		TEST_METHOD(TestMethod6)
		{
			Polynomial p1(3, { 1, 4, 5 });
			Polynomial p2(4, { 5, 6, 9, 10 });
			p1 -= p2;
			Polynomial expected(4, { -4, -2, -4, -10 });
			Assert::AreEqual(p1,  expected);
		}

		TEST_METHOD(TestMethod7)
		{
			Polynomial p1(3, { 1, 4, 5 });
			Polynomial p2(4, { 5, 6, 9, 4 });
			Polynomial result = p1 * p2;
			Polynomial expected(6, { 5, 26, 58, 70, 61, 20 });
			Assert::AreEqual(result,  expected);
		}

		TEST_METHOD(TestMethod8)
		{
			Polynomial p1(3, { 1, 4, 5 });
			Polynomial p2(4, { 5, 6, 9, 4 });
			p1 *= p2;
			Polynomial expected(6, { 5, 26, 58, 70, 61, 20 });
			Assert::AreEqual(p1,  expected);
		}

		TEST_METHOD(TestMethod9)
		{
			Polynomial p1(3, { -4, 7, 2 });
			Polynomial p2(2, { -3, 1 });
			Polynomial result = p1 / p2;
			Polynomial expected(2, { 13, 2 });
			Assert::AreEqual(result,  expected);
		}

		TEST_METHOD(TestMethod10)
		{
			Polynomial p1(3, { -4, 7, 2 });
			Polynomial p2(2, { -3, 1 });
			p1 /= p2;
			Polynomial expected(2, { 13, 2 });
			Assert::AreEqual(p1,  expected);
		}

		TEST_METHOD(TestMethod11)
		{
			Polynomial p1(3, { -20, 7, 6 });
			Polynomial p2(2, { 5, 2 });
			p1 /= p2;
			Polynomial expected(2, { -4, 3 });
			Assert::AreEqual(p1,  expected);
		}

		TEST_METHOD(TestMethod12)
		{
			Polynomial p1(3, { -20, 7, 6 });
			Polynomial p2(2, { 5, 2 });
			Polynomial result = p1 / p2;
			Polynomial expected(2, { -4, 3 });
			Assert::AreEqual(result , expected);
		}

		TEST_METHOD(TestMethod13)
		{
			Polynomial p1(2, { 5, 2 });
			Polynomial p2(3, { -20, 7, 6 });
			Polynomial result = p1 / p2;
			Polynomial expected;
			Assert::AreEqual(result,  expected);
		}

		TEST_METHOD(TestMethod14)
		{
			Polynomial p1(3, { 5, 4, 9 });
			Polynomial p2(2, { -5, -4 });
			Polynomial result = p1 + p2;
			Polynomial expected(3, { 0, 0, 9 });
			Assert::AreEqual(result,  expected);
		}

		TEST_METHOD(TestMethod15)
		{
			Polynomial p1(3, { 5, 4, 9 });
			Polynomial p2(2, { -5, -4 });
			p1 += p2;
			Polynomial expected(3, { 0, 0, 9 });
			Assert::AreEqual(p1,  expected);
		}

		TEST_METHOD(TestMethod16)
		{
			Polynomial p1(3, { 5, 4, 9 });
			Polynomial p2(3, { -5, -4, -9 });
			Polynomial result = p1 + p2;
			Polynomial expected;
			Assert::AreEqual(result,  expected);
		}

		TEST_METHOD(TestMethod17)
		{
			Polynomial p1(3, { 5, 4, 9 });
			Polynomial p2(3, { 5, 4, 9 });
			Polynomial result = p1 - p2;
			Polynomial expected;
			Assert::AreEqual(result,  expected);
		}

		TEST_METHOD(TestMethod18)
		{
			Polynomial p1(3, { 5, 4, 9 });
			Polynomial p2(3, { 5, 4, 9 });
			p1 -= p2;
			Polynomial expected;
			Assert::AreEqual(p1,  expected);
		}

		TEST_METHOD(TestMethod19)
		{
			Polynomial p1(2, { -3, 4 });
			Polynomial p2(3, { -1, 2, 5 });
			Polynomial result = p1 * p2;
			Polynomial expected(4, { 3, -10, -7, 20});
			Assert::AreEqual(result,  expected);
		}

		TEST_METHOD(TestMethod20)
		{
			Polynomial p1(2, { -3, 4 });
			Polynomial p2(1, { 2 });
			Polynomial result = p2 * p1;
			Polynomial expected(2, { -6, 8 });
			Assert::AreEqual(result,  expected);
		}

		TEST_METHOD(TestMethod21)
		{
			Polynomial p1(2, { -3, 4 });
			Polynomial p2(3, { -1, 2, 5 });
			p1 *= p2;
			Polynomial expected(4, { 3, -10, -7, 20 });
			Assert::AreEqual(p1,  expected);
		}

		TEST_METHOD(TestMethod22)
		{
			Polynomial p1(2, { -3, 4 });
			
			Assert::AreEqual<float>(5, p1(2));
		}

		TEST_METHOD(TestMethod23)
		{
			Polynomial p1(5, { -3, 4, 5, 0, 10 });

			Assert::AreEqual<float>(10, p1[4]);
		}

		TEST_METHOD(TestMethod24)
		{
			Polynomial p1(5, { -3, 4, 5, 0, 10 });
			Polynomial p2(5, { -10, -2, -3, 0, -10 });

			Polynomial result = p1 + p2;

			Polynomial expected(3, { - 13, 2, 2 });

			Assert::AreEqual(expected,  result);
		}

		TEST_METHOD(TestMethod25)
		{
			Polynomial p1(5, { -3, 4, 5, 0, 10 });
			Polynomial p2(5, { 10, 2, 3, 0, 10 });

			Polynomial result = p1 - p2;

			Polynomial expected(3, { -13, 2, 2 });

			Assert::AreEqual(expected,  result);
		}

		TEST_METHOD(TestMethod26)
		{
			Polynomial p1(5, { -3, 4, 5, 0, 10 });
			Polynomial p2(5, { 10, 2, 3, 0, 10 });

			p1 -= p2;

			Polynomial expected(3, { -13, 2, 2 });

			Assert::AreEqual(p1,  expected);
		}

		TEST_METHOD(TestMethod27)
		{
			Polynomial p1(2, { 2, 1 });
			Polynomial p2(2, { 3, 1 });

			Polynomial result = p1 * p2;

			Polynomial expected(3, { 6, 5, 1 });

			Assert::AreEqual(expected,  result);
		}

		TEST_METHOD(TestMethod28)
		{
			Polynomial p1(2, { 2, 1 });
			Polynomial p2(2, { 3, 1 });

			p1 *= p2;

			Polynomial expected(3, { 6, 5, 1 });

			Assert::AreEqual(expected,  p1);
		}

		TEST_METHOD(TestMethod29)
		{
			Polynomial p1(3, { 1, 3, 2 });
			Polynomial p2(2, { 2, 1 });

			Polynomial result = p1 / p2;

			Polynomial expected(2, { -1, 2 });

			Assert::AreEqual(expected,  result);
		}

		TEST_METHOD(TestMethod30)
		{
			Polynomial p1(4, { -21, 5, 20, 6 });
			Polynomial p2(2, { 7, 3 });
			Polynomial expected(3, { -3, 2, 2 });

			Polynomial result = p1 / p2;

			Assert::AreEqual(expected,  result);
		}
	};
}
