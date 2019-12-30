#include <iostream>
#include <conio.h>

using namespace std;

int kuota[10] , potongan[10];
string menu[4] = {"nasgor" , "naskun" , "es kelapa" , "es kepal milo"};
int harga[4] = {5000 , 5000 , 7000 , 7000};
string jenis[4] = {"makanan" , "makanan" , "minuman" , "minuman"};
string voucher[10];
int counter = 1;
void bubbleSort();
void bubbleSort1();
void tampilVoucher();
void tampilPesanan();
void prosesPesanan();
void hasilPesanan();

string menu1[10];
int counter1 = 1;
string voucher1;
string voucher2[10];

int total;
int harga1 , harga2;
int pesanan;
main()
{
	int pil , pil1;
	char ulang;
	
	do {
	system("cls");
	cout << "1.Tambah kode voucher\n"
		 << "2.hapus kode voucher\n"
		 << "3.tampilkan menu\n"
		 << "4.Bayar\n";
	cout << "input pilihan : ";
	cin >> pil;
		switch(pil)
		{
			case 1 :
		
					cout << "input voucher : ";
					cin >> voucher[counter];
					cout << "input kuota : ";
					cin >> kuota[counter];
					cout << "input potongan : ";
					cin >> potongan[counter];
					
					
				
				counter++;
			
				break;
			case 2 : 
				counter--;
				tampilVoucher();
				getch();
				
				break;
			case 3 :
				cout << "1.kuota terbesar\n"
					 << "2.potongan terkecil\n";
				cout << "input pilihan : ";
				cin >> pil1;
				switch(pil1)
				{
					case 1:
						cout << endl;
						bubbleSort();
						tampilVoucher();
						break;
					case 2:
						cout << endl;
						bubbleSort1();
						cout << "kode voucher\t\t kuota\t\t potongan" <<endl;
						tampilVoucher();
							
						break;
					
		 		}
		 		getch();
		 		break;
		 
		 	case 4 :
		 		do {
				 	
					system("cls");
					tampilVoucher();
					cout << endl << endl;
					tampilPesanan();
					cout << endl;
					cout << "input pesanan : ";
					cin >> pesanan;
					
					prosesPesanan();
					cout << "Apakah anda ingin memesan lagi(y/t) : ";
					cin >> ulang;
					
				} while(ulang!='t');
				system("cls");
				hasilPesanan();
				getch();
				break;	
		 	
			
		} 
	} while(pil != 5);
}

void bubbleSort()
{
    int i, j, temp , temp3;
    string temp1;
    for(i = 1; i < counter-1; i++)
    {
        for(j = 1; j < counter-1; j++)
        {
            if( kuota[j] < kuota[j+1])
            {
                // swap the elements
                temp = kuota[j];
                kuota[j] = kuota[j+1];
                kuota[j+1] = temp;
                
                temp1 = voucher[j];
                voucher[j] = voucher[j+1];
                voucher[j+1] = temp1;
                
                
                temp = potongan[j];
                potongan[j] = potongan[j+1];
                potongan[j+1] = temp;
            } 
        }
    }
}

void bubbleSort1()
{
    int i, j, temp , temp3;
    string temp1;
    for(i = 0; i < counter-1; i++)
    {
        for(j = 0; j < counter-1; j++)
        {
            if( potongan[j+1] < potongan[j])
            {
                // swap the elements
                temp = potongan[j];
                potongan[j] = potongan[j+1];
                potongan[j+1] = temp;
                
                temp3 = kuota[j];
                kuota[j] = kuota[j+1];
                kuota[j+1] = temp3;
                
                temp1 = voucher[j];
                voucher[j] = voucher[j+1];
                voucher[j+1] = temp1;
                
            } 
        }
    }
}

void tampilVoucher()
{
	cout << "kode voucher\t\t kuota\t\t potongan" <<endl;
	for (int i = 1;i <counter;i++)
	{
		cout << i<<"."<<voucher[i]<<"\t\t\t"<<kuota[i]<<"\t\t\t"<<potongan[i]<<endl;
	}
}

void tampilPesanan()
{
	cout << "daftar menu" << endl;
	cout << "menu\t\t\t harga\t\t\t jenis" <<endl;
	for (int i = 1;i <4;i++)
	{
		cout << i<<"."<<menu[i]<<"\t\t\t"<<harga[i]<<"\t\t\t"<<jenis[i]<<endl;
	}
}

void prosesPesanan()
{
		for (int j =1;j < 4;j++)
		{
			if(j == pesanan)
			{
				cout << "input kode voucher : ";
				cin >> voucher1;
				for (int i = 1;i < counter;i++)
				{
					if (voucher[i] == voucher1)
					{
						harga2 = harga2 + harga[j];
						harga1 = harga2 * potongan[i] / 100;
									
						total = harga[j] -  harga1;
									
					} else {
						total = harga[j];
					}
				}
					menu1[counter1] = menu[j];
			}
		}
		counter1++;
}

void hasilPesanan()
{
	cout << "pesanan : ";
	for (int i = 1;i < counter1;i++)
	{
		cout << i << ". " << menu1[i] << " " << endl;
		cout << "harga : " << harga[i] << endl;
					
	}
	cout << "harga total : " << harga2 << endl;
	cout << "harga setelah potongan : " << total << endl;
	counter1 = 1;
	harga2 = 0;
}
