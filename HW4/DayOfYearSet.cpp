#include "DayOfYearSet.hpp"

using namespace std;

namespace Set
{
    DayOfYearSet::DayOfYear::DayOfYear(int day_value, int month_value=1) /*There is default parameter for january*/
    {
        day = day_value;
        month = month_value;
        if(!validation())
        {
            cout << "month: " << month << endl << "day: " << day << endl; 
            cerr << "Invalid input\n";
            exit(1);   
        }
    }

    /*
        #This is destructor
        #It deletes memory we allocated before, after object dead.
    */
    DayOfYearSet::~DayOfYearSet()
    {
        delete[] data;
        data = nullptr;
        num_of_elements = 0;
    }
    DayOfYearSet::DayOfYear::DayOfYear()/*If there is no parameter, date is automatically 1 january*/
    {
        day = 1;
        month = 1;
    }

    DayOfYearSet::DayOfYearSet(initializer_list<DayOfYearSet::DayOfYear> list)
    {
        num_of_elements = list.size();
        int i = 0;
        data = new DayOfYear[num_of_elements];
        // iterator kullanmadan dene
        for(auto pointer = list.begin(); pointer != list.end(); pointer++)// It assign list to dynamic array by using iterator
        {
            data[i] = *pointer;
            i++;
        }
    }

    /*
        #This is copy constructor
        #It allocates memory and fill it
    */
    DayOfYearSet::DayOfYearSet(const DayOfYearSet& other)
    {
        int i;

        (*this).data = new DayOfYear[other.size()];
        for(i=0; i<other.size(); i++)
            (*this).data[i] = other.data[i];
        num_of_elements = other.size();
    }


    DayOfYearSet::DayOfYearSet()// if it is empty set
    {
        num_of_elements = 0;
        data = nullptr;
    }
    /*
        #is_duplicated takes const DayOfYear &other parameter.
        #It controls all set if there is any DayOfYear object same as we want to add
        #If there is, it returns true
        #If there is not, it returns false
    */

    bool DayOfYearSet::is_duplicated(const DayOfYear &other) const
    {
        int i;
        for(i=0; i<size(); i++)
        {
            if((other.get_day() == data[i].get_day()) && (other.get_month() == data[i].get_month()))
                return true;
        }
        return false;
    }

    /*
        #validation do not have any parameter.
        #It controls month and day value
        #If they are valid, it returns true
        #If they are not valid, it returns false
    */
    bool DayOfYearSet::DayOfYear::validation()
    {
        // Daha çok kontrol yapılır mı düşün
        
        if(month > 12 || month < 1 || day < 1)
            return false;
        else if (month == 2)
        {
            if(day > 29)
                return false;
        }
        else if(month % 2 == 1)
        {
            if(day > 31)
                return false;
        }
        else if(month % 2 == 0)
        {
            if(day > 30)
                return false;
        }
        return true;
    }

    /*
        #operator = takes const DayOfYearSet &other parameter
        #It allocates according to parameter and assign values.
        #It returns DayOfYearSet&
    */

    DayOfYearSet& DayOfYearSet::operator =(const DayOfYearSet &other)// copy assignment operator
    {
        int i;
        if (this == &other)
            return *this;
        else
        {
            delete[] (*this).data;
            (*this).data = new DayOfYear[other.size()];
            for(i=0; i<other.size(); i++)
                (*this).data[i] = other.data[i];
            num_of_elements = other.size();
        }
        return *this;
    }

    /*
        #operator + takes const DayOfYearSet &other parameter.
        #It returns union of sets.
        #First of all it assign one of sets
        #Then it assign other set but only elements which is does not exist in the new set
    */

