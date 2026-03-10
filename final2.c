#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char log[256];
    struct Node* next;
};

struct Node* head = NULL;

void addLog(char *text) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->log, text);
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printLogs() {
    struct Node* temp = head;

    printf("\n--- SYSLOG KAYITLARI ---\n\n");

    while(temp != NULL) {
        printf("%s\n", temp->log);
        temp = temp->next;
    }
}

int main() {

    addLog("Jan 10 login successful");
    addLog("Jan 10 ssh connection established");
    addLog("Jan 10 system reboot");
    addLog("Jan 10 network error detected");
    addLog("Jan 10 USB device connected");

    printLogs();

    return 0;
}
