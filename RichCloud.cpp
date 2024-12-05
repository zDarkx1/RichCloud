#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>
#include <ctime>
#include <windows.h>
#include <fstream>
using namespace std;

// Variabel global
string os, location, planName, ram, storage, bandwidth, cpu,
price, domainType, domainName,priceinbtc,priceinusdt,priceineth,priceintrx,priceinavax;

//Deklarasi print struk
ofstream exc("struk");

int printinvoice();

// Warna ANSI
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string BOLD = "\033[1m";

//Fungsi tampilan awal
void display() {
    system("cls");
    cout << CYAN << "****************************************" << endl;
    cout << "*                                      *" << endl;
    cout << "*              " << BOLD << "RICHCLOUD" << RESET << CYAN << "               *" << endl;
    cout << "*                                      *" << endl;
    cout << "****************************************" << RESET << endl;
    cout << GREEN << "         Welcome to RichCloud" << endl;
    cout << "        Tekan enter untuk lanjut" << RESET << endl;
    getch();
    system("cls");
}
// Fungsi loading dengan pesan
void loading(const string &message) {
    cout << YELLOW << "\n" << message << RESET;
    for (int i = 0; i < 8; i++) {
        cout << ".";
        sleep(1);
    }
    cout << endl;
}

// Fungsi pemilihan OS
void selectOS(string &os) {
    system("cls");
    cout << BLUE << "****************************************" << endl;
    cout << "*          " << BOLD <<"PILIH IMAGE    " << RESET <<  BLUE <<"    *" << RESET << endl;
    cout << BLUE << "****************************************" << RESET << endl;
    cout << BOLD << "OS :" << RESET << endl;
    cout << "****************************************" << RESET << endl;
    cout << "1. " << GREEN << "Ubuntu 20.04" << RESET << endl;
    cout << "2. " << GREEN << "Ubuntu 22.04" << RESET << endl;
    cout << "3. " << GREEN << "Windows Server 2016 Datacenter" << RESET << endl;
    cout << "4. " << GREEN << "Windows Server 2019 Datacenter" << RESET << endl;
    cout << "5. " << GREEN << "Windows Server 2022 Datacenter" << RESET << endl;
    cout << "6. " << GREEN << "Windows Server 2025 Datacenter" << RESET << endl;
    cout << "7. " << GREEN << "Alma Linux 9" << RESET << endl;
    cout << "8. " << GREEN << "Rocky Linux 9" << RESET << endl;
    cout << "9. " << GREEN << "Debian 11" << RESET << endl;
    cout << "****************************************" << RESET << endl;
    cout << BOLD << "Blockchain :" << RESET << endl;
    cout << "****************************************" << RESET << endl;
    cout << "10. " << GREEN << "Ethereum Staking Node" << RESET << endl;
    cout << "11. " << GREEN << "Bitcoin Node" << RESET << endl;
    cout << "12. " << GREEN << "IPFS Node" << RESET << endl;
    cout << "12. " << GREEN << "FLUX Node" << RESET << endl;
    cout << "13. " << GREEN << "Horizen Node" << RESET << endl;
    cout << "****************************************" << RESET << endl;
    cout << BOLD << "Apps & Panel :" << RESET << endl;
    cout << "****************************************" << RESET << endl;
    cout << "14. " << GREEN << "Cpanel/WHM (5 ACCOUNTS)" << RESET << endl;
    cout << "15. " << GREEN << "Docker (Ubuntu 22.04)" << RESET << endl;
    cout << BLUE << "****************************************" << RESET << endl;
    cout << YELLOW << "Masukkan pilihan Image Anda: " << RESET;
    int osChoice;
    cin >> osChoice;
    switch (osChoice) {
        case 1: os = "Ubuntu 20.04 [OS]"; break;
        case 2: os = "Ubuntu 22.04 [OS]"; break;
        case 3: os = "Windows Server 2016 Datacenter [OS]"; break;
        case 4: os = "Windows Server 2019 Datacenter [OS]"; break;
        case 5: os = "Windows Server 2022 Datacenter [OS]"; break;
        case 6: os = "Windows Server 2025 Datacenter [OS]"; break;
        case 7: os = "Alma Linux 9 [OS]"; break;
        case 8: os = "Rocky Linux 9 [OS]"; break;
        case 9: os = "Ethereum Staking Node [BLOCKCHAIN]"; break;
        case 10: os = "Bitcoin Node [BLOCKCHAIN]"; break;
        case 11: os = "IPFS Node [BLOCKCHAIN]"; break;
        case 12: os = "FLUX Node [BLOCKCHAIN]"; break;
        case 13: os = "Horizen Node [BLOCKCHAIN]"; break;
        case 14: os = "Cpanel/WHM (5 ACCOUNTS) [Apps & Panel]"; break;
        case 15: os = "Docker (Ubuntu 22.04) [Apps & Panel]"; break;
        default: os = "Tidak diketahui"; break;
    }
}

