#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

void Exercise4()
{
    // Exercuse4: Каждую часто используемую букву в строке заменить
    // на менее используемую (и наоборот)
    // SSSSfbcd -> ffffSSSS

    std::string strSomeString = "SSSSfbcd";

    std::map<int, char> mapCharsCount;

    for (std::string::iterator it = strSomeString.begin(); it != strSomeString.end(); ++it)
    {
        const int iCount = std::count(strSomeString.begin(), strSomeString.end(), *it);
        std::pair<int, const char> pairCharCount(iCount, *it);
        mapCharsCount.insert(pairCharCount);
    }

    char chFrequentChar = (--mapCharsCount.end())->second;
    char chRareChar     = mapCharsCount.begin()->second;

    for (std::string::iterator it = strSomeString.begin(); it != strSomeString.end(); ++it)
    {
        if (*it == chFrequentChar)
        {
            std::string::iterator itTempEnd = it + 1;
            strSomeString.replace(it, itTempEnd, 1, chRareChar);
        }
        else
        {
            std::string::iterator itTempEnd = it + 1;
            strSomeString.replace(it, itTempEnd, 1, chFrequentChar);
        }
    }

    std::cout << strSomeString << std::endl;
}

template <typename T>
bool DeletePredicate(T tValue)
{
    return tValue > 5;
}

void Exercise3()
{
    // Exercuse3: написать функцию remove_if, которая удаляет из диапазона
    // (ограниченного итераторами) все значения

    typedef int VectorType;

    std::vector<VectorType> vecIntVector;
    size_t uVectorSize = 11;

    for (size_t i = 0; i < uVectorSize; ++i)
        vecIntVector.push_back(i);

    vecIntVector.erase(std::remove_if(vecIntVector.begin(), vecIntVector.end(), DeletePredicate<VectorType>),
                       vecIntVector.end());

    uVectorSize = vecIntVector.size();
    for (size_t i = 0; i < uVectorSize; ++i)
        std::cout << vecIntVector[i] << std::endl;
}

template <typename T>
int IteratorsDistance(T start, T end, std::random_access_iterator_tag)
{
    return std::distance(start, end);
}

void Exercise2()
{
    // Exercise2: написать простую функцию distance(),
    // которая находит расстояние между переданными в неё итераторами

    typedef int VectorType;
    typedef std::vector<VectorType>::iterator VectorIterator;

    std::vector<VectorType> vecIntVector;
    const size_t uVectorSize = 11;

    for (size_t i = 0; i < uVectorSize; ++i)
        vecIntVector.push_back(i);

    int iIteratorsDistance = IteratorsDistance(vecIntVector.begin(), vecIntVector.end(),
                                               typename std::iterator_traits<VectorIterator>::iterator_category());

    std::cout << iIteratorsDistance << std::endl;
}

template <typename T>
bool VectorPredicate(T tValue)
{
    return tValue == 7;
}

void Exercise1()
{
    // Exercise1: написать функцию, которая находит в векторе первое значение,
    // удовлетворяющее заданному предикату

    typedef int VectorType;
    typedef std::vector<VectorType>::iterator VectorIterator;

    std::vector<VectorType> vecIntVector;
    const size_t uVectorSize = 10;

    for (size_t i = 0; i < uVectorSize; ++i)
        vecIntVector.push_back(i);

    VectorIterator pFirstPos = std::find_if(vecIntVector.begin(), vecIntVector.end(), VectorPredicate<VectorType>);
    if (pFirstPos != vecIntVector.end())
        *pFirstPos = 777;

    for (size_t i = 0; i < uVectorSize; ++i)
        std::cout << vecIntVector[i] << std::endl;
}

int main()
{
//    Exercise4();
//    Exercise3();
//    Exercise2();
//    Exercise1();

    return 0;
}
