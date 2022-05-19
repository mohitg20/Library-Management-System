#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <string.h>
#include <iomanip>
#include <bits/stdc++.h>

#define LIBRARIAN "a"
#define LIBPASSWORD "a"
#define present_date 70


using namespace std;

class book
{
public:
    int isbn;
    string bookname;
    string bookauth;
    string bookpublication;
    bool bookissued = 0;
    // int issuetime;
    int issue_date = 0;
    string issuedby;
    void display()
    {
        cout << "\n\tBook ISBN No. : " << isbn;
        cout << "\n\tBook Name : " << bookname;
        cout << "\n\tBooks Author : " << bookauth;
        cout << "\n\tBook Publication : " << bookpublication;
        if (bookissued)
        {
            cout << "\n\tBook Availability: No";
            cout << "\n\tBook Issued  by: "
                 << issuedby;
            cout << "\n\tIssue Date: "
                 << issue_date;
        }
        else
            cout << "\n\tBook Availability: Yes";
    }
};

class bookData
{

public:
    vector<book> booklist;
    void add_book()
    {
        system("cls");
        book newbook;
        cout << "\n\tAdd a book to library..." << endl;
        cout << "\n\tEnter Book ISBN No.: ";
        cin >> newbook.isbn;
        cout << "\n\tEnter Book Name: ";
        cin >> newbook.bookname;
        cout << "\n\tEnter Book Author: ";
        cin >> newbook.bookauth;
        cout << "\n\tEnter Book Publication: ";
        cin >> newbook.bookpublication;
        cout << "\n\tThe new book is added successfully to the library...";
        booklist.push_back(newbook);
        getch();
    }
    void remove_book()
    {
        system("cls");
        int isbn;
        cout << "\n\tRemove a Book from Library..." << endl;
        cout << "\n\tEnter Book ISBN No.: ";
        cin >> isbn;

        for (int i = 0; i < booklist.size(); i++)
        {
            if (booklist[i].isbn == isbn)
            {
                if (booklist[i].bookissued)
                {
                    cout << "\n\tBook already issued by someone";
                    break;
                }
                booklist.erase(booklist.begin() + i);
                cout << "\n\tThe book is removed successfully from the library...";
                break;
            }
        }
        getch();
    }
    void search_book()
    {
        system("cls");
        int choice;
        cout << "\n\tSearch a book from Library..." << endl;
        cout << "\n\t1. Search by Book ISBN No.\n\n\t2. Search by Book Name.\n\n\tEnter Your Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            system("cls");
            int isbn;
            cout << "\n\tEnter Book ISBN No.: ";
            cin >> isbn;
            int i = 0;
            for (i = 0; i < booklist.size(); i++)
            {
                if (booklist[i].isbn == isbn)
                {
                    system("cls");
                    booklist[i].display();
                    getch();
                    break;
                }
            }
            if (i == booklist.size())
            {
                cout << "\n\tThis book is not in the library ! ";
                getch();
            }
        }
        else if (choice == 2)
        {
            system("cls");
            string bookname;
            cout << "\n\tEnter Book Name.: ";
            cin >> bookname;
            int i = 0;
            for (i = 0; i < booklist.size(); i++)
            {
                if (booklist[i].bookname == bookname)
                {
                    system("cls");
                    booklist[i].display();
                    getch();
                    break;
                }
            }
            if (i == booklist.size())
            {
                cout << "\n\tThis book is not in the library ! ";
                getch();
            }
        }
        else
        {
            cout << "\n\tPlease enter valid choice...";
            getch();
            search_book();
        }
    }
    void show_book()
    {
        system("cls");
        cout << "\n\tHere is list of all the books...";
        for (int i = 0; i < booklist.size(); i++)
        {
            cout << "\n\t-----------------------------------";
            booklist[i].display();
        }
        cout << "\n\t-----------------------------------\n\t";
        getch();
    }
    void update_book(){
        system("cls");
        int choice;
        cout << "\n\tSearch a book from Library..." << endl;
        cout << "\n\t1. Search by Book ISBN No.\n\n\t2. Search by Book Name.\n\n\tEnter Your Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            system("cls");
            int isbn;
            cout << "\n\tEnter Book ISBN No.: ";
            cin >> isbn;
            int i = 0;
            for (i = 0; i < booklist.size(); i++)
            {
                if (booklist[i].isbn == isbn)
                {
                    system("cls");
                    booklist[i].display();
                    
                    if(booklist[i].bookissued){
                        cout<<"\n\tBook is already issued by someone...";
                    }
                    else{
                        cout<<"\n\n\tUpdate this book...\n";
                        booklist.erase(booklist.begin() + i);
                        book newbook;
                        newbook.isbn=isbn;
                        cout << "\n\tEnter New Name: ";
                        cin >> newbook.bookname;
                        cout << "\n\tEnter New Author: ";
                        cin >> newbook.bookauth;
                        cout << "\n\tEnter New Publication: ";
                        cin >> newbook.bookpublication;
                        cout << "\n\tThe book is updated successfully to the library...";
                        booklist.push_back(newbook);
                    }
                    getch();
                    break;
                }
            }
            if (i == booklist.size())
            {
                cout << "\n\tThis book is not in the library ! ";
                getch();
            }
        }
        else if (choice == 2)
        {
            system("cls");
            string bookname;
            cout << "\n\tEnter Book Name.: ";
            cin >> bookname;
            int i = 0;
            for (i = 0; i < booklist.size(); i++)
            {
                if (booklist[i].bookname == bookname)
                {
                    system("cls");
                    booklist[i].display();

                    if(booklist[i].bookissued){
                        cout<<"\n\tBook is already issued by someone...";
                    }
                    else{
                        cout<<"\n\n\tUpdate this book...\n";
                        booklist.erase(booklist.begin() + i);
                        book newbook;
                        newbook.bookname=bookname;
                        cout << "\n\tEnter New isbn: ";
                        cin >> newbook.isbn;
                        cout << "\n\tEnter New Author: ";
                        cin >> newbook.bookauth;
                        cout << "\n\tEnter New Publication: ";
                        cin >> newbook.bookpublication;
                        cout << "\n\tThe book is updated successfully to the library...";
                        booklist.push_back(newbook);
                    }
                    getch();
                    break;
                }
            }
            if (i == booklist.size())
            {
                cout << "\n\tThis book is not in the library ! ";
                getch();
            }
        }
        else
        {
            cout << "\n\tPlease enter valid choice...";
            getch();
            search_book();
        }
    }
};

