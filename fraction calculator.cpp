
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;
void addition(int first, int second, int third, int fourth)
{
    int lcm_value = lcm(second, fourth); // get the least common factor
    first *= lcm_value / second;         // make the two denomenator equal
    third *= lcm_value / fourth;
    int numerator = first + third;
    int denominator = lcm(second, fourth);
        cout << "= " << numerator << "/" << denominator << "\n";

}

void subtract(int first, int second, int third, int fourth)
{
    int lcm_Value = lcm(second, fourth);
    first *= lcm_Value / second; // make the two denomenator equal
    third *= lcm_Value / fourth;
    int numerator = first - third;
    int denominator = lcm(second, fourth);
    cout << "= " << numerator << "/" << denominator << "\n";
}
void division(int first, int second, int third, int fourth)
{
    int numerator = first * fourth;
    int denominator = second * third;
    int commonDivisor = gcd(numerator, denominator);
    numerator /= commonDivisor;
    denominator /= commonDivisor;
        cout << "= " << numerator << "/" << denominator << "\n";
}
void multiply(int first, int second, int third, int fourth)
{
    int numerator = first * third;
    int denominator = second * fourth;
    int commonDivisor = gcd(numerator, denominator);
    numerator /= commonDivisor;
    denominator /= commonDivisor;
        cout << "= " << numerator << "/" << denominator << "\n";
}

int main()
{
    int firstnumber, secondnumber, thirdnumber, fourthnumber;
    while (true)
    {
    cout << "welcome to fraction calculator\n";
    cout << "please enter the fraction expression\n";
    cout << "Please write your expression between double quotations, just like \"-1 * +1/3\"" << "\n";
    // The expression from the user
    string user_Expression;
    cin.ignore();
    getline(cin,user_Expression);

    // Search for any expression
    regex search1("[+\\-]\\d+/\\d+ [+\\-*\\/] [+\\-]\\d+/\\d+");
    regex search2("[+\\-]\\d+ [+\\-*\\/] [+\\-]\\d+/\\d+");
    regex search3("[+\\-]\\d+ [+\\-*\\/] [+\\-]\\d+");
    regex search4("[+\\-]\\d+/\\d+ [+\\-*\\/] [+\\-]\\d+");
    regex search5("/0");
    smatch matches;
    if (regex_search(user_Expression,matches,search5)){
        cout << "Undifined\n";
        continue;
    }
    if (regex_search(user_Expression, matches, search1) || regex_search(user_Expression, matches, search2) || regex_search(user_Expression, matches, search3) || regex_search(user_Expression, matches, search4))
    {
        regex self_regex("[+\\-]?\\d+");

        // Perform the operation based on the operator (+ or -)
        size_t plus_pos = user_Expression.find(" + ");
        size_t minus_pos = user_Expression.find(" - ");
        size_t multi_pos = user_Expression.find(" * ");
        size_t devide_pos = user_Expression.find(" / ");

        // Match size
        sregex_iterator next(user_Expression.begin(), user_Expression.end(), self_regex);
        sregex_iterator end;
        int matchCount = distance(next, end);

        if (matchCount == 4)
        { // get the each integer number from the user string
            smatch match = *next;
            firstnumber = stoi(match.str());
            match = *++next;
            secondnumber = stoi(match.str());
            match = *++next;
            thirdnumber = stoi(match.str());
            match = *++next;
            fourthnumber = stoi(match.str());

            if (plus_pos != string::npos) // if it positive so make this operation
            {
                addition(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else if (minus_pos != string::npos)
            {
                subtract(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else if (multi_pos != string::npos)
            {
                multiply(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else if (devide_pos != string::npos)
            {
                division(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else
            {
                cout << "Invalid expression format." << endl;
            }
        }
        // if the single number is in the first position
        else if (matchCount == 3 && regex_search(user_Expression, matches, search2)) // if the operation like +4 + -5/4
        {
            smatch match = *next;
            firstnumber = stoi(match.str());
            match = *++next;
            secondnumber = 1; // Assuming second number is always 1 for single fraction
            thirdnumber = stoi(match.str());
            match = *++next;
            fourthnumber = stoi(match.str());

            if (plus_pos != string::npos)
            {
                addition(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else if (minus_pos != string::npos)
            {
                subtract(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else if (multi_pos != string::npos)
            {
                multiply(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else if (devide_pos != string::npos)
            {
                division(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else
            {
                cout << "Invalid expression format." << endl;
            }
        }
        // if the single number is in the second position
        else if (matchCount == 3 && regex_search(user_Expression, matches, search4))
        { // if the operation like +4/-3 + 4
            smatch match = *next;
            firstnumber = stoi(match.str());
            match = *++next;
            secondnumber = stoi(match.str()); // Assuming second number is always 1 for single fraction
            match = *++next;
            thirdnumber = stoi(match.str());
            fourthnumber = 1;
            if (plus_pos != string::npos)
            {
                addition(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else if (minus_pos != string::npos)
            {
                subtract(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else if (multi_pos != string::npos)
            {
                multiply(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else if (devide_pos != string::npos)
            {
                division(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else
            {
                cout << "Invalid expression format." << endl;
            }
        }
        else if (matchCount == 2) // if the operation like +4 + -5
        {
            smatch match = *next;
            firstnumber = stoi(match.str());
            match = *++next;
            secondnumber = 1;
            thirdnumber = stoi(match.str());
            ;
            fourthnumber = 1;
            if (plus_pos != string::npos)
            {
                addition(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else if (minus_pos != string::npos)
            {
                subtract(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else if (multi_pos != string::npos)
            {
                multiply(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else if (devide_pos != string::npos)
            {
                division(firstnumber, secondnumber, thirdnumber, fourthnumber);
            }
            else
            {
                cout << "Invalid expression format." << endl;
            }
        }
        else
        {
            cout << "Invalid expression format." << endl;
        }
    }
    else
    {
        cout << "Wrong Expression please try again\n";
    }
    }
    return 0;
}