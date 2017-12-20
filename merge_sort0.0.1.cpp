#include <iostream>
#include <sstream>

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

void Merge(int *a, int low, int high, int mid)
{

    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;
    
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i-low];
    }
}

void MergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;

        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        Merge(a, low, high, mid);
    }
}

int main() {
    unsigned int n;
    cin >> n;
    cin.get();
    int *a = new int[n];
    if (read_numbers(a, n)) {
        MergeSort(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    } else {
        cout << "An error has occured while reading input data";
    }
    destroy(a);
    cin.get();
    return 0;
}
