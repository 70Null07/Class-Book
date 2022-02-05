#include <locale>
#include <fstream>
#include "Book.h"
int COUNT_OBJ = -1;

void selection(Book** _objPtr, char _TypeSelection)
{
    switch (_TypeSelection)
    {
    // Выборка по автору
    case 'a':
    {
        string _Author;
        cout << "\nВведите автора: ";
        cin >> _Author;
        for (int i = 0; i < COUNT_OBJ; ++i)
        {
            if (_objPtr[i][0].get_author() == _Author)
                cout << _objPtr[i][0].get_title();
        }
        break;
    }

    // Выборка по издательству и диапазону
    case 'b':
    {
        string _Publisher; int begin_of_range, end_of_range;
        cout << "\nВведите издательство, начало и конец диапазона страниц: ";
        cin >> _Publisher >> begin_of_range >> end_of_range;
        for (int i = 0; i < COUNT_OBJ; ++i)
        {
            if (_objPtr[i][0].get_publisher() == _Publisher && _objPtr[i][0].get_NumPages() >= begin_of_range && _objPtr[i][0].get_NumPages() <= end_of_range)
                _objPtr[i][0].get_title();
        }
        break;
    }

    // Выборка по типу переплета и году выпуска
    case 'c':
    {
        string _BindingType;
        int _Year = 0;
        cout << "\nВведите тип переплета и год выпуска: ";
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


// Содержание меню
void print_menu()
{
    cout << "\t\t\tВыберите один из пунктов: " << endl;
    cout << "\t\t\t1. Создание и вывод класса посредством конструкторов." << endl;
    cout << "\t\t\t2. Реализация выборки согласно варианту задания." << endl;
    cout << "\t\t\t3. Заполнение массива объектов класса данными из файла, указанного пользователем." << endl;
    cout << "\t\t\t4. Вывод массива объектов класса в файл, указанный пользователем." << endl;
    cout << "\t\t\t5. Сортировка массива объектов класса согласно варианту задания." << endl;
    cout << "\t\t\t6. Вывод массива объектов класса на экран." << endl;
    cout << "\t\t\t7. Закончить работу с программой." << endl;
    cout << ">";
}

// Анализ ваианта выбора
int get_variant(int count)
{
    int variant;
    string s;
    getline(cin, s);
    if (s == "") getline(cin, s);
    while (sscanf_s(s.c_str(), "%d", &variant) != 1 || variant <1 || variant>count)
    {
        cout << "Ввод некорректен. Попробуйте снова: ";
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
            cout << "\nСоздание и вывод класса по умолчанию: \n";
            Book A; cout << A;
            cout << "\nСоздание и вывод класса с помощью конструктора с параметрами: \n";
            string Author, Title, Publisher, BindingType;
            int Year, NumPages;
            cout << "\nВведите поля книги через пробел:\n" << "Автор, Название, Издательство, Тип переплета, Год, Число страниц  \n";
            cin >> Author >> Title >> Publisher >> BindingType >> Year >> NumPages;
            Book B(Author, Title, Publisher, BindingType, Year, NumPages);
            cout << B;
            cout << "\nСоздание и вывод класса конструктором копирования: \n";
            Book C(B);
            cout << C;
        }
              break;
        case 2:
        {
            char TypeSelection;
            cout << "Выберите тип выборки : \n a)список книг заданного автора\n b)список книг выпущенных заданным издательством "
                 << "и количество страниц которых лежит в указанном диапазоне\n c)список книг с заданным типом переплета и выпущенных после указанного года\n";
            cin >> TypeSelection;
            cout << TypeSelection;
            selection(objPtr, TypeSelection);
        }
              break;
        case 3:
        {
            string in_file_name;
            cout << "\nВведите название файла для ввода (Пример: F:\\temp\\hello.txt): \n ";
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
                cout << "\nФайл не найден, проверьте ввод и попробуйте еще раз\n";
            }
        }
              break;
        case 4:
        {
            string in_file_name;
            cout << "\nВведите название файла для вывода (Пример: F:\\temp\\bye.txt): \n ";
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
