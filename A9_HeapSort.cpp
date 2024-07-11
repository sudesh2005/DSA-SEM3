#include <iostream>
using namespace std;

class HeapSort
{
    public :
    int n;
        void BuildHeap(int[] , int , int);
        void MaxHeapify(int[] , int , int);
        void MinHeapify(int[] , int , int);
        void sort();
        void swap(int& , int& );
        void print (int[], int);
};

void HeapSort ::swap(int& a , int& b )
{
    int temp = a;
    a = b;
    b = temp;
}

void HeapSort :: BuildHeap(int arr[] , int n , int choice )
{
    if(choice == 1)
    {
        for (int i = (n / 2 - 1) ; i >= 0 ; i-- )
        {   
            MaxHeapify(arr , n , i );
        }
        for (int i = n - 1 ; i >= 1 ; i--)
        {
            swap(arr[0] , arr[i]);
            MaxHeapify(arr , i , 0);
        }
    }
    else if (choice == 2)
    {
        for (int i = (n / 2 - 1) ; i >= 0 ; i-- )
        {
            MinHeapify(arr , n , i);
        }
        for(int i = n - 1 ; i >= 1 ; i--)
        {
            swap(arr[0] , arr[i]);
            MinHeapify(arr , i , 0);
        }
    }
    
}

void HeapSort :: MaxHeapify (int arr[], int n , int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        MaxHeapify(arr, n , largest);
    }

}

void HeapSort :: MinHeapify(int arr[] , int n , int i)
{
    int minimum = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[minimum])
    {
        minimum = left;
    }

    if(right < n && arr[right] < arr[minimum])
    {
        minimum = right;
    }

    if(minimum != i)
    {
        swap(arr[minimum] , arr[i]);
        MinHeapify(arr , n , minimum);
    }

}

void HeapSort :: print (int arr[] , int n)
{
    cout << "\nTHE SORTED ARRAY IS :" << endl;
    for (int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << "\t";
    }
}

int main ()
{
    HeapSort hobj;
    int n , choice;

    while(1)
    {
        cout << "\nENTER THR NUMBER OF ELEMENTS IN ARRAY :  "  << endl;
        cin >> n;
        int* arr = new int[n];
        cout << "\nENTER THE ELEMENTS IN ARRAY : " << endl;
        for (int i = 0; i < n ; i++)
        {
            cin >> arr[i];
        }
        cout << "\n1.Sort Maximum."<< endl;
        cout << "2.Sort Minimum."<< endl;
        cout << "3.Exit." << endl;
        cout << "ENTER CHOICE"<<endl;
        cin >> choice;
        
        switch(choice)
        {
            case 1 :
                hobj.BuildHeap(arr , n , choice);
                hobj.print(arr , n);
                break;

            case 2 :
                hobj.BuildHeap(arr , n , choice);
                hobj.print(arr , n);
                break;

            case 3 :
                cout << "EXITING THE APPLICATION....." ;
                return 0;
                break;        

            default : 
                cout << "Invalid Input......"; 
                break;   
        }

        delete[] arr;
    }

    return 0;

}
