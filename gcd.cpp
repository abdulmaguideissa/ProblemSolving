#include <iostream>

/*int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}*/
long gcd(long long a,long long b){
	long d, current_gcd = 1;
	while ( a % b != 0 ) {
		d = b;
		b = a % b;
		a = d;
	}
	current_gcd = b;
	return current_gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd(a,b) <<'\n';
  return 0;
}
