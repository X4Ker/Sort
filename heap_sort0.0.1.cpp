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
heapify( int * ptr, unsigned int size, int index )
{
    int largest = index;  // Initialize largest as root
    int left = 2 * index + 1;  // left = 2*i + 1
    int right = 2 * index + 2;  // right = 2*i + 2

    // If left child is larger than root
    if( left < size && ptr[left] > ptr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < size && ptr[right] > ptr[largest])
        largest = right;

    // If largest is not root
    if (largest != index)
    {
        swap(ptr[index], ptr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(ptr, size, largest);
    }
}

// main function to do heap sort
void
heapSort(int * ptr, int size)
{
    // Build heap (rearrange array)
    for (int index = size / 2 - 1; index >= 0; index--)
        heapify(ptr, size, index);

    // One by one extract an element from heap
    for (int index=size-1; index>=0; index--)
    {
        // Move current root to end
        swap(ptr[0], ptr[index]);

        // call max heapify on the reduced heap
        heapify(ptr, index, 0);
    }
}

int main() {
    unsigned int n;
    cin >> n;
    cin.get();
    int * a = new int[n];
    if (read_numbers(a, n)) {
        heapSort(a, n);
        print(a, n);
    } else {
        cout << "An error has occured while reading input data";
    }

    delete [] a;

    cin.get();

    return 0;
}
