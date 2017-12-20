#include <iostream>
#include <sstream>

using namespace std;


bool
read_numbers( int * ptr, unsigned int size ) {
    string string;
    getline( cin, string );
    istringstream stream(string);
    for( unsigned int i = 0; i < size; ++i ) {
        if( !( stream >> ptr[i] ) ) {
            return false;
        }
    }

    return stream.eof();
}


void
print( int * ptr, unsigned int size )
{
    for( unsigned int i = 0; i < size; ++i ) {
        std::cout << ptr[ i ];
        if( i != size - 1 ) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

void
CountingSort(int * & a, unsigned int n){
    int c[256];
    for (int i = 0; i < 256; i++){
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[a[i]] = c[a[i]] + 1;
    }
        int b = 0;
        for (int j = 0; j < 256; j++) {
            for (int i = 0; i < c[j]; i++) {
                a[b] = j;
                b++;

            }
        }

}

int main() {
    unsigned int n;
    cin >> n;
    cin.get();
    int * a = new int[n];
    if (read_numbers(a, n)) {
        CountingSort(a, n);
        print(a, n);
    } else {
        cout << "An error has occured while reading input data";
    }

    delete [] a;

    cin.get();

    return 0;
}