class user
{
public:
    int id;
    string username;
    string password;
    vector<book> issued;
    int fine = 0;
    void issued_books(){
        cout << "\n\tBooks Issued : ";
        if (issued.size())
        {
            cout << "\n\t..................................";
            for (int i = 0; i < issued.size(); i++)
            {
                issued[i].display();
                cout << "\n\t..................................";
            }
        }
        else
            cout << "No book issued yet.";
    }
    void display()
    {
        cout << "\n\tId : " << id;
        cout << "\n\tUsername : " << username;
        issued_books();
        cout << "\n\tFine : " << fine<<"\n\t";
        ;
    }
};

class student : public user
{
public:
    void calculate_fine()
    {
        fine = 0;
        for (int i = 0; i < issued.size(); i++)
        {
            if (present_date - issued[i].issue_date > 30)
            {
                fine += (present_date - issued[i].issue_date - 30) * 2;
            }
        }
    }
    void clear_fine_amount(bookData*b){
        system("cls");
        cout<<"\n\tFine Clearance Portal...\n";
        calculate_fine();
        string isdone;
        cout << "\n\tPay Rs. "<< fine;
        cout << "\n\n\tType paid when done : ";
        cin>> isdone;
        if(isdone=="paid"){
            for (int j = 0; j < issued.size(); j++){
                if (present_date - issued[j].issue_date > 30){
                    int isbn=issued[j].isbn;
                    for (int i = 0; i < (*b).booklist.size(); i++)
                    {
                        if ((*b).booklist[i].isbn == isbn)
                        {
                                (*b).booklist[i].issue_date = 0;
                                (*b).booklist[i].bookissued = 0;
                                (*b).booklist[i].issuedby = "none";
                                for (int j = 0; j < issued.size(); j++)
                                {
                                    if (issued[j].isbn == isbn)
                                    {
                                        cout << "\n\tThe book is returned to the library..." << endl;
                                        issued.erase(issued.begin() + j);
                                        break;
                                    }
                                }
                                break;
                        }
                    }
                }
            }
        }
        // for (int i = 0; i < (*b).booklist.size(); i++)
        // {
        //         if ((*b).booklist[i].bookissued && (*b).booklist[i].issuedby == username)
        //         {
        //             if (present_date - (*b).booklist[i].issue_date > 30)
        //             {
        //                 calculate_fine();
        //                 string isdone;
        //                 cout << "\n\tPay Rs. "<< fine;
        //                 cout << "\n\n\tType paid when done : ";
        //                 cin>> isdone;
        //                 if(isdone=="paid"){
        //                     int isbn=(*b).booklist[i].isbn;
        //                     (*b).booklist[i].issue_date = 0;
        //                     (*b).booklist[i].bookissued = 0;
        //                     (*b).booklist[i].issuedby = "none";
        //                     for (int j = 0; j < issued.size(); j++)
        //                     {
        //                         if (issued[j].isbn == isbn)
        //                         {
        //                             issued.erase(issued.begin() + j);
        //                             break;
        //                         }
        //                     }
        //                 }else{
        //                     cout<<"\n\n\tFine Clearance failed...";
        //                     break;
        //                 }
        //             }
        //         }
        //         cout << "\n\tYou haven't issued this book." << endl;
        //         break;
        // }
        getch();
    }
    void issue_book(bookData *b)
    {
        if (issued.size() == 5)
        {
            cout << "\n\tYou have reached the maximum book issue limit...";
            getch();
            return;
        }
        system("cls");
        int isbn,i=0;
        cout << "\n\tIssue Book from Library...\n\n\tEnter book's isbn : ";
        cin >> isbn;
        for (i = 0; i < (*b).booklist.size(); i++)
        {
            if ((*b).booklist[i].isbn == isbn)
            {
                if ((*b).booklist[i].bookissued)
                {
                    cout << "\n\tBook already issued by someone...";
                    break;
                }
                (*b).booklist[i].bookissued = 1;
                cout << "\n\tEnter todays date: ";
                cin >> (*b).booklist[i].issue_date;
                (*b).booklist[i].issuedby = username;
                issued.push_back((*b).booklist[i]);
                cout << "\n\tBook is successfully issued to you...";
                break;
            }
        }
        if(i==(*b).booklist.size()){
            return;
        }
        getch();
    }
    void return_book(bookData *b)
    {
        system("cls");
        int isbn;
        cout << "\n\tReturn Book to the Library...\n\n\tEnter book's isbn : ";
        cin >> isbn;
        for (int i = 0; i < (*b).booklist.size(); i++)
        {
            if ((*b).booklist[i].isbn == isbn)
            {
                if ((*b).booklist[i].bookissued && (*b).booklist[i].issuedby == username)
                {
                    if (present_date - (*b).booklist[i].issue_date > 30)
                    {
                        cout << "\n\tFirst pay the fine..." << endl;
                        break;
                    }
                    (*b).booklist[i].issue_date = 0;
                    (*b).booklist[i].bookissued = 0;
                    (*b).booklist[i].issuedby = "none";
                    for (int j = 0; j < issued.size(); j++)
                    {
                        if (issued[j].isbn == isbn)
                        {
                            cout << "\n\tThe book is returned to the library..." << endl;
                            issued.erase(issued.begin() + j);
                            break;
                        }
                    }
                    break;
                }
                cout << "\n\tYou haven't issued this book." << endl;
                break;
            }
        }
        getch();
    }
};

