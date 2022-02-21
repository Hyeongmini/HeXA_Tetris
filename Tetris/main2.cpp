#include <iostream>
#include "block.cpp"
#include <windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

class map
{
private:
    int size;
    int x_pos;
    int y_pos;
    int pMap[10][10];
    int stack[10][10];
public:
    map() : size(10), x_pos(0), y_pos(0), pMap{ }, stack{ }
    {
    }

    ~map()
    {
    }

    void posInit()
    {
        x_pos = 0;
        y_pos = 0;
    }
    //x_pos,y_pos에 블록 놓기
    template<class T>
    void setBlock(T s)
    {

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {

                if (pMap[y_pos + i][x_pos + j] == 1 && s.getInfo(i, j) == 0);
                else
                    pMap[y_pos + i][x_pos + j] = s.getInfo(i, j);
            }
        }
    }
    //x_pos,y_pos에 블록 없애기
    template<class T>
    void unBlock(T s)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (pMap[y_pos + i][x_pos + j] == 1 && s.getInfo(i, j) == 0);
                else
                    pMap[y_pos + i][x_pos + j] = 0;
            }
        }
    }
    //콘솔창 초기화
    void mapInit()
    {
        system("cls");
    }
    //블록 한칸 내리기
    template<class T>
    void down(T s)
    {
        unBlock<T>(s);
        ++y_pos;
        setBlock<T>(s);
    }
    //블록 한칸 왼쪽으로
    template<class T>
    void left(T s)
    {

        unBlock<T>(s);
        --x_pos;
        setBlock<T>(s);
    }
    //블록 한칸 오른쪽으로
    template<class T>
    void right(T s)
    {
        unBlock<T>(s);
        ++x_pos;
        setBlock<T>(s);
    }
    //맵 출력
    void showMap()
    {

        for (int i = 0; i < size; ++i)
        {
            std::cout << "■";
        }
        std::cout << std::endl;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (pMap[i][j] == 1)
                    std::cout << "■";
                else
                    std::cout << "□";
            }
            std::cout << std::endl;
        }
        for (int i = 0; i < size; ++i)
        {
            std::cout << "■";
        }
        std::cout << std::endl;
    }
    //키 입력 받고 작동하기
    template<class T>
    void getKey(T s)
    {

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {

                pMap[i][j] = stack[i][j];
            }
        }
        int crash = 1;
        while (crash)
        {
            int key = _getch();
            key = _getch();

            for (int i = 0; i < 3; ++i)
            {
                if ((y_pos == size - 3 && s.getInfo(2, i) == 1) || (y_pos == size - 2 && s.getInfo(1, i) == 1))
                {
                    crash = 0;
                    break;
                }
                else if ((pMap[y_pos + 3][x_pos + i] == 1 && s.getInfo(2, i) == 1) || (pMap[y_pos + 2][x_pos + i] == 1 && s.getInfo(1, i) == 1 && s.getInfo(2, i) == 0) || (pMap[y_pos + 1][x_pos + i] == 1 && s.getInfo(0, i) == 1 && s.getInfo(1, i) == 0 && s.getInfo(2, i) == 0))
                {
                    crash = 0;
                    break;
                }

                else if (i == 2)
                {
                    switch (key)
                    {
                    case UP:
                        for (int i = 0; i < 3; ++i)
                        {
                            if (x_pos == size - 2 && s.getInfo(i, 1) == 1) left<T>(s);
                            else if (x_pos == -1 && s.getInfo(i, 1) == 1) right<T>(s);
                            else if ((pMap[y_pos + i][x_pos - 1] == 1 && s.getInfo(i, 0)) == 1 || (pMap[y_pos + i][x_pos] == 1 && s.getInfo(i, 1) == 1 && s.getInfo(i, 0) == 0)) break;
                            else if ((pMap[y_pos + i][x_pos + 3] == 1 && s.getInfo(i, 2) == 1) || (pMap[y_pos + i][x_pos + 2] == 1 && s.getInfo(i, 1) == 1 && s.getInfo(i, 2) == 0)) break;
                            else if (i == 2)
                            {
                                mapInit();
                                unBlock<T>(s);
                                s.rotate();
                                setBlock<T>(s);
                                showMap();
                            }
                        }
                        break;
                    case DOWN:
                        for (int i = 0; i < 3; ++i)
                        {
                            if ((y_pos == size - 3 && s.getInfo(2, i) == 1) || (y_pos == size - 2 && s.getInfo(1, i) == 1)) break;
                            else if (i == 2)
                            {
                                mapInit();
                                down<T>(s);
                                showMap();
                            }
                        }
                        break;
                    case LEFT:
                        for (int i = 0; i < 3; ++i)
                        {
                            if ((x_pos == 0 && s.getInfo(i, 0) == 1) || (x_pos == -1 && s.getInfo(i, 1) == 1)) break;
                            else if ((pMap[y_pos + i][x_pos - 1] == 1 && s.getInfo(i, 0)) == 1 || (pMap[y_pos + i][x_pos] == 1 && s.getInfo(i, 1) == 1 && s.getInfo(i, 0) == 0)) break;
                            else if (i == 2)
                            {
                                mapInit();
                                left<T>(s);
                                showMap();
                            }
                        }
                        break;
                    case RIGHT:
                        for (int i = 0; i < 3; ++i)
                        {
                            if ((x_pos == size - 3 && s.getInfo(i, 2) == 1) || (x_pos == size - 2 && s.getInfo(i, 1) == 1)) break;
                            else if ((pMap[y_pos + i][x_pos + 3] == 1 && s.getInfo(i, 2) == 1) || (pMap[y_pos + i][x_pos + 2] == 1 && s.getInfo(i, 1) == 1 && s.getInfo(i, 2) == 0)) break;
                            else if (i == 2)
                            {
                                mapInit();
                                right<T>(s);
                                showMap();
                            }
                        }
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                stack[i][j] = pMap[i][j];
            }
        }

    }
    //만약 한 줄이 다차면 사라지게 하고 위에 있는 것들 내리기
    void oneLine()
    {

        for (int i = 0; i < size; ++i)
        {
            int one = 0;
            for (int j = 0; j < size; ++j)
            {
                if (stack[i][j] == 1)
                    ++one;
            }
            if (10 == one)
            {
                for (int k = 0; k < size; ++k)
                    stack[i][k] = 0;
                for (int o = i - 1; o >= 0; --o)
                {
                    for (int k = 0; k < size; ++k)
                    {
                        if (stack[o][k] == 1)
                        {
                            stack[o + 1][k] = stack[o][k];
                            stack[o][k] = 0;
                        }
                    }
                }
            }
        }
    }


};


