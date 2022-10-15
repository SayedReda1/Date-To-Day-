#include <iostream>
#include <string>
#include <sstream>

// do it again but with struct
class Doomsday
{
private:
    std::string days[7] = {"saturday", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday"};
    std::string century_doomsday[6] = {"tuesday", "sunday", "friday", "wednesday"};
    int month_doom[12] = {31, 28, 14, 4, 9, 6, 11, 8, 5, 10, 7, 12};

    int m_day, m_month, m_year;

    // will return the index of dooms day in days array
    int year()
    {
        int yr_tens = m_year%100;
        int yr_thousands = (m_year - yr_tens)/100;
        int add_to_doomyear = (int(yr_tens/4)+yr_tens) % 7;

        // declaring the doom of century
        int doom_century_index = yr_thousands < 5 ? yr_thousands-1 : (yr_thousands%4);
        std::string century_doom = century_doomsday[doom_century_index];

        // adding century dooms with yr tens operations
        int final_doom_index = 0;
        for (int i=0; i<7; i++)
            if (days[i] == century_doom)
                final_doom_index += (add_to_doomyear + i)%7;
        return final_doom_index;
    }
    // Calculating the part related to day and month
    int day_index()
    {
        int diff = abs(m_day - month_doom[m_month-1]) % 7;
        int index;
        if (month_doom[m_month-1] > m_day)
            index = (year() - diff) < 0 ? (year() - diff + 7) : (year() - diff);
        else
            index = (year() + diff) % 7;
        
        return index;
    }
public:
    Doomsday(int day, int month, int year)
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }

    void PrinResult() {std::cout << "It's " << days[day_index()] << std::endl;}
};

int main()
{
    int input[3];
    std::cout << "Type the date as [dd mm y]\n";
    scanf("%d %d %d", &input[0], &input[1], &input[2]);

    Doomsday d(input[0], input[1], input[2]);
    d.PrinResult();      // printing result
}
