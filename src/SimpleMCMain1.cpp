#include <iostream>
#include <cmath>
#include <Random1.h>

double SimpleMonteCarlo1(double Expiry,
                         double Strike,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths)
{
    double variance = Vol * Vol * Expiry;
    double rootVariance = std::sqrt(variance);
    double itoCorrection =  -0.5 * variance; 

    double moveSpot = Spot * std::exp(r * Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for (unsigned long i = 0; i < NumberOfPaths; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = moveSpot * std::exp(rootVariance * thisGaussian);
        double thisPayoff = thisSpot - Strike;
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= std::exp(-r * Expiry);
    return mean;
}


int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    std::cout << "\nEnter expiry\n";
    std::cin >> Expiry;
    std::cout << "\nStrike\n";
    std::cin >> Strike;
    std::cout << "\nSpot\n";
    std::cin >> Spot;
    std::cout << "\nVol\n";
    std::cin >> Vol;
    std::cout << "\nr\n";
    std::cin >> r;
    std::cout << "\nNumber of paths\n";
    std::cin >> NumberOfPaths;

    double result = SimpleMonteCarlo1(Expiry,
                                      Strike,
                                      Spot,
                                      Vol,
                                      r,
                                      NumberOfPaths);
    std::cout << "The price is " << result << "\n";

    double tmp;
    std::cin >> tmp;

    std::cin.get();
    return 0;
}