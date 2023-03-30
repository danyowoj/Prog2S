#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct dormitory
{
    string faculty;
    int number;
    float square;
    int quantity;
};

void in(dormitory *mas, int n)
{
    printf("\nEnter information about rooms in dormitory:\n");
    for (int i = 0; i < n; i++)
    {
        cout << "\nName of faculty: ";
        cin >> mas[i].faculty;
        cout << "Number of room: ";
        cin >> mas[i].number;
        cout << "Square of room: ";
        cin >> mas[i].square;
        cout << "Quantity of people: ";
        cin >> mas[i].quantity;
    }
}

void out(dormitory *mas, int n, vector<string> facul)
{
    for (int i = 0; i < facul.size(); i++)
    {
        int room_num = 0;     // variable for counting the number of rooms of one faculty
        int students = 0;     // variable for counting the number of students of one faculty
        float sum_square = 0; // variable for counting the sum of square of rooms
        for (int j = 0; j < n; j++)
        {
            if (mas[j].faculty == facul[i])
            {
                room_num++;
                students += mas[j].quantity;
                sum_square += mas[j].square;
            }
        }
        float square_per_student = float(sum_square / students); // variable for calculating the average area per student
        cout << "\nFaculty: " << facul[i] << endl;
        cout << "Room number: " << room_num << endl;
        cout << "Quantity of students: " << students << endl;
        cout << "Square of room per student: " << square_per_student << endl;
    }
}

int main()
{
    int n;
    cout << "\nEnter quantity of rooms in dormitory: ";
    cin >> n;
    dormitory *mas = new dormitory[n];

    in(mas, n);

    vector<string> facul; // Vector of faculties for further information output

    bool find; // repeating faculty test variable
    for (int i = 0; i < n; i++)
    {
        find = false;
        for (int j = 0; j < facul.size(); j++) // facul.size() - vector size
        {
            if (facul[j] == mas[i].faculty) // repetitive faculty check
                find = true;
        }
        if (find == false)
            facul.push_back(mas[i].faculty); // facul.push_back() - filling the vector (adding an element to the end of the vector)
    }

    out(mas, n, facul);

    return 0;
}