// Fungsi pemilihan lokasi server
void selectLocation(string &location) {
    system("cls");
    cout << BLUE << "****************************************" << endl;
    cout << "*          PILIH LOKASI SERVER         *" << endl;
    cout << "****************************************" << RESET << endl;
    cout << "1. " << GREEN << "Jakarta" << RESET << "  \t\t\t[o] Good Latency" << endl;
    cout << "2. " << GREEN << "Singapore" << RESET << " \t\t\t[o] Good Latency" << endl;
    cout << "3. " << GREEN << "Tokyo" << RESET << "     \t\t\t[~] Mid Latency" << endl;
    cout << "4. " << GREEN << "European Union" << RESET << "     \t\t[~] Mid Latency" << endl;
    cout << "5. " << GREEN << "United States (East)" << RESET << "     \t[~] Mid Latency" << endl;
    cout << "6. " << GREEN << "Australia (Sydney)" << RESET << "     \t[~] Good Latency" << endl;
    cout << "7. " << GREEN << "Asia (India)" << RESET << "     \t\t[~] Good Latency" << endl;
    cout << "8. " << GREEN << "United States (Central)" << RESET << "     \t[~] Mid Latency" << endl;
    cout << "9. " << GREEN << "Asia (Korea)" << RESET << "     \t\t[~] Good Latency" << endl;
    cout << BLUE << "****************************************" << RESET << endl;
    cout << YELLOW << "Masukkan pilihan lokasi server Anda: " << RESET;
    int locationChoice;
    cin >> locationChoice;
    switch (locationChoice) {
        case 1: location = "Jakarta"; break;
        case 2: location = "Singapore"; break;
        case 3: location = "Tokyo"; break;
        case 4: location = "European Union"; break;
        case 5: location = "United States (East)"; break;
        case 6: location = "Australia (Sydney)"; break;
        case 7: location = "Asia (India)"; break;
        case 8: location = "United States (Central)"; break;
        case 9: location = "Asia (Korea)"; break;
        default: location = "Tidak diketahui"; break;
    }
}

// Fungsi ringkasan pembelian
void displaySummary() {
    system("cls");
    cout << BLUE << "****************************************" << endl;
    cout << "*          " << BOLD <<"RINGKASAN PEMBELIAN    " << RESET <<  BLUE <<"    *" << RESET << endl;
    cout << BLUE << "****************************************" << RESET << endl;
    if (!planName.empty()){
    cout << "| Plan        : " << planName << endl;
    cout << "| RAM         : " << ram << endl;
    cout << "| Storage     : " << storage << endl;
    cout << "| Bandwidth   : " << bandwidth << endl;
    cout << "| CPU Core    : " << cpu << endl;
    cout << "| Image       : " << os << endl;
    cout << "| Lokasi      : " << location << endl;
    }
    if (!domainType.empty()) {
        cout << "| Domain      : " << domainName << domainType << endl;
    }
    cout << "| Harga       : " << price << endl;
    cout << BLUE << "-----------------------------------------" << RESET <<endl;
    cout << "Apakah Anda ingin melanjutkan pembelian? (y/n): ";
}

