//
//  main.cpp
//  x_o_game
//
//  Created by Agness on 26.02.15.
//  Copyright (c) 2015 Agness Ansh. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
// проверка наличия полностью заполненных строк
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// искомый знак
//
// ВЫХОД
// число - количество полностью заполненных знаком строк

int count_total_raws(char a[], int rank, char sign)
{
    int temp_int = 0, total = 0;
    
    for(int i = 0; i <rank; i++)
    {
        temp_int = 0;
        for(int j = 0; j <rank; j++)
            if(a[i*rank+j] == sign) temp_int++;
        
        if(temp_int == rank) total++;
    }
    return total;
}

// проверка наличия полностью заполненных столбцов
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// искомый знак
//
// ВЫХОД
// число - количество полностью заполненных знаком столбцов

int count_total_cols(char a[], int rank, char sign)
{
    int temp_int = 0, total = 0;
    uint am = rank*rank;
    
    for(int i = 0; i < rank; i++)
    {
        temp_int = 0;
        for(int j = i; j < am; j+=rank)
            if(a[j] == sign) temp_int++;
        if(temp_int == rank) total++;
    }
    return total;
}

// проверка наличия полностью заполненной главной диагонали
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// искомый знак
//
// ВЫХОД
// число - 1 - заполнена, 0 - не заполнена

int check_main_diag(char a[], int rank, char sign)
{
    int temp_int = 0, total = 0;
    
    for(int i = 0; i <rank; i++)
    {
        for(int j = 0; j <rank; j++)
            if(i == j && a[i*rank+j] == sign) temp_int++;
    }
    if(temp_int == rank) total = 1;

    return total;
}

// проверка наличия полностью заполненной второстепенной диагонали
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// искомый знак
//
// ВЫХОД
// число - 1 - заполнена, 0 - не заполнена

int check_sub_diag(char a[], int rank, char sign)
{
    int temp_int = 0, total = 0;
    
    for(int i = rank-1; i < (rank*rank - rank); i+=(rank-1))
        if(a[i] == sign) temp_int++;
    
    if(temp_int == rank) total = 1;
    
    return total;
}

////////////////////////////////////////////////////////

// проверка наличия строк, в которых до полного заполнения символом, осталась только одна ячейка
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// искомый знак
//
// ВЫХОД
// число - количество искомых строк

int count_almost_complete_raws(char a[], int rank, char sign)
{
    int temp_int_empt = 0, temp_int_sign = 0, total = 0;
    
    for(int i = 0; i <rank; i++)
    {
        temp_int_empt = 0, temp_int_sign = 0;
        for(int j = 0; j <rank; j++)
        {
            if(a[i*rank+j] == sign) temp_int_sign++;
            if(a[i*rank+j] == '0') temp_int_empt++;
        }
        if((rank - temp_int_sign) == 1  && (temp_int_sign + temp_int_empt) == rank) total++;
    }
    
    return total;
}

// проверка наличия столбцов, в которых до полного заполнения символом, осталась только одна ячейка
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// искомый знак
//
// ВЫХОД
// число - количество искомых столбцов

int count_almost_complete_cols(char a[], int rank, char sign)
{
    int temp_int_empt = 0, temp_int_sign = 0, total = 0;
    uint am = rank*rank;
    
    for(int i = 0; i < rank; i++)
    {
        temp_int_empt = 0, temp_int_sign = 0;
        for(int j = i; j < am; j+=rank)
        {
            if(a[j] == sign) temp_int_sign++;
            if(a[j] == '0') temp_int_empt++;
        }
        if((rank - temp_int_sign) == 1 && (temp_int_sign + temp_int_empt) == rank) total++;
    }
    return total;
}

// проверка главной диагонали, осталась ли в ней только одна ячейка в до полного заполнения символом
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// искомый знак
//
// ВЫХОД
// число - 1 - такая диагональ есть, 0 - такой диагонали нет

