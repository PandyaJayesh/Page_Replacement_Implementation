
#include <fstream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "USAGE: invalid arguments!!" << endl;
        exit(1);
    }
    int range = atoi(argv[1]);
    int seq_length = atoi(argv[2]);
    char *file_name;
    file_name = argv[3];
    if (range > 100) {
        cout << "USAGE: invalid arguments!!" << endl;
        exit(1);
    }
    ofstream file;
    file.open(file_name);
    if (!file.is_open()) {
        cout << "The file is not opened. The program will now exit." << endl;
        exit(0);
    }
    srand(time(0)); // Seed the random number generator
    int num2;
    int num1 = rand() % range;
    file << num1 << " ";
    for (int i = 1; i < seq_length; i++) {
        retry:
        num2 = rand() % range;
        if (num2 == num1) goto retry;
        file << num2 << " ";
        num1 = num2;
    }
    file.close();
    return 0;
}
