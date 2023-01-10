#include <iostream>
#include <queue>

using std::queue;
using std::cout;
using std::cin;
using std::endl;

bool check_prime(unsigned int is_prime) {
	for (unsigned int i = 2U; i < is_prime; i++) {
		if (is_prime % i == 0U) return false;
	}
	return true;
}

queue<unsigned int> primes(unsigned int num) {
	queue<unsigned int> primes_queue;
	for (unsigned int i = 2U; i <= num; i++) {
		if (check_prime(i)) primes_queue.push(i);
	}
	return primes_queue;
}

queue<unsigned int> clear_primes(queue<unsigned int> _q, unsigned int num) {
	queue<unsigned int> cleared_primes;
	while (!_q.empty()) {
		if (num % _q.front() == 0) cleared_primes.push(_q.front());
		_q.pop();
	}
	return cleared_primes;
}

queue<unsigned int> clear235(queue<unsigned int> _queue) {
	queue<unsigned int> cleared_queue;
	unsigned int val = 0U;
	while (!_queue.empty()) {
		val = _queue.front();
		if (val != 2U && val != 3U && val != 5) cleared_queue.push(val);
		_queue.pop();
	}
	return cleared_queue;
}

bool check235(unsigned int num) {
	queue<unsigned int> prime_mults = clear_primes(primes(num), num);
	if (prime_mults.size() == 0 || clear235(prime_mults).size() != 0) return false;
	return true;
}

int main() {
	int N = 0, i, num = 2;
	system("chcp 1251 > nul");
	int option;
	while (true) {
		cout << "Select an action:\n"
			<< "1. Enter quantity\n"
			<< "2. Run the Program\n"
			<< "3. Exit\n"
			<< "Your choice: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "Enter the number of items you are looking for: ";
			cin >> N;
			break;
		case 2:
			i = 0;
			while (i < N) {
				if (check235(num)) {
					cout << num << " ";
					i++;
				}
				cout << endl;
				num++;
			}
			break;
		case 3:
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
		num = 2;
	}
}
