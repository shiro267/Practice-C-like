#include "BubbleSort.h"

int main()
{
    int input;
    vector<int> data;
    while(cin>>input)
    {
        data.push_back(input);
    }



    BubbleSort(data);

    cout << "BubbleSort = ";
    for(auto&c : data)
    {
        cout << c << " ";
    }
    cout << endl;



}
