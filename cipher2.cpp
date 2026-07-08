#include <iostream>
using namespace std;

#define MAX 100

char queueArr[MAX];
int front = -1, rear = -1;

void enqueue(char value)
{
    if (rear == MAX - 1)
        cout << "Queue Overflow\n";
    else
    {
        if (front == -1)
            front = 0;
        queueArr[++rear] = value;
    }
}

char dequeue()
{
    if (front == -1)
    {
        cout << "Queue Underflow\n";
        return '\0';
    }

    char value = queueArr[front];

    if (front == rear)
        front = rear = -1;
    else
        front++;

    return value;
}


struct Node {
    char data;
    Node* next;
};

Node* createList(char text[])
{
    Node *head = NULL, *temp = NULL;

    for (int i = 0; text[i] != '\0'; i++)
    {
        Node* newNode = new Node;
        newNode->data = text[i];
        newNode->next = NULL;

        if (head == NULL)
            head = temp = newNode;
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

void display(Node* head)
{
    while (head)
    {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

Node* copyList(Node* head)
{
    Node *newHead = NULL, *temp = NULL;

    while (head)
    {
        Node* newNode = new Node;
        newNode->data = head->data;
        newNode->next = NULL;

        if (!newHead)
            newHead = temp = newNode;
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
        head = head->next;
    }
    return newHead;
}

void deleteList(Node* head)
{
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


struct StackNode {
    Node* state;
    StackNode* next;
};

StackNode* top = NULL;

void pushState(Node* head)
{
    Node* copy = copyList(head);

    StackNode* newNode = new StackNode;
    newNode->state = copy;
    newNode->next = top;
    top = newNode;
}

Node* popState()
{
    if (!top)
    {
        cout << "No Undo Available!\n";
        return NULL;
    }

    StackNode* temp = top;
    Node* prev = temp->state;

    top = top->next;
    delete temp;

    return prev;
}

Node* undo(Node* head)
{
    Node* prev = popState();

    if (prev)
    {
        deleteList(head);
        return prev;
    }
    return head;
}


void encode(Node* head, int shift)
{
    shift %= 95;

    while (head)
    {
        if (head->data >= 32 && head->data <= 126)
            head->data = ((head->data - 32 + shift) % 95) + 32;

        head = head->next;
    }
}


void decode(Node* head, int shift)
{
    shift %= 95;
    front = rear = -1;

    Node* temp = head;

    while (temp)
    {
        enqueue(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp)
    {
        char ch = dequeue();

        if (ch >= 32 && ch <= 126)
            ch = ((ch - 32 - shift + 95) % 95) + 32;

        temp->data = ch;
        temp = temp->next;
    }
}



void bubbleSort(string arr[] , int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}



void bruteForce(Node* head)
{
    string results[95];
    int count = 0;

    for(int shift = 1 ; shift <= 95 ; shift++)
    {
        Node* temp = copyList(head);

        decode(temp , shift);

        string output = "";
        Node* p = temp;

        while(p)
        {
            output += p->data;
            p = p->next;
        }

        results[count++] = output;

        deleteList(temp);
    }

    bubbleSort(results , count);

    cout << "\nBrute Force Results\n";

    for(int i=0;i<count;i++)
    {
        cout << i+1 << " : " << results[i] << endl;
    }
}


int main()
{
    int choice;
    char text[100];
    int shift;
    char ch;

    do {
        cout << "\n=====================================\n";
        cout << "|          CAESAR CIPHER TOOL 	    |\n";
        cout << "=====================================\n";
        cout << "| 1. Encode                         |\n";
        cout << "| 2. Decode                         |\n";
        cout << "| 3. Brute Force Attack             |\n";
        cout << "| 4. Exit                           |\n";
        cout << "=====================================\n";

        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                do {
                    cout << "----Encoding----\n";

                    cout << "Enter text: ";
                    cin.getline(text, 100);

                    Node* head = createList(text);
                    pushState(head);

                    cout << "Enter shift: ";
                    cin >> shift;

                    encode(head, shift);

                    cout << "\nEncoded Text: ";
                    display(head);

                    cout << "\nUndo [y/n]: ";
                    cin >> ch;
                    cin.ignore();

                    if (ch == 'y' || ch == 'Y') {
                        head = undo(head);
                        cout << "After Undo: ";
                        display(head);
                    }

                    deleteList(head);

                    cout << "\nContinue Encoding? [y/n]: ";
                    cin >> ch;
                    cin.ignore();

                } while (ch == 'y' || ch == 'Y');
                break;

            case 2:
                do {
                    cout << "----Decoding----\n";

                    cout << "Enter text: ";
                    cin.getline(text, 100);

                    Node* head = createList(text);
                    pushState(head);

                    cout << "Enter shift: ";
                    cin >> shift;

                    decode(head, shift);

                    cout << "\nDecoded Text: ";
                    display(head);

                    cout << "\nUndo [y/n]: ";
                    cin >> ch;
                    cin.ignore();

                    if (ch == 'y' || ch == 'Y') {
                        head = undo(head);
                        cout << "After Undo: ";
                        display(head);
                    }

                    deleteList(head);

                    cout << "\nContinue Decoding? [y/n]: ";
                    cin >> ch;
                    cin.ignore();

                } while (ch == 'y' || ch == 'Y');
                break;

            case 3:
                cout << "Enter text: ";
                cin.getline(text, 100);

                {
                    Node* head = createList(text);
                    bruteForce(head);
                    deleteList(head);
                }
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
