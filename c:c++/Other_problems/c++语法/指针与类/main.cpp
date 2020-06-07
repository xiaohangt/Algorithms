#include <iostream>
#include <iomanip>
using namespace std;
class Elements{
    
private:
    
    int value;
    
    static int numberOfObjects;
    
public:
    
    Elements();
    Elements(const int &value);
    Elements(const Elements &elem);
    
    ~ Elements();

    Elements & operator=(const Elements &elem);//assignment
    
    Elements & operator=(const int &value);//assignment
    
    friend istream& operator>>(istream& is, Elements & elem);
    
    //input one integer, and set the value
    
    friend ostream& operator<<(ostream& os, const Elements & elem);
    
    //output one integer to ostream
    
    void setValue(const int &value);
    
    //set value
    
    int getValue()const;
    
    //get value
    
    
    Elements & operator+=(const Elements &elem);
    
    Elements & operator+=(const int &value);
    
    
    
    Elements operator+(const Elements &elem)const;
    
    Elements operator+(const int &value)const;
    
    
    
    bool operator ==(const Elements &elem)const;
    
    bool operator ==(const int &value)const;
    
    
    
    bool operator <(const Elements &elem)const;
    
    bool operator <(const int &value)const;
    
    operator int()const;//converts Elementes to int
    
    
    
    static int getNumberOfObjects();//return the number of objects
    
    
};

class MyVector{
    
private:
    
    Elements *elem;
    
    int _size;
    
public:
    
    MyVector();//default constructor
    
    MyVector(int n);// constructor an Array of n Elements
    
    MyVector(const MyVector &vec);//copy constructor
    
    ~MyVector();//destructor
    
    const MyVector & operator=(const MyVector &vec);//assignment
    
    Elements &operator[](int i);//return the references of elem[i]
    
    Elements operator[](int i) const; //return the copy of elem[i]
    
    
    
    int size()const;//return the size
    
    
    
    bool operator == (const MyVector &vec)const;//judge if it is equal
    
    friend istream& operator>>(istream& is, MyVector & vec);
    
    //first input n as a _size, then input elem[0],elem[1],…,elem[n-1];
    
    
    
    friend ostream& operator<<(ostream& os, const MyVector & vec);
    
    //output elem[0],elem[1],elem[2],..,elem[_size-1] in a line, separated by a
    
    //space. e.g  _size = 2 and elem[0]=5,elem[1]=6, you should output
    
    //”5 6” in a line
    
};


//ssssssssssssssssssssssssssssssssssssssssssssss
int Elements::numberOfObjects=0;
Elements::Elements()
{
    value=0;
    ++numberOfObjects;
}

Elements::Elements(const int &value)
{
    this->value=value;
    ++numberOfObjects;
}
Elements::Elements(const Elements &elem)
{
    value=elem.value;
    ++numberOfObjects;
}

Elements::~ Elements()
{
    --numberOfObjects;
}

int Elements::getNumberOfObjects()
{
    return numberOfObjects;
}
Elements & Elements::operator=(const Elements &elem)
{
    value=elem.getValue();
    return *this;
}
Elements & Elements::operator=(const int &value)
{
    this->value=value;
    return *this;
}
istream& operator>>(istream& is, Elements & elem)
{
    is >> elem.value;
    return is;
}
//input one integer, and set the value

ostream& operator<<(ostream& os, const Elements & elem)
{
    os<<elem.value;
    return os;
}

//output one integer to ostream

void Elements::setValue(const int &value)
{
    this->value=value;
}

//set value

int Elements::getValue()const
{
    return value;
}

//get value

//加减乘除
Elements & Elements::operator+=(const Elements &elem)
{
    value += elem.value;
    return *this;
}
Elements & Elements::operator+=(const int &val)
{
    value += val;
    return *this;
}
Elements Elements::operator+(const Elements &elem)const
{
    return Elements(value+elem.value);
}
Elements Elements::operator+(const int &val)const
{
    return Elements(value+val);
}


