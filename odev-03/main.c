#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int saglik = 100;
    int enerji = 100;
    int yemek = 2;
    char komut;
    srand(time(NULL));

    printf("=== HAYATTA KALMA SIMULATORU ===\n");
    printf("Komutlar: A=Avlan, S=Siginak Ara, E=Envanter, R=Dinlen, F=Tehlike Dalgasi, P=Sifreli Ilerleme, X=Cikis\n");

    do {
        printf("\nKomut girin: ");
        scanf(" %c", &komut);

        switch (komut) {

        case 'A':   // Avlan
        case 'a':
            printf("\nAvlaniyorsun...\n");
            enerji -= 15;

            int sans = rand() % 100;

            if ((sans > 50 && enerji > 20) || saglik > 50) {
                printf("Yemek buldun! +1 yemek\n");
                yemek++;
            } else if (sans < 20 && enerji < 40) {
                printf("Av sirasinda yaralandin! -10 saðlýk\n");
                saglik -= 10;
            } else {
                printf("Hicbir sey bulamadin.\n");
            }

            break;

        case 'S':   // Sýðýnak
        case 's':
        {
            printf("\nCevrede siginak ariyorsun...\n");
            int durum = rand() % 100;

            if (durum > 70) {
                printf("Güvenli bir siginak buldun! Enerji +10\n");
                enerji += 10;
            } else if (durum > 40 && durum <= 70) {
                printf("Kismi bir korunak buldun. Saðlýk +5\n");
                saglik += 5;
            } else {
                printf("Hiçbir siginak bulamadin.\n");
            }
        }
        break;

        case 'E':   // Envanteri göster
        case 'e':
            printf("\n--- Envanter ---\n");
            printf("Saglik : %d\n", saglik);
            printf("Enerji : %d\n", enerji);
            printf("Yemek  : %d\n", yemek);
            printf("-----------------\n");
            break;

        case 'R':   // Dinlen
        case 'r':
            printf("\nDinleniyorsun...\n");

            enerji += 20;
            saglik += 10;

            if (enerji > 100) enerji = 100;
            if (saglik > 100) saglik = 100;

            printf("Enerji ve saglik artti!\n");
            break;

        case 'F':   // Tehlike dalgasý (FOR döngüsü)
        case 'f':
            printf("\n--- Tehlike Dalgasi Basladi ---\n");
            
            int i; 
            
            for (i = 1; i <= 5; i++) {
                printf("Dalga %d geliyor...\n", i);

                int olay = rand() % 3;

                if (olay == 0) {
                    printf("Canavar saldirdi! -15 saðlýk\n");
                    saglik -= 15;
                } else if (olay == 1) {
                    printf("Kosman gerekiyor! -10 enerji\n");
                    enerji -= 10;
                } else {
                    printf("Tehlikeden ustaca kaciyorsun!\n");
                }

                if (saglik <= 0) {
                    printf("\nOLDUN! Oyun bitti.\n");
                    return 0;
                }
            }
            printf("--- Tehlike Dalgasi Bitti ---\n");
            break;

        case 'P':   // Þifreli ilerleme (do-while)
        case 'p':
        {
            printf("\nBir kapi onundesin. Acmak icin gizli karakteri girmelisin.\n");
            char giris;
            char sifre = 'K';

            do {
                printf("Sifre gir (ipucu: 'K'): ");
                scanf(" %c", &giris);
            } while (giris != sifre);

            printf("Kapi acildi! Devam edebilirsin.\n");
        }
        break;

        case 'X':
        case 'x':
            printf("\nCikis yapiliyor...\n");
            break;

        default:
            printf("Gecersiz komut! Tekrar deneyin.\n");
            break;
        }

    } while (komut != 'X' && komut != 'x');

    return 0;
}

