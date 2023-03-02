//Railfence
 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string railFenceEncrypt(string text, int key) {
 vector<string> rails(key);
 int rail = 0;
 bool down = false;
 
 for (int i = 0; i < text.length(); i++) {
 rails[rail] += text[i];
 if (rail == 0 || rail == key - 1) {
 down = !down;
 }
 if (down) {
 rail++;
 } else {
 rail--;
 }
 }
 
 string ciphertext = "";
 for (int i = 0; i < rails.size(); i++) {
 ciphertext += rails[i];
 }
 
 return ciphertext;
}
string railFenceDecrypt(string ciphertext, int key) {
 vector<vector<int> > fence(key);
 for (int i = 0; i < ciphertext.length(); i++) {
 int rail = 0;
 bool down = false;
 
 for (int j = 0; j < key; j++) {
 fence[j].push_back(-1);
 }
 
 fence[rail][i] = 0;
 for (int j = 1; j < key; j++) {
 if (rail == 0 || rail == key - 1) {
 down = !down;
 }
 if (down) {
 rail++;
 } else {
 rail--;
 }
 fence[rail][i] = j;
 }
 }
 
 int index = 0;
 string plaintext(ciphertext.length(), ' ');
 for (int i = 0; i < key; i++) {
 for (int j = 0; j < ciphertext.length(); j++) {
 if (fence[i][j] != -1) {
 plaintext[j] = ciphertext[index++];
 }
 }
 }
 
 return plaintext;
}
int main() {
 string text;
 int key;
 cout << "Enter plaintext: ";
 getline(cin, text);
 cout << "Enter key: ";
 cin >> key;
 string ciphertext = railFenceEncrypt(text, key);
 cout << "Ciphertext: " << ciphertext << endl; 
 return 0;
}
