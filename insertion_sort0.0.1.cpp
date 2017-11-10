#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool read_numbers(int *a, unsigned int n)
{
    string string;
    int k;
    getline(cin, string);
    istringstream stream(string);
    bool success = true;
    for (int i = 0; i < n; ++i) {
        if (!(stream >> a[i])) {
            if (string[i] == ' ')
                k = k + 1;
            if (k != n - 1)
            success = false;
            break;
        }
    }

    return success;
}


void insertion_sort (int *a, int length){
    int j, temp;

    for (int i = 0; i < length; i++){
        j = i;

        while (j > 0 && a[j] < a[j-1]){
            temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
    }
}

int main() {
int *a, n;
    cin >> n;
    cin.get();
    a = new int[n];
    if (read_numbers(a, n)){
        insertion_sort(a, n);
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
    }
    else {
        cout << "An error has occured while reading input data";
    }
    cin.get();
    return 0;
}