class teacher : public user
{
public:
    void calculate_fine()
    {
        fine = 0;
        for (int i = 0; i < issued.size(); i++)
        {
            if (present_date - issued[i].issue_date > 60)
            {
                fine += (present_date - issued[i].issue_date - 30) * 5;
            }
        }
    }
    void clear_fine_amount(bookData*b){
        system("cls");
        cout<<"\n\tFine Clearance Portal...\n";
        calculate_fine();
        string isdone;
        cout << "\n\tPay Rs. "<< fine;
        cout << "\n\n\tType paid when done : ";
        cin>> isdone;
        if(isdone=="paid"){
            for (int j = 0; j < issued.size(); j++){
                if (present_date - issued[j].issue_date > 60){
                    int isbn=issued[j].isbn;
                    for (int i = 0; i < (*b).booklist.size(); i++)
                    {
                        if ((*b).booklist[i].isbn == isbn)
                        {
                                (*b).booklist[i].issue_date = 0;
                                (*b).booklist[i].bookissued = 0;
                                (*b).booklist[i].issuedby = "none";
                                for (int j = 0; j < issued.size(); j++)
                                {
                                    if (issued[j].isbn == isbn)
                                    {
                                        cout << "\n\tThe book is returned to the library..." << endl;
                                        issued.erase(issued.begin() + j);
                                        break;
                                    }
                                }
                                break;
                        }
                    }
                }
            }
        }
        // for (int i = 0; i < (*b).booklist.size(); i++)
        // {
        //         if ((*b).booklist[i].bookissued && (*b).booklist[i].issuedby == username)
        //         {
        //             if (present_date - (*b).booklist[i].issue_date > 30)
        //             {
        //                 calculate_fine();
        //                 string isdone;
        //                 cout << "\n\tPay Rs. "<< fine;
        //                 cout << "\n\n\tType paid when done : ";
        //                 cin>> isdone;
        //                 if(isdone=="paid"){
        //                     int isbn=(*b).booklist[i].isbn;
        //                     (*b).booklist[i].issue_date = 0;
        //                     (*b).booklist[i].bookissued = 0;
        //                     (*b).booklist[i].issuedby = "none";
        //                     for (int j = 0; j < issued.size(); j++)
        //                     {
        //                         if (issued[j].isbn == isbn)
        //                         {
        //                             issued.erase(issued.begin() + j);
        //                             break;
        //                         }
        //                     }
        //                 }else{
        //                     cout<<"\n\n\tFine Clearance failed...";
        //                     break;
        //                 }
        //             }
        //         }
        //         cout << "\n\tYou haven't issued this book." << endl;
        //         break;
        // }
        getch();
    }
    void issue_book(bookData *b)
    {
        system("cls");
        int isbn;
        cout << "\n\tIssue Book from Library...\n\n\tEnter book's isbn : ";
        cin >> isbn;
        int i=0;
        for ( i = 0; i < (*b).booklist.size(); i++)
        {
            if ((*b).booklist[i].isbn == isbn)
            {
                if ((*b).booklist[i].bookissued)
                {
                    cout << "\n\tBook already issued by someone...";
                    break;
                }
                (*b).booklist[i].bookissued = 1;
                cout << "\n\tEnter todays date: ";
                cin >> (*b).booklist[i].issue_date;
                (*b).booklist[i].issuedby = username;
                issued.push_back((*b).booklist[i]);
                cout << "\n\tBook is successfully issued to you...";
                break;
            }
        }
        if(i==(*b).booklist.size()){
            return;
        }
        getch();
    }
    void return_book(bookData *b)
    {
        system("cls");
        int isbn;
        cout << "\n\tReturn Book to the Library...\n\n\tEnter book's isbn : ";
        cin >> isbn;
        for (int i = 0; i < (*b).booklist.size(); i++)
        {
            if ((*b).booklist[i].isbn == isbn)
            {
                if ((*b).booklist[i].bookissued && (*b).booklist[i].issuedby == username)
                {
                    if (present_date - (*b).booklist[i].issue_date > 60)
                    {
                        cout << "First pay the fine" << endl;
                        break;
                    }
                    (*b).booklist[i].issue_date = 0;
                    (*b).booklist[i].bookissued = 0;
                    (*b).booklist[i].issuedby = "none";
                    for (int j = 0; j < issued.size(); j++)
                    {
                        if (issued[j].isbn == isbn)
                        {
                            cout << "The book is returned to the library..." << endl;
                            issued.erase(issued.begin() + j);
                            break;
                        }
                    }
                    break;
                }
                cout << "\n\tYou haven't issued this book." << endl;
                break;
            }
        }
        getch();
    }
};

