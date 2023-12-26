#include <iostream>
using namespace std;

int N;                            //Размер массива

struct Element {                 //Структура, представляющая элемент массива
    double val = 0;             //с 2-мя полями: значением и индексом элемента
    int in = 0;
};

struct Result {                //Структура для хранения результата поиска
    double max1 = 0, max2 = 0;//максимальных значений и их индексов
    int index1 = 0, index2=0;
};

/********Функция заполнения массива********/
static void arr_in(Element* arr, int N) {
    cout << "\n Заполните массив\n" << endl;
    for (int i = 0; i < N; i++) {
        arr[i].in = i;
        cout << "arr [" << i << "] = ";
        cin >> arr[i].val;
    }
}
/*****************************************/

/********Функция вывода массива***********/
static void arr_out(Element* arr, int N) {
    cout << "arr[] = { ";
    for (int i = 0; i < N; i++) {
        cout << arr[i].val << " ";
    }
    cout << "}\n\n";
}
/****************************************/

/*Функция сортировки массива и нахождения максимальных элементов*/
static Result sort(Element* arr, int N, Result &res) {

    Element  buf;                 //Переменная для временного хранения элемента массива при сортировке
    unsigned int i = 0, j = 0;

    /*Сортировка массива методом пузырька*/
    for (j = 1; j <= (N - 1); j++)
        for (i = 0; i < (N - j); i++) {
            if (arr[i].val > arr[i + 1].val) {
                buf = arr[i + 1];
                swap(arr[i + 1], arr[i]);
                arr[i] = buf;
            }
        }
    /*Если элементы одинаковы, большим является тот,
      у которого индекс меньше*/
    if (arr[N - 1].val == arr[N - 2].val) {
        double s = arr[N - 1].in;
        swap(arr[N - 1], arr[N - 2]);
        arr[N - 2].in = s;
    }

    res.max1 = arr[N - 1].val;
    res.max2 = arr[N - 2].val;
    res.index1 = arr[N - 1].in;
    res.index2 = arr[N - 2].in;
    
    return res;
}
/*********Конец функции сортировки****************/

/******************Функция вывода результата********************/
static void result_out(Result r) {
    cout << "max1 = " << r.max1<< "\tINDEX 1: " << r.index1 << endl;
    cout << "max2 = " << r.max2<< "\tINDEX 2: " << r.index2 << endl;
}
/**************************************************************/

int main()
{
    setlocale(0, "");                //Функция для отображения кириллицы в консоль

    cout << "Введите размер массива N>0: ";
    cin >> N;
    while (N <= 0) {
        cout << "Ошибка! Размер массива должен быть больше 0" << endl;
        cin >> N;
    }

    Element* arr = new Element[N]; //Объявление и инициализация динамического массива

    arr_in(arr, N);               //Заполнение массива
    
    if (N == 1) {
        cout << "arr[0]= " << arr[0].val << " - Единственный элемент" << endl;
       
        delete[] arr;            //Очистка выделенной памяти
        arr = NULL;             //Сбрасывание указателя в 0

        return 0;
    }

    cout << "\nИсходный массив" << endl;
    arr_out(arr, N);              //Вывод исходного массива
    
    Result result;
    sort(arr, N, result);        //Сортировка массива

    cout << "\nОтсортированный массив" << endl;
    arr_out(arr, N);            //Вывод отсортированного массива

    cout << "\nВывод результата\n";
    result_out(result);
 
    delete[] arr;              //Очистка выделенной памяти
    arr = NULL;               //Сбрасывание указателя в 0
   
    return 0;
}