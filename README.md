# Syslog Linked List Projesi

## Proje Açıklaması

Bu proje, **C programlama dili kullanılarak syslog kayıtlarının Linked List (Bağlı Liste) veri yapısı ile saklanmasını ve ekrana yazdırılmasını** göstermektedir.

Program içerisinde her log kaydı bir **node (düğüm)** olarak tutulur. Bu düğümler birbirine bağlanarak bir **linked list** oluşturur ve daha sonra tüm log kayıtları ekrana yazdırılır.

## Projenin Amacı

Bu projenin amacı aşağıdaki konuları öğrenmektir:

* Linked List (Bağlı Liste) veri yapısı
* C dilinde dinamik bellek kullanımı
* Log kayıtlarının veri yapıları ile saklanması
* Liste üzerinde dolaşma (traversal)

## Program Nasıl Çalışır?

Programın çalışma adımları:

1. Log kayıtlarını tutmak için bir **Node yapısı** oluşturulur.
2. `addLog()` fonksiyonu ile log kayıtları linked list içerisine eklenir.
3. `printLogs()` fonksiyonu linked list üzerinde dolaşarak tüm log kayıtlarını ekrana yazdırır.

## Kullanılan Teknolojiler

* C Programlama Dili
* Linked List Veri Yapısı

## Örnek Çıktı

--- SYSLOG KAYITLARI ---

Jan 10 login successful
Jan 10 ssh connection established
Jan 10 system reboot
Jan 10 network error detected
Jan 10 USB device connected

## Veri Yapısı

Programda kullanılan node yapısı:

struct Node {
char log[256];
struct Node* next;
};

## Geliştirici

Öğrenci Projesi
