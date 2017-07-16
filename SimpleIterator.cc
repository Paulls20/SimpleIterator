// Example program
#include <iostream>
#include <string>

template<int START = 0, int END = 360, int INCR = 18>
struct AngleIter 
{
    AngleIter& begin()
    {
        return *this;     
    }
     
    AngleIter& end()
    {
        m_value = END;
        return *this; 
    }
    
    bool operator!=(const AngleIter& other)
    {
        return (m_value != other.m_value);
    }

    // Required
    const AngleIter& operator++()
    {
        m_value += INCR;
        return *this;
    }

    // Required
    int operator*() const
    {
        return m_value;
    }
    
    int m_value = START;
};

int main()
{
    for(auto i :AngleIter<10, 50, 5>()) 
        std::cout << i <<std::endl;
}
