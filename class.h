#ifndef CLASS_H
#define CLASS_H
using namespace std;

class AddressInfo
{
public:
    AddressInfo();
    AddressInfo(string surname, string address, int phone);
    AddressInfo &operator=(const AddressInfo &org);
    ~AddressInfo();

    string getSurname();
    string getAddress();
    int getPhone();

    void setSurname(string sname);
    void setAddress(string address);
    void setPhone(int ph);


    friend std::istream &operator>>(std::istream &input, const AddressInfo &org);
    friend std::ostream &operator<<(std::ostream &out,const AddressInfo &org);

private:
    int N;
    string *array;
    string surname;
    string address;
    int phone;
};

typedef int (*Ptf)(AddressInfo, AddressInfo,int);
int cmp_surname (AddressInfo a, AddressInfo b,int order);
int cmp_address (AddressInfo a, AddressInfo b,int order);
int cmp_phone (AddressInfo a, AddressInfo b,int order);

void mergeShell (AddressInfo *array, int N,Ptf cmp, int order);

void readfile (AddressInfo *array,int N);

#endif