// Fungsi pembayaran
void payment() {
    system("cls");
    int usdtnetwork,paymentChoice;
    string netfinal,usdttype,paymenttype;
    cout << BLUE << "****************************************" << endl;
    cout << "*          " << BOLD <<"PEMBAYARAN    " << RESET <<  BLUE <<"    *" << RESET << endl;
    cout << BLUE << "****************************************" << RESET << endl;
    cout << BOLD << "Bank Transfer :" << RESET << endl;
    cout << "****************************************" << RESET << endl;
    cout << "1. " << GREEN << "BCA" << RESET << endl;
    cout << "2. " << GREEN << "Mandiri" << RESET << endl;
    cout << "3. " << GREEN << "BNI" << RESET << endl;
    cout << "4. " << GREEN << "MayBank" << RESET << endl;
    cout << "5. " << GREEN << "BANK BRI" << RESET << endl;
    cout << "****************************************" << RESET << endl;
    cout << BOLD << "E-Wallet :" << RESET << endl;
    cout << "****************************************" << RESET << endl;
    cout << "6. " << GREEN << "Dana" << RESET << endl;
    cout << "7. " << GREEN << "OVO" << RESET << endl;
    cout << "8. " << GREEN << "Gopay" << RESET << endl;
    cout << "9. " << GREEN << "LinkAja" << RESET << endl;
    cout << "****************************************" << RESET << endl;
    cout << BOLD << "CryptoCurrency :" << RESET << endl;
    cout << "****************************************" << RESET << endl;
    cout << "10. " << GREEN << "Bitcoin (BTC)" << RESET << endl;
    cout << "11. " << GREEN << "Avalanche (AVAX)" << RESET << endl;
    cout << "12. " << GREEN << "Ethereum (ETH)" << RESET << endl;
    cout << "13. " << GREEN << "TRX (TRON)" << RESET << endl;
    cout << "14. " << GREEN << "USDT (Tether)" << RESET << endl;
    cout << BLUE << "****************************************" << RESET << endl;
    cout << "Pilih metode pembayaran Anda: ";
    cin >> paymentChoice;

    system("cls");
    switch (paymentChoice) {
        case 1:
            cout << "-------------------------------------------" << endl;
            cout << "Nama Bank : BCA" << endl;
            cout << "Nomor Rek : 7819992831203" << endl;
            cout << "A/N       : Alrizky Filardhi Budiman" << endl;
            cout << "Total     : " << price << endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 2:
            cout << "-------------------------------------------" << endl;
            cout << "E-Wallet  : Mandiri " << endl;
            cout << "Nomor Rek : 9200273922123" << endl;
            cout << "A/N       : Alrizky Filardhi Budiman" << endl;
            cout << "Total     : " << price << endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 3:
            cout << "-------------------------------------------" << endl;
            cout << "E-Wallet  : BNI " << endl;
            cout << "Nomor Rek : 37497238782832" << endl;
            cout << "A/N       : Alrizky Filardhi Budiman" << endl;
            cout << "Total     : " << price << endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 4:
            cout << "-------------------------------------------" << endl;
            cout << "E-Wallet  : MAYBANK " << endl;
            cout << "Nomor Rek : 2873299231284" << endl;
            cout << "A/N       : Alrizky Filardhi Budiman" << endl;
            cout << "Total     : " << price << endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 5:
            cout << "-------------------------------------------" << endl;
            cout << "E-Wallet  : Bank BRI " << endl;
            cout << "Nomor Rek : 29993729474834" << endl;
            cout << "A/N       : Alrizky Filardhi Budiman" << endl;
            cout << "Total     : " << price << endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 6:
            cout << "-------------------------------------------" << endl;
            cout << "E-Wallet  : Dana " << endl;
            cout << "Nomor Rek : 089523077006" << endl;
            cout << "A/N       : Alrizky Filardhi Budiman" << endl;
            cout << "Total     : " << price << endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 7:
            cout << "-------------------------------------------" << endl;
            cout << "E-Wallet  : OVO " << endl;
            cout << "Nomor Rek : 089523077006" << endl;
            cout << "A/N       : Alrizky Filardhi Budiman" << endl;
            cout << "Total     : " << price << endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 8:
            cout << "-------------------------------------------" << endl;
            cout << "E-Wallet  : Gopay " << endl;
            cout << "Nomor Rek : 089523077006" << endl;
            cout << "A/N       : Alrizky Filardhi Budiman" << endl;
            cout << "Total     : " << price << endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 9:
            cout << "-------------------------------------------" << endl;
            cout << "E-Wallet  : LinkAja " << endl;
            cout << "Nomor Rek : 089523077006" << endl;
            cout << "A/N       : Alrizky Filardhi Budiman" << endl;
            cout << "Total     : " << price << endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 10:
            cout << "-------------------------------------------" << endl;
            cout << MAGENTA << "                 BITCOIN" << RESET <<endl;
            cout << "Address : 1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa" << endl;
            cout << "Network : BTC" << endl;
            cout << "Total   : " << priceinbtc << endl;
            cout << "-------------------------------------------" << endl;
            cout << RED << "             Secured By RichNET" << RESET <<endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 11:
            cout << "-------------------------------------------" << endl;
            cout << MAGENTA <<"                   AVAX" << RESET <<endl;
            cout << "Address : X-avax1r8lq83w72jlmcsq5axc9g2ttxjlg2x55hdwpe8" << endl;
            cout << "Network : Avalanche" << endl;
            cout << "Total     : " << priceinavax << endl;
            cout << "-------------------------------------------" << endl;
            cout << RED << "             Secured By RichNET" << RESET <<endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 12:
            cout << "-------------------------------------------" << endl;
            cout << MAGENTA <<"                    ETH" << RESET <<endl;
            cout << "Address : 0x32Be343B94f860124dC4fEe278FDCBD38C102D88" << endl;
            cout << "Network : ETH (ERC-20)" << endl;
            cout << "Total     : " << priceineth << endl;
            cout << "-------------------------------------------" << endl;
            cout << RED << "             Secured By RichNET" << RESET <<endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 13:
            cout << "-------------------------------------------" << endl;
            cout << MAGENTA <<"                    TRX" << RESET <<endl;
            cout << "Address : TJP3bmE2URtV2D3Gppoyv1QUh93uFHZ9ZG" << endl;
            cout << "Network : TRON (TRC-20)" << endl;
            cout << "Total     : " << priceintrx << endl;
            cout << "-------------------------------------------" << endl;
            cout << RED << "             Secured By RichNET" << RESET <<endl;
            cout << "-------------------------------------------" << endl;
            break;
        case 14:
            cout << BOLD <<"Choose your network !" << RESET << endl;
            cout << "-------------------------------------------" << endl;
            cout << MAGENTA <<"                   USDT" << RESET <<endl;
            cout << "1. BSC (BEP-20) " << GREEN << "[MOST POPULAR]"<< RESET << endl;
            cout << "2. TRON (TRC-20) " << endl;
            cout << "3. ETH (ERC-20) " << endl;
            cout << "4. POLYGON (ERC-20) " << endl;
            cout << "5. ARBITRUM " << endl;
            cout << "6. AVALANCHE " << endl;
            cout << "7. SOL " << endl;
            cout << "8. TON " << endl;
            cout << "-------------------------------------------" << endl;
            cout << RED << "             Secured By RichNET" << RESET <<endl;
            cout << "-------------------------------------------" << endl;
            cout << "Choose your network : ";
            cin >> usdtnetwork;
            switch (usdtnetwork)
            {
            case 1:
                usdttype = "BSC (BEP-20)";
                netfinal = "0x1A2b3C4d5E6f7G8h9I0jKlMnOpQrStUvWxYz1234";
                break;
            case 2:
                usdttype = "TRON (TRC-20)";
                netfinal = "T1a2B3c4D5E6f7g8h9i0JKLMNopqRstuVWXYZ";
                break;
            case 3:
                usdttype = "ETH (ERC-20)";
                netfinal = "0xAbCdEf1234567890abcdef1234567890aBcDef12";
                break;
            case 4:
                usdttype = "POLYGON (ERC-20)";
                netfinal = "0x98aBcDef1234567890abcdef1234567890DefAbC";
                break;
            case 5:
                usdttype = "ARBITRUM";
                netfinal = "0x1234aBcDefAbCdeF1234567890AbCdEf12345678";
                break;
            case 6:
                usdttype = "AVALANCHE";
                netfinal = "0x89Def1234567890aBcDef1234567890abCdEfABC";
                break;
            case 7:
                usdttype = "SOL";
                netfinal = "3F4Gh5Jk6LmNopQRStuVWXYZ123456789AbCDeF";
                break;
            case 8:
                usdttype = "TON";
                netfinal = "EQ1A2b3C4D5E6f7g8H9I0JKLMNopqRstuVWXYZABC";
                break;
            case 0:
                return;
            default:
                cout << "Pilihan tidak valid!" << endl;
                sleep(1);
            }
            if (usdtnetwork != 0) {
                system("cls");
            cout << "-------------------------------------------" << endl;
            cout << MAGENTA <<"                   USDT" << RESET <<endl;
            cout << "Address : " << netfinal << endl;
            cout << "Network : " << usdttype << endl;
            cout << "Total     : " << priceinusdt << endl;
            cout << "-------------------------------------------" << endl;
            cout << RED << "             Secured By RichNET" << RESET <<endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    loading("Memproses pembayaran");
    cout << "Pembayaran Berhasil! Terima kasih telah menggunakan layanan kami." << endl;
    sleep(2);
    printinvoice();
    cout << "Tekan enter untuk kembali." << endl;
    getch();
}

// Fungsi pemilihan domain dengan input nama domain
void domain() {
    int domainChoice;
    do {
        system("cls");
        cout << "****************************************" << endl;
        cout << "*            PILIH DOMAIN             *" << endl;
        cout << "****************************************" << endl;
        cout << "1. .com   - Rp 150.000/tahun" << endl;
        cout << "2. .id    - Rp 175.000/tahun" << endl;
        cout << "3. .net   - Rp 200.000/tahun" << endl;
        cout << "0. Kembali" << endl;
        cout << "****************************************" << endl;
        cout << "Masukkan pilihan domain Anda: ";
        cin >> domainChoice;

        switch (domainChoice) {
            case 1:
                domainType = ".com";
                price = "Rp 150.000/tahun";
                priceinbtc = "0.000097465 BTC";
                priceineth = "0.003645 ETH";
                priceinavax = "0.51 AVAX";
                priceinusdt = "9.55 USDT";
                priceintrx = "1,667 TRX";
                break;
            case 2:
                domainType = ".id";
                price = "Rp 175.000/tahun";
                priceinbtc = "0.0001137 BTC";
                priceineth = "0.00425 ETH";
                priceinavax = "0.61 AVAX";
                priceinusdt = "11.15 USDT";
                priceintrx = "1,944 TRX";
                break;
            case 3:
                domainType = ".net";
                price = "Rp 200.000/tahun";
                priceinbtc = "0.0001869 BTC";
                priceineth = "0.00566 ETH";
                priceinavax = "0.85 AVAX";
                priceinusdt = "12.73 USDT";
                priceintrx = "2,222 TRX";
                break;
            case 0:
                return;
            default:
                cout << "Pilihan tidak valid!" << endl;
                sleep(1);
        }

        if (domainChoice != 0) {
            // Meminta nama domain
            system("cls");
            cout << "****************************************" << endl;
            cout << "*            INPUT NAMA DOMAIN        *" << endl;
            cout << "****************************************" << endl;
            cout << "Masukkan nama domain yang Anda inginkan (tanpa ekstensi): ";
            cin >> domainName;

            // Validasi sederhana
            if (domainName.empty()) {
                cout << "Nama domain tidak boleh kosong!" << endl;
                sleep(1);
                continue;
            }

            // Menampilkan ringkasan
            displaySummary();
            char confirm;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                payment();
            } else {
                cout << "Pembelian dibatalkan." << endl;
                cout << "Tekan enter untuk kembali." << endl;
                getch();
            }
        }

    } while (domainChoice != 0);
}

// Fungsi pemilihan server dengan parameter tipe server
void selectServer(const string &serverType) {
    int planChoice;
    do {
        system("cls");
        cout << "****************************************" << endl;
        cout << "*         " << serverType << "          *" << endl;
        cout << "****************************************" << endl;
        cout << "1. Starter Plan" << endl;
        cout << "2. Professional Plan" << endl;
        cout << "3. Enterprise Plan" << endl;
        cout << "0. Kembali" << endl;
        cout << "****************************************" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> planChoice;

        switch (planChoice) {
            case 1:
                planName = "Starter";
                ram = "4GB";
                storage = "100GB SSD";
                bandwidth = "2TB";
                cpu = "2 Core";
                price = "Rp 150.000/bulan";
                priceinbtc = "0.000097465 BTC";
                priceineth = "0.003645 ETH";
                priceinavax = "0.51 AVAX";
                priceinusdt = "9.55 USDT";
                priceintrx = "1,667 TRX";
                break;
            case 2:
                planName = "Professional";
                ram = "8GB";
                storage = "200GB SSD";
                bandwidth = "4TB";
                cpu = "4 Core";
                price = "Rp 300.000/bulan";
                priceinbtc = "0.00019493 BTC";
                priceineth = "0.00549 ETH";
                priceinavax = "1.02 AVAX";
                priceinusdt = "19.11 USDT";
                priceintrx = "3,333 TRX";
                break;
            case 3:
                planName = "Enterprise";
                ram = "16GB";
                storage = "500GB SSD";
                bandwidth = "8TB";
                cpu = "8 Core";
                price = "Rp 500.000/bulan";
                priceinbtc = "0.0003249 BTC";
                priceineth = "0.00823 ETH";
                priceinavax = "1.70 AVAX";
                priceinusdt = "31.85 USDT";
                priceintrx = "5,556 TRX";
                break;
            case 0:
                return;
            default:
                cout << "Pilihan tidak valid!" << endl;
                sleep(1);
        }
        if (planChoice != 0) {
            selectOS(os);
            selectLocation(location);
            displaySummary();
            char confirm;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                payment();
            } else {
                cout << "Pembelian dibatalkan." << endl;
                cout << "Tekan enter untuk kembali." << endl;
                getch();
            }
        }

    } while (planChoice != 0);
}

