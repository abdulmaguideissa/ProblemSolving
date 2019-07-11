#include <iostream>

/*long long lcm_naive(long a, long b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}*/
/* the least common multiple is the smallest number that is a multiple
 of a and b */
long long lcm(long a,long b){
  long d,current_gcd = 1;
  while(a%b != 0){
        d = b;
        b = a%b;
        a = d;
      }  
   current_gcd = b;
  return current_gcd;
}
int main() {
  long long a, b,c,d;
  std::cin >> a >> b;
  c = b/lcm(a,b);
  d = c*a;
  std::cout << d << std::endl;
  return 0;
}
