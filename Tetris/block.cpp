#include <iostream>

class baseblock
{
protected:
    bool m_base[3][3];

public:
    baseblock() : m_base{ }
    {
    }
    int getinfo(int i, int j)
    {
        return m_base[i][j];
    }
    void showblock()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (1 == m_base[i][j])
                    std::cout << "■";
                else
                    std::cout << "□";
            }
            std::cout << std::endl;
        }
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
    void setblock()
    {

    }
};

class stick : public baseblock
{
public:
    stick()
    {
        baseblock();
        m_base[0][1] = 1;
        m_base[1][1] = 1;
        m_base[2][1] = 1;
    }
};
class nieun : public baseblock
{
public:
    nieun()
    {
        baseblock();
        m_base[1][0] = 1;
        m_base[2][0] = 1;
        m_base[2][1] = 1;
        m_base[2][2] = 1;
    }
};
class re_nieun : public baseblock
{
public:
    re_nieun()
    {
        baseblock();
        m_base[1][2] = 1;
        m_base[2][0] = 1;
        m_base[2][1] = 1;
        m_base[2][2] = 1;
    }
};

class nemo : public baseblock
{
public:
    nemo()
    {
        baseblock();
        m_base[1][0] = 1;
        m_base[2][0] = 1;
        m_base[1][1] = 1;
        m_base[2][1] = 1;
    }
    void rotate()
    {
    }
};
class oh : public baseblock
{
public:
    oh()
    {
        baseblock();
        m_base[1][1] = 1;
        m_base[2][0] = 1;
        m_base[2][1] = 1;
        m_base[2][2] = 1;
    }
};
class sshape : public baseblock
{
public:
    sshape()
    {
        baseblock();
        m_base[0][1] = 1;
        m_base[1][1] = 1;
        m_base[1][2] = 1;
        m_base[2][2] = 1;
    }
};
class zshape : public baseblock
{
public:
    zshape()
    {
        baseblock();
        m_base[0][1] = 1;
        m_base[1][1] = 1;
        m_base[1][0] = 1;
        m_base[2][0] = 1;
    }
};


