#include <iostream>
using namespace std;

// Structure for Heap
struct Heap {
    int *arr;
    int capacity;
    int size;
};

// Function to initialize a heap
Heap* initializeHeap(int capacity) {
    Heap* heap = new Heap;
    heap->arr = new int[capacity];
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain max heap property
void maxHeapify(Heap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;
    
    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;
    
    if (largest != index) {
        swap(&heap->arr[index], &heap->arr[largest]);
        maxHeapify(heap, largest);
    }
}

// Function to insert a new element into max heap
void insertMaxHeap(Heap* heap, int value) {
    if (heap->size == heap->capacity) {
        cout << "Heap overflow\n";
        return;
    }

    int index = heap->size;
    heap->arr[index] = value;
    heap->size++;

    while (index != 0 && heap->arr[(index - 1) / 2] < heap->arr[index]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Function to extract maximum from max heap
int extractMax(Heap* heap) {
    if (heap->size <= 0)
        return -1;
    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);

    return root;
}

// Function to maintain min heap property
void minHeapify(Heap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;
    
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;
    
    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

// Function to insert a new element into min heap
void insertMinHeap(Heap* heap, int value) {
    if (heap->size == heap->capacity) {
        std::cout << "Heap overflow\n";
        return;
    }

    int index = heap->size;
    heap->arr[index] = value;
    heap->size++;

    while (index != 0 && heap->arr[(index - 1) / 2] > heap->arr[index]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Function to extract minimum from min heap
int extractMin(Heap* heap) {
    if (heap->size <= 0)
        return -1;
    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);

    return root;
}

// Function to build max heap
void buildMaxHeap(Heap* heap) {
    for (int i = (heap->size - 1) / 2; i >= 0; i--) {
        maxHeapify(heap, i);
    }
}

// Function to build min heap
void buildMinHeap(Heap* heap) {
    for (int i = (heap->size - 1) / 2; i >= 0; i--) {
        minHeapify(heap, i);
    }
}

// Function to perform heap sort
void heapSort(Heap* heap) {
    buildMaxHeap(heap);
    for (int i = heap->size - 1; i >= 0; i--) {
        swap(&heap->arr[0], &heap->arr[i]);
        heap->size--;
        maxHeapify(heap, 0);
    }
}

// Function to print heap elements
void printHeap(Heap* heap) {
    for (int i = 0; i < heap->size; i++) {
        std::cout << heap->arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int capacity ;
    cout<<"Enter capacity: ";
    cin>>capacity;
    Heap* maxHeap = initializeHeap(capacity);
    Heap* minHeap = initializeHeap(capacity); 

    for (int i = 0; i < capacity; i++)
    {
        int n;
        cout<<"Enter a number for max heap: ";
        cin>>n;
        insertMaxHeap(maxHeap, n);
    }
    cout << "Max Heap: ";
    printHeap(maxHeap);

    for (int i = 0; i < capacity; i++)
    {
        int m;
        cout<<"Enter a number for min heap: ";
        cin>>m;
        insertMaxHeap(minHeap, m);
    }
    cout << "Min Heap: ";
    printHeap(minHeap);

    heapSort(maxHeap);
    cout << "Sorted Array (Max Heap): ";
    printHeap(maxHeap);

    heapSort(minHeap);
    cout << "Sorted Array (Min Heap): ";
    printHeap(minHeap);

    delete maxHeap->arr;
    delete maxHeap;
    delete minHeap->arr;
    delete minHeap;

    return 0;
}