class studentData
{
public:
    vector<student> stud;
    void add_stud()
    {
        system("cls");
        student student;
        cout << "\n\tRegister a Student to Library..." << endl;
        cout << "\n\tEnter Admission No.: ";
        cin >> student.id;
        cout << "\tEnter username: ";
        cin >> student.username;
        cout << "\tEnter password ";
        cin >> student.password;
        cout << "\n\tThe student is registered successfully...";
        stud.push_back(student);
        getch();
    }
    void remove_stud()
    {
        system("cls");
        int id;
        cout << "\n\tRemove a Student from Library..." << endl;
        cout << "\n\tEnter Admission No.: ";
        cin >> id;

        for (int i = 0; i < stud.size(); i++)
        {
            if (stud[i].id == id)
            {
                if (stud[i].issued.size() != 0 || stud[i].fine != 0)
                {
                    cout << "\n\n\tFirst return all books and pay fine !" << endl;
                    break;
                }
                cout << "\n\n\tThe student is successfully removed from the library..." << endl;
                stud.erase(stud.begin() + i);
                break;
            }
        }
        getch();
    }
    void search_stud()
    {
        system("cls");
        int id;
        cout << "\n\tSearch a Student from Library..." << endl;
        cout << "\n\tEnter Admission No.: ";
        cin >> id;
        for (int i = 0; i < stud.size(); i++)
        {
            if (stud[i].id == id)
            {
                system("cls");
                stud[i].calculate_fine();
                stud[i].display();
                break;
            }
        }
        getch();
    }
    void show_stud()
    {
        system("cls");
        cout << "\n\tHere is list of all students";
        for (int i = 0; i < stud.size(); i++)
        {
            cout << "\n\t-----------------------------------";
            stud[i].calculate_fine();
            stud[i].display();
        }
        cout << "-----------------------------------\n\t";
        getch();
    }
    void update_stud(){
        system("cls");
        string username;
        cout << "\n\tSearch a Student from Library..." << endl;
        cout << "\n\tEnter username : ";
        cin >> username;
        for (int i = 0; i < stud.size(); i++)
        {
            if (stud[i].username==username)
            {
                system("cls");
                stud[i].calculate_fine();
                stud[i].display();
                        cout<<"\n\n\tUpdate this user...\n";
                        string password=stud[i].password;
                        stud.erase(stud.begin() + i);
                        student newstud;
                        newstud.username=username;
                        newstud.password=password;
                        cout << "\n\tEnter New id: ";
                        cin >> newstud.id;
                        cout << "\n\tThe user is updated successfully to the library...";
                        stud.push_back(newstud);
                break;
            }
        }
        getch();
    }
};

