
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class SafeIntArray
{
public:
    SafeIntArray (int n)// an int array with 10 elements
    {
        size=n;
        array = new int [n];
        for (int i=0;i<=size-1;++i) array[i]=0;
    }
    void set(int i,int k) // sa[i]=100, if i is invalid, error message("Outside the boundary!") will be printed;
    {
        if (i<0 || i>size-1) {cout<<"Outside the boundary!"<<endl;return;}
        else
        {
            array[i]=k;
        }
    }
    int get(int i) //return sa[i], if i is invalid, error message("Outside the boundary!") will be printed and return -1;
    {
        if (i<0 || i>size-1) {cout<<"Outside the boundary!"<<endl;return -1;}
        else
        {
            return array[i];
        }
    }
    ~SafeIntArray()
    {
        delete [] array;
    }
private:
    int size;
    int * array;
};

class IndexIntArray:public SafeIntArray
{
public:
    IndexIntArray (int s,int e):SafeIntArray(e-s+1) // an int array which its index is between -10 and 2.
    {
        start=s;
        end=e;
    }
    void set(int i,int n) // set the first element to 100
    {
        if (i<start || i>end) cout<<"Outside the boundary!"<<endl;
        else SafeIntArray::set(i-start,n);
    }
    int get(int i) //return 100
    {
        if (i<start || i>end) {cout<<"Outside the boundary!"<<endl;return -1;}
        else return SafeIntArray::get(i-start);
    }
    ~IndexIntArray()
    {
        delete [] array;
    }
private:
    int start;
    int end;
    int * array;
};
int main(int argc, char** argv) {
    
    int test;
    cin >> test;
    while (test --) {
        int size, n;
        cin >> size;
        SafeIntArray sia(size);
        // test SafeIntArray::set(int,int) of SafeIntArray
        cin >> n;
        while (n --) {
            int index, data;
            cin >> index >> data;
            sia.set(index, data);
        }
        // test SafeIntArray::get(int) of SafeIntArray
        cin >> n;
        while (n --) {
            int index;
            cin >> index;
            int value = sia.get(index);
            if (value != -1) {
                cout << value << endl;
            }
        }
        
        int begin, end;
        cin >> begin >> end;
        IndexIntArray iia(begin, end);
        // test IndexIntArray::set(int,int) of IndexIntArray
        cin >> n;
        while (n --) {
            int index, data;
            cin >> index >> data;
            iia.set(index, data);
        }
        // test IndexIntArray::get(int) of IndexIntArray
        cin >> n;
        while (n --) {
            int index;
            cin >> index;
            int value = iia.get(index);
            if (value != -1) {
                cout << value << endl;
            }
        }
    }
    
    return 0;
}