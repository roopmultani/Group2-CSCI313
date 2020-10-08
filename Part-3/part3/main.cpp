//
//  main.cpp
//  part3
//
//  Created by Rupinder Kaur on 9/26/20.
//  Copyright © 2020 Rupinder Kaur. All rights reserved.
//

  
#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
    int arr[5][3], temp;
    int r, c;
    
    cout << "Enter number of rows: ";
    cin >> r;
    cout << endl;
    cout << "Enter number of columns: ";
    cin >> c;
    cout << "\nEnter " << c << " values for column: ";
    cout << endl;
   
    for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                cin >> arr[i][j];
            }
        }
    
    cout <<"\nSorting array using bubble sort...\n";
    
    for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
                {
                    for (int k=0; k<r; k++)
                        {
                            for (int l=0; l<c; l++)
                                {
                                    if (arr[i][j] < arr[k][l])
                                        {
                                            temp = arr[i][j];
                                            arr[i][j] = arr[k][l];
                                            arr[k][l] = temp;
                                        }
                                }
                        }
                }
        }
    
    cout <<"\n Sorted Successfully!\n";
    cout <<" Sorted order (ascending) list: \n\n";
    for (int i=0; i<r; i++)
        {
           for (int j=0; j<c; j++)
            {
                cout << arr[i][j] << "\t";
            }
        }
    cout << "\n" << endl;
    
    return 0;
}
