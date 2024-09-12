//Nicholas Guidice
//CS 375 Project 2 "Merge Sort"

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    //Calculate The Size Of The Left And Right Subarrays
    int leftNum = mid - left + 1;
    int rightNum = right - mid;

    //Create The Left And Right Subarrays
    vector<int> leftSub(leftNum), rightSub(rightNum);

    //Copy Data To Left And Right Subarrays
    for(int i = 0; i < leftNum; i++){
        leftSub[i] = arr[left + i];
    }
    for (int j = 0; j < rightNum; j++){
        rightSub[j] = arr[mid + 1 + j];
    }

    //Redeclare Temp Variables 
    int i = 0;
    int j = 0;
    int temp = left;

    while (i < leftNum && j < rightNum){
        if(leftSub[i] <= rightSub[j]){
            arr[temp] = leftSub[i];
            i++;
        }
        else{
            arr[temp] = rightSub[j];
            j++;
        }
        temp++;
    }

    //Copy Any Remaining Elements
    while(i < leftNum){
        arr[temp] = leftSub[i];
        i++;
        temp++;
    }

    //Copy Any Remaining Elements
    while(j < rightNum){
        arr[temp] = rightSub[j];
        j++;
        temp++;
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    //Check If left Subarray Is Greater Than The Right Subarray, If So Return
    if(left >= right){
        return;
    }

    //Calculate The Middle Index 
    int mid = left + (right - left) / 2;

    mergeSort(arr,left,mid);
    mergeSort(arr,mid + 1,right);
    merge(arr,left,mid,right);
}

void print(const vector<int>& arr){
    //Iterate Over The Entire Array And Print
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " " << endl;
    }
}

void printArg(const vector<int>& arr,int start, int end){
    //Exception Handling 
     if (start < 0 || end >= arr.size() || start > end) {
        throw out_of_range("Index out of range");
    }
    //Print The Range Size Specified By The Arguments
    //cout << endl;
    cout << "Range Size:" << (end - start) + 1 << endl; 

    //Iterate Over The Entire Array And Print
    cout << "Sorted Array:" << endl;
    for (int i = start; i <= end; i++){
        cout << arr[i] << " " << endl;
    }
}

int main(int argc, char* argv[]) {
    //Declare Variable That Will Hold The Size Of The Vector
    int arrNum;

    // Define A Value Vector To The Correct Size
    cin >> arrNum;
    vector<int> valArr(arrNum);

    // Read In the Pre-Sorted Values Into The Vector 
    for (int i = 0; i < arrNum; i++) {
        cin >> valArr[i];
    }


    //Call mergeSort Function
    mergeSort(valArr,0,arrNum - 1);

    //Check That There Are No Range Requierments
    if (argc != 3){
    //Print The Total Amount Of Numbers
    //cout << endl;
    cout << "Total Numbers:" << endl; 
    cout << arrNum << endl;

    //Call Print Function
    print(valArr);
    }

    //If There Are Range Requierments
    if (argc == 3){
        //Read In Command Line Arguments
        int start = stoi(argv[1]);
        int end = stoi (argv[2]);

        //Call printArg Function
        printArg(valArr,start,end);
    }

    // End Main
    return 0;
}
