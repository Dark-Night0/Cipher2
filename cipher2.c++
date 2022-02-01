#include <iostream>
#include <string.h>
using namespace std;
void get_Decrypt();
void get_Encrypt();
string encyrpt(string test, int key);
string decrypt(string test, int key);
void display();
int main()
{
    system("clear");
    display();

    return 0;
}

string encyrpt(string test, int key)
{
    string s1 = "";
    int s2;
    for (int i = 0; i < test.length(); i++)
    {

        if (isupper(test[i]))
        {
            // When entering spaces
            if (int(test[i]) == 32)
            {
                s1 += " ";
                continue;
            }
            int x = int(test[i]) + key;
            s2 = (x > 90) ? (x - 90) + 65 : x;
            
            s1 += char(s2);
        }
        else
        {
            // When entering spaces
            if (int(test[i]) == 32)
            {
                s1 += " ";
                continue;
            }
            int z = int(test[i]) + key;
            s2 = (z > 122) ? (z - 122) + 97 : z;
            s1 += char(s2);
        }
    }
    return s1;
}

string decrypt(string test, int key)
{

    string s1 = "";
    int s2;

    for (int i = 0; i < test.length(); i++)
    {

        if (isupper(test[i]))
        {
            // When entering spaces
            if (int(test[i]) == 32)
            {
                s1 += " ";
                continue;
            }
            int x = int(test[i]) - key;
            s2 = (65 <= x) ? x : 90 - (65 - x);
            s1 += char(s2);
        }
        else
        {
            // When entering spaces
            if (int(test[i]) == 32)
            {
                s1 += " ";
                continue;
            }
            int z = int(test[i]) - key;
            s2 = (97 <= z) ? z : 122 - (97 - z);
            s1 += char(s2);
        }
    }
    return s1;
}

void get_Decrypt()
{

    string x;
    int key = 0;
    cout << "Enter The Key : ";
    cin >> key;
    cin.ignore();
    cout << "Enter The TEXT : ";
    getline(cin, x);

    system("clear");
    cout << "The TEXT : " << x << endl;
    cout << "The Key is : " << key << endl;
    cout << "Decrypt : " << decrypt(x, key);
}
void get_Encrypt()
{

    string x;
    cout << "Enter The Key : ";
    int key;
    cin >> key;
    cin.ignore();
    cout << "Enter The TEXT : ";
    getline(cin, x);

    system("clear");
    cout << "The TEXT : " << x << endl;
    cout << "The Key is : " << key << endl;
    cout << "Encrypt : " << encyrpt(x, key);
}
void display()
{
    system("figlet Cipher2");
    cout << "\n\n\033[1;36m 1) ENCRYPT \n\033[1;31m 2) DECRYPT\n\033[1;32m 3) Exit\n\033[1;36m >>>";
    char k;
    cin >> k;
    if (k == '1')
    {
        system("clear");
        system("figlet Cipher2");
        get_Encrypt();
        system("clear");
        display();
    }
    else if (k == '2')
    {
        system("clear");
        system("figlet Cipher2");
        get_Decrypt();
        system("clear");
        display();
    }
    else if (k == '3')
    {
        exit;
    }
    else
    {
        system("clear");
        display();
    }
}
