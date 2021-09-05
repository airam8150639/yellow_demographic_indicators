#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*enum class Gender {
	FEMALE,
	MALE
};

struct Person {
	int age;            // возраст
	Gender gender;      // пол
	bool is_employed;   // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    vector<typename InputIt::value_type> range_copy(range_begin, range_end);
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
        begin(range_copy), middle, end(range_copy),
        [](const Person& lhs, const Person& rhs) {
            return lhs.age < rhs.age;
        }
    );
    return middle->age;
}*/

void PrintStats(vector<Person> persons) {
    // All people
    cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;

    // Male and female people
    sort(persons.begin(), persons.end(), [](const auto& a, const auto& b)
        {
            if (a.gender == Gender::FEMALE && b.gender == Gender::MALE) return true;
            else return false;
        }
    );

    auto it_gender = find_if(persons.begin(), persons.end(), [](const auto& a) {
            return (a.gender == Gender::MALE);
        }
    );

    cout << "Median age for females = " << ComputeMedianAge(persons.begin(), it_gender) << endl;
    cout << "Median age for males = " << ComputeMedianAge(it_gender, persons.end()) << endl;

    //Unemployed and employed

    sort(persons.begin(), it_gender, [](const auto& a, const auto& b)
        {
            if (a.is_employed && !b.is_employed) return true;
            else return false;
        }
    );

    sort(it_gender, persons.end(), [](const auto& a, const auto& b)
        {
            if (a.is_employed && !b.is_employed) return true;
            else return false;
        }
    );

    auto it_fem_empl = find_if(persons.begin(), it_gender, [](const auto& a) {
        return (a.is_employed == false);
        }
    );

    auto it_mal_empl = find_if(it_gender, persons.end(), [](const auto& a) {
        return (a.is_employed == false);
        }
    );

    cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), it_fem_empl) << endl;
    cout << "Median age for unemployed females = " << ComputeMedianAge(it_fem_empl, it_gender) << endl;
    cout << "Median age for employed males = " << ComputeMedianAge(it_gender, it_mal_empl) << endl;
    cout << "Median age for unemployed males = " << ComputeMedianAge(it_mal_empl, persons.end()) << endl;

}

/*int main() {
    vector<Person> persons = {
        {31, Gender::MALE, false},
        {40, Gender::FEMALE, true},
        {24, Gender::MALE, true},
        {20, Gender::FEMALE, true},
        {80, Gender::FEMALE, false},
        {78, Gender::MALE, false},
        {10, Gender::FEMALE, false},
        {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}*/