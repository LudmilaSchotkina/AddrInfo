#include <iostream>
#include <fstream>
#include "class.h"

AddressInfo::AddressInfo():
    N(0),array(0) {}

AddressInfo::AddressInfo(string surname, string address, int phone):
    surname(surname), address(address), phone(phone) {}

AddressInfo::~AddressInfo()
{
    surname='\0';
    address='\0';
    phone=0;
}

AddressInfo &AddressInfo::operator=(const AddressInfo &org)
{
    if (this==&org)
        return *this;

    surname=org.surname;
    address=org.address;
    phone=org.phone;

    return *this;
}

std::ostream &operator<<(std::ostream &out,const AddressInfo &org)
{
    out.width(4);
    out<<org.surname<<"\t\t"<<org.address<<"\t\t"<<org.phone<<endl;
    out<<"________________________________________________";
    return out;
}
///////////////////////////////////////////////////////////

string AddressInfo::getSurname()
{
    return surname;
}
string AddressInfo::getAddress()
{
    return address;
}
int AddressInfo::getPhone()
{
    return phone;
}
///////////////////////////////
void AddressInfo::setSurname(string sname)
{
    surname=sname;
}

void AddressInfo::setAddress(string adr)
{
    address=adr;
}
void AddressInfo::setPhone(int ph)
{
    phone=ph;
}
///////////////////////////////////////////////////////////


int cmp_surname (AddressInfo a, AddressInfo b,int order)
{
    if(order==1)
        return a.getSurname()<b.getSurname()?-1:(a.getSurname()>b.getSurname()?1:0);
    else
        return a.getSurname()<b.getSurname()?1:(a.getSurname()>b.getSurname()?-1:0);

}
int cmp_address ( AddressInfo a, AddressInfo b,int order)
{
    if(order==1)
        return a.getAddress()<b.getAddress()?-1:(a.getAddress()>b.getAddress()?1:0);
    else
        return a.getAddress()<b.getAddress()?1:(a.getAddress()>b.getAddress()?-1:0);

}
int cmp_phone (AddressInfo a, AddressInfo b,int order)
{
    if(order==1)
        return a.getPhone()-b.getPhone();
    else
        return b.getPhone()-a.getPhone();
}


void merge(AddressInfo *array, int N, int first, int middle, int last, Ptf cmp,int order)
{

    AddressInfo *b=new AddressInfo[N];
    for(int i=0; i<N; ++i)
    {
        b[i]=array[i];
    }

    int h,i,j,k;
    h=first;
    i=first;
    j=middle+1;

    while((h<=middle)&&(j<=last))
    {
        if(cmp(array[h],array[j],order)<=0)
        {
            b[i]=array[h];
            h++;
        }
        else
        {
            b[i]=array[j];
            j++;
        }
        i++;
    }
    if(h>middle)
    {
        for(k=j; k<=last; k++)
        {
            array[k]=b[i];
            i++;
        }
    }
    else
    {
        for(k=h; k<=middle; k++)
        {
            b[i]=array[k];
            ++i;
        }
    }
    for(k=first; k<=last; k++)
    {
        array[k]=b[k];

    }
    delete [] b;
}

void mergesort(AddressInfo *array, int N, int first, int last, Ptf cmp, int order)
{
    int middle;
    if(first<last)
    {
        middle=(first+last)/2;
        mergesort(array,N,first,middle,cmp,order);
        mergesort(array,N,middle+1,last,cmp,order);
        merge(array,N,first,middle,last,cmp,order);
    }
}

void mergeShell (AddressInfo *array, int N,Ptf cmp, int order)
{
    int  first=0, last=N-1;
    mergesort(array,N,first,last,cmp,order);
}


void readfile(AddressInfo *array, int N)
{
    string surname,address;
    int phone;

    fstream inBaseFile;
    inBaseFile.open("base.txt", ios::in);

    if(!inBaseFile)
    {
        cerr<<"ERROR"<<endl;
    }

    for(int i=0; i<N && !inBaseFile.eof(); ++i)
    {
        inBaseFile>>surname;
        array[i].setSurname(surname);

        inBaseFile>>address;
        array[i].setAddress(address);

        inBaseFile>>phone;
        array[i].setPhone(phone);
    }
    inBaseFile.close();
}
