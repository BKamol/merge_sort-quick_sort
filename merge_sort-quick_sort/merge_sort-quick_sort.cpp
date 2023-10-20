
#include <iostream>

using namespace std;

struct elem
{
    int info;
    elem* next;
};


template <class T>
void merge_sort(T* mas, int size)
{
    T* b = new T[size];
    int rght, rend, wid;
    int i, j, m, t;
    for (int k = 1; k < size; k *= 2) {
        for (int left = 0; left + k < size; left += k * 2) {
            rght = left + k;
            rend = rght + k;
            if (rend > size) rend = size;
            m = left; i = left; j = rght;
            while (i < rght && j < rend) {
                if (mas[i] <= mas[j]) {
                    b[m] = mas[i]; i++;
                }
                else {
                    b[m] = mas[j]; j++;
                }
                m++;
            }
            while (i < rght) {
                b[m] = mas[i];
                i++; m++;
            }
            while (j < rend) {
                b[m] = mas[j];
                j++; m++;
            }
            for (m = left; m < rend; m++) {
                mas[m] = b[m];
            }
        }
    }
    delete[] b;
}

template <class T>
void input_array(T* array, int size)
{
    cout << "Input " << size << " values" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
}

template <class T>
void print_array(T* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

elem* merge_sort_list(elem*& top)
{
    if (top == NULL || top->next == NULL)
    {
        return top;
    }

    elem* middle = getMiddle(top);
    elem* left_head = top;
    elem* right_head = middle->next;
    middle->next = NULL;

    return merge(merge_sort_list(left_head), merge_sort_list(right_head));
}

elem* merge(elem* a, elem* b)
{
    elem* dummyHead = new elem;
    for (elem* current = dummyHead; a != NULL && b != NULL; current = current->next)
    {
        if (a->info <= b->info)
        {
            current->next = a;
            a = a->next;
        }
        else
        {
            current->next = b;
            b = b->next;
        }
    }

    if (a == NULL) dummyHead = b;
    else dummyHead = a;

    elem* p = dummyHead->next;
    delete dummyHead;

    return p;
}

elem* getMiddle(elem* top)
{
    if (top == NULL) return top;

    elem* slow = top;
    elem* fast = top;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

elem* create_list(int size)
{
    elem* top = new elem;
    cout << "Input " << size << " elements: " << endl;
    cin >> top->info;
    elem* p = top;
    for (int i = 1; i < size; i++)
    {
        p->next = new elem;
        p = p->next;
        cin >> p->info;
    }
    p->next = NULL;
    return top;
}

void print_list(elem* top)
{

}

int main()
{
    /*int size;
    cin >> size;
    int* mas = new int[size];
    input_array(mas, size);

    merge_sort(mas, size);

    print_array(mas, size);*/



}
