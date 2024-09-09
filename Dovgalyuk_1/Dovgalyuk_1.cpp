#include <iostream>
#include <cstdlib>  // Для rand()
#include <ctime>    // Для time()

using namespace std;


void printArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void shiftRight(int* array, int size, int shift) {
    // Для каждого шага сдвигаем элементы массива вправо, заполняя освободившиеся ячейки нулями
    for (int s = 0; s < shift; ++s) {
        // Сохраняем последний элемент, так как он сдвинется вправо
        int last = array[size - 1];

        // Сдвигаем все элементы вправо
        for (int i = size - 1; i > 0; --i) {
            array[i] = array[i - 1];
        }

        // Освободившаяся ячейка заполняется нулём
        array[0] = 0;

        // Выводим массив после каждого шага
        printArray(array, size);
    }
}

void shiftLeft(int* array, int size, int shift) {
    // Для каждого шага сдвигаем элементы массива влево, заполняя освободившиеся ячейки нулями
    for (int s = 0; s < shift; ++s) {
        // Сохраняем первый элемент, так как он сдвинется влево
        int first = array[0];

        // Сдвигаем все элементы влево
        for (int i = 0; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }

        // Освободившаяся ячейка заполняется нулём
        array[size - 1] = 0;

        // Выводим массив после каждого шага
        printArray(array, size);
    }
}









int main() {
    setlocale(LC_ALL, "rus");

    int size;
    cout << "Введите размер массива - ";
    cin >> size;

    
    if (size <= 0) {
        cout << "Размер массива должен быть больше нуля." << endl;
    }

    
    int* arr = new int[size];

    
    srand(time(0));

    
    for (int i = 0; i < size; i++) {
        arr[i] = 60 + rand() % 11;
    }


//----------------------------------------------------------------в какой период выпало больше осадков: в первую половину июня или во вторую-----------------------------------

    if (size % 2 == 0) {

        int sum_1 = 0;
        int sum_2 = 0;

        for (int i = 0; i < size / 2; i++) {
            sum_1 += arr[i];  
        }
        for (int i = size / 2; i < size; i++) {
            sum_2 += arr[i];  
        }

        
        for (int i = 0; i < size; i++) {
            cout << "Элемент " << i+1 << ": " << arr[i] << endl;
        }

        
        cout << "Сумма первой половины: " << sum_1 << endl;
        cout << "Сумма второй половины: " << sum_2 << endl;
        
        
        if (sum_1 > sum_2) {
            cout << "Сумма первой половины больше суммы второй половины на " << sum_1 - sum_2;
        }
        else if(sum_2 > sum_1){
            cout << "Сумма второй половины больше суммы первой половины на " << sum_2 - sum_1;
        }
        else{
            cout << "Суммы первой и второй половин равны";
        }
    }
    else {
        cout << "Размер массива нечётный." << endl;

        // Вариант 1: Первая половина имеет на один элемент больше
        int sum_1 = 0;
        int sum_2 = 0;
        for (int i = 0; i < size / 2 + 1; i++) {
            sum_1 += arr[i];  // Первая часть содержит на 1 элемент больше
        }
        for (int i = size / 2 + 1; i < size; i++) {
            sum_2 += arr[i];  // Вторая часть содержит оставшиеся элементы
        }


        for (int i = 0; i < size; i++) {
            cout << "Элемент " << i + 1 << ": " << arr[i] << endl;
        }
        
        
        cout << "Вариант 1 - Первая часть больше на 1 элемент:" << endl;
        cout << "Сумма первой части: " << sum_1 << endl;
        cout << "Сумма второй части: " << sum_2 << endl;


        if (sum_1 > sum_2) {
            cout << "Сумма первой части больше второй на " << sum_1 - sum_2 << endl;
        }
        else if (sum_1 < sum_2) {
            cout << "Сумма второй части больше первой на " << sum_2 - sum_1 << endl;
        }
        else {
            cout << "Суммы первой и второй частей равны." << endl;
        }

        // Вариант 2: Вторая половина имеет на один элемент больше
        int sum_3 = 0;
        int sum_4 = 0;
        for (int i = 0; i < size / 2; i++) {
            sum_3 += arr[i];  // Первая часть содержит на 1 элемент меньше
        }
        for (int i = size / 2; i < size; i++) {
            sum_4 += arr[i];  // Вторая часть содержит на 1 элемент больше
        }


        cout << "Вариант 2 - Вторая часть больше на 1 элемент:" << endl;
        cout << "Сумма первой части: " << sum_3 << endl;
        cout << "Сумма второй части: " << sum_4 << endl;


        if (sum_3 > sum_4) {
            cout << "Сумма первой части больше второй на " << sum_3 - sum_4 << endl;
        }
        else if (sum_3 < sum_4) {
            cout << "Сумма второй части больше первой на " << sum_4 - sum_3 << endl;
        }
        else {
            cout << "Суммы первой и второй частей равны." << endl;
        }
    }

//----------------------------------------------------------------в какую декаду месяца выпало больше всего осадков.-----------------------------------------------------------

    cout << '\n';
    cout << '\n';
    cout << '\n';

    int maxSum = 0;
    int maxDecade = -1;
    int startIdx = 0;

    for (int decade = 1; startIdx < size; ++decade) {
        int endIdx = min(startIdx + 10, size);
        int sum = 0;

        for (int i = startIdx; i < endIdx; ++i) {
            sum += arr[i];
        }

        cout << "Сумма осадков декады " << decade << " (" << startIdx + 1 << " - " << endIdx << "): " << sum << endl;

        if (sum > maxSum) {
            maxSum = sum;
            maxDecade = decade;
        }

        startIdx = endIdx;
    }

    cout << "Декада с наибольшей суммой осадков: " << maxDecade << " (сумма осадков = " << maxSum << ")" << endl;


    delete[] arr;

//----------------------------------------------------------------------------------------------------------------------------------------------------

    int size1;
    cout << "Введите размер массива - ";
    cin >> size1;

    if (size1 <= 0) {
        cout << "Размер массива должен быть больше нуля." << endl;
        return 1;
    }

    int* array = new int[size1];
    srand(time(0));

    // Заполнение массива случайными числами
    for (int i = 0; i < size1; i++) {
        array[i] = rand() % 100; // Пример диапазона от 0 до 99
    }

    // Выводим исходный массив
    cout << "Исходный массив: ";
    printArray(array, size1);

    int hjvf;
    cout << "Если вы хотите сдвинуть элементы вправо, наберите 1, если влево, наберите 2, если хотите выйти, наберите 0: ";
    cin >> hjvf;

    if (hjvf != 0 && hjvf != 1 && hjvf != 2) {
        cout << "Вы ввели что-то не так!" << endl;
        delete[] array;
        return 1;
    }

    int kolvo;
    if (hjvf != 0) {
        cout << "Введите на сколько элементов вы хотите сдвинуть элементы массива: ";
        cin >> kolvo;

        if (kolvo < 0 || kolvo >= size1) {
            cout << "Количество сдвигов должно быть от 0 до " << size1 - 1 << "." << endl;
            delete[] array;
            return 1;
        }

        if (hjvf == 1) {
            // Сдвиг вправо
            shiftRight(array, size1, kolvo);
        }
        else if (hjvf == 2) {
            // Сдвиг влево
            shiftLeft(array, size1, kolvo);
        }
    }

    delete[] array;


    
    
    return 0;
}
