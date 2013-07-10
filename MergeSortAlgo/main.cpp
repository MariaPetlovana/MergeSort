#include <iostream>
//#include std::cout
using std::cout;
using std::cin;

int* TemporaryArray;
void MakeMerge(int* MakeMergeArray, int Left, int Middle, int Right){
    int i = Left, j = Middle + 1;

  for (int step = 0; step < Right - Left + 1; ++step){
        if ((j > Right || (i <= Middle && MakeMergeArray[i] < MakeMergeArray[j])))
        {
            TemporaryArray[step] = MakeMergeArray[i];
            ++i;
        }
        else
        {
            TemporaryArray[step] = MakeMergeArray[j];
            ++j;
        }
  }

  for (int step = 0; step < Right - Left + 1; ++step)
  {
        MakeMergeArray[Left + step] = TemporaryArray[step];
  }

  return;
}

void MergeSort(int* MergeSortArray, int Left, int Right){
  if (Left == Right) return;
  int Middle = (Left + Right) / 2;

  MergeSort(MergeSortArray, Left, Middle);
  MergeSort(MergeSortArray, Middle + 1, Right);
  MakeMerge(MergeSortArray, Left, Middle, Right);

  return;
}

int main()
{
    size_t ElementsCount = 0;
    cout << "Enter number of elements in the array:\n";
    cin >> ElementsCount;

    int ArrayToSort[ElementsCount];
    TemporaryArray = new int[ElementsCount];
    cout << "Enter elements:\n";

    for(size_t i = 0; i < ElementsCount; ++i)
    cin >> ArrayToSort[i];

    MergeSort(ArrayToSort, 0, ElementsCount-1);

    cout << "Sorted array:\n";
    for(size_t i = 0; i < ElementsCount; ++i)
    cout << ArrayToSort[i] << ' ';
    cout << "\n";

    delete[] TemporaryArray;

    return 0;
}
