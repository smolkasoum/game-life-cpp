#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <windows.h> 

void logo()
{
    for (size_t j = 0; j < 5; j++)
    {
        std::cout << "# | * | #" << std::endl;
    }

    std::cout << "| Game Life  | by Sm.soum | " << std::endl;

    int pause; std::cin >> pause;
}

void print(char** mass_two, int ver, int horiz)
{
    for (int i = 0; i < ver; ++i) 
    {
        for (int j = 0; j < horiz; ++j)
        {
            std::cout << mass_two[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int fulling(char** mass, int ver, int horiz)
{
    for (int i = 0; i < ver; ++i) 
    {
        for (int j = 0; j < horiz; ++j)
        {
            mass[i][j] = '.';
        }
    }

    std::cout << "manual filling - 0" << std::endl;
    std::cout << "automatic filling - 1" << std::endl;
    int var_one = 0; 
    std::cin >> var_one;

    if (var_one == 0)
    {
        std::cout << "enter number of filled cells" << std::endl;
        int var_two; 
        std::cin >> var_two;

        int ver_vert, ver_horix;
        for (size_t i = 0; i < var_two; i++)
        {
            system("cls");
            std::cout << "enter vertical cell " << std::endl;
            std::cin >> ver_vert;
            std::cout << "enter horizontal cell " << std::endl;
            std::cin >> ver_horix;

            if (ver_vert >= ver || ver_horix >= horiz || ver_vert < 0 || ver_horix < 0)
            {
                std::cout << "Invalid coordinates!" << std::endl;
                continue;
            }

            mass[ver_vert][ver_horix] = '*';
        }
    }
    else if (var_one == 1)
    {
        std::cout << "enter number of filled cells" << std::endl;
        int var_two; 
        std::cin >> var_two;

        for (size_t i = 0; i < var_two; i++)
        {
            mass[rand() % ver][rand() % horiz] = '*';
        }
    }
    else
    {
        system("cls");
        fulling(mass, ver, horiz);
    }

    print(mass, ver, horiz);

    int pause; 
    std::cin >> pause;

    return 0;
}

int algoritm_one(char** mass_ch_cop, int ver, int horiz)
{
    for (int i = 0; i < ver; i++) 
    {
        for (int j = 0; j < horiz; j++) 
        {
            int live_neighbors = 0;

            // Проверка 8 соседей
            for (int di = -1; di <= 1; di++) 
            {
                for (int dj = -1; dj <= 1; dj++) 
                {
                    if (di == 0 && dj == 0) continue;

                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < ver && nj >= 0 && nj < horiz) 
                    {
                        if (mass_ch_cop[ni][nj] == '*') 
                        {
                            live_neighbors++;
                        }
                    }
                }
            }

            // Применяем правила игры «Жизнь»
            if (mass_ch_cop[i][j] == '*') 
            {
                if (live_neighbors < 2 || live_neighbors > 3) 
                {
                    mass_ch_cop[i][j] = '.';  // Клетка умирает
                }
            } 
            else 
            {
                if (live_neighbors == 3) 
                {
                    mass_ch_cop[i][j] = '*';  // Клетка становится живой
                }
            }
        }
    }    

    return 0;
}

int mass_two(char** mass_ch, int ver, int horiz)
{
    char** mass_ch_two = new char*[ver];
    for (int i = 0; i < ver; ++i)
    {
        mass_ch_two[i] = new char[horiz];
    }

    for (size_t i = 0; i < ver; i++)
    {
        for (size_t j = 0; j < horiz; j++)
        {
            mass_ch_two[i][j] = mass_ch[i][j];
        }
    }

    algoritm_one(mass_ch_two, ver, horiz);

    for (size_t i = 0; i < ver; i++)
    {
        for (size_t j = 0; j < horiz; j++)
        {
            mass_ch[i][j] = mass_ch_two[i][j];
        }
    }

    for (int i = 0; i < ver; ++i)
    {
        delete[] mass_ch_two[i];
    }
    delete[] mass_ch_two;

    return 0;
}

int algorinm_two(char** mass_ch_one, int ver, int horiz)
{
    std::cout << "enter number of generations" << std::endl;
    int gen; 
    std::cin >> gen;
    system("cls");

    if (gen <= 100)
    {
        for (size_t i = 0; i < gen; i++)
        {
            mass_two(mass_ch_one, ver, horiz);
            print(mass_ch_one, ver, horiz);
            Sleep(1000);  // Задержка между поколениями
            system("cls");
        }
    }
    else
    {
        std::cout << "error!" << std::endl;
        Sleep(1000);
        algorinm_two(mass_ch_one, ver, horiz);
        system("cls");
    }

    return 0;
}

int main()
{
    srand(time(NULL));

    logo();

    int size_ver;
    int size_horiz;

    std::cout << "enter vertical" << std::endl;
    std::cin >> size_ver;
    std::cout << "enter horizontal" << std::endl;
    std::cin >> size_horiz;

    system("cls");

    char** mass_point = new char*[size_ver];
    for (int i = 0; i < size_ver; ++i)
    {
        mass_point[i] = new char[size_horiz];
    }

    fulling(mass_point, size_ver, size_horiz);

    algorinm_two(mass_point, size_ver, size_horiz);

    for (int i = 0; i < size_ver; ++i)
    {
        delete[] mass_point[i];
    }
    delete[] mass_point;

    std::cout << "game stop!" << std::endl;
    system("pause");

    return 0;
}