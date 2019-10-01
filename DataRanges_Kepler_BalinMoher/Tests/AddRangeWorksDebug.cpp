#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

struct Range {
    int first, last;
    Range(int a, int b)
    {
        first = a;
        last = b;
    }
};

struct flags {
    int q, t, p, h;
    flags(int a, int b, int c, int d)
    {
        q = a;
        t = b;
        p = c;
        h = d;
    }
};

int input, run = 1;
int ind = 0;
int i;
int m1;
int recheck = 0;
int add = 0;
vector<Range> RangeList;
vector<flags> Flag;

void check(vector<Range> &RangeList, vector<flags> &Flag, int &temp_first, int &temp_last, int &p, int &q, int &t, int &h, int &i, int &m1, int &recheck, int &add);
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
        
        int temp_first, last_input, temp_last;
        int p = 0, q = 0, t = 0, h = 0, i = 0;
        Flag.clear();
        
        for (int j = 0; j < 1; j++) {
        cout << "Please enter the start of the range" << endl;
        cin >> temp_first;
        cout << "Please enter the end of the range" << endl;
        cin >> last_input;
        cout << ". . ." << endl;
        temp_last = last_input-1;
            if (temp_last - temp_first < 0) {
                cout << "start must be less than end. please re-enter." << endl;
            j--;    
            }
        }
        
    
        if (ind != 0) {
            for (i; i < RangeList.size();) {
                if (RangeList.empty()) {
                    break;
                }
                check(RangeList, Flag, temp_first, temp_last, p, q, t, h, i, m1, recheck, add);
                cout << "Confirm recheck (1 if yes): " << recheck << endl;
                cout << "Rechecking " << RangeList.size() << " vector entries. Starting at " << i << endl;
            }
        }
        
        cout << "Outside of Loop i and m1:  " << i << m1 << endl;
        m1 = 0;
        recheck = 0;
        i = 0;
        if (add == 1) {
        RangeList.push_back(Range(temp_first, temp_last));
        }
  
    
        if (ind == 0) {
            RangeList.push_back(Range(temp_first, temp_last));
            ind++;
        }
    cout << "Printing " << RangeList.size() << " Entries." << endl;
    for (int i = 0; i < RangeList.size() ; i++) {
    cout << "entry: " << i << endl;
    cout << RangeList.at(i).first << ' ' << RangeList.at(i).last << endl; 
    }
  

    


    
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

void check(vector<Range> &RangeList, vector<flags> &Flag, int &temp_first, int &temp_last, int &p, int &q, int &t, int &h, int &i, int &m1, int &recheck, int &add) {

        p = 0, q = 0, t = 0, h = 0, i;
        int start_bound, end_bound;


            cout << "Evaluating " << temp_first << "," << temp_last << " against " << RangeList.at(i).first  << "," << RangeList.at(i).last << " at position: " << i << endl;
            
            // New start in range, new end in range
            if (temp_first <= RangeList.at(i).last && temp_first >= RangeList.at(i).first && temp_last >= RangeList.at(i).first && temp_last <= RangeList.at(i).last) {
                q=1; //start point intersection
                t=1; //end point interesection
                p=0; //new range within existing, merge
                h=0;
                Flag.push_back(flags(q, t, p, h));
            }
            
            // New start in range, new end greater than range
            if (temp_first <= RangeList.at(i).last && temp_first >= RangeList.at(i).first && temp_last > RangeList.at(i).last) {
                q=1; //start point in range
                t=0; //end point outside
                p=0; //merge
                h=0;
                Flag.push_back(flags(q, t, p, h));
            }
            // New start less than range, new end within range
            if (temp_first < RangeList.at(i).first && temp_last >= RangeList.at(i).first && temp_last <= RangeList.at(i).last) {
                q=0; //start point less than range
                t=1; //end in range
                p=0; //merge
                h=0;
                Flag.push_back(flags(q, t, p, h));
            }
            //New start less than range, new end greater than range
            if (temp_first < RangeList.at(i).first && temp_last > RangeList.at(i).last) {
                q=0; //start point less than range
                t=0; //end point greater than range
                p=1; //scan again
                h=1; //New range encompasses old
                Flag.push_back(flags(q, t, p, h));
            }
            //New start and end less than range
            if (temp_first < RangeList.at(i).first && temp_last < RangeList.at(i).first) {
                q=0; //start point less than range
                t=0; //end point less than range
                p=1; //scan again
                h=0; //New range less than range. 
                Flag.push_back(flags(q, t, p, h));
            }
            //New start and end greater than range
            if (temp_first > RangeList.at(i).last && temp_last > RangeList.at(i).last) {
                q=0; //No start point intersection
                t=0; //end point greater than range
                p=0; //scan again
                h=1; //new range greater than range. rescan
                Flag.push_back(flags(q, t, p, h));
            }

        cout << "Indicators (q, t, p, h):" << q << " " << t << " " << p << " " << h << endl;   
        
        if ( (q == 1 && t == 1 && p == 0 && h == 0) || (temp_first == RangeList.at(i).first && temp_last == RangeList.at(i).last)) {

        cout << "Already exists or within an existing range. Do not add new range." << endl;
        add = 0;
        recheck = 0;
        i++;
        }
    
        if (q == 1 && t == 0 && p == 0 && h == 0) {
            cout << "New start in range, new end greater than range. Found at " << i << ". Merging." << endl;

            start_bound = min(RangeList.at(i).first, temp_first);
            end_bound = temp_last;
            add = 1;
            RangeList.erase(RangeList.begin() + i);
            recheck = 1;
            i = 0;
        }
        
        else if (q == 0 && t == 1 && p == 0 && h == 0) {
            cout << "New start less than range, new end within range at " << i << ". Merging." << endl;
            
            start_bound = temp_first;
            end_bound = max(RangeList.at(i).last, temp_last);
            add = 1;
            RangeList.erase(RangeList.begin() + i);
            recheck = 1;
            i = 0;
        }
        
        if (q == 0 && t == 0 && p == 1 && h == 1) {
            cout << "New start less than range, new end greater than range at " << i << ". Merging. Re-Check for Intersection." << endl;
            
            start_bound = temp_first;
            end_bound = temp_last;
            add = 1;
            RangeList.erase(RangeList.begin() + i);
            recheck = 1;
            i = 0;
        }
        
        if (q == 0 && t == 0 && p == 1 && h == 0) {
            cout << "New start and end less than range at " << i << ". Re-Check for Intersection." << endl;
            
            start_bound = temp_first;
            end_bound = temp_last;
            add = 1;
            recheck = 1;
            i++;
        }
        
        if (q == 0 && t == 0 && p == 0 && h == 1) {
            cout << "New start and end greater than range at " << i << ". Re-Check for Intersection." << endl;
            
            start_bound = temp_first;
            end_bound = temp_last;
            add = 1;
            recheck = 1;
            i++;
        }
        
        if (q == 0 && t == 0 && p == 0 && h == 0) {
            cout << "No match found" << endl;
            add = 0;
            recheck = 0;
        }
        if (recheck == 1) {
            temp_first = start_bound;
            temp_last = end_bound;
        }
           cout << "Inside Loop. Recheck? (1 if yes):  " << recheck << endl;
        for (int k = 0; k < RangeList.size() ; k++) {
    cout << "entry: " << k << endl;
    cout << RangeList.at(k).first << ',' << RangeList.at(k).last << endl; 
    }
}