#include <iostream>
#include <cstdlib>
#include "class.h"

using namespace std;

int main()
{
    int N=20, choice,order,key;
    bool flag=1;


    while(flag)
    {
        AddressInfo *array=new AddressInfo[N];
        readfile(array,N*3);
        cout<<"================================================"<<endl;
        cout<<"SURNAME"<<"\t\t"<<"ADDRESS"<<"\t\t"<<"PHONE"<<endl;
        cout<<"================================================"<<endl;

        for( int i=0; i<N; i++)
        {
            cout<<array[i]<<endl;
        }

        Ptf cmp_ar[3]= {cmp_surname,cmp_address,cmp_phone};
        cout<<"To sort:"<<endl<<"1 - surname"<<"\t"<<"2 - address"<<"\t"<<"3 - phone"<<endl;
        cin>>choice;
        cout<<endl<<"To sort:"<<endl<<"1 - sort ascending "<<"\t"<<"2 - sort descending "<<endl;
        cin>>order;
        mergeShell(array,N,cmp_ar[choice-1],order);

        cout<<"After sorting: "<<endl<<endl;
        cout<<"================================================"<<endl;
        cout<<"SURNAME"<<"\t\t"<<"ADDRESS"<<"\t\t"<<"PHONE"<<endl;
        cout<<"================================================"<<endl;
        for( int i=0; i<N; i++)
        {
            cout<<array[i]<<endl;
        }

        delete [] array;

        cout<<endl<<"Do you want to continue? (1 or 0)?"<<endl;
        cin>>key;
        switch(key)
        {
        case 0:
            flag=0;
            break;
        case 1:
            flag=1;
            break;
        default:
            flag=0;
            break;
        }
    }

    return 0;
}