class teacherData
{
public:
    vector<teacher> teach;
    void add_teach()
    {
        system("cls");
        teacher teacher;
        int adno;
        string teachname;
        cout << "\n\tRegister a teacher " << endl;
        cout << "\n\tEnter Admission No.: ";
        cin >> teacher.id;
        cout << "\tEnter username: ";
        cin >> teacher.username;
        cout << "\tEnter password ";
        cin >> teacher.password;
        teach.push_back(teacher);
        cout << "\n\tThe teacher is registered successfully...";
        getch();
    }
    void remove_teach()
    {
        system("cls");
        int id;
        cout << "\n\tRemove a teacher from Library" << endl;
        cout << "\n\tEnter Admission No.: ";
        cin >> id;

        for (int i = 0; i < teach.size(); i++)
        {
            if (teach[i].id == id)
            {
                if (teach[i].issued.size() != 0 || teach[i].fine != 0)
                {
                    cout << "\n\tFirst return all books and pay fine..." << endl;
                    break;
                }
                cout << "\n\tThe teacher is removed from the library..." << endl;
                teach.erase(teach.begin() + i);
                break;
            }
        }
        getch();
    }
    void search_teach()
    {
        system("cls");
        int id;
        cout << "\n\tSearch a teacher from Library" << endl;
        cout << "\n\tEnter Admission No.: ";
        cin >> id;
        for (int i = 0; i < teach.size(); i++)
        {
            if (teach[i].id == id)
            {
                system("cls");
                teach[i].calculate_fine();
                teach[i].display();
                break;
            }
        }
        getch();
    }
    void show_teach()
    {
        system("cls");
        cout << "\n\tHere is list of all teachers";
        for (int i = 0; i < teach.size(); i++)
        {
            cout << "\n\t-----------------------------------";
            teach[i].calculate_fine();
            teach[i].display();
        }
        cout << "-----------------------------------\n\t";
        getch();
    }
    void update_teach(){
        system("cls");
        string username;
        cout << "\n\tSearch a Student from Library..." << endl;
        cout << "\n\tEnter username : ";
        cin >> username;
        for (int i = 0; i < teach.size(); i++)
        {
            if (teach[i].username==username)
            {
                system("cls");
                teach[i].calculate_fine();
                teach[i].display();
                        cout<<"\n\n\tUpdate this user...\n";
                        string password=teach[i].password;
                        teach.erase(teach.begin() + i);
                        teacher newteach;
                        newteach.username=username;
                        newteach.password=password;
                        cout << "\n\tEnter New id: ";
                        cin >> newteach.id;\
                        cout << "\n\tThe user is updated successfully to the library...";
                        teach.push_back(newteach);
                break;
            }
        }
        getch();
    }
};

