#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void exit()
{
    cout << "press enter to exit...";
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    cin.ignore();
}

int main()
{
    ios_base::sync_with_stdio(false);

    long double n = -1, x = 1;
    int seq = -1;

    // stringstream to contain a long double number as a string
    ostringstream stream;
    string res;

    // user input
    while (n < 0)
    {
        cout << "Enter a number of which you want to find the square root (>= 0): ";
        cin >> n;
    }
    while (seq < 0)
    {
        cout << "Enter the order of a sequence to which the approximation should be precise (>= 0): ";
        cin >> seq;
    }
    cout << "Do you want to see the process of approximation? (y/n): ";
    cin >> res;
    bool mode = (res == "Y" || res == "y") ? true : false;
    if (mode)
    {
        cout << "The approximation of the square root of " << n << " to the order of\n";
    }

    // approximate the square root with a sequence
    for (int i = 0; i <= seq; i++)
    {
        x = 0.5 * (x + n / x);

        // output an approximation for the every order
        if (mode)
        {
            stream << fixed << setprecision(33) << x;
            string str = stream.str();
            int pos = str.find_last_not_of('0');
            if (pos == 1)
            {
                str = str[0];
            }
            else
            {
                str = str.substr(0, pos + 1);
            }
            cout << i << ": " << str << "\n";
            stream.str("");
            stream.clear();
        }
    }

    // output an approximation for only the final order
    if (!mode)
    {
        stream << fixed << setprecision(100) << x;
        string str = stream.str();
        int pos = str.find_last_not_of('0');
        if (pos == 1)
        {
            str = str[0];
        }
        else
        {
            str = str.substr(0, pos + 1);
        }
        cout << "The approximation of the square root of " << n << " by Newton's Method (Convergency of a Sequence) is: " << str << "\n";
    }
    exit();
    return 0;
}