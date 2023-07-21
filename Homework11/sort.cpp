//
//  main.cpp
//  Homework11
//
//  Created by Sean Belingheri on 11/10/22.
//
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;



int main()
{
    int*arr=NULL;
    int i=0, size, store1, indicator = 0;
    char ch;
    string temp;
    
    cout<<"Enter the array length: ";
    cin>>size;
    
    cout<<"Enter "<<size<<" values: ";
    arr=new int[size];
    do
    {
        cin>>arr[i];
        i++;
        ch = cin.get();
    } while(ch != '\n' && i < size);
    
    if(i == size && ch != '\n')
        getline(cin, temp);
    else if(i < size && ch == '\n')
    {
        for(i; i<size; i++)
            arr[i]=0;
    }
    
    do{
        for(int k = 0; k < size - 1; k++) //goes through each index in array and compares it with value to the left. If the first value is greater than the second value, this swaps them. This needs to run multiple times for the entire sequence, as this loop naturally pushes the biggest numbers to the back first.
            {
                store1 = arr[k];
                if(arr[k]>arr[k+1])
                {
                    arr[k] = arr[k+1];
                    arr[k+1] = store1;
                }
            }
        indicator++; //the indicator makes it so the loop runs as many times as there are values in the array.
    }while(indicator < size);
    
    for(int g = 0; g<size; g++)
        cout<<arr[g]<<" ";
    
    cout<<endl;
    return 0;
}
