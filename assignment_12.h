#pragma once
#include <iostream>


using namespace std;

#define MAX_SIZE 100

class CStack
{
private:
    int stack[MAX_SIZE];   
    int top = -1;          
public:
    void Push(int x);
    int Pop();
    void print();
};