int check_almost_complete_main_diag(char a[], int rank, char sign)
{
   int temp_int_empt = 0, temp_int_sign = 0, total = 0;
    
    for(int i = 0; i <rank; i++)
    {
        for(int j = 0; j <rank; j++)
        {
            if(i == j && a[i*rank+j] == sign) temp_int_sign++;
            if(i == j && a[i*rank+j] == '0') temp_int_empt++;
        }
    }
    if((rank - temp_int_sign) == 1 && (temp_int_sign + temp_int_empt) == rank) total = 1;
    
    return total;
}

// проверка второстепенной диагонали, осталась ли в ней только одна ячейка в до полного заполнения символом
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// искомый знак
//
// ВЫХОД
// число - 1 - такая диагональ есть, 0 - такой диагонали нет

int check_almost_complete_sub_diag(char a[], int rank, char sign)
{
   int temp_int_empt = 0, temp_int_sign = 0, total = 0;
    
    for(int i = rank-1; i <= (rank*rank - rank); i+=(rank-1))
    {
        if(a[i] == sign) temp_int_sign++;
        if(a[i] == '0') temp_int_empt++;
    }
    
    if((rank - temp_int_sign) == 1 && (temp_int_sign + temp_int_empt) == rank) total = 1;
    
    return total;
}

//////////////////////////////////////////////////////////////////////

// проверка наличия строк, в которых есть только символ 0 и переданный символ (нет других символов)
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// искомый знак
//
// ВЫХОД
// число - количество искомых строк

int count_uncomplete_single_sign_raws(char a[], int rank, char sign)
{
    int temp_int_empt = 0, temp_int_sign = 0, total = 0;
    
    for(int i = 0; i <rank; i++)
    {
        temp_int_empt = 0, temp_int_sign = 0;
        for(int j = 0; j <rank; j++)
        {
            if(a[i*rank+j] == sign) temp_int_sign++;
            if(a[i*rank+j] == '0') temp_int_empt++;
        }
        if((rank - temp_int_sign) > 1 && (rank - temp_int_sign) < rank && (temp_int_sign + temp_int_empt) == rank) total++;
    }
    
    return total;
}

// проверка наличия столбцов, в которых есть только символ 0 и переданный символ (нет других символов)
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// искомый знак
//
// ВЫХОД
// число - количество искомых столбцов

int count_uncomplete_single_sign_cols(char a[], int rank, char sign)
{
    int temp_int_empt = 0, temp_int_sign = 0, total = 0;
    uint am = rank*rank;
    
    for(int i = 0; i < rank; i++)
    {
        temp_int_empt = 0, temp_int_sign = 0;
        for(int j = i; j < am; j+=rank)
        {
            if(a[j] == sign) temp_int_sign++;
            if(a[j] == '0') temp_int_empt++;
        }
        if((rank - temp_int_sign) > 1 && (rank - temp_int_sign) < rank && (temp_int_sign + temp_int_empt) == rank) total++;
    }
    return total;
}

// проверка главной диагонали, есть ли в ней только символ 0 и переданный символ (нет других символов)
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// искомый знак
//
// ВЫХОД
// число - 1 - такая диагональ есть, 0 - такой диагонали нет

int check_uncomplete_single_sign_main_diag(char a[], int rank, char sign)
{
    int temp_int_empt = 0, temp_int_sign = 0, total = 0;
    
    for(int i = 0; i <rank; i++)
    {
        for(int j = 0; j <rank; j++)
        {
            if(i == j && a[i*rank+j] == sign) temp_int_sign++;
            if(i == j && a[i*rank+j] == '0') temp_int_empt++;
        }
    }
    if((rank - temp_int_sign) > 1 && (rank - temp_int_sign) < rank && (temp_int_sign + temp_int_empt) == rank) total = 1;
    
    return total;
}

// проверка второстепенной диагонали, есть ли в ней только символ 0 и переданный символ (нет других символов)
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// искомый знак
//
// ВЫХОД
// число - 1 - такая диагональ есть, 0 - такой диагонали нет

