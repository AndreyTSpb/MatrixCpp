#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const int N = 3; //кол-во элементов в массиве по горизонтале
const int M = 3; //кол-во элементов в массиве по вертикале
int arr[N][M]; //Исходный двумерный массив
int arr2[M]; //Конечный массив
int maxLenght = 1; //Максимальная количество знаков в массиве

//Функция вывода массива в консоль
void viewArray(int arr[]){
    for(int i = 0; i < M; i++)
    {
        if(M-1 == i){
            cout << "[" << i << "] => " << arr[i] << "\n";
        }else{
            cout << "[" << i << "] => " << arr[i] << ", ";
        }
        
    }
}

//Функция прверки максимольной введенной длинны
void getLength(){
    for(int i = 0; i< M; i++){
        for(int j = 0; j < N; j++){
            int qnt = to_string(arr[i][j]).size();
            if(maxLenght < qnt){
                maxLenght = qnt;
            }
        }
    }
    maxLenght = maxLenght+2;
}
//Отрисовка строк
void row(char c){
    for(int j = 0; j < N+(maxLenght*N)+4; j++){
        cout << c;   
    }
    cout << endl; 
}

//Функция вывода двумерного массива в консоль
void viewMatrix(){
    //
    int s = 2;
    if(N>9){
        s = to_string(N).size();
    }
    cout << setw(s+2);
    for(int j = 0; j < N; j++){
        cout<<"|"<<setw(maxLenght-2)<< "["<<j<<"]";
        if(j == N-1){
            cout << "|" << endl;
        }
    }
    row('=');
    for(int i = 0; i< M; i++){
        cout << ""<< "["<<i<<"]";
        for(int j = 0; j < N; j++){
            if(j == N-1){
                cout << "|" << setw(maxLenght) << arr[i][j] << "|";
            }else{
                cout << "|" << setw(maxLenght) << arr[i][j];
            }
        }
        cout << endl;
        if(i == M-1){
            row('=');
        }else{
            row('-');
        }
    }
}

//Функция заполнения двумерного массива с клавиатуры
void fillMatrix(){
    cout << "Укажите данные для двумерного массива " << N << " на "<< M << endl;
    for(int i = 0; i< M; i++){
        for(int j = 0; j < N; j++){
            cout << "arr["<<i<<"]["<< j <<"]= ";
            cin >> arr[i][j];
        }
    }
}
//Функция для создание нового одномерного массива
void newArray(){
    for(int i = 0; i< M; i++){
        int summ = 1;
        for(int j = 0; j < N; j++){
            summ += arr[i][j];
        }
        arr2[i] = summ;
    }
}
int main(){
    fillMatrix(); //ввод двумерного массива
    getLength(); //максиммальная длинна символов в числе
    cout << " Двумерный массив: " << endl;
    viewMatrix(); //вывод двумерного массива
    newArray();
    cout << " Новый одномерный массив: " << endl;
    viewArray(arr2); //вывод одномерного массива
    return 0;
}
