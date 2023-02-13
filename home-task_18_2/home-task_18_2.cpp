#include <iostream>
using namespace std;

//Реализовать структуру «Автомобиль»(длина,
//клиренс(высота посадки), объем двигателя, мощность
//двигателя, диаметр колес, цвет, тип коробки передач).
//Создайте функции для задания значений, отображения
//значений, поиска значений.
int size1 = -1;
struct car {
    float len;      //длина
    float klirens;  //высота посадки
    float V;        //объем двигателя
    float W;        //мощность двигателя
    float D;        //диаметр
    string color;   //цвет
    bool type_c;    //тип коробки передач
};
car* arr;
//ввод данных
void InputData(){
    cout << "Введите количесто моделей: ";
    cin >> size1;
    if (size1 < 1) size1 = 1;

    arr = new car[size1];
    for (int i = 0; i < size1; i++)
    {
        int type = 0;
        cout << "Номер модели - " << i + 1 << ": " << endl;
        cout << "Введите длину автомобиля:" << endl;
        cin >> arr[i].len;
        cout << "Введите клиренс:" << endl;
        cin >> arr[i].klirens;
        cout << "Введите объем двигателя:" << endl;
        cin >> arr[i].V;
        cout << "Введите мощность двигателя:" << endl;
        cin >> arr[i].W;
        cout << "Введите диаметр колес:" << endl;
        cin >> arr[i].D;
        cout << "Введите цвет:" << endl;
        cin >> arr[i].color;
        cout << "Введите тип коробки передач"<<endl
             << "0 - авт, 1 - механика" << endl;
        cin >> type;
        if (type > 0)arr[i].type_c = true;
        else arr[i].type_c = false;
    }
}
//заполнение данных
void EnteringData(int i) {
    cout << "Номер модели - " << i + 1 << endl
        << "длина -" << arr[i].len << endl
        << "клиренс -" << arr[i].klirens << endl
        << "объём -" << arr[i].V << endl
        << "мощность -" << arr[i].W << endl
        << "диаметр колёс -" << arr[i].D << endl
        << "цвет - " << arr[i].color << endl
        << "коробка передач - ";
    if (arr[i].type_c > 0)cout<<"механика\n";
    else cout<<"автомат";
    cout << endl << endl;
}
//вывод данных
void OutputData() {
    if (size1 < 0) cout << "Нельзя ввести отрыцательное значение!" << endl;
    else for (int i = 0; i < size1; i++) EnteringData(i);
}
int search() // поиск и вывод всех машин 
{
    if (size1 <= 0) cout << "Нельзя ввести то чего нет!" << endl; 
    else{
        int menu_s;
        cout << "Введите параметр для поиска:" << endl;
        cout << "1 - длина" << endl;
        cout << "2 - клиренс" << endl;
        cout << "3 - объём двигателя" << endl;
        cout << "4 - мощность двигателя" << endl;
        cout << "5 - диаметр колёс" << endl;
        cout << "6 - тип коробки передач" << endl;
        cout << "7 - цвет" << endl;
        cin >> menu_s;
        system("cls");
        if (menu_s != 6)
            cout << "Введите модель для поиска" << endl; 
        else
            cout << "<= 0 - автомат, >=1 - механика" << endl;

        float obr;
        string obr_color;

        if (menu_s <= 6)  cin >> obr;

        else  cin >> obr_color;

        int count_s = 0;

        for (int i = 0; i < size1; i++){
            float temp;
            string temp_color;

            switch (menu_s)
            {

            case 1: {
                temp = arr[i].len;
                break; }
            case 2: {
                temp = arr[i].klirens;
                break; }
            case 3: {
                temp = arr[i].V;
                break; }
            case 4: {
                temp = arr[i].W;
                break; }
            case 5: {
                temp = arr[i].D;
                break; }
            case 6: {
                temp = arr[i].type_c;
                break; }
            case 7: {
                temp_color = arr[i].color;
                break; }
            }
            if (menu_s <= 6) {
                if (temp == obr) {
                    EnteringData(i);
                    count_s++;
                }
            }
            else {
                if (temp_color == obr_color){
                    EnteringData(i);
                    count_s++;
                }
            }
        }
        return count_s;
    }
}

int main() {
    setlocale(LC_ALL, "");
    
    bool ok = true;
    int menu = 0;
    do
    {
        cout << "МЕНЮ" << endl;
        cout << "1 - Ввести значения;" << endl;
        cout << "2 - Вывести все хар-ки моделей;" << endl;
        cout << "3 - Поиск конкретной модели;" << endl;
        cout << "любая другая клавиша - выход." << endl;
        cout << "Введите пункт меню:";
        cin >> menu;

        system("cls");

        switch (menu) {
        case 1:
            InputData();
            break;
        case 2:
            OutputData();
            break;
        case 3:
        {
            int count = search();
            if (count == 0)  cout << "параметр не найден!" << endl;
            if (size1 < 0)  cout << "ошибка поиска!" << endl;
            if(count>0)cout << "параметры модели: " << count << endl;
            break;
        }
        default:
            ok = false;
            break;
        }


    } while (ok);
    cout << "Готово";
    return 0;
}