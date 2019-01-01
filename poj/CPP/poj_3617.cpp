#include<iostream>
#include<deque>
using namespace std;

int main() {
    int N;
    cin >> N;
    char str[2010];
    deque<char> S;
    deque<char> T;
    int i;
    for (i = 0; i < N; i++) {
        cin >> str[i];
        S.push_back(str[i]);
    }
    deque<char>::iterator it1, it2;
    it1 = S.begin();
    it2 = S.end()-1;
    while (S.size() != 0) {
        if (*it1 < *it2) {
            T.push_back(S.front());
            S.pop_front();
            it1 = S.begin();
            it2 = S.end() - 1;
        } else if (*it1 == *it2) {
            it1++;
            it2--;
        } else if (*it1 > *it2){
            T.push_back(S.back());
            S.pop_back();
            it2 = S.end() - 1;
            it1 = S.begin();
        } else if(it1 == it2) {
            T.push_back(S.front());
            S.pop_front();
            break;
        }
    }
    i = 0;
    for (it1 = T.begin(); it1 < T.end(); it1++) {
        if (i && i % 80 == 0) {
            cout << endl;
        }
        cout << *it1;
        i++;
    }
    return 0;
}
