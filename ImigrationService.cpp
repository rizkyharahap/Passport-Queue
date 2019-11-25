#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <time.h>

using namespace std;

struct date
{
    int date,
        month,
        year;
};

struct passport_queue
{
    int no;
    string typeQueue;
};

struct passport_data
{
    string passportNo;
    char name[50];
    char nationality[30];
    date dateOfBirth;
    date dateOfIssue;
    date dateOfExpiry;
    char issuingOffice[30];
    string status;
};

struct queue_apply
{
    passport_queue info;
    queue_apply *next;
};
queue_apply *frontApply, *endApply;

struct queue_collect
{
    passport_queue info;
    queue_collect *next;
};
queue_collect *frontCollect, *endCollect;

struct node
{
    passport_data info;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;

string random(int len)
{
    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string r;
    srand(time(NULL));
    for (int i = 0; i < len; i++)
        r.push_back(a.at(size_t(rand() % 36)));
    return r;
}

void createQueue()
{
    queue_apply *newQueuApply;
    frontApply = NULL;
    endApply = frontApply;
    queue_collect *newQueueCollect;
    frontCollect = NULL;
    endCollect = frontCollect;
}

void inputQueue(passport_queue newData, string typeService)
{
    if (typeService == "A")
    {
        queue_apply *NQA;
        NQA = (queue_apply *)malloc(sizeof(queue_apply));
        NQA->info = newData;

        if (frontApply == NULL)
        {
            frontApply = NQA;
            endApply = NQA;
        }
        else
        {
            endApply->next = NQA;
            endApply = NQA;
            endApply->next = NULL;
        }

        cout << "\n\tPASSPORT APPLICATION\n";
        cout << "\n\t" << NQA->info.typeQueue << NQA->info.no << endl;
    }
    else if (typeService == "C")
    {
        queue_collect *NQC;
        NQC = (queue_collect *)malloc(sizeof(queue_collect));
        NQC->info = newData;

        if (frontCollect == NULL)
        {
            frontCollect = NQC;
            endCollect = NQC;
        }
        else
        {
            endCollect->next = NQC;
            endCollect = NQC;
            endCollect->next = NULL;
        }

        cout << "\n\tPASSPORT COLLECTION\n";
        cout << "\n\t" << NQC->info.typeQueue << NQC->info.no << endl;
    }
}

void displayQueue(string typeService)
{
    if (typeService == "A")
    {
        queue_apply *HQA;
        HQA = frontApply;
        if (frontApply == NULL)
        {
            cout << "\n\tQueue is empty !\n";
        }
        else
        {
            cout << "\n\tPASSPORT APPLICATION QUEUE\n";
            cout << "\n\tNUMBER\t   SERVICE";

            while (HQA != NULL)
            {
                cout << "\n\t" << HQA->info.no << HQA->info.typeQueue;
                cout << "\t APPLICATION";
                HQA = HQA->next;
            }
        }
    }
    else if (typeService == "C")
    {
        queue_collect *HQC;
        HQC = frontCollect;
        if (frontCollect == NULL)
        {
            cout << "\n\tQueue is empty !\n";
        }
        else
        {
            cout << "\n\tPASSPORT COLLECTION QUEUE\n";
            cout << "\n\tNUMBER\t   SERVICE";

            while (HQC != NULL)
            {
                cout << "\n\t" << HQC->info.no << HQC->info.typeQueue;
                cout << "\t COLLECTION";
                HQC = HQC->next;
            }
        }
    }
}

void insert(passport_data newdata)
{
    struct node *ND = (struct node *)malloc(sizeof(struct node));
    ND->info = newdata;
    ND->prev = NULL;
    ND->next = head;
    if (head != NULL)
        head->prev = ND;
    head = ND;

    cout << "\n\tApplication data has entered !\n";
}

void display()
{
    node *DN;
    DN = head;

    if (head == NULL)
    {
        cout << "\tData not found !\n";
        return;
    }

    cout << "\n\t\t\t PASSPORT APPLICATION DATA\n";
    cout << "\n\t| Passport No\t|\t  Name\t\t|\tNationality\t| Date of Birth | Date of Issue | Date of Expire |   Status\t|\n";
    while (DN != NULL)
    {
        cout << "\t|   "
             << DN->info.passportNo << "\t| "
             << DN->info.name << "\t|\t"
             << DN->info.nationality << "\t|    "
             << DN->info.dateOfBirth.date << "/" << DN->info.dateOfBirth.month << "/" << DN->info.dateOfBirth.year << "   |    "
             << DN->info.dateOfIssue.date << "/" << DN->info.dateOfIssue.month << "/" << DN->info.dateOfIssue.year << "   |    "
             << DN->info.dateOfExpiry.date << "/" << DN->info.dateOfExpiry.month << "/" << DN->info.dateOfExpiry.year << "   |    "
             << DN->info.status << "\t|\n";
        DN = DN->next;
    }
}

void update(string key)
{
    if (head == NULL)
    {
        cout << "\tData not found !\n";
        return;
    }

    node *UN;
    UN = head;
    bool found = false;

    while (UN != NULL)
    {
        if (UN->info.passportNo == key)
        {
            found = true;
            break;
        }

        UN = UN->next;
    }

    if (found)
    {
        if (UN->info.status == "Collected")
        {
            cout << "\n\tPassport has collected\n";
        }
        else
        {
            UN->info.status = "Collected";

            cout << "\n\t+--------------------------------------------------------+\n\n";
            cout << "\t\t\t REPUBLIC OF INDONESIA\n\n";
            cout << "\tPASSPORT NO.\n";
            cout << "\t" << UN->info.passportNo << "\n\n";
            cout << "\tFULL NAME\n";
            cout << "\t" << UN->info.name << "\n\n";
            cout << "\tNATIONALITY\n";
            cout << "\t" << UN->info.nationality << "\n\n";
            cout << "\tDATE OF BIRTH\n";
            cout << "\t" << UN->info.dateOfBirth.date << "/" << UN->info.dateOfBirth.month << "/" << UN->info.dateOfBirth.year << "\n\n";
            cout << "\tDATE OF ISSUE\t\t\tDATE OF EXPIRY\n";
            cout << "\t" << UN->info.dateOfIssue.date << "/" << UN->info.dateOfIssue.month << "/" << UN->info.dateOfIssue.year << "\t\t\t"
                 << UN->info.dateOfExpiry.date << "/" << UN->info.dateOfExpiry.month << "/" << UN->info.dateOfExpiry.year << "\n\n";
            cout << "\tISSUING OFFICE\n";
            cout << "\t" << UN->info.issuingOffice << "\n\n";
            cout << "\t+--------------------------------------------------------+\n\n";
        }
    }
    else
    {
        cout << "\n\tData not found !\n";
    }
}

void passportApplication()
{
    cin.ignore();
    passport_data dataPassport;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    cout << "\n\t\tPASSPORT APPLICATION\n\n";
    cout << "\tName          : ";
    cin.getline(dataPassport.name, 50);
    cout << "\tNationality   : ";
    cin.getline(dataPassport.nationality, 30);
    cout << "\tDate Of Birth : ";
    cout << "\n\t\tDate  : ";
    cin >> dataPassport.dateOfBirth.date;
    cout << "\t\tMonth : ";
    cin >> dataPassport.dateOfBirth.month;
    cout << "\t\tYear  : ";
    cin >> dataPassport.dateOfBirth.year;
    cin.ignore();
    cout << "\tIssuing Office : ";
    cin.getline(dataPassport.issuingOffice, 30);

    dataPassport.passportNo = random(5);
    dataPassport.dateOfIssue.date = ltm->tm_mday;
    dataPassport.dateOfIssue.month = 1 + ltm->tm_mon;
    dataPassport.dateOfIssue.year = 1900 + ltm->tm_year;
    dataPassport.dateOfExpiry.date = dataPassport.dateOfIssue.date;
    dataPassport.dateOfExpiry.month = dataPassport.dateOfIssue.month;
    dataPassport.dateOfExpiry.year = 5 + dataPassport.dateOfIssue.year;
    dataPassport.status = "In Progress";

    insert(dataPassport);
}

void passportCollection()
{
    display();

    string keyNo;

    cout << "\n\t\t\t PASSPORT COLLECTION\n";
    cout << "\n\tInsert Passport Number : ";
    cin >> keyNo;

    update(keyNo);
}

void deleteQueue(string typeService)
{
    if (typeService == "A")
    {
        queue_apply *DQA;

        system("CLS");
        if (frontApply == NULL)
        {
            cout << "\n\tQueue is empty !\n";
        }
        else
        {
            DQA = frontApply;
            frontApply = DQA->next;

            cout << "\n\tPASSPORT APPLICATION\n";
            cout << "\n\t\t" << DQA->info.typeQueue << DQA->info.no << endl;

            free(DQA);

            cout << "\n\n";
            system("PAUSE");
            system("CLS");
            passportApplication();
        }
    }
    else if (typeService == "C")
    {
        queue_collect *DQC;

        system("CLS");
        if (frontCollect == NULL)
        {
            cout << "\n\tQueue is empty !\n";
        }
        else
        {
            DQC = frontCollect;
            frontCollect = DQC->next;

            cout << "\n\tPASSPORT APPLICATION\n";
            cout << "\n\t\t" << DQC->info.typeQueue << DQC->info.no << endl;

            free(DQC);

            cout << "\n\n";
            system("PAUSE");
            system("CLS");
            passportCollection();
        }
    }
}

void passportQueue(string typeOfService)
{
    // push the elements of stack
    passport_queue tmp;
    int menu = 1;
    int queue_apply = 1;
    int queue_collect = 1;

    system("CLS");
    for (;;)
    {
        if (typeOfService == "A")
        {
            cout << "\n\t\tPASSPORT APPLICATION SERVICE\n";
        }
        else if (typeOfService == "C")
        {
            cout << "\n\t\tPASSPORT COLLECTION SERVICE\n";
        }

        cout << "\t1.List Queue\n";
        cout << "\t2.Customer Entered\n";
        cout << "\t3.Customer Calling\n";
        cout << "\t4.Exit\n";
        cout << "\tChoose : ";

        cin >> menu;

        switch (menu)
        {
        case 1:
            displayQueue(typeOfService);
            break;

        case 2:
            if (typeOfService == "A")
            {
                tmp.no = queue_apply;
                tmp.typeQueue = typeOfService;
                queue_apply++;
                inputQueue(tmp, typeOfService);
            }
            else if (typeOfService == "C")
            {
                tmp.no = queue_collect;
                tmp.typeQueue = typeOfService;
                queue_collect++;
                inputQueue(tmp, typeOfService);
            }
            break;
        case 3:
            deleteQueue(typeOfService);
            break;

        case 4:
            return;
            break;

        default:
            cout << "\tMenu's not found !";
            break;
        }

        cout << "\n\n";
        system("PAUSE");
        system("CLS");
    }
}

int main()
{
    // push the elements of stack
    createQueue();
    int menu = 1;

    for (;;)
    {
        cout << "\n\t\tIMMIGRATION OFFICE SERVICE\n\n";
        cout << "\t1.Passport Application\n";
        cout << "\t2.Passport Collection\n";
        cout << "\t3.Data Service\n";
        cout << "\t4.Exit\n";
        cout << "\tChoose : ";

        cin >> menu;

        switch (menu)
        {
        case 1:
            passportQueue("A");
            break;

        case 2:
            passportQueue("C");
            break;

        case 3:
            display();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout << "\tMenu's not found !";
            break;
        }

        cout << "\n\n";
        system("PAUSE");
        system("CLS");
    }
}
