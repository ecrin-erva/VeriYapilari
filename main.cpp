#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Karesel O(n^2) çözüm
void kisaToplamKaresel(const vector<int>& A, vector<int>& S) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        S[i] = 0;

        for (int j = 0; j <= i; j++) {
            S[i] += A[j];
        }
    }
}

// 2. Doğrusal O(n) çözüm
void kisaToplamDogrusal(const vector<int>& A, vector<int>& S) {
    int n = A.size();

    S[0] = A[0];

    for (int i = 1; i < n; i++) {
        S[i] = S[i - 1] + A[i];
    }
}

int main() {
    srand(time(0));

    int boyutlar[] = {1000, 5000, 10000, 50000, 100000};

    cout << "Dizi Boyutu\tKaresel (ms)\tDogrusal (ms)" << endl;

    for (int n : boyutlar) {

        vector<int> A(n);
        vector<int> S1(n);
        vector<int> S2(n);

        // Rastgele sayilar olusturma
        for (int i = 0; i < n; i++) {
            A[i] = rand() % 100;
        }

        // Karesel algoritmanin suresini olcme
        auto baslangic1 = chrono::high_resolution_clock::now();

        kisaToplamKaresel(A, S1);

        auto bitis1 = chrono::high_resolution_clock::now();

        double sure1 = chrono::duration<double, milli>(bitis1 - baslangic1).count();

        // Dogrusal algoritmanin suresini olcme
        auto baslangic2 = chrono::high_resolution_clock::now();

        kisaToplamDogrusal(A, S2);

        auto bitis2 = chrono::high_resolution_clock::now();

        double sure2 = chrono::duration<double, milli>(bitis2 - baslangic2).count();

        cout << n << "\t\t" << sure1 << "\t\t" << sure2 << endl;
    }

    return 0;
}