//RSA algorithm
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
 
long int gcd(long int a, long int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
long int modExp(long int base, long int exp, long int mod)
{
    long int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}
 
int main()
{
    long int p, q, n, e, d, phi, message, encryptedMessage, decryptedMessage;
 
    cout << "Enter two prime numbers: ";
    cin >> p >> q;
 
    n = p * q;
    phi = (p - 1) * (q - 1);
 
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) {
            break;
        }
    }
 
    for (d = 2; d < phi; d++) {
        if ((d * e) % phi == 1) {
            break;
        }
    }
 
    cout << "Public Key: {" << e << ", " << n << "}" << endl;
    cout << "Private Key: {" << d << ", " << n << "}" << endl;
 
    cout << "Enter a message to encrypt: ";
    cin >> message;
 
    encryptedMessage = modExp(message, e, n);
    cout << "Encrypted message: " << encryptedMessage << endl;
 
    decryptedMessage = modExp(encryptedMessage, d, n);
    cout << "Decrypted message: " << decryptedMessage << endl;
 
    return 0;
}
 
 

