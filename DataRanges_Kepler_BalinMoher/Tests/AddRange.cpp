#include <iostream>
#include <vector>

using namespace std;



struct Range {
    int first, last;
    Range(int a, int b)
    {
        first = a;
        last = b;
    }
};


int input, run = 1;
int temp_first, temp_last;
int ind = 0;
int i;
vector<Range> RangeList;

int menu();

int main()
{


    
    menu();
    
    

}

int menu() {
   while (run == 1) {
   cout << "1: Add new Data Range\n2: Delete Data Range\n3: Get Data Range\n4: Exit\n(Enter 1, 2, 3 or 4)" << endl;
   cin >> input;
   if (input == 1){
       

    cout << "Please enter the start of the range" << endl;
    cin >> temp_first;
    cout << "Please enter the end of the range" << endl;
    cin >> temp_last;
    RangeList.push_back(Range(temp_first, temp_last));
    ind++;
    
    for (int i = 0; i < RangeList.size() ; i++) {
    cout << RangeList.at(i).first << ' ' <<RangeList.at(i).last << endl;
    }
    // if (ind =! 0) {
        
    // }
   }
   else if (input == 2){

   }
   else if (input == 3){

   }
   else if (input == 4){
      run = 0;
   }
   if (run == 0) {
   cout << ". . .\nGoodbye" << endl;
   break;
   }
}
}