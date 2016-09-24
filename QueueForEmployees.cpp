#include <iostream>
using namespace std;

struct alldata {
        char* surname;
        char* speciality;
        char* dateStatement;      // the date of submission of an application
        char* dateRegExchange;    // date of registration at the labor exchange
        alldata* next;
};

struct Queue {
        int sizeQueue;
        alldata* start = nullptr;
        alldata* end = nullptr;
};

void Creation(Queue* Q)
{
        Q->start = new alldata; // allocate memory for the 1-st elemnt
        Q->start->next = nullptr;
        Q->end = Q->start;
        Q->sizeQueue = 0;
        return;
}

bool Empty(Queue* Q)
{
        if (Q->start == Q->end)
                return true;
        else
                return false;
}

void Add(Queue* Q) // to add data
{
        char* funcSurname = new char;
        char* funcSpeciality = new char;
        char* funcDateStatement = new char;
        char* funcDateRegExchange = new char;

        cout << "\nSurname > ";
        cin >> funcSurname;

        cout << "\nSpeciality > ";
        cin >> funcSpeciality;

        cout << "\nThe date of submission of an application > ";
        cin >> funcDateStatement;

        cout << "\nThe date of registration at the labor exchange > \n";
        cin >> funcDateRegExchange;

        Q->end->next = new alldata;
        Q->end = Q->end->next;

        // Adding data to the end of the queue
        Q->end->surname = funcSurname;
        Q->end->speciality = funcSpeciality;
        Q->end->dateStatement = funcDateStatement;
        Q->end->dateRegExchange = funcDateRegExchange;

        Q->end->next = nullptr;
        Q->sizeQueue++;
        cout << "\n>> The element added <<\n\n";
        return;
}

void Delete(Queue* Q) // to remove elements
{
/*
 * For remove all elements:
 *
 * alldata* temp = Q->start;
 * while (temp != nullptr) {
 *     temp = Q->start->next;
 *     delete Q->start;
 *     Q->start = temp;
 * }
 */
        Q->start = Q->start->next; // displacement of a pointer
        Q->sizeQueue--;

        delete Q->start->surname;
        delete Q->start->speciality;
        delete Q->start->dateStatement;
        delete Q->start->dateRegExchange;
        delete Q->start;
        cout << "\n>> The element removed <<\n\n";
        return;
}

void Show(Queue* Q) // to display the output
{
        alldata* temp = Q->start->next;
        while (temp != nullptr) {    // till we got to the end
                cout << "\nSurname: "
                     << temp->surname << endl;
                cout << "Speciality: "
                     << temp->speciality << endl;
                cout << "The date of submission of an application: "
                     << temp->dateStatement << endl;
                cout << "The date of registration at the labor exchange: "
                     << endl << temp->dateRegExchange << endl;
                cout << endl;
                temp = temp->next;
        }
        return;
}

int Size(Queue* Q)
{
        return Q->sizeQueue;
}

void FindClone(Queue* Q)
{
        cout << "Enter specialty, to create a list...\n";
        string YourString;
        cin >> YourString;

        alldata* temp = Q->start->next;
        while (temp != nullptr) {
                if (YourString ==
                    static_cast<string>(temp->speciality)) {
                        cout << "\nSurname: "
                             << temp->surname << endl;
                        cout << "Speciality: "
                             << temp->speciality << endl;
                        cout << "The date of submission of an application: "
                             << temp->dateStatement << endl;
                        cout << "The date of registration at the labor exchange: "
                             << endl << temp->dateRegExchange << endl;
                }
                temp = temp->next;
        }
        cout << endl;
        return;
}

void FindElement(Queue* Q)
{
        cout << "Enter surname..." << endl;

        cout << "Surname: ";
        string surname_for_FindElemnt;
        cin >> surname_for_FindElemnt;

        alldata* temp = Q->start->next;
        while (temp != nullptr) {
                if (surname_for_FindElemnt ==
                    static_cast<string>(temp->surname)) {
                        cout << "\nSurname: "
                             << temp->surname << endl;
                        cout << "Speciality: "
                             << temp->speciality << endl;
                        cout << "The date of submission of an application: "
                             << temp->dateStatement << endl;
                        cout << "The date of registration at the labor exchange: "
                             << endl << temp->dateRegExchange << endl;
                }
                temp = temp->next;
        }
        cout << endl;
        return;
}

int main(void)
{
        Queue Q;
        Creation(&Q);
        int numberOfMenu;
        do {
                cout << "1. Add a new element" << endl;
                cout << "2. Delete element" << endl;
                cout << "3. Display all the data on the screen" << endl;
                cout << "4. Display the queue size on the screen" << endl;
                cout << "5. Create a list of by speciality" << endl;
                cout << "6. Find an element by surname" << endl;
                cout << "7. Сlear the terminal window" << endl;
                cout << "0. Exit\n\n";
                cout << "[Number of menu] —> ";
                cin >> numberOfMenu;

                switch (numberOfMenu) {
                case 1:
                        Add(&Q);
                        break;

                case 2:
                        if (Empty(&Q))
                                cout << endl << ">> The queue is empty <<\n\n";
                        else
                                Delete(&Q);
                        break;

                case 3:
                        if (Empty(&Q))
                                cout << endl << ">> The queue is empty <<\n\n";
                        else
                            Show(&Q);
                        break;

                case 4:
                        if (Empty(&Q))
                                cout << endl << ">> The queue is empty <<\n\n";
                        else
                                cout << "\nThe queue size: "
                                     << Size(&Q) << "\n\n";
                        break;

                case 5:
                        if (Empty(&Q))
                                cout << endl << ">> The queue is empty <<\n\n";
                        else
                                FindClone(&Q);
                        break;

                case 6:
                        if (Empty(&Q))
                                cout << endl << ">> The queue is empty <<\n\n";
                        else
                                FindElement(&Q);
                        break;

                case 7:
                        system("clear");
                        break;

                case 0:
                        break;

                default:
                        cerr << endl << "Error: command not found\n\n";
                        break;
                }
            } while (numberOfMenu);
        return 0;
}