int check_uncomplete_single_sign_sub_diag(char a[], int rank, char sign)
{
    int temp_int_empt = 0, temp_int_sign = 0, total = 0;
    
    for(int i = rank-1; i <= (rank*rank - rank); i+=(rank-1))
    {
        if(a[i] == sign) temp_int_sign++;
        if(a[i] == '0') temp_int_empt++;
    }
    
     if((rank - temp_int_sign) > 1 && (rank - temp_int_sign) < rank && (temp_int_sign + temp_int_empt) == rank) total = 1;
    
    return total;
}

//////////////////////////////////////////////////////////////////////

// подсчет количества свободных ячеек и заполнения массива индексов свободных ячеек
//
// ВХОД
// указатель на 1Д массив чар
// размерность
// указатель на массив свободных индексов
//
// ВЫХОД
//
// заполненный массив свободных индексов

void count_free(char a[], int indicies[], int &free_am, int rank)
{
    int am = rank*rank;
    for(int i = 0; i < am; i++) indicies[i] = -1;
    free_am = 0;
    for(int i = 0; i < am; i++)
        if(a[i] == '0')
        {
            indicies[free_am] = i;
            free_am++;
        }
}

//////////////////////////////////////////////////////////////////////

// СТРУКТУРА
// ПОЛЕ
// указатель на массив символов - состояние игрового поля
// текущий_знак - символ - тот знак, для которого ищем стратегию
// следующий_знак - символ - тот знак, который будет ходить следующим
// последний_заполненный_индекс - индекс массива, в который знак поставлен последним
// количество_свободных - число
// метод добавления знака
//
// конструктор
// конструктор-копировщик
// деструктор

struct Field
{
    Field(int r):rank(r),free_remain(r*r),last_filled_index(-1), its_sign('x'), have_winner(false)
    {
        play_field = new char[rank*rank];
        for(int i = 0; i < rank*rank; i++)
            play_field[i] = '0';
    }
    Field(const Field &rhs)
    {
        rank = rhs.rank;
        play_field = new char[rank*rank];
        for(int i = 0; i < rank*rank; i++)
          play_field[i] = rhs.play_field[i];
        
        last_filled_index = rhs.last_filled_index;
        free_remain = rhs.free_remain;
        its_sign = rhs.its_sign;
    }
    ~Field(){delete play_field; play_field = 0;}
    bool add_new_sign(int index, char sign)
    {
        if(index == -1 || play_field[index] != '0') return false;
        
        play_field[index] = its_sign = sign;
        
        free_remain--;
        last_filled_index = index;
        
        return true;
    }
    void show()
    {
        cout<<endl;
        cout<<endl;
        for(int i = 0; i < rank; i++)
        {
            cout<<endl;
            for(int j = 0; j < rank; j++)
                if(play_field[i*rank+j] == '0') cout<< i*rank+j << " ";
                else cout<< play_field[i*rank+j] <<" ";
        }
        cout<<endl;
        cout<<endl;
    }
    char*play_field;
    char its_sign;
    int last_filled_index;
    int free_remain;
    int rank;
    bool have_winner;
};

//////////////////////////////////////////////////////////////////////
// СТРУКТУРА - вспомогательная сущность для функции выбора стратегии
// СОСТОЯНИЕ ПОЛЯ
// index - число - номер варианта поля с проставленным знаком игрока (о или х)
// total_complete - число полностью запоненных линий (строк, столбцов, диагоналей)
// one_sign_to_complete - число линий, в которых осталось проставить один знак (х или о) до выигрыша соответствующего игрока
// mono_sign - число линий, в которых только пустые ячейки или знак только одного вида (х или о)
//
struct MoveVars
{
    MoveVars(int i):total_complete(0),one_sign_to_complete(0),mono_sign(0){}
    int index;
    int total_complete;
    int one_sign_to_complete;
    int mono_sign;
};