    DayOfYearSet DayOfYearSet::operator +(const DayOfYearSet &other)
    {
        int i,j,k,number_of_non=0;
        DayOfYearSet union_set; // new set
        k=0;

        for(j=0; j<other.size(); j++)
        {
            k = 0;
            for(i=0; i<size(); i++)
            {
                /*It scan all sets*/
                if((other.data[j].get_day() != data[i].get_day()) || (other.data[j].get_month() != data[i].get_month()))
                    k += 1;
            }
            if(k == size())
            {
                number_of_non++; // It finds number of elements which is does not exist in the new set
            }
        }
        union_set.num_of_elements = size() + number_of_non;
        union_set.data = new DayOfYear[size()+number_of_non];// it allocates

        /*It assign two sets to union sets*/
        for(i=0; i<size(); i++)
        {
            union_set.data[i] = data[i];
        }
        k=i;
        for(j=0; j<other.size(); j++)
        {
            number_of_non = 0;
            for(i=0; i<size(); i++)
            {
                if((other.data[j].get_day() != data[i].get_day()) || (other.data[j].get_month() != data[i].get_month()))
                    number_of_non += 1;
            }
            if(number_of_non == size())
            {
                union_set.data[k] = other.data[j];
                k++;
            }
        }

        return union_set;
    }

    /*
        #operator == takes const DayOfYearSet &other parameter
        #If two of sets are equal it returns true
        #If two of sets are not equal it returns false

    */
    bool DayOfYearSet::operator ==(const DayOfYearSet &other)
    {
        int counter = 0, control_point1, control_point2;
        if(size() != other.size()) // if size of sets are not equal they are not same
            return false;
        for(int i=0; i<size(); i++)
        {
            control_point1 = counter;
            for(int j=0; j<other.size(); j++)
            {
                if((get_array()[i].get_day() == other.get_array()[j].get_day()) && 
                                        (get_array()[i].get_month() == other.get_array()[j].get_month()))
                {
                    counter += 1;
                }
            }
            control_point2 = counter;
            if(control_point1 == control_point2) // counter doesnt increse inner loop, it means there is not matching.
                return false;
        }
            return true;
    }

    void DayOfYearSet::print() const
    {
        for(int i=0; i<size(); i++)
        {
            cout << data[i].get_month() << ". month " << data[i].get_day() << ". day\n" ;
        }
    }

    /*
        #operator != takes const DayOfYearSet &other parameter
        #If two of sets are equal it returns true
        #If two of sets are not equal it returns false
        #It works opposite with == operator
    */
    bool DayOfYearSet::operator !=(const DayOfYearSet &other)
    {
        return (!(*this == other));
    }

    /*
        #This is for SetA + DateA type 
        #operator + takes const DayOfYear &other parameter
        #It add an element to set (if it does not duplicate)
        #It returns new set
        #If it duplicates, it does not add and return themself
    */
    DayOfYearSet DayOfYearSet::operator +(const DayOfYear &other)
    {
        int i;
        if(!is_duplicated(other))
        {
            DayOfYear *temp;
            temp = new DayOfYear[size()];
            for(i =0; i< size(); i++)
            {
                temp[i] = get_array()[i];
            }
            delete[] data;
            data = nullptr;
            data = new DayOfYear[size()+1];
            num_of_elements = size() + 1;

            for(i=0; i<size()-1; i++)
            {
                data[i] = temp[i];
            }
            data[i] = other;
            delete[] temp;
            temp = nullptr;
        }
        else
        {
            cout << "This element is already exist!\n";
        }
        return *this;
    }

    void DayOfYearSet::DayOfYear::print()const
    {
        cout << "day ->" << get_day() << " month->" << get_month() << endl;
    }

    /*
        #This is for DateA + SetA type
        #operator + takes cDayOfYearSet &set parameter
        #It add an element to set (if it does not duplicate)
        #It returns new set
        #If it duplicates, it does not add and return themself
    */
    DayOfYearSet DayOfYearSet::DayOfYear::operator +(DayOfYearSet &set)
    {
        int i;
        if(!set.is_duplicated(*this))
        {
            DayOfYear *temp;
            temp = new DayOfYear[set.size()];
            for(i =0; i< set.size(); i++)
            {
                temp[i] = set.get_array()[i];
            }
            delete[] set.data;
            set.data = nullptr;
            set.data = new DayOfYear[set.size()+1];
            set.num_of_elements = set.size() + 1;

            for(i=0; i<set.size()-1; i++)
            {
                set.data[i] = temp[i];
            }
            set.data[i] = *this;
            delete[] temp;
            temp = nullptr;
        }
        else
        {
            cout << "This element is already exist!\n";
        }
        return set;
    }