bool Elements::operator ==(const Elements &elem)const
{
    if (value==elem.getValue()) return true;
    else return false;
}

bool Elements::operator ==(const int &val)const
{
    if (val==value) return true;
    else return false;
}



bool Elements::operator <(const Elements &elem)const
{
    if (value<elem.value) return true;
    else return false;
}

bool Elements::operator <(const int &val)const
{
    if (value<val) return true;
    else return false;
}

Elements::operator int()const
{
    return value;
}






MyVector::MyVector()
{
    elem=NULL;
    _size=0;
}

MyVector::MyVector(int n)// constructor an Array of n Elements
{
    elem= new Elements [n];
    _size=n;
}

MyVector::MyVector(const MyVector &vec)//copy constructor
{
    elem= new Elements [vec._size+1];
    _size=vec._size;
    for (int i=0;i<=_size-1;++i)
    {
        elem[i]=vec.elem[i];//*************
    }
}

MyVector::~MyVector()//destructor
{
    delete [] elem;
    
}

const MyVector & MyVector::operator=(const MyVector &vec)//assignment
{
    //***********************(1)避免自我复制！！！！！
    if (&vec!=this)
    {
    _size=vec._size;
    delete [] elem;
    elem= new Elements [_size+1];
    for (int i=0;i<=_size-1;++i)
    {
        elem[i].setValue(vec.elem[i].getValue());
    }
    return *this;
    }
    return *this;
}

Elements & MyVector::operator[](int i)//return the references of elem[i]
{
    //***********
    return (elem[i]);
}

Elements MyVector::operator[](int i) const //return the copy of elem[i]
{
    Elements k(elem[i]);
    return k;
}



int MyVector::size()const//return the size
{
    return _size;
}



bool MyVector::operator == (const MyVector &vec)const//judge if it is equal
{
    if (_size!=vec._size) return false;
    else
    {
        for (int i=0;i<=_size-1;++i)
            if (*(elem+i)!=*(vec.elem+i)) return false;
    }
    return true;
}

istream& operator>>(istream& is, MyVector & vec)
{
    //***************（2）删除指针后才能进行创建
    if (vec.elem!=NULL) delete [] vec.elem;
    is >> vec._size;
    vec.elem = new Elements[vec._size];
    for (int i=0;i<=vec._size-1;++i)
    {
        is >> vec.elem[i];
    }
    return is;
}

//first input n as a _size, then input elem[0],elem[1],…,elem[n-1];



ostream& operator<<(ostream& os, const MyVector & vec)
{
    os <<vec.elem[0];
    for (int i=1;i<=vec._size-1;++i)
    {
        os  << " " << vec.elem[i].getValue();
    }
    return os;
}

//output elem[0],elem[1],elem[2],..,elem[_size-1] in a line, separated by a

//space. e.g  _size = 2 and elem[0]=5,elem[1]=6, you should output

//”5 6” in a line

//sssssssssssssssssssssssssssssssssssssssssssssss
Elements getSum(const MyVector &vec)

{
    
    Elements sum = 0;
    
    for(int i=0;i<vec.size();i++)
    {
        sum += vec[i];
    }
    return sum;
}
void sample()
{
    MyVector vec;
    while( cin >> vec )
    {
        cout << vec << endl;
        MyVector vec2 = vec;
        Elements sum = getSum(vec);
        int average = (int)sum / vec.size();
        for(int i=0;i<vec.size();i++)
        {
            if( vec[i] < average )
            {
                vec [i] = average;
            }
        }
        cout << vec << endl;
        if( vec == vec2 )
        {
            cout << "They are equal" << endl;
        }
    }
}
int main()
{
    sample();
    if(Elements::getNumberOfObjects()!=0)
    {
        cout << "Error: occupied memory" << endl;
        cout << "Too young too simple, sometimes naive!" << endl;
    }
    
    return 0;
    
}
