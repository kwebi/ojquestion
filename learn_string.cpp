#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    int x, sum;
    stringstream ss(line);
    while (ss >> x) sum += x;
    cout << sum << "\n";
    return 0;
}