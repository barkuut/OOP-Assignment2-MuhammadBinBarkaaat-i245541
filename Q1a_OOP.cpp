#include <iostream>
using namespace std;

void ChangeLocation(char *Array, int b1, int b2)
{
    
    if (b1 >= b2)
        return;


    char temp = Array[b1];
    Array[b1] = Array[b2];
    Array[b2] = temp;

    ChangeLocation(Array, b1 + 1, b2 - 1);
}

int main()
{
    char arr[] = {'C', 'O', 'M', 'P', 'U', 'T', 'E', 'R'};
    int size = 8;
	
	cout << "Before change: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
	
    ChangeLocation(arr, 2, 6);

    cout << "After change: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

