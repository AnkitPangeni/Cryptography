//Deffie hellman
#include <iostream>
#include <cmath>
 
using namespace std;
 
// Function to calculate the power of a number
int power(int a, int b, int p) {
    int res = 1;
    a = a % p;
 
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % p;
        }
 
        b = b >> 1;
        a = (a * a) % p;
    }
 
    return res;
}
 
// Function to generate the secret key
int generate_key(int base, int private_key, int prime) {
    return power(base, private_key, prime);
}
 
int main() {
    int prime, base, alice_private_key, bob_private_key;
 
    cout << "Enter the prime number: ";
    cin >> prime;
 
    cout << "Enter the base number: ";
    cin >> base;
 
    cout << "Enter Alice's private key: ";
    cin >> alice_private_key;
 
    cout << "Enter Bob's private key: ";
    cin >> bob_private_key;
 
    // Generate Alice's public key
    int alice_public_key = generate_key(base, alice_private_key, prime);
 
    // Generate Bob's public key
    int bob_public_key = generate_key(base, bob_private_key, prime);
 
    // Generate Alice's shared secret key
    int alice_shared_key = generate_key(bob_public_key, alice_private_key, prime);
 
    // Generate Bob's shared secret key
    int bob_shared_key = generate_key(alice_public_key, bob_private_key, prime);
 
    // Verify that the shared secret keys match
    if (alice_shared_key == bob_shared_key) {
        cout << "Shared secret key: " << alice_shared_key << endl;
    } else {
        cout << "Error: Shared secret keys do not match" << endl;
    }
 
    return 0;
}
 
