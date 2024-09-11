#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//1 start
class student
{
    string G_birth, P_num, City, password;

public:
    
    
    string FIO , Country, N_school, School_city, School_country, Group_num,pass;

    /*student(string g_birth, string p_num, string city) {
        this->G_birth = g_birth;
        this->P_num = p_num;
        this->City = city;
    }*/

    //аксессоры
    student(string pass) { password = pass; }
    string get_d_birth(string pass) {
        if (pass == password) { return G_birth; }
        else { cout << "У вас нет доступа!\n\n"; }
    }
    string get_p_num(string pass) {
        if (pass == password) { return P_num;}  
        else { cout << "У вас нет доступа!\n\n"; }
    }
    string get_city(string pass) {
        if (pass == password) { return City;  }  
        else { cout << "У вас нет доступа!\n\n"; }
    }

    //ввод
    void enter() {
        cout << "Enter like this: \n\n";
        cout << "date of birth is: "; getline(cin, G_birth);cout<< "\n\n";
        cout << "phone number is: "; getline(cin, P_num); cout << "\n\n";
        cout << "City of birth is: "; getline(cin, City); cout << "\n\n";
        cout << "FIO is: "; getline(cin,FIO); cout << "\n";
        cout << "Country is: "; getline(cin,Country); cout << "\n";
        cout << "School name is: "; getline(cin, N_school); cout << "\n";
        cout << "Schools city is : "; getline(cin,School_city); cout << "\n";
        cout << "Schools country is : "; getline(cin,School_country); cout << "\n";
        cout << "Group number is : "; getline(cin, Group_num); cout << "\n";
        system("cls");
        
    }

    //вывод
    void c_out(student s) {
        cout << "Your data is: \n\n";
        cout << "FIO is: "<<s.FIO << "\n";
        cout << "Country is: "<<s.Country<< "\n";
        cout << "School name is: " << s.N_school<< "\n";
        cout << "Schools city is : " << s.School_city<< "\n";
        cout << "Schools country is : " << s.School_country << "\n";
        cout << "Group number is : " << s.Group_num<< "\n";

        //решил добавить и пароль
        cout << "If you wanna get date of birth, phone number and City of birth enter password: ";
        getline(cin, pass);
        cout << "\n";
        if (pass == password) {
            cout << "date of birth is: " << get_d_birth(pass) << "\n\n";
            cout << "phone number is: " << get_p_num(pass) << "\n\n";
            cout << "City of birth is: " << get_city(pass) << "\n\n";
        }
        else {
            cout << "password is wrong!" << endl;
        }
    }
    
};


//1 end

//2 start

class point 
{
    int x, y, z;
public:
    int get_x() { return x; }
    int get_y() { return y; }
    int get_z() { return z; }

    void enter() {
        cout << "Enter x: "; cin >> x;
        cout << "Enter y: "; cin >> y;
        cout << "Enter z: "; cin >> z;
    }
    void c_out() {
        cout << " x: " << get_x();
        cout << " y: " << get_y();
        cout << " z: " << get_z()<<endl;
    }
    void save_file() 
    {
        string name_f;
        cout << "Enter the name of the file: "; cin >> name_f;
        
        
        name_f +=".txt";
        int s = name_f.size() + 1;
        char* name = new char[s];

        
        for (int i = 0; i < s-1; ++i) {
            name[i] = name_f[i];
        }

        name[s - 1] = '\0';
        FILE* file;
        file = fopen(name, "wb");
        if (file != NULL) {

            string* q = new string[3];
            q[0] = to_string(x);
            q[1] = to_string(y);
            q[2] = to_string(z);

            int l_str1 = q[0].length();
            int l_str2 = q[1].length();
            int l_str3 = q[2].length();

            char* str1 = new char[l_str1 + 1];
            char* str2 = new char[l_str2 + 1];
            char* str3 = new char[l_str3 + 1];

            strcpy(str1, q[0].c_str());
            strcpy(str2, q[1].c_str());
            strcpy(str3, q[2].c_str());
            
            
            fputs(str1, file);
            fputs(" ",  file);
            fputs(str2, file);
            fputs(" ",  file);
            fputs(str3, file);
            fputs(" ",  file);

            fclose(file);
            delete[] str1, str2, str2,name;
        }
        else {
            cout << "ERROR!" << endl;
        }
        
    }
    void get_file() {
        

        string name_f;
        cout << "Enter the name of the file where read: ";cin>>name_f;
        FILE* file;

        name_f += ".txt";
        int s = name_f.size() + 1;
        char* name = new char[s];


        for (int i = 0; i < s - 1; ++i) {
            name[i] = name_f[i];
        }

        name[s - 1] = '\0';
        file = fopen(name, "rb");
        if (file != NULL) {
            int w;
            char p[4];
            fgets(p,3,file);
            w = atoi(p);
            char* str1 = new char[w+2];
            char* str2 = new char[w+2];
            char* str3 = new char[w+2];

            fread(str1, sizeof(char), w + 2, file);
            fread(str2, sizeof(char), w + 2, file);
            fread(str3, sizeof(char), w + 2, file);
            x = atoi(str1);
            y = atoi(str2);
            z = atoi(str3);

            fclose(file);
        }
        else {
            cout << "ERROR!" << endl;
        }
    }
};







//2 end
int main()
{
    setlocale(LC_ALL, "Rus");
    {
        cout << "\tExercise 2\n\n";
        point pixel1;
        pixel1.enter();
        pixel1.c_out();
        pixel1.save_file();
        pixel1.get_file();
        pixel1.c_out();
    }
    system("pause");
    {
        cout << "\tExercise 1\n\n";
        string password;
        cout << "Установите пароль: "; getline(cin, password);
        student u1(password);
        u1.enter();
        u1.c_out(u1);
    }

}