// Menu utama dengan ASCII Art
void mainMenu() {
    int choice;
    do {
        system("cls");
        cout << "****************************************" << endl;
        cout << "*            RICHCLOUD MENU           *" << endl;
        cout << "****************************************" << endl;
        cout << "1. Server VPS" << endl;
        cout << "2. Dedicated Server" << endl;
        cout << "3. Bare Metal Server" << endl;
        cout << "4. Domain" << endl;
        cout << "0. Keluar" << endl;
        cout << "****************************************" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                selectServer("SERVER VPS");
                break;
            case 2:
                selectServer("DEDICATED SERVER");
                break;
            case 3:
                selectServer("BARE METAL SERVER");
                break;
            case 4:
                domain();
                break;
            case 0:
                system("cls");
                cout << "****************************************" << endl;
                cout << "*  Terima kasih telah menggunakan     *" << endl;
                cout << "*          layanan kami!            *" << endl;
                cout << "****************************************" << endl;
                sleep(2);
                break;
            default:
                cout << "Pilihan tidak tersedia!" << endl;
                sleep(1);
        }
    } while (choice != 0);
}

int printinvoice() {
    system("cls");
    time_t curr_time;
    curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);

    char cetak;
    cout << GREEN << "||=================================================================||" << RESET << endl;
    cout << "||                             RichCloud                           ||" << endl;
    cout << "||     Waktunya beralih pada server cloud yang cepat dan aman !!   ||" << endl;
    cout << "||                                                                 ||" << endl;
    cout << "||   " << tm_local->tm_mday << "/" << tm_local->tm_mon + 1 << "/" << tm_local->tm_year + 1900;
    cout << "\t\t\t\t\t\t   " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << "   ||" << endl;
    cout << "||======================== STRUK PEMBELIAN ========================||" << endl;

    // Cetak detail plan jika ada
    if (!planName.empty()) {
        cout << "|| Plan       : " << planName << "\t\t\t\t\t\t   ||" << endl;
        cout << "|| OS         : " << os << "\t\t\t\t\t\t   ||" << endl;
        cout << "|| Lokasi     : " << location << "\t\t\t\t\t\t   ||" << endl;
    }
    if (!domainType.empty()) {
        cout << "|| Domain     : " << domainType << "\t\t\t\t\t\t   ||" << endl;
    }

    cout << "|| Total      : " << price << "\t\t\t\t\t\t   ||" << endl;

    // Cetak kredensial
    cout << "||=========================== CREDENTIAL ==========================||" << endl;
    if (!planName.empty()) {
        cout << "|| IP Address : 120.203.65.2                                      ||" << endl;
        cout << "|| Username   : root                                              ||" << endl;
        cout << "|| Password   : Ui9923xvcsy@                                      ||" << endl;
    }
    if (!domainType.empty()) {
        cout << "|| URL        : richkeyhost.sea51.net/clientarea.php             ||" << endl;
        cout << "|| Username   : User392                                           ||" << endl;
        cout << "|| Password   : 09230HJ@                                          ||" << endl;
    }

    cout << "||                                                                 ||" << endl;
    cout << "||                  TERIMAKASIH SUDAH BERBELANJA                   ||" << endl;
    cout << "||=================================================================||" << endl;

    // Simpan ke file
    ofstream exc("Struk Pembayaran.txt");
    exc << "||=================================================================||" << endl;
    exc << "||                             RichCloud                           ||" << endl;
    exc << "||     Waktunya beralih pada server cloud yang cepat dan aman !!   ||" << endl;
    exc << "||                                                                 ||" << endl;
    exc << "||   " << tm_local->tm_mday << "/" << tm_local->tm_mon + 1 << "/" << tm_local->tm_year + 1900;
    exc << "\t\t\t\t\t\t   " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << "   ||" << endl;
    exc << "||======================== STRUK PEMBELIAN ========================||" << endl;

    if (!planName.empty()) {
        exc << "|| Plan       : " << planName << "\t\t\t\t\t\t   ||" << endl;
        exc << "|| Image      : " << os << "\t\t\t\t\t\t   ||" << endl;
        exc << "|| Lokasi     : " << location << "\t\t\t\t\t\t   ||" << endl;
    }
    if (!domainType.empty()) {
        exc << "|| Domain     : " << domainType << "\t\t\t\t\t\t   ||" << endl;
    }

    exc << "|| Total      : " << price << "\t\t\t\t\t\t   ||" << endl;

    exc << "||=========================== CREDENTIAL ==========================||" << endl;
    if (!planName.empty()) {
        exc << "|| IP Address : 120.203.65.2                                      ||" << endl;
        exc << "|| Username   : root                                              ||" << endl;
        exc << "|| Password   : Ui9923xvcsy@                                      ||" << endl;
    }
    if (!domainType.empty()) {
        exc << "|| URL        : richkeyhost.sea51.net/clientarea.php             ||" << endl;
        exc << "|| Username   : User392                                           ||" << endl;
        exc << "|| Password   : 09230HJ@                                          ||" << endl;
    }

    exc << "||                                                                 ||" << endl;
    exc << "||                  TERIMAKASIH SUDAH BERBELANJA                   ||" << endl;
    exc << "||=================================================================||" << endl;
    exc.close();

    // Konfirmasi pencetakan
    cout << YELLOW << "Cetak Struk? [Y/N]: " << RESET;
    cin >> cetak;
    if (cetak == 'n' || cetak == 'N') {
        return 0;
    } else {
        system("notepad /p Struk Pembayaran.txt");
        system("cls");
        cout << BLUE << "Struk Berhasil dicetak" << RESET << endl;
        return 0;
    }
}

// Fungsi utama
int main() {
    display();
    mainMenu();
    return 0;
}