    /*
        #operator - takes const DayOfYearSet &other parameter
        #It finds the number of different elements and allocate place
        #Then it assign different elements to the new set and returns it.
    */
    DayOfYearSet DayOfYearSet::operator -(const DayOfYearSet &other)
    {
        int i,j,k=0, number_of_non=0;
        DayOfYearSet set;
        
        for(i=0; i<size(); i++)
        {
            number_of_non = 0;
            for(j=0; j<other.size(); j++)
            {
                // It scans all set
                if((get_array()[i].get_day() != other.get_array()[j].get_day()) || (get_array()[i].get_month() != other.get_array()[j].get_month()))
                    number_of_non += 1;
            }
            if(number_of_non == other.size())
            {
                k += 1; // It find number of different elements of set
            }
        }

        set.num_of_elements = k;
        if (*this != other)
            set.data = new DayOfYear[k];

        k=0;
        for(i=0; i<size(); i++)
        {
            number_of_non = 0;
            for(j=0; j<other.size(); j++)
            {
                if((get_array()[i].get_day() != other.get_array()[j].get_day()) || (get_array()[i].get_month() != other.get_array()[j].get_month()))
                    number_of_non += 1;
            }
            /*It finds different elements and assign*/
            if(number_of_non == other.size())
            {
                set.data[k] = get_array()[i];
                k += 1;
            }
        }
        return set;
    }

    /*
        #remove takes const DayOfYear &other paremeter
        #It finds the index of element that we want to erase
        #And then it assign a new array without element that we want to erase
    */
    void DayOfYearSet::remove(const DayOfYear &other)
    {
        int i, k=0, j;
        DayOfYear *temp1;
        DayOfYear *temp2;
        
        i=0;
        // It finds the index 
        while((get_array()[i].get_day() != other.get_day()) || (get_array()[i].get_month() != other.get_month())) // buradaki yada ya bakkkk and yapmıştım başta
        {
            i++; // index
        }

        temp1 = new DayOfYear[i];
        for (j = 0; j< i; j++)// It assign until index
        {
            temp1[j] = get_array()[j];
        }

        temp2 = new DayOfYear[size()-i-1];
        for (j = i+1; j<size(); j++)// It assign after index
        {
            temp2[k] = get_array()[j];
            k++;
        }
        delete[] data;
        data = nullptr;
        data = new DayOfYear[size()-1];
        num_of_elements = size() - 1;

        k=0;

        for(j=0; j<size(); j++)// It assign again sets
        {
            if(j<i)// buna bak i == 0 için
            {
                data[j] = temp1[j];
            }
            else
            {
                data[j] = temp2[k];
                k++;
            }
        }
        delete[] temp1;
        temp1 = nullptr;
        delete[] temp2;
        temp2 = nullptr;
    }

    /*
        #operator ^ takes const DayOfYearSet &other parameter
        #It finds same elements and assign new set.
        #It return dayofyearset set
    */
    DayOfYearSet DayOfYearSet::operator ^(const DayOfYearSet &other)
    {
        int j,k=0, number_of_intersection=0;
        DayOfYearSet set;
        decltype(number_of_intersection) i;
        for(i=0; i<size(); i++)
        {
            for(j=0; j<other.size(); j++)
            {
                if((get_array()[i].get_day() == other.get_array()[j].get_day()) && (get_array()[i].get_month() == other.get_array()[j].get_month()))
                {
                    number_of_intersection += 1;// It finds number of intersection
                    break;
                }
            }
        }
        set.num_of_elements = number_of_intersection;
        set.data = new DayOfYear[number_of_intersection];
        for(i=0; i<size(); i++)
        {
            for(j=0; j<other.size(); j++)
            {
                if((get_array()[i].get_day() == other.get_array()[j].get_day()) && (get_array()[i].get_month() == other.get_array()[j].get_month()))
                {
                    // If elements are same it assign it new set
                    set.data[k] = get_array()[i];
                    k++;
                    break;
                }
            }
        }
        return set;
    }

