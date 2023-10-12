#include <stdlib.h>
#include <iostream>

struct TwoInts
{
    int a;
    int b;
};
struct StructWithArray
{
    int arr[4];
    int* someNumber;
};

int main()
{
    TwoInts i2 = { };
    i2.a = 5;
    //значение для a=5
    i2.b = 7;
    //значение для b=7

    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;

    StructWithArray s = { };
    s.arr[0] = 10;
    //значение первого элемента массива s=10

    StructWithArray s1 = { };
    s1.arr[0] = 15;
    //значение первого элемента массива s1=15

    StructWithArray* sPointer = &s;
    //sPointer указывается на s
    sPointer->arr[0] = 20;
    //первый элемент массива на который указывает sPointer приравнивается к 20(к s)

    std::cout << s.arr[0] << std::endl;
    s.arr[0] = 25;
    //значение первого элемента переменной с массивом внутри приравнивается к 25
    std::cout << s.arr[0] << std::endl;
    //вывод значения первого элемента из массива s
    sPointer->arr[0] = 30;
    //указатель на первый элемент массива s=30
    std::cout << s.arr[0] << std::endl;
    //вывод значения первого элемента из массива s

    sPointer = &s1;
    //sPointer указывается на s1
    sPointer->arr[0] = 35;
    //первый элемент массива на который указывает sPointer приравнивается к 35(к s1)
    std::cout << s.arr[0] << std::endl;
    //вывод первого элемента массива внутри переменной s
    std::cout << s1.arr[0] << std::endl;
    //вывод первого элемента массива внутри переменной s1
    StructWithArray structArray[2] = { };

    structArray[0].arr[3] = 77;
    //записываем в structArray в четвёртый элемент значение 77
    structArray[1].someNumber = &structArray[0].arr[3];
    //записываем в structArray адрес третьего элемента structArray

    sPointer = &s;
    //поинтер перенапрявляет на s
    int* pointer = &sPointer->arr[3];
    //создание указателя pointer и присваивание ему значение уквзателя sPointer указывающего на четвертый элемент массива arr
    s.arr[3] = 72;
    //записываем в четвертый элемент массива s значение 72
    std::cout << *pointer;
    //вывод значения указателя *pointer

    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));
    return 0;
}
//
// Created by nicki on 10/11/2023.
//
