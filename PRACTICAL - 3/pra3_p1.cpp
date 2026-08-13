#include<iostream>
#include<vector>

using namespace std;

void Bubble(vector<int>arr,int n)
{
    
    for(int i =0; i<=n-1;i++)
    {
        for(int j =0 ; j<=n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int k : arr)
    {
        cout<< k <<" ";
    }
}; 

void Selection(vector<int>arr,int n)
{ for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
    for(int h : arr)
    {
        
        cout<< h <<" ";
    }


};
void Insertion(vector<int> arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i;

        while(j > 0 && arr[j-1] > arr[j])
        {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }

    for(int y : arr)
    {
        cout << y << " ";
    }
}
int main()
{
    vector<int>arr = {3,7,5,1,4};

    Bubble(arr,arr.size());
    cout<<endl;
    Selection(arr,arr.size());
    cout<<endl;
    Insertion(arr,arr.size());


}
