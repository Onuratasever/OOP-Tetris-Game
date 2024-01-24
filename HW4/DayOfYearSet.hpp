#ifndef DAYOFYEARSET_HPP
#define DAYOFYEARSET_HPP

#include <iostream>
#include <initializer_list>

using namespace std;

namespace Set
{
    class DayOfYearSet
    {
        public:

            class DayOfYear
            {
                public:
                    DayOfYear(int day_value, int month_value);
                    DayOfYear();
                    void print()const;
                    const int get_day()const{return day;};
                    const int get_month()const{return month;};
                    DayOfYearSet operator +(DayOfYearSet &set);

                private:
                    int day;
                    int month;
                    bool validation();
            };

            DayOfYearSet(initializer_list<DayOfYear> list);
            DayOfYearSet();
            DayOfYearSet(const DayOfYearSet& other);
            ~DayOfYearSet();

            bool operator ==(const DayOfYearSet &other);
            bool operator !=(const DayOfYearSet &other);
            DayOfYearSet operator +(const DayOfYear &other);
            DayOfYearSet operator +(const DayOfYearSet &other);
            DayOfYearSet operator -(const DayOfYearSet &other);
            DayOfYearSet operator ^(const DayOfYearSet &other);
            DayOfYearSet operator -(const DayOfYear &other);
            DayOfYearSet& operator =(const DayOfYearSet &other);
            DayOfYearSet operator !();
            DayOfYearSet::DayOfYear& operator [](int index);
            const DayOfYearSet::DayOfYear& operator [](int index) const;
            friend ostream& operator <<(ostream& outs, const DayOfYearSet& set); 

            DayOfYear *get_array()const{return data;};
            DayOfYear *get_array(){return data;};
            const int size()const{return num_of_elements;};
            void remove(const DayOfYear &other);
            void print() const;
            bool is_duplicated(const DayOfYear &other) const;
        private:
            DayOfYear *data;
            int num_of_elements;
    };
}
#endif