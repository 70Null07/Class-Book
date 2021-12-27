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
        cout << "\nÂâåäèòå àâòîðà: ";
        cin >> _Author;
        for (int i = 0; i < COUNT_OBJ; ++i)
        {
            if (_objPtr[i][0].get_author() == _Author)
                cout << _objPtr[i][0].get_title();
        }
        break;
    }
    // Âûáîðêà ïî èçäàòåëüñòâó è äèàïàçîíó
    case 'b':
    {
        string _Publisher; int begin_of_range, end_of_range;
        cout << "\nÂâåäèòå èçäàòåëüñòâî, íà÷àëî è êîíåö äèàïàçîíà ñòðàíèö: ";
        cin >> _Publisher >> begin_of_range >> end_of_range;
        for (int i = 0; i < COUNT_OBJ; ++i)
        {
            if (_objPtr[i][0].get_publisher() == _Publisher && _objPtr[i][0].get_NumPages() >= begin_of_range && _objPtr[i][0].get_NumPages() <= end_of_range)
                _objPtr[i][0].get_title();
        }
        break;
    }
    // Âûáîðêà ïî òèïó ïåðåïëåòà è ãîäó âûïóñêà
    case 'c':
    {
        string _BindingType;
        int _Year = 0;
        cout << "\nÂâåäèòå òèï ïåðåïëåòà è ãîä âûïóñêà: ";
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


// Ñîäåðæàíèå ìåíþ
void print_menu()
{
    cout << "\t\t\tÂûáåðèòå îäèí èç ïóíêòîâ: " << endl;
    cout << "\t\t\t1. Ñîçäàíèå è âûâîä êëàññà ïîñðåäñòâîì êîíñòðóêòîðîâ." << endl;
    cout << "\t\t\t2. Ðåàëèçàöèÿ âûáîðêè ñîãëàñíî âàðèàíòó çàäàíèÿ." << endl;
    cout << "\t\t\t3. Çàïîëíåíèå ìàññèâà îáúåêòîâ êëàññà äàííûìè èç ôàéëà, óêàçàííîãî ïîëüçîâàòåëåì." << endl;
    cout << "\t\t\t4. Âûâîä ìàññèâà îáúåêòîâ êëàññà â ôàéë, óêàçàííûé ïîëüçîâàòåëåì." << endl;
    cout << "\t\t\t5. Ñîðòèðîâêà ìàññèâà îáúåêòîâ êëàññà ñîãëàñíî âàðèàíòó çàäàíèÿ." << endl;
    cout << "\t\t\t6. Âûâîä ìàññèâà îáúåêòîâ êëàññà íà ýêðàí." << endl;
    cout << "\t\t\t7. Çàêîí÷èòü ðàáîòó ñ ïðîãðàììîé." << endl;
    cout << ">";
}

// Àíàëèç âàèàíòà âûáîðà
int get_variant(int count)
{
    int variant;
    string s;
    getline(cin, s);
    if (s == "") getline(cin, s);
    while (sscanf_s(s.c_str(), "%d", &variant) != 1 || variant <1 || variant>count)
    {
        cout << "Ââîä íåêîððåêòåí. Ïîïðîáóéòå ñíîâà: ";
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
            cout << "\nÑîçäàíèå è âûâîä êëàññà ïî óìîë÷àíèþ: \n";
            Book A; cout << A;
            cout << "\nÑîçäàíèå è âûâîä êëàññà ñ ïîìîùüþ êîíñòðóêòîðà ñ ïàðàìåòðàìè: \n";
            string Author, Title, Publisher, BindingType;
            int Year, NumPages;
            cout << "\nÂâåäèòå ïîëÿ êíèãè ÷åðåç ïðîáåë:\n" << "Àâòîð, Íàçâàíèå, Èçäàòåëüñòâî, Òèï ïåðåïëåòà, Ãîä, ×èñëî ñòðàíèö  \n";
            cin >> Author >> Title >> Publisher >> BindingType >> Year >> NumPages;
            Book B(Author, Title, Publisher, BindingType, Year, NumPages);
            cout << B;
            cout << "\nÑîçäàíèå è âûâîä êëàññà êîíñòðóêòîðîì êîïèðîâàíèÿ: \n";
            Book C(B);
            cout << C;
        }
              break;
        case 2:
        {
            char TypeSelection;
            cout << "Âûáåðèòå òèï âûáîðêè : \n a)ñïèñîê êíèã çàäàííîãî àâòîðà\n b)ñïèñîê êíèã âûïóùåííûõ çàäàííûì èçäàòåëüñòâîì "
                 << "è êîëè÷åñòâî ñòðàíèö êîòîðûõ ëåæèò â óêàçàííîì äèàïàçîíå\n c)ñïèñîê êíèã ñ çàäàííûì òèïîì ïåðåïëåòà è âûïóùåííûõ ïîñëå óêàçàííîãî ãîäà\n";
            cin >> TypeSelection;
            cout << TypeSelection;
            selection(objPtr, TypeSelection);
        }
              break;
        case 3:
        {
            string in_file_name;
            cout << "\nÂâåäèòå íàçâàíèå ôàéëà äëÿ ââîäà (Ïðèìåð: F:\\temp\\hello.txt): \n ";
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
                cout << "\nÔàéë íå íàéäåí, ïðîâåðüòå ââîä è ïîïðîáóéòå åùå ðàç\n";
            }
        }
              break;
        case 4:
        {
            string in_file_name;
            cout << "\nÂâåäèòå íàçâàíèå ôàéëà äëÿ âûâîäà (Ïðèìåð: F:\\temp\\bye.txt): \n ";
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
