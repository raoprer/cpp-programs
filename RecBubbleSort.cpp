#include<iostream>
using namespace std;

void bubbleSort(int a[],int n)
{
    if(n==1)
        return;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            int temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
    return bubbleSort(a,n-1);
}

int main()
{
    int n,a[20];
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
        cin>>a[i];

    bubbleSort(a,n);
    cout<<"The sorted array is as follows: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
