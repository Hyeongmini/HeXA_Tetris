#include <iostream>

class BaseBlock
{
protected:
    bool m_base[3][3];

public:
    BaseBlock() : m_base{ }
    {
    }
    int getInfo(int i, int j)
    {
        return m_base[i][j];
    }

    void rotate()
    {
        //모서리
        char temp = m_base[0][0];
        m_base[0][0] = m_base[2][0];
        m_base[2][0] = m_base[2][2];
        m_base[2][2] = m_base[0][2];
        m_base[0][2] = temp;
        //변
        temp = m_base[0][1];
        m_base[0][1] = m_base[1][0];
        m_base[1][0] = m_base[2][1];
        m_base[2][1] = m_base[1][2];
        m_base[1][2] = temp;
    }
};

//일자모양 블록
class A : public BaseBlock
{
public:
    A()
    {
        BaseBlock();
        m_base[0][1] = 1;
        m_base[1][1] = 1;
        m_base[2][1] = 1;
    }
};
//ㄴ모양 블록
class B : public BaseBlock
{
public:
    B()
    {
        BaseBlock();
        m_base[1][0] = 1;
        m_base[2][0] = 1;
        m_base[2][1] = 1;
        m_base[2][2] = 1;
    }
};
//ㄱ모양 블록
class C : public BaseBlock
{
public:
    C()
    {
        BaseBlock();
        m_base[1][2] = 1;
        m_base[2][0] = 1;
        m_base[2][1] = 1;
        m_base[2][2] = 1;
    }
};
//ㅁ모양 블록
class D : public BaseBlock
{
public:
    D()
    {
        BaseBlock();
        m_base[1][0] = 1;
        m_base[2][0] = 1;
        m_base[1][1] = 1;
        m_base[2][1] = 1;
    }
    void rotate()
    {
    }
};
//ㅓ모양 블록
class E : public BaseBlock
{
public:
    E()
    {
        BaseBlock();
        m_base[1][1] = 1;
        m_base[2][0] = 1;
        m_base[2][1] = 1;
        m_base[2][2] = 1;
    }
};
//s모양 블록
class F : public BaseBlock
{
public:
    F()
    {
        BaseBlock();
        m_base[0][1] = 1;
        m_base[1][1] = 1;
        m_base[1][2] = 1;
        m_base[2][2] = 1;
    }
};
//z모양 블록
class G : public BaseBlock
{
public:
    G()
    {
        BaseBlock();
        m_base[0][1] = 1;
        m_base[1][1] = 1;
        m_base[1][0] = 1;
        m_base[2][0] = 1;
    }
};


