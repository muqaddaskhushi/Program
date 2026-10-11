#include <iostream>
using namespace std;

int main()
{
    int n;
    int roll[100], marks[100];

    // 1. Input
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter roll number of student " << i + 1 << ": ";
        cin >> roll[i];
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> marks[i];
    }

    // 2. Display all records
    cout << "\n--- Student Records ---\n";
    cout << "Roll No\tMarks\n";
    for (int i = 0; i < n; i++)
        cout << roll[i] << "\t" << marks[i] << endl;

    // 3. Highest and lowest marks
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (marks[i] > marks[maxIndex])
            maxIndex = i;
        if (marks[i] < marks[minIndex])
            minIndex = i;
    }
    cout << "\nHighest Marks: " << marks[maxIndex]
         << " (Roll No: " << roll[maxIndex] << ")" << endl;
    cout << "Lowest Marks: " << marks[minIndex]
         << " (Roll No: " << roll[minIndex] << ")" << endl;

    // 4. Selection Sort (ascending by marks)
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (marks[j] < marks[minIdx])
                minIdx = j;
        }
        int temp = marks[i];
        marks[i] = marks[minIdx];
        marks[minIdx] = temp;

        temp = roll[i];
        roll[i] = roll[minIdx];
        roll[minIdx] = temp;
    }

    cout << "\n--- Sorted Records (Ascending by Marks) ---\n";
    cout << "Roll No\tMarks\n";
    for (int i = 0; i < n; i++)
        cout << roll[i] << "\t" << marks[i] << endl;

    // 5. Binary Search
    int key;
    cout << "\nEnter marks to search: ";
    cin >> key;

    int low = 0, high = n - 1, found = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (marks[mid] == key)
        {
            found = mid;
            break;
        }
        else if (marks[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // 6. Result
    if (found != -1)
        cout << "Marks " << key << " found. Roll No: " << roll[found] << endl;
    else
        cout << "Marks " << key << " not found in the records." << endl;

    return 0;
}
