#include <stdio.h>   // printf gibi giriş-çıkış işlemleri için kullanılır
#include <stdlib.h>  // malloc gibi dinamik bellek ayırma işlemleri için kullanılır
#include <string.h>  // strcpy gibi string işlemleri için kullanılır

// Bağlı listenin her elemanını temsil eden yapı (Node)
// Her Node bir syslog kaydını saklamak için kullanılmaktadır
struct Node {
    char log[256];        // Syslog mesajını saklamak için 256 karakterlik alan
    struct Node* next;    // Bir sonraki düğümün adresini tutan pointer
};

// Listenin başlangıç noktasını tutan pointer
// "head" ismi listenin başını temsil ettiği için seçilmiştir
struct Node* head = NULL;

// Yeni bir syslog kaydını bağlı listenin sonuna ekleyen fonksiyon
// Fonksiyonun adı "addLog" olarak seçilmiştir çünkü amacı log kaydı eklemektir
void addLog(char *text) {

    // Yeni bir düğüm oluşturmak için bellekten yer ayrılır
    // malloc fonksiyonu Node yapısı kadar bellek ayırır
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Fonksiyona parametre olarak gelen text değişkeni
    // log mesajını temsil eder ve düğümün log alanına kopyalanır
    strcpy(newNode->log, text);

    // Yeni düğüm başlangıçta listenin son elemanı olacağı için
    // next pointer'ı NULL yapılır
    newNode->next = NULL;

    // Eğer liste boşsa (head NULL ise)
    if(head == NULL) {
        // Yeni oluşturulan düğüm listenin ilk elemanı olur
        head = newNode;
    } 
    else {
        // Liste boş değilse son düğümü bulmak gerekir
        // Bunun için geçici bir pointer kullanılır
        struct Node* temp = head;

        // temp pointer'ı listenin sonuna kadar ilerletilir
        while(temp->next != NULL) {
            temp = temp->next;
        }

        // Listenin sonuna ulaşıldığında yeni düğüm eklenir
        temp->next = newNode;
    }
}

// Bağlı listedeki tüm syslog kayıtlarını ekrana yazdıran fonksiyon
// Fonksiyon adı "printLogs" olarak seçilmiştir çünkü logları yazdırma görevini yapmaktadır
void printLogs() {

    // Listenin başından başlayarak ilerlemek için geçici pointer
    struct Node* temp = head;

    printf("\n--- SYSLOG KAYITLARI ---\n\n");

    // Liste sonuna kadar ilerleyen döngü
    while(temp != NULL) {

        // Her düğümde bulunan log mesajı ekrana yazdırılır
        printf("%s\n", temp->log);

        // Bir sonraki düğüme geçilir
        temp = temp->next;
    }
}

int main() {

    // Programın ana fonksiyonu
    // Burada örnek syslog kayıtları bağlı listeye eklenmektedir

    addLog("Jan 10 login successful");        // Kullanıcı girişinin başarılı olduğunu belirten log
    addLog("Jan 10 ssh connection established"); // SSH bağlantısının kurulduğunu belirten log
    addLog("Jan 10 system reboot");           // Sistem yeniden başlatıldığını belirten log
    addLog("Jan 10 network error detected");  // Ağ hatasının oluştuğunu belirten log
    addLog("Jan 10 USB device connected");    // USB cihazının bağlandığını belirten log

    // Eklenen tüm log kayıtlarını ekrana yazdırır
    printLogs();

    return 0; // Programın başarıyla tamamlandığını gösterir
}
