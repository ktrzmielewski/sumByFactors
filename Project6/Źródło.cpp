#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cinttypes>
#include <cmath>

class SumOfDivided
{
public:
	static std::string sumOfDivided(std::vector<int>& lst);
};

std::vector<float> primeFactors(int n)
{
	std::vector<float> factors;
	// If n is negative, for this solution We'll just make it positive
	if (n < 0) {
		n = n * (-1);
	}
	// Print the number of 2s that divide n
	while (n % 2 == 0)
	{
		factors.push_back(2);
		n = n / 2;
	}

	// n must be odd at this point. So we can skip
	// one element (Note i = i +2)
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		// While i divides n, print i and divide n
		while (n % i == 0)
		{
			factors.push_back(i);
			n = n / i;
		}
	}

	// This condition is to handle the case when n
	// is a prime number greater than 2
	if (n > 2)
		factors.push_back(n);

	return factors;
}

bool is_integer(float k)
{
	return std::floor(k) == k;
}

std::string SumOfDivided::sumOfDivided(std::vector<int>& lst) {
	std::vector<float> primes;
	std::vector<std::pair<int, int>> pairs;
	std::string formatedText;

	for (unsigned int i = 0; i < lst.size(); i++) {
		std::vector<float> factors = primeFactors(lst[i]);

		for (float num : factors) {
			primes.push_back(num);
		}

	}

	sort(primes.begin(), primes.end());
	primes.erase(unique(primes.begin(), primes.end()), primes.end());

	for (unsigned int i = 0; i < primes.size(); i++) {
		pairs.push_back(std::make_pair(primes[i], 0));
	}

	for (int integer : lst) {
		for (unsigned int i = 0; i < primes.size(); i++) {

			float primeNum = primes[i];
			float check = integer / primeNum;

			if (is_integer(check)) {
				pairs[i].second += integer;
			}

		}


	}

	for (unsigned int i = 0; i < primes.size(); i++) {
		if (pairs[i].second != 0) {
			formatedText += ('(') + std::to_string(pairs[i].first) + (' ') + std::to_string(pairs[i].second) + (')');
		}
	}

	return formatedText;
}

int main() {
	// Numbers to calculate sum by factors with
	std::vector<int> lst = { 12, 15 };
	std::string ans = SumOfDivided::sumOfDivided(lst);
	std::cout << ans;

	return 0;
}
