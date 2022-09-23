(a + b) % n == ((a % n) + (b % n)) % n;
(a - b) % n == ((a % n) - (b % n)) % n (+ n);
(a * b) % n == ((a % n) * (b % n)) % n;
(a / b) % n == ((a % n) * ((b%n)^-1 % n)) % n;