    /*
        #operator - takes const DayOfYear &other paremeter
        #It finds the index of element that we want to erase
        #And then it assign a new array without element that we want to erase
        #It return themself
    */
    DayOfYearSet DayOfYearSet::operator -(const DayOfYear &other)
    {
        int index=0,i;
        decltype(index) k;
        DayOfYear *temp1, *temp2;
        while((data[index].get_day() != other.get_day()) || (data[index].get_month() != other.get_month()))
            index++;// It finds index
        temp1 = new DayOfYear[index];
        for(i=0; i<index; i++)
        {
            temp1[i] = data[i];// It assign until index
        }

        temp2 = new DayOfYear[size() - index - 1];
        for(i=index+1, k=0; i<size(); i++, k++)
        {
            temp2[k] = data[i];// It assign after index
        }
        num_of_elements = size() - 1;

        delete[] data;
        data = nullptr;
        data = new DayOfYear[num_of_elements];

        k=0;
        for(i=0; i<size(); i++)// It assigns temp arrays to set again
        {
            if(i<index)
                data[i] = temp1[i];
            else
            {
                data[i] = temp2[k];
                k++;
            }
        }
        delete[] temp1;
        temp1 = nullptr;
        delete[] temp2;
        temp2 = nullptr;

        return *this;
    }

    /*
        #operator << takes ostream& outs, const DayOfYearSet& set parameters
        #It print detail about sets
        #It return outs
    */
    ostream& operator <<(ostream& outs, const DayOfYearSet& set)
    {
        int i;
        outs << "Number of elements of sets is: " << set.size() << endl;
        if(set.size() == 0)
            outs << "This set is empty set\n";
        for(i=0; i<set.size(); i++)
            outs << i+1 << ". element of set: " << "day->" << set.get_array()[i].get_day() << " " << "month->" << set.get_array()[i].get_month()<<endl;
        return outs;    
    }

    /*
        #operator []takes int index parameter
        #It returns DayOfYear object in index
        #It is for non const objects
        #If index out of range it exit
    */
    DayOfYearSet::DayOfYear& DayOfYearSet::operator [](int index)
    {
        if(index < size() && index > 0)// It controls index
            return data[index];
        else
        {
            cerr << "Index exceed\n";
            exit(1);
        }
    }

    /*
        #operator []takes int index parameter
        #It returns DayOfYear object in index
        #It is for const objects
        #If index out of range it exit
    */
    const DayOfYearSet::DayOfYear& DayOfYearSet::operator [](int index) const
    {
        if(index < size() && index > 0)// It controls index
            return data[index];
        else
        {
            cerr << "Index exceed\n";
            exit(1);
        }
    }
    /*
        #operator ! does not take parameter.
        #It controls sets and find missing elements
        #It assign elements to new set and returns set.
    */
    DayOfYearSet DayOfYearSet::operator !()
    {
        DayOfYearSet set;
        int i, j, l, counter=0, num=0;
        decltype(i) k;  
        for(i=1; i<=12; i++)//months
        {
            for(j=1; j<=31; j++)//days
            {
                if(i==2)// for February
                {
                    if(j<=29)// for February
                    {
                        counter = 0;
                        for(k=0; k<size(); k++)
                        {
                            /*It controls if there is an object which contains months and days*/
                            if((data[k].get_day() == j) && (data[k].get_month() == i))
                                counter++;
                        }
                        if(counter == 0)// if counter 0 it means there is no matching and it adds new element to set
                        {
                            num += 1;
                            set + DayOfYear(j,i);
                        }
                    }
                }
                else if(i%2 == 0)//for even months
                {
                    if(j <= 30)
                    {
                        counter = 0;
                        for(k=0; k<size(); k++)
                        {
                            /*It controls if there is an object which contains months and days*/
                            if((data[k].get_day() == j) && (data[k].get_month() == i))
                                counter++;
                        }
                        if(counter == 0)// if counter 0 it means there is no matching and it adds new element to set
                        {
                            num += 1;
                            set + DayOfYear(j,i);
                        }
                    }
                }
                else if(i%2 == 1)// for odd months
                {
                    if(j <= 31)
                    {
                        counter = 0;
                        for(k=0; k<size(); k++)
                        {
                            /*It controls if there is an object which contains months and days*/
                            if((data[k].get_day() == j) && (data[k].get_month() == i))
                                counter++;
                        }
                        if(counter == 0)// if counter 0 it means there is no matching and it adds new element to set
                        {
                            num += 1;
                            set + DayOfYear(j,i);
                        }
                    }
                }
            }
        }
        set.num_of_elements = num;
        return set;
    }
}