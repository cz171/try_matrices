//
//  main.cpp
//  try_matrices
//
//  Created by ZHAN CHEN on 11/1/14.
//  Copyright (c) 2014 Zhan CHEN. All rights reserved.
//
//this is a very simple example for illustring th benefit of applying the compiler blocking optimaziton
#include <iostream>

int main(int argc, const char * argv[]) {
    
//let the user to put the N
    int n;
    std::cout<< "Please put n : ";
    while(std::cin>> n) {
        std::cout<< '\n';
        //allocate array dynamically
        int **a = new int*[n];
        for(int i = 0; i<n ;i++){
            a[i] = new int[n];
        }
    
        int **b = new int*[n];
        for(int i = 0; i<n ;i++){
            b[i] = new int[n];
        }
    
        int **c = new int*[n];
        for(int i = 0; i<n ;i++){
            c[i] = new int[n];
        }
    
    
        //initializet the matrices
        for(int i = 0 ; i <n; i++)
            for(int j = 0; j<n; j++){
                a[i][j] = i+j;
                b[i][j] = i+j;
            }
    
        //do the calculation
    
        for(int i= 0; i<n ; i++)
            for (int j= 0; j<n; j++) {
                int temp = 0;
                for (int k = 0; k<n; k++){
                    temp+= a[i][j] * b[j][k];
                    c[i][j] = temp;
                }
            }
    
        //output the result
    
        std::cout<< "the result is :"<<  '\n';
        for(int i= 0; i<n ; i++){
            for (int j= 0; j<n; j++){
                std::cout<<c[i][j]<< " ";
            
            }
            std::cout<<'\n';
        }
        std::cout<<'\n';
    
        //delete all the matrices
        for(int i=0;i<n;i++)
            delete[] a[i];
        delete[] a;
    
        for(int i=0;i<n;i++)
            delete[] b[i];
        delete[] b;
    
        for(int i=0;i<n;i++)
            delete[] c[i];
        delete[] c;
        }
    
        return 0;
    
    
}
