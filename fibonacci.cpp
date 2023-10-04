#include <iostream>
using namespace std;

// Funktsiooni deklaratsioon
//https://www.programiz.com/cpp-programming/library-function/cstdlib/strtoull
unsigned long long fibonacci(int n);

int main() {
    int n;
    cout << "Sisesta mitmendat Fibonacci numbrit soovid arvutada: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        // Kutsume välja funktsiooni ja prindime tulemuse
        unsigned long long result = fibonacci(i);
        cout << "Fibonacci number (" << i << ") = " << result << endl;
    }
    return 0;
}
// Fibonacci funktsioon
unsigned long long fibonacci(int n) {
    // Baasjuhud on kus me teame tulemust ilma rekursioonita.
    //Kui sisestatud arv on 0 siis Fibonacci on 0 ja kui sisestatud arv on 1 siis Fibonacci on 1
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    // Fibonacci arvutamine rekursiivselt
    return fibonacci(n - 1) + fibonacci(n - 2);
}
