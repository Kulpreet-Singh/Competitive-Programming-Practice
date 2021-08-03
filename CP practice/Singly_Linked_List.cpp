#include <iostream>

int size = 0;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void Insert(int data, int index) {
    ++size;
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;

    if (index == 0 || (index == -1 && size <= 1)) {
        temp->next = head;
        head = temp;
        return;
    }

    if (index == -1) {
        Node* tempDash = head;
        while (tempDash->next != NULL) {
            tempDash = tempDash->next;
        }
        temp->next = tempDash->next;
        tempDash->next = temp;
        return;
    }

    if (index > size) {
        --size;
        std::cout << "Insertion not possible! Try a value <= " << size+1 << std::endl;
    } else {
        Node* tempDash = head;
        for (int i = 0; i < index - 2; ++i)
        {
            tempDash = tempDash->next;
        }
        temp->next = tempDash->next;
        tempDash->next = temp;
    }
}

int Search(int data) {
 
    if (head == NULL) {
        return -1;
    }

    Node* temp = head;
    int i = 0;

    while (temp != NULL)
    {
        if (temp->data == data) {
            return i+1;
        }
        ++i;
        temp = temp->next;
    }
    return -1;
}

void Delete(int data, int index) {

    if (size <= 0 || index > size){
        std::cout << "Linked List is empty!/Invalid Index!" << std::endl;
        return;
    }

    if (data == -1) {
        Node* temp = head;
        if (index <= 1)
        {
            head = temp->next;
            delete(temp);
            --size;
            return;
        }
        for (int i = 0; i < index-2; ++i) {
            temp = temp->next;
        }
        Node* tempDash = temp->next; // index-1
        temp->next = tempDash->next;
        delete(tempDash);
        --size;
    }
    else {
        int pos = Search(data);
        if (pos == -1) {
            std::cout << "Number not found, hence can't be deleted." << std::endl;
        }
        else {
            Delete(-1, pos);
        }
    }
}

void Print() {
    Node* temp = head;
    std::cout << "\nThe linked list:" << std::endl;

    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

void Reverse() {
    if (size <= 1) {
        return;
    }
    Node* prev = NULL, * curr = head, * nxt;
    //iterative method
    while (curr != NULL) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;

    //recursive method
    /*
    void Reverse (Node* temp) {
        if (temp->next == NULL) {
            head = temp;
            return;
        }
        Reverse(temp->next);
        Node* tempDash = temp->next;
        tempDash->next = temp;
        temp->next = NULL;
    }
    */
}

int main() {
    int i = 0, data, index, rNum, branch;

    while (i != 6) {
        std::cout << "Operations:\n1.Insert\n2.Delete\n3.Search\n4.Print\n5.Reverse\n6.Exit" << std::endl;
        std::cin >> i;

        switch (i) {
        case 1: std::cout << "Enter data element followed by index (0 for insertion at start, -1 for insertion at end):" << std::endl;
            std::cin >> data >> index;
            Insert(data, index);
            break;

        case 2: std::cout << "Delete element by value(enter 0) or by index(enter 1):" << std::endl;
            std::cin >> branch;
            if (branch == 0) {
                std::cout << "Enter data element:" << std::endl;
                std::cin >> data;
                Delete(data, -1);
            } else if (branch == 1) {
                std::cout << "Enter position:" << std::endl;
                std::cin >> index;
                Delete(-1, index);
            } else {
                std::cout << "Invalid Input!" << std::endl;
            }
            break;

        case 3: std::cout << "Enter number to be searched:" << std::endl;
            std::cin >> data;
            rNum = Search(data);
            if (rNum != -1) {
                std::cout << "Number found in linked list at " << rNum << " position." << std::endl;
            } else {
                std::cout << "Number doesn't exist in linked list." << std::endl;
            }
            break;

        case 4: Print();
            break;

        case 5: Reverse();
            std::cout << "List has been reversed." << std::endl;
            break;

        default:
            if (i != 6) {
                std::cout << "Invalid Input!\n" << std::endl;
            }
        }
    }

    return 0;
}
