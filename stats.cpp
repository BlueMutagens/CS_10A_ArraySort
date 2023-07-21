//
//  stats.cpp
//  Homework11
//
//  Created by Sean Belingheri on 11/10/22.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double mean(double arrproto[], int sizeproto);
double range(double arrproto[], int sizeproto);
double stdDev(double arrproto[], int sizeproto);

int main()
{
    double*arr=NULL;
    double size;
    int i = 0;
    char ch;
    string temp;
    
    cout<<"Enter the array size: ";
    cin>>size;
    
    cout<<"Enter "<<size<<" values: ";
    arr=new double[size];
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
    

    cout<<"Mean: "<<mean(arr, size)<<endl;
    cout<<"Range: "<<range(arr, size)<<endl;
    cout<<"Standard deviation: "<<stdDev(arr, size)<<endl;
    return 0;
}

double mean(double arrproto[], int sizeproto)
{
    double mean = 0;
    for(int g = 0; g < sizeproto; g++)
        mean += arrproto[g];
    return mean/sizeproto;
}

double range(double arrproto[], int sizeproto)
{
    double min=arrproto[0], max=0;
    
    for(int g = 0; g < sizeproto; g++)
    {
        if(arrproto[g] < min)
            min = arrproto[g];
        if(arrproto[g] > max)
            max = arrproto[g];
    }
    return max - min;
}

double stdDev(double arrproto[], int sizeproto)
{
    double mean = 0, standard = 0;
    const int square = 2;
    for(int g = 0; g < sizeproto; g++)
        mean += arrproto[g];
    mean /= sizeproto;
    
    for(int g = 0; g < sizeproto; g++)
    {
        standard += pow((arrproto[g] - mean), square);
    }
    
    standard /= sizeproto;
    return sqrt(standard);
}
