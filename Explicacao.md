Claro! Vou explicar brevemente cada algoritmo e fornecer exemplos de código documentados em C para ilustrar sua implementação.

Algoritmos de Ordenação Estáveis:
Merge Sort:
O Merge Sort é um algoritmo eficiente e estável que divide a lista em duas metades, ordena cada metade separadamente e, em seguida, combina as metades ordenadas em uma única lista.
Exemplo de código em C:

c
Copy code
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size) {
    if (size < 2) {
        return;
    }
    
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    
    merge(arr, left, mid, right, size - mid);
}
Insertion Sort:
O Insertion Sort é um algoritmo simples e estável que percorre a lista da esquerda para a direita, inserindo cada elemento em sua posição correta na parte já ordenada da lista.
Exemplo de código em C:

c
Copy code
void insertionSort(int arr[], int size) {
    int i, j, key;
    
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = key;
    }
}
Bubble Sort:
O Bubble Sort é um algoritmo simples, porém ineficiente, que compara pares de elementos adjacentes e os troca se estiverem na ordem errada, repetindo esse processo até que a lista esteja completamente ordenada.
Exemplo de código em C:

c
Copy code
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
Tim Sort:
O Tim Sort é um algoritmo de ordenação híbrido baseado no Merge Sort e no Insertion Sort. Ele é otimizado para lidar com casos em que a lista possui sequências ordenadas ou parcialmente ordenadas.
A implementação detalhada do Tim Sort em C é complexa e extensa, mas você pode encontrar exemplos completos de código em várias bibliotecas e recursos online.

Algoritmos de Ordenação Instáveis:
Quick Sort:
O Quick Sort é um algoritmo de ordenação eficiente que não é estável. Ele seleciona um elemento pivô na lista, particiona os elementos em torno do pivô e, em seguida, recursivamente ordena as duas sub-listas resultantes.
Exemplo de código em C:

c
Copy code
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
Heap Sort:
O Heap Sort é um algoritmo de ordenação que utiliza uma estrutura de dados chamada heap. Ele transforma a lista em um heap, uma árvore binária especial, e extrai repetidamente o elemento máximo (ou mínimo) do heap até que a lista esteja ordenada.
Exemplo de código em C:

c
Copy code
void heapify(int arr[], int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != root) {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;
        
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    
    for (int i = size - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        heapify(arr, i, 0);
    }
}
Selection Sort:
O Selection Sort é um algoritmo simples, mas ineficiente, que seleciona repetidamente o elemento mínimo (ou máximo) da lista restante e o coloca em sua posição correta. No entanto, ele não é estável, pois pode trocar elementos iguais e alterar sua ordem relativa.
Exemplo de código em C:

c
Copy code
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
Esses são exemplos de implementações dos algoritmos de ordenação mencionados em linguagem C. Esses códigos fornecem uma visão geral de como cada algoritmo funciona, mas é importante lembrar que existem muitas outras implementações e variações possíveis para cada algoritmo.
