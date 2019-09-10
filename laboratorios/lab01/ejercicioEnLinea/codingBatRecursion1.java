# Complejidad: O(n)
public int factorial(int n) {
  if (n==1) return 1; #C1
 else return n*factorial(n-1); #T(n-1)
}
# Complejidad: O(2^n)
public int fibonacci(int n) {
  if (n==0)return 0;#C1
  else if(n<=2)return 1;#C2
  else return fibonacci(n-1)+fibonacci(n-2);#T(n-1)+T(n-2)
}
# Complejidad: O(n)
public int triangle(int n) {
  if (n==0)return 0;#C1
  else return n+ triangle(n-1);#T(n-1)
}
# Complejidad: O(log n)
public int sumDigits(int n) {
  if(n<10) return n;#C1
  else return n%10 + sumDigits(n/10);#T(n)=C2+T(n/10)
}
# Complejidad: O(log n)
public int count7(int n) {
  if(n==7) return 1;#C1
  else if (n<10)return 0;#C2
  else if (n%10==7)return 1+count7(n/10);
  else return count7(n/10);#T(n)=C2+T(n/10)
}