class Library
{
public:
    teacherData t;
    studentData s;
    bookData b;

    void librarian()
    {
        int Choice = 0;
        while (Choice != 16)
        {
            system("cls");
            cout << "\n\t You are logged in as a librarian...";
            cout << "\n\t\n\t";
            cout << "\n\t1. Add new book";
            cout << "\n\t2. Search a Book's Details";
            cout << "\n\t3. Modify existing Book";
            cout << "\n\t4. Delete Book";
            cout << "\n\t5. List of all Books";
            cout << "\n\t6. Add new Student";
            cout << "\n\t7. Search a Student's Details";
            cout << "\n\t8. Modify existing Student";
            cout << "\n\t9. Delete Existing Student";
            cout << "\n\t10. List of all Students";
            cout << "\n\t11. Add new Teacher";
            cout << "\n\t12. Search a Teacher's Details";
            cout << "\n\t13. Modify existing User";
            cout << "\n\t14. Delete Existing Teacher";
            cout << "\n\t15. List of all Teachers";
            cout << "\n\t16. Exit";
            cout << "\n\t\n\t Please enter your choice : ";
            cin >> Choice;
            switch (Choice)
            {
            case 1:
                b.add_book();
                break;
            case 2:
                // b.update_book();
                b.search_book();
                break;
            case 3:
                b.update_book();
                break;
            case 4:
                b.remove_book();
                break;
            case 5:
                b.show_book();
                break;
            case 6:
                s.add_stud();
                break;
            case 7:
                // s.update_stud();
                s.search_stud();
                break;
            case 8:
                s.update_stud();
                break;
            case 9:
                s.remove_stud();
                break;
            case 10:
                s.show_stud();
                break;
            case 11:
                t.add_teach();
                break;
            case 12:
                // t.update_teach();
                t.search_teach();
                break;
            case 13:
                t.update_teach();
                break;
            case 14:
                t.remove_teach();
                break;
            case 15:
                t.show_teach();
                break;
            case 16:
                break;
            default:
                cout << "\n\n Invalid Choice. Please enter the valid one";
                getch();
            }
            system("cls");
        }
    };

