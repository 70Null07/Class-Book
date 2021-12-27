#pragma once

#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    string Author, Title, Publisher, BindingType;
    int Year, NumPages;
public:

    // ������������
    // ����������� �� ���������
    Book();

    // ����������� � �����������
    Book(string _Author, string _Title, string _Publisher, string _BindingType, int _Year, int _NumPages);

    // ����������� �����������
    Book(const Book& b);

    // ������ ����� � ������ ����� ������
    ostream& print(ostream& stream) const;
    istream& scan(istream& stream);

    string get_author() const { return Author; }
    string get_title() const { return Title; }
    string get_publisher() const { return Publisher; }
    string get_bindingtype() const { return BindingType; }
    int get_year() const { return Year; }
    int get_NumPages() const { return NumPages; }

    void set_author(string _Author) { Author = _Author; }
    void set_title(string _Title) { Title = _Title; }
    void set_publisher(string _Publisher) { Publisher = _Publisher; }
    void set_bindingtype(string _BindingType) { BindingType = _BindingType; }
    void set_year(int _Year) { Year = _Year < 0 ? 0 : _Year; }
    void set_NumPages(int _NumPages) { NumPages = _NumPages < 0 ? 0 : _NumPages; }

    // ���������� �������� ���� �����
    static void sort(Book** obj, int COUNT_OBJ);

    // ���������� �������� ���������
    bool operator >(const Book& obj) const;
    bool operator <(const Book& obj) const;

    // ���������� �������� �����/������
    friend ostream& operator << (ostream& stream, const Book& obj);
    friend istream& operator >> (istream& stream, Book& obj);
};
