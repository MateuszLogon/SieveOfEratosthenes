#include <iostream>
#include <cmath>

class PrimeSieve
{
private:
    int N;
    bool* primeArray;

public:
    PrimeSieve();
    ~PrimeSieve();
    void Sieve();
    void DisplayPrimes();
};

PrimeSieve::PrimeSieve()
{
    std::cout << "Enter the upper limit to find prime numbers:" << std::endl;
    while (!(std::cin >> N) || N <= 1)
    {
        std::cout << "Invalid input. Please enter a number greater than 1." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    primeArray = new bool[N + 1]; // dynamic memory allocation for the array
    for (int i = 2; i <= N; ++i)
    {
        primeArray[i] = true;
    }
}

PrimeSieve::~PrimeSieve()
{
    delete[] primeArray; // releasing allocated memory
}

void PrimeSieve::Sieve()
{
    int sqrtN = sqrt(N);
    for (int i = 2; i <= sqrtN; ++i)
    {
        if (primeArray[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
            {
                primeArray[j] = false;
            }
        }
    }
}

void PrimeSieve::DisplayPrimes()
{
    std::cout << "Prime numbers from 2 to " << N << ":" << std::endl;
    for (int i = 2; i <= N; ++i)
    {
        if (primeArray[i] == true)
        {
            std::cout << i << ", ";
        }
    }
    std::cout << std::endl;

    // Displaying multiples:
    std::cout << "Multiples of 2:" << std::endl;
    for (int i = 2; i <= (N / 2); ++i) // Multiples of 2
    {
        int j = i * 2;
        std::cout << j << ", ";
    }

    std::cout << '\n' << "Multiples of 3:" << std::endl;
    for (int i = 2; i <= (N / 3); ++i) // Multiples of 3
    {
        int j = i * 3;
        std::cout << j << ", ";
    }

    std::cout << '\n' << "Multiples of 5:" << std::endl;
    for (int i = 2; i <= (N / 5); ++i) // Multiples of 5
    {
        int j = i * 5;
        std::cout << j << ", ";
    }

    std::cout << '\n' << "Multiples of 7:" << std::endl;
    for (int i = 2; i <= (N / 7); ++i) // Multiples of 7
    {
        int j = i * 7;
        std::cout << j << ", ";
    }
}

int main()
{
    PrimeSieve sieve;
    sieve.Sieve();
    sieve.DisplayPrimes();

    return 0;
}