    void student(string username, string password)
    {
        int i = 0;
        for (i = 0; i < s.stud.size(); i++)
        {
            if (s.stud[i].username == username)
            {
                system("cls");
                cout << "\n\tWelcome " << username << " !\n\n\tFollowing are your details:\n";
                s.stud[i].calculate_fine();
                s.stud[i].display();
                getch();
                break;
            }
        }
        if (i == s.stud.size())
        {
            cout << "\n\tIncorrect Login Details !" << endl;
            getch();
            return;
        }
        int choice = 0;
        while (choice != 8)
        {
            system("cls");
            cout << "\n\t You are logged in as a student...";
            cout << "\n\t\n\t";
            cout << "\n\t1. View All Books";
            cout << "\n\t2. Search a Book's Details";
            cout << "\n\t3. Issue Book";
            cout << "\n\t4. Return Your Issued Book";
            cout << "\n\t5. View Your Fine";
            cout << "\n\t6. View Issued Books";
            cout << "\n\t7. Clear Your Fines";
            cout << "\n\t8. Exit";
            cout << "\n\n\tEnter your choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                b.show_book();
                break;
            case 2:
                b.search_book();
                break;
            case 3:
                s.stud[i].issue_book(&b);
                break;
            case 4:
                s.stud[i].return_book(&b);
                break;
            case 5:
                s.stud[i].calculate_fine();
                cout << "\n\tYour total fine amount = " << s.stud[i].fine << endl;
                getch();
                break;
            case 6:
                s.stud[i].issued_books();
                getch();
                break;
            case 7:
                s.stud[i].clear_fine_amount(&b);
                getch();
                break;
            case 8:
                break;
            default:
                cout << "\n\n Invalid Choice. Please enter the valid one";
                getch();
            }
            system("cls");
        }
    }

    void teacher(string username, string password)
    {
        int i = 0;
        for (i = 0; i < t.teach.size(); i++)
        {
            if (t.teach[i].username == username)
            {
                system("cls");
                cout << "\n\tWelcome " << username << " !\n\n\tFollowing are your details:\n";
                t.teach[i].calculate_fine();
                t.teach[i].display();
                getch();
                break;
            }
        }
        if (i == t.teach.size())
        {
            cout << "\n\tIncorrect Login Details !" << endl;
            getch();
            return;
        }
        int choice = 0;
        while (choice != 8)
        {
            system("cls");
            cout << "\n\t You are logged in as a teacher...";
            cout << "\n\t\n\t";
            cout << "\n\t1. View All Books";
            cout << "\n\t2. Search a Book's Details";
            cout << "\n\t3. Issue Book";
            cout << "\n\t4. Return Your Issued Book";
            cout << "\n\t5. View Your Fine";
            cout << "\n\t6. View Issued Books";
            cout << "\n\t7. Clear Your Fines";
            cout << "\n\t8. Exit";
            cout << "\n\n\tEnter your choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                b.show_book();
                break;
            case 2:
                b.search_book();
                break;
            case 3:
                t.teach[i].issue_book(&b);
                break;
            case 4:
                t.teach[i].return_book(&b);
                break;
            case 5:
                t.teach[i].calculate_fine();
                cout << "\n\tYour total fine amount = " << t.teach[i].fine << endl;
                getch();
                break;
            case 6:
                t.teach[i].issued_books();
                getch();
                break;
            case 7:
                t.teach[i].clear_fine_amount(&b);
                getch();
                break;
            case 8:
                break;
            default:
                cout << "\n\n Invalid Choice. Please enter the valid one";
                getch();
            }
            system("cls");
        }
    }
};

int main()
{
    Library lib;
    int choice = 0;
    while (1)
    {
        system("cls");
        cout << "\n\tLibrary Management System\n\t-------------------------\n\n";
        cout << "\tChoose your role\n\t1) Librarian\n\t2) Student\n\t3) Teacher\n\t4) Exit\n";
        cout << "\n\tEnter your choice: ";
        choice = 0;
        cin >> choice;
        string username;
        string password;
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "\n\tLibrarian Login...\n\n\tEnter Username :";
            cin >> username;
            cout << "\tPassword :";
            cin >> password;
            if (username == LIBRARIAN && password == LIBPASSWORD)
            {
                cout << "\n\tLibrarian Login Successful...";
                getch();
                system("cls");
                lib.librarian();
            }
            else
            {
                cout << "\n\tIncorrect Login Details !" << endl;
                getch();
            }
            break;

        case 2:
            system("cls");
            cout << "\n\tStudent Login...\n\n\tEnter Username :";
            cin >> username;
            cout << "\tPassword :";
            cin >> password;
            lib.student(username, password);
            break;

        case 3:
            system("cls");
            cout << "\n\tTeacher Login...\n\n\tEnter Username :";
            cin >> username;
            cout << "\tPassword :";
            cin >> password;
            lib.teacher(username, password);
            break;

        case 4:
            return 0;

        default:
            cout << "\tEnter a valid choice...";
            getch();
            break;
        }
    }
    return 0;
}