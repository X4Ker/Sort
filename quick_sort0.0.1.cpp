#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

void destroy(int *a){
     delete[]a;
}

bool read_numbers(int *a, unsigned int n) {
    string string;
    getline(cin, string);
    istringstream stream(string);
    for (int i = 0; i < n; ++i) {
        if (!(stream >> a[i])) {
            return false;
            break;
        }
    }
    if (stream >> n){
        return false;
    }
    return true;
}

unsigned int partition(int *a, unsigned left, unsigned int right){
    int i = left;
    int j = right;
    unsigned int tmp;
    int pivot = a[(left + right)/2];
    while (i <= j) {
        while(a[i] < pivot)
            i++;
        while(a[j] > pivot)
            j--;
        if(i <= j){
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    return i - 1;
}

void print(int * ptr, unsigned int size)
{
    for( unsigned int i = 0; i < size; ++i ) {
        std::cout << ptr[ i ];
        if( i != size - 1 ) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

void quick_sort(int *a, unsigned int left, unsigned int right){
   // print(a + left, right - left + 1);
    if(left != right) {

        unsigned int index = partition(a, left, right);
    //    print(a + left, right - left + 1);
        if (left < index)
            quick_sort(a, left, index - 1);
        if (index < right)
            quick_sort(a, index + 1, right);
    }
    return;
}

int main(){
    unsigned int n;
    cin >> n;
    cin.get();
    int *a = new int[n];
    if (read_numbers(a, n)) {
        quick_sort(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    }
    else {
        cout << "An error has occured while reading input data";
    }
    destroy(a);
    cin.get();
    return 0;
}