void tetris()
{
    map dd;
    A a;
    B b;
    C c;
    D d;
    E e;
    F f;
    G g;

    while (true)
    {
        dd.oneLine();
        int i = rand() % 7;
        switch (i)
        {
        case 0:
            dd.setBlock<A>(a);
            dd.showMap();
            dd.getKey<A>(a);
            dd.posInit();
            dd.mapInit();
            break;
        case 1:
            dd.setBlock<B>(b);
            dd.showMap();
            dd.getKey<B>(b);
            dd.posInit();
            dd.mapInit();
            break;
        case 2:
            dd.setBlock<C>(c);
            dd.showMap();
            dd.getKey<C>(c);
            dd.posInit();
            dd.mapInit();
            break;
        case 3:
            dd.setBlock<D>(d);
            dd.showMap();
            dd.getKey<D>(d);
            dd.posInit();
            dd.mapInit();
            break;
        case 4:
            dd.setBlock<E>(e);
            dd.showMap();
            dd.getKey<E>(e);
            dd.posInit();
            dd.mapInit();
            break;
        case 5:
            dd.setBlock<F>(f);
            dd.showMap();
            dd.getKey<F>(f);
            dd.posInit();
            dd.mapInit();
            break;
        case 6:
            dd.setBlock<G>(g);
            dd.showMap();
            dd.getKey<G>(g);
            dd.posInit();
            dd.mapInit();
            break;
        }
    }
}


int main()
{
    tetris();

    return 0;
}
