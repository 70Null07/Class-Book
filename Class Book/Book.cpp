#include "Book.h"

Book::Book()
{
    Author = "Unknown";
    Title = "Unknown";
    Publisher = "Unknown";
    BindingType = "Unknown";
    Year = 0;
    NumPages = 0;
}

Book::Book(string _Author, string _Title, string _Publisher, string _BindingType, int _Year, int _NumPages)
{
    Author = _Author;
    Title = _Title;
    Publisher = _Publisher;
    BindingType = _BindingType;
    Year = _Year;
    NumPages = _NumPages;
}

Book::Book(const Book& b) 
{
    Author = b.Author;
    Title = b.Title;
    Publisher = b.Publisher;
    BindingType = b.BindingType;
    Year = b.Year;
    NumPages = b.NumPages;
}

ostream& Book::print(ostream& stream)  const 
{
    stream << "�����: " << Author << "\n��������: " << Title << "\n������������: "
           << Publisher << "\n��� ���������: " << BindingType << "\n���: "
           << Year << "\n����� �������: " << NumPages << endl;
    return stream;
}

istream& Book::scan(istream& stream)
{
    cout << "������� ���� ����� ����� ������:\n" << "�����, ��������, ������������, ��� ���������, ���, ����� �������  ";
    stream >> Author >> Title >> Publisher >> BindingType >> Year >> NumPages;
    cout << "\n";
    return stream;
};

void Book::sort(Book** _objPtr, int COUNT_OBJ)
{
    bool was_swaped = true;
    while (was_swaped)
    {
        was_swaped = false;
        for (int i = 0; i < COUNT_OBJ - 1; ++i)
        {
            if (_objPtr[i][0] > _objPtr[i + 1][0])
            {
                swap(_objPtr[i][0], _objPtr[i + 1][0]);
                was_swaped = true;
            }
        }
    }
}

bool Book::operator >(const Book& obj) const
{
    return Year > obj.Year;
}

bool Book::operator < (const Book& obj) const
{
    return obj > (*this);
}

ostream& operator << (ostream& stream, const Book& obj)
{
    return obj.print(stream);
}

istream& operator >> (istream& stream, Book& obj)
{
    return obj.scan(stream);
}
