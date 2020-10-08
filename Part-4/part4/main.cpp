//
//  main.cpp
//  part4
//
//  Created by Rupinder Kaur on 10/6/20.
//  Copyright © 2020 Rupinder Kaur. All rights reserved.
//

#include<iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// ------- array list with bubble sort ---------

int main()
{
    clock_t start, end;
    
    //starting clock
    start = clock();
    
    int a[50], n;
    
    cout << " Enter the size of array: ";
    cin >> n;
    cout << "\n Enter the array elements: ";

    for (int i = 0; i<n; ++i)
    cin >> a[i];

    //bubble sort
    for (int i = 1; i<n; ++i)
        {
            for (int j = 0; j<(n - i); ++j)
                if (a[j] > a[j + 1])
                {
                    int temp;
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
        }

    cout << "\n Array after bubble sort:";
        for (int i = 0; i<n; ++i)
        cout << " " << a[i];
        cout << endl;
   
    //ending clock
    end = clock();
     
    //computing execution time.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n Time taken : " << fixed << time_taken << setprecision(5)<< " sec " << endl;
    cout <<" \n";
  
    return 0;
}