//////////////////////////////////////////////////////////////////////

// функция выбора стратегии
//
// ВХОД
// ссылка на ТЕКУЩУЮ СТРУКТУРУ
// ранг - число, размерность. ранг*ранг = количество элементов в массиве  ----- ранг сейчас в Field
//
// наш_знак - знак игрока, за которого играет компьютер
//
// ВЫХОД
// число - индекс, куда сделать следующий ход

int get_next_step(Field &current_field, char our_sign, char sign_to_go)
{
    // стек - стек, контейнер стл, содержит проверяемые состояния СТРУКТУР.
    //        при самом первом обращении стек содержит копию пустого игрового поля
    stack <Field> stack_field;
    //  копия с переданного игрового ПОЛЯ
    Field work_copy(current_field);
    stack_field.push(work_copy);
    
    // темп - вектор, контейнер стл, содержит копии СТРУКТУРЫ ИЗ СТЕКА по числу свободных ячеек СТРУКТУРЫ (до начала ЦИКЛ ПОКА СТЕК НЕ ПУСТ темп пуст)
    vector <Field> temp;
    
    // вектор всех ходов выигрышной стратегии для our_sign
    vector<int>moves_x;
    
    // ЦИКЛ ПОКА СТЕК НЕ ПУСТ
    while(stack_field.size() != 0)
    {
        // если на игровом поле не осталось пустых ячеек, выходим
        if(stack_field.top().free_remain == 0) break;
        
        //  1. вынимаем структуру из стека
        Field current_copy = stack_field.top();
        stack_field.pop();
        
        //  2. считаем количество свободных ячеек и заполняем массив свободных индексов в СТРУКТУРЕ ИЗ СТЕКА
        
        // количество свободных индексов
        int free_am = 0;
        int dimension = current_field.rank*current_field.rank;
        // массив свободных индексов - свободные индексы СТРУКТУРЫ ИЗ СТЕКА
        int ind[dimension];
        // заполнение массива свободных индексов и количества свободных
        count_free(current_copy.play_field, ind, free_am, current_copy.rank);

        //  3. создаем копии по числу свободных индексов СТРУКТУРЫ ИЗ СТЕКА, в каждой копии заполняем           соответствующий индекс. Проставляем sign_to_go
        // Меняем its_sign в структуре на sign_to_go.  Каждую копию СТРУКТУРЫ ИЗ СТЕКА добавляем в вектор темп
        for(int i = 0; i < free_am; i++)
        {
            Field a(current_copy);
            if(a.add_new_sign(ind[i], sign_to_go))
                temp.push_back(a);
        }
        
        sign_to_go = (sign_to_go == 'x')?'o':'x';
       
        // вектор с вариантами ходов (для выбора того, гда вариантов больше)
        vector<MoveVars> list_of_moves;
        
        //  4. для каждой структуры из темп вызываем процедуры (ЦИКЛ ТЕМП):
        for(int i = 0; i < temp.size(); i++)
        {
            MoveVars a(i);
            // подсчет количества полностью заполненных
            a.total_complete +=count_total_raws(temp[i].play_field, temp[i].rank, temp[i].its_sign);
            a.total_complete +=count_total_cols(temp[i].play_field, temp[i].rank, temp[i].its_sign);
            a.total_complete +=check_main_diag(temp[i].play_field, temp[i].rank, temp[i].its_sign);
            a.total_complete +=check_sub_diag(temp[i].play_field, temp[i].rank, temp[i].its_sign);
            
            // подсчет количества, где для полного заполненения нужен 1 символ
            a.one_sign_to_complete += count_almost_complete_raws(temp[i].play_field, temp[i].rank, temp[i].its_sign);
            a.one_sign_to_complete += count_almost_complete_cols(temp[i].play_field, temp[i].rank, temp[i].its_sign);
            a.one_sign_to_complete += check_almost_complete_main_diag(temp[i].play_field, temp[i].rank, temp[i].its_sign);
            a.one_sign_to_complete += check_almost_complete_sub_diag(temp[i].play_field, temp[i].rank, temp[i].its_sign);
            
            // подсчет количества, где или пустая ячейка или символы только одного вида
            a.mono_sign += count_uncomplete_single_sign_raws(temp[i].play_field, temp[i].rank, temp[i].its_sign);
            a.mono_sign += count_uncomplete_single_sign_cols(temp[i].play_field, temp[i].rank, temp[i].its_sign);
            a.mono_sign += check_uncomplete_single_sign_main_diag(temp[i].play_field, temp[i].rank, temp[i].its_sign);
            a.mono_sign += check_uncomplete_single_sign_sub_diag(temp[i].play_field, temp[i].rank, temp[i].its_sign);
            list_of_moves.push_back(a);
        }
       // ЗАВЕРШЕНИЕ ЦИКЛА ТЕМП
        
        int max_total = 0;
        int max_alm_complete = 0;
        int max_mono = 0;
        int better_index_t = 0;
        int better_index_a = 0;
        int better_index_m = 0;
        int result_index = 0;
        
        // перебор вариантов ходов
        for(int i = 0; i < list_of_moves.size(); i++)
        {
            if(list_of_moves[i].total_complete > max_total) {max_total = list_of_moves[i].total_complete; better_index_t = i;}
            if(list_of_moves[i].one_sign_to_complete > max_alm_complete) {max_alm_complete = list_of_moves[i].one_sign_to_complete; better_index_a = i;}
            if(list_of_moves[i].mono_sign > max_mono) {max_mono = list_of_moves[i].mono_sign; better_index_m = i;}
         
        }
        // выбор лучшего варианта хода
        if(max_total > 0) result_index = better_index_t;
        else if(max_alm_complete > 0) result_index = better_index_a;
        else result_index = better_index_m;
        
        list_of_moves.clear();
        
        // если ходили за "нашего игрока", добавляем ход в вектор выигрышных ходов
        if(temp[result_index].its_sign == our_sign) moves_x.push_back(temp[result_index].last_filled_index);
        // поле с выбранным лучшим ходом кладем в стек
        Field a(temp[result_index]);
        stack_field.push(a);
        
        temp.clear();
        if(max_total > 0) break;
    }
    // ЗАВЕРШЕНИЕ ЦИКЛА "ПОКА СТЕК НЕ ПУСТ"
    
    return moves_x[0];
}

