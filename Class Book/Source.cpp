#include <locale>
#include <fstream>
#include "Book.h"
int COUNT_OBJ = -1;

void selection(Book** _objPtr, char _TypeSelection)
{
    switch (_TypeSelection)
    {

    // ������� �� ������
    case 'a':
    {
        string _Author;
        cout << "\n������� ������: ";
        cin >> _Author;
        for (int i = 0; i < COUNT_OBJ; ++i)
        {
            if (_objPtr[i][0].get_author() == _Author)
                cout << _objPtr[i][0].get_title();
        }
        break;
    }
    // ������� �� ������������ � ���������
    case 'b':
    {
        string _Publisher; int begin_of_range, end_of_range;
        cout << "\n������� ������������, ������ � ����� ��������� �������: ";
        cin >> _Publisher >> begin_of_range >> end_of_range;
        for (int i = 0; i < COUNT_OBJ; ++i)
        {
            if (_objPtr[i][0].get_publisher() == _Publisher && _objPtr[i][0].get_NumPages() >= begin_of_range && _objPtr[i][0].get_NumPages() <= end_of_range)
                _objPtr[i][0].get_title();
        }
        break;
    }
    // ������� �� ���� ��������� � ���� �������
    case 'c':
    {
        string _BindingType;
        int _Year = 0;
        cout << "\n������� ��� ��������� � ��� �������: ";
        cin >> _BindingType, _Year;
        for (int i = 0; i < COUNT_OBJ; ++i)
        {
            if (_objPtr[i][0].get_bindingtype() == _BindingType && _objPtr[i][0].get_year() > _Year)
                cout << _objPtr[i][0].get_title();
        }
        break;
    }
    }
}


// ���������� ����
void print_menu()
{
    cout << "\t\t\t�������� ���� �� �������: " << endl;
    cout << "\t\t\t1. �������� � ����� ������ ����������� �������������." << endl;
    cout << "\t\t\t2. ���������� ������� �������� �������� �������." << endl;
    cout << "\t\t\t3. ���������� ������� �������� ������ ������� �� �����, ���������� �������������." << endl;
    cout << "\t\t\t4. ����� ������� �������� ������ � ����, ��������� �������������." << endl;
    cout << "\t\t\t5. ���������� ������� �������� ������ �������� �������� �������." << endl;
    cout << "\t\t\t6. ����� ������� �������� ������ �� �����." << endl;
    cout << "\t\t\t7. ��������� ������ � ����������." << endl;
    cout << ">";
}

// ������ ������� ������
int get_variant(int count)
{
    int variant;
    string s;
    getline(cin, s);
    if (s == "") getline(cin, s);
    while (sscanf_s(s.c_str(), "%d", &variant) != 1 || variant <1 || variant>count)
    {
        cout << "���� �����������. ���������� �����: ";
        getline(cin, s);
    }
    return variant;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int variant;
    Book** objPtr = NULL;
    do
    {
        print_menu();
        variant = get_variant(7);
        switch (variant)
        {
        case 1:
        {
            cout << "\n�������� � ����� ������ �� ���������: \n";
            Book A; cout << A;
            cout << "\n�������� � ����� ������ � ������� ������������ � �����������: \n";
            string Author, Title, Publisher, BindingType;
            int Year, NumPages;
            cout << "\n������� ���� ����� ����� ������:\n" << "�����, ��������, ������������, ��� ���������, ���, ����� �������  \n";
            cin >> Author >> Title >> Publisher >> BindingType >> Year >> NumPages;
            Book B(Author, Title, Publisher, BindingType, Year, NumPages);
            cout << B;
            cout << "\n�������� � ����� ������ ������������� �����������: \n";
            Book C(B);
            cout << C;
        }
              break;
        case 2:
        {
            char TypeSelection;
            cout << "�������� ��� ������� : \n a)������ ���� ��������� ������\n b)������ ���� ���������� �������� ������������� "
                 << "� ���������� ������� ������� ����� � ��������� ���������\n c)������ ���� � �������� ����� ��������� � ���������� ����� ���������� ����\n";
            cin >> TypeSelection;
            cout << TypeSelection;
            selection(objPtr, TypeSelection);
        }
              break;
        case 3:
        {
            string in_file_name;
            cout << "\n������� �������� ����� ��� ����� (������: F:\\temp\\hello.txt): \n ";
            cin >> in_file_name;
            ifstream F;
            F.open(in_file_name);
            if (F)
            {
                F >> COUNT_OBJ;
                objPtr = new Book * [COUNT_OBJ];
                for (int i = 0; i < COUNT_OBJ; ++i)
                {
                    objPtr[i] = new Book();
                    F >> objPtr[i][0];
                }
                for (int i = 0; i < COUNT_OBJ; ++i) F >> objPtr[i][0];
            }
            else
            {
                cout << "\n���� �� ������, ��������� ���� � ���������� ��� ���\n";
            }
        }
              break;
        case 4:
        {
            string in_file_name;
            cout << "\n������� �������� ����� ��� ������ (������: F:\\temp\\bye.txt): \n ";
            cin >> in_file_name;
            ofstream F;
            F.open(in_file_name);
            for (int i = 0; i < COUNT_OBJ; ++i) F << objPtr[i][0];
        }
              break;
        case 5:
        {
            Book::sort(objPtr, COUNT_OBJ);
        }
              break;
        case 6:
        {
            for (int i = 0; i < COUNT_OBJ; ++i)
            {
                cout << objPtr[i][0];
            }
            break;
        }
        default:
            break;
        }

    } while (variant != 7);

    return 0;
}