// функция провеки наличия победителя
bool check_winner(Field &curr_field, char sign)
{
    int am_comp = 0;
    
    am_comp +=count_total_raws(curr_field.play_field, curr_field.rank, sign);
    am_comp +=count_total_cols(curr_field.play_field, curr_field.rank, sign);
    am_comp +=check_main_diag(curr_field.play_field, curr_field.rank, sign);
    am_comp +=check_sub_diag(curr_field.play_field, curr_field.rank, sign);

    if(am_comp > 0) return true;
    else return false;
}

int main(int argc, const char * argv[]) {
   
    Field a(3);
    int ind_x = get_next_step(a,'x','x');
    a.add_new_sign(ind_x, 'x');
    int ind_o = -1;
    char winner = '0';
    
    while(a.free_remain > 0)
    {
        a.show();

        while(!a.add_new_sign(ind_o, 'o'))
        {
            cout<<" Enter index of o "<<endl;
            cin>>ind_o;
        }
        if(check_winner(a,'o')) {a.have_winner = true; winner = 'o'; break;}
        
        ind_x = get_next_step(a,'x','x');
        a.add_new_sign(ind_x,'x');
        if(check_winner(a,'x')) {a.have_winner = true; winner = 'x'; break;}

    }
    if( winner == '0') cout<<" Nobody wins"<<endl;
    else if( winner == 'x') cout<<" x wins"<<endl;
    else if( winner == 'o') cout<<" o wins"<<endl;
    
    a.show();
    
    return 0